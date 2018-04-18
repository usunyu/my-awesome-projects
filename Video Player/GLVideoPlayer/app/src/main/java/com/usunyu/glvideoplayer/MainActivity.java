package com.usunyu.glvideoplayer;

import android.graphics.SurfaceTexture;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Surface;
import android.view.TextureView;

import java.io.IOException;

public class MainActivity extends AppCompatActivity implements TextureView.SurfaceTextureListener,
        MediaPlayer.OnPreparedListener {
    /**本地视频的路径*/
    public String videoPath = Environment.getExternalStorageDirectory().getPath()+"/Movies/WARCRAFT.mp4";
    private TextureView textureView;
    private MediaPlayer mediaPlayer;
    /**
     * 视频绘制前的配置就发生在这个对象所在类中.
     * 真正的绘制工作则在它的子类中VideoTextureSurfaceRenderer
     */
    private TextureSurfaceRenderer videoRenderer;
    private int surfaceWidth;
    private int surfaceHeight;
    private Surface surface;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textureView = (TextureView) findViewById(R.id.textureView);
        //注册一个SurfaceTexture，用于监听SurfaceTexure
        textureView.setSurfaceTextureListener(this);
    }

    /**
     * 播放视频的入口，当SurfaceTexure可得到时被调用
     */
    private void playVideo() {
        if (mediaPlayer == null) {
            videoRenderer = new VideoTextureSurfaceRenderer(this, textureView.getSurfaceTexture(), surfaceWidth, surfaceHeight);

            Log.d("MainActivity", "VideoPath: " + videoPath);
            while (videoRenderer.getSurfaceTexture() == null) {
                try {
                    Thread.sleep(100);
                    Log.d("MainActivity", "Wait for video surface texture");
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            surface = new Surface(videoRenderer.getSurfaceTexture());
            initMediaPlayer();
        }
    }

    private void initMediaPlayer() {
        this.mediaPlayer = new MediaPlayer();
        try {
            mediaPlayer.setDataSource(videoPath);
            mediaPlayer.setSurface(surface);
            mediaPlayer.prepareAsync();
            mediaPlayer.setOnPreparedListener(this);
            mediaPlayer.setLooping(true);
        } catch (IllegalArgumentException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        } catch (SecurityException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        } catch (IllegalStateException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        } catch (IOException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }
    }

    @Override
    public void onPrepared(MediaPlayer mp) {
        try {
            if (mp != null) {
                mp.start(); //视频开始播放了
            }
        } catch (IllegalStateException e) {
            e.printStackTrace();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (textureView.isAvailable()) {
            playVideo();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (videoRenderer != null) {
            videoRenderer.onPause();  //记得去停止视频的绘制线程
        }
        if (mediaPlayer != null) {
            mediaPlayer.release();
            mediaPlayer =null;
        }
    }

    @Override
    public void onSurfaceTextureAvailable(SurfaceTexture surface, int width, int height) {
        surfaceWidth = width;
        surfaceHeight = height;
        playVideo();
    }

    @Override
    public void onSurfaceTextureSizeChanged(SurfaceTexture surface, int width, int height) {

    }

    @Override
    public boolean onSurfaceTextureDestroyed(SurfaceTexture surface) {
        return false;
    }

    @Override
    public void onSurfaceTextureUpdated(SurfaceTexture surface) {

    }
}
