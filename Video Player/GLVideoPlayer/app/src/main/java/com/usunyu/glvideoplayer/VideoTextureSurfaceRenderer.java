package com.usunyu.glvideoplayer;

/**
 * Created by sun on 1/30/17.
 */

import android.content.Context;
import android.graphics.SurfaceTexture;
import android.opengl.GLES11Ext;
import android.opengl.GLES20;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.nio.ShortBuffer;

/***
 * 在这个类里面对视频纹理进行绘制工作，继承了 {@link TextureSurfaceRenderer},
 * 并实现了{@link SurfaceTexture.OnFrameAvailableListener}
 */
public class VideoTextureSurfaceRenderer extends TextureSurfaceRenderer implements
        SurfaceTexture.OnFrameAvailableListener {

    public static final String TAG = VideoTextureSurfaceRenderer.class.getSimpleName();
    /**绘制的区域尺寸*/
    private static float squareSize = 1.0f;
    private static float squareCoords[] = {
            -squareSize,  squareSize, 0.0f,   // top left
            -squareSize, -squareSize, 0.0f,   // bottom left
            squareSize, -squareSize, 0.0f,    // bottom right
            squareSize,  squareSize, 0.0f     // top right
    };
    /**绘制次序*/
    private static short drawOrder[] = {
            0, 1, 2,
            0, 2, 3
    };
    /**
     * 用来缓存纹理坐标，因为纹理都是要在后台被绘制好，然
     * 后不断的替换最前面显示的纹理图像
     */
    private FloatBuffer textureBuffer;
    /**纹理坐标*/
    private float textureCoords[] = {
            0.0f, 1.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 0.0f, 1.0f
    };
    /**生成的真实纹理数组*/
    private int[] textures = new int[1];
    /**着色器脚本程序的handle(句柄)*/
    private int shaderProgram;
    /**squareCoords的的顶点缓存*/
    private FloatBuffer vertexBuffer;
    /**绘制次序的缓存*/
    private ShortBuffer drawOrderBuffer;

    /**矩阵来变换纹理坐标，（具体含义下面再解释）*/
    private float[] videoTextureTransform;
    /**当前的视频帧是否可以得到*/
    private boolean frameAvailable = false;
    private Context context;
    private SurfaceTexture videoTexture;    // 从视频流捕获帧作为Opengl ES 的Texture

    /**
     * @param texture 从TextureView获取到的SurfaceTexture，目的是为了配置EGL 的native window
     */
    public VideoTextureSurfaceRenderer(Context context, SurfaceTexture texture, int width, int height)
    {
        super(texture, width, height);  //先调用父类去做EGL初始化工作
        this.context = context;
        videoTextureTransform = new float[16];
    }

    /**
     * 重写父类方法，初始化组件
     */
    @Override
    protected void initGLComponents()
    {
        setupVertexBuffer();
        setupTexture();
        loadShaders();
    }

    @Override
    protected void deinitGLComponents()
    {
        GLES20.glDeleteTextures(1, textures, 0);
        GLES20.glDeleteProgram(shaderProgram);
        videoTexture.release();
        videoTexture.setOnFrameAvailableListener(null);
    }

    /***
     * 设置顶点缓存
     */
    private void setupVertexBuffer()
    {
        /** Draw Order buffer*/
        ByteBuffer orderByteBuffer = ByteBuffer.allocateDirect(drawOrder. length * 2);
        orderByteBuffer.order(ByteOrder.nativeOrder());  //Modifies this buffer's byte order
        drawOrderBuffer = orderByteBuffer.asShortBuffer();  //创建此缓冲区的视图，作为一个short缓冲区.
        drawOrderBuffer.put(drawOrder);
        drawOrderBuffer.position(0); //下一个要被读或写的元素的索引，从0 开始

        // Initialize the texture holder
        ByteBuffer bb = ByteBuffer.allocateDirect(squareCoords.length * 4);
        bb.order(ByteOrder.nativeOrder());
        vertexBuffer = bb.asFloatBuffer();
        vertexBuffer.put(squareCoords);
        vertexBuffer.position(0);
    }

    /**接着初始化纹理*/
    private void setupTexture()
    {
        ByteBuffer texturebb = ByteBuffer.allocateDirect(textureCoords.length * 4);
        texturebb.order(ByteOrder.nativeOrder());

        textureBuffer = texturebb.asFloatBuffer();
        textureBuffer.put(textureCoords);
        textureBuffer.position(0);

        // 启用纹理
        GLES20.glActiveTexture(GLES20.GL_TEXTURE0);
        //生成纹理对象textures（用于存储纹理数据）
        GLES20.glGenTextures(1, textures, 0);
        // 将绑定纹理(texuture[0]表示指针指向纹理数据的初始位置)
        GLES20.glBindTexture(GLES11Ext.GL_BLEND_EQUATION_RGB_OES, textures[0]);

        videoTexture = new SurfaceTexture(textures[0]);
        videoTexture.setOnFrameAvailableListener(this);
    }

    /**加载顶点与片段着色器*/
    private void loadShaders()
    {
        final String vertexShader = "attribute vec4 vPosition;    //顶点着色器输入变量由attribute来声明\n" +
                        "attribute vec4 vTexCoordinate;\n" +
                        "//uniform表示一个变量的值由应用程序在着色器执行之前指定，\n" +
                        "//并且在图元处理过程中不会发生任何变化。mat4表示一个4x4矩阵\n" +
                        "uniform mat4 textureTransform;\n" +
                        "varying vec2 v_TexCoordinate;    //片段着色器输入变量用arying来声明\n" +
                        "\n" +
                        "void main () {\n" +
                        "    v_TexCoordinate = (textureTransform * vTexCoordinate).xy;\n" +
                        "    gl_Position = vPosition;\n" +
                        "}\n";
        final String fragmentShader = "/**使用GL_OES_EGL_image_external扩展处理，来增强GLSL*/\n" +
                "#extension GL_OES_EGL_image_external : require\n" +
                "precision mediump float;\n" +
                "uniform samplerExternalOES texture; //定义扩展的的纹理取样器amplerExternalOES\n" +
                "varying vec2 v_TexCoordinate;\n" +
                "\n" +
                "void main () {\n" +
                "    vec4 color = texture2D(texture, v_TexCoordinate);\n" +
                "    gl_FragColor = color;\n" +
                "}\n";

        final int vertexShaderHandle = ShaderHelper.compileShader(GLES20.GL_VERTEX_SHADER, vertexShader);
        final int fragmentShaderHandle = ShaderHelper.compileShader(GLES20.GL_FRAGMENT_SHADER, fragmentShader);
        shaderProgram = ShaderHelper.createAndLinkProgram(vertexShaderHandle, fragmentShaderHandle,
                new String[]{"texture","vPosition","vTexCoordinate","textureTransform"});
    }

    @Override
    protected boolean draw()
    {
        synchronized (this)
        {
            if (frameAvailable)
            {
                videoTexture .updateTexImage();
                videoTexture .getTransformMatrix(videoTextureTransform);
                frameAvailable = false;
            }
            else
            {
                return false;
            }

        }
        GLES20.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT);
        GLES20.glViewport(0, 0, width, height);
        this.drawTexture();

        return true;
    }

    private void drawTexture() {
        // Draw texture
        GLES20.glUseProgram(shaderProgram); //绘制时使用着色程序
        int textureParamHandle = GLES20.glGetUniformLocation(shaderProgram, "texture"); //返回一个于着色器程序中变量名为"texture"相关联的索引
        int textureCoordinateHandle = GLES20.glGetAttribLocation(shaderProgram, "vTexCoordinate");
        int positionHandle = GLES20.glGetAttribLocation(shaderProgram, "vPosition");
        int textureTransformHandle = GLES20.glGetUniformLocation(shaderProgram, "textureTransform");
        //在用VertexAttribArray前必须先激活它
        GLES20.glEnableVertexAttribArray(positionHandle);
        //指定positionHandle的数据值可以在什么地方访问。 vertexBuffer在内部（NDK）是个指针，指向数组的第一组值的内存
        GLES20.glVertexAttribPointer(positionHandle, 3, GLES20.GL_FLOAT, false, 0, vertexBuffer);
        GLES20.glBindTexture(GLES20.GL_TEXTURE0, textures[0]);
        GLES20.glActiveTexture(GLES20.GL_TEXTURE0);
        //指定一个当前的textureParamHandle对象为一个全局的uniform 变量
        GLES20.glUniform1i(textureParamHandle, 0);

        GLES20.glEnableVertexAttribArray(textureCoordinateHandle);
        GLES20.glVertexAttribPointer(textureCoordinateHandle, 4, GLES20.GL_FLOAT, false, 0, textureBuffer);

        GLES20.glUniformMatrix4fv(textureTransformHandle, 1, false, videoTextureTransform, 0);
        //GLES20.GL_TRIANGLES（以无数小三角行的模式）去绘制出这个纹理图像
        GLES20.glDrawElements(GLES20.GL_TRIANGLES, drawOrder.length, GLES20.GL_UNSIGNED_SHORT, drawOrderBuffer);
        GLES20.glDisableVertexAttribArray(positionHandle);
        GLES20.glDisableVertexAttribArray(textureCoordinateHandle);
    }

    @Override
    public SurfaceTexture getSurfaceTexture()
    {
        return videoTexture;
    }

    @Override
    public void onFrameAvailable(SurfaceTexture surfaceTexture)
    {
        synchronized (this)
        {
            frameAvailable = true;
        }
    }
}