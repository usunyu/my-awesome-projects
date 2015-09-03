package com.opengles3.book.egl;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.EGL14;
import android.opengl.EGLConfig;
import android.opengl.EGLContext;
import android.opengl.EGLDisplay;
import android.opengl.EGLSurface;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceView;

public class EGLActivity extends Activity {
    private static final String TAG = "EGLActivity";
    private final int CONTEXT_CLIENT_VERSION = 3;

    public boolean initEGL() {
        EGLDisplay display = EGL14.eglGetDisplay(EGL14.EGL_DEFAULT_DISPLAY);
        if (display == EGL14.EGL_NO_DISPLAY) {
            // Unable to open connection to local windowing system
        }
        int[] major = new int[1];
        int[] minor = new int[1];
        if (!EGL14.eglInitialize(display, major, 0, minor, 0)) {
            // Unable to initialize EGL; handle and recover
        }
        Log.i(TAG, "success get display");
        Log.i(TAG, "major: " + major[0]);
        Log.i(TAG, "minor: " + minor[0]);

        int attribList[] = {
                EGL14.EGL_RED_SIZE, 5,
                EGL14.EGL_GREEN_SIZE, 6,
                EGL14.EGL_BLUE_SIZE, 5,
                EGL14.EGL_DEPTH_SIZE, 1,
                EGL14.EGL_NONE
        };
        int MaxConfigs = 10;
        EGLConfig[] configs = new EGLConfig[MaxConfigs]; // We'll accept only 10 configs
        int numConfigs[] = new int[1];
        int test_num[] = new int[1];
        EGLConfig[] test_configs = new EGLConfig[1];
        test_configs[0] = null;
        EGL14.eglChooseConfig(display, attribList, 0, test_configs, 0, 0, test_num, 0);
        Log.i(TAG, "test_num: " + test_num[0]);

        if (!EGL14.eglChooseConfig(display, attribList, 0, configs, 0, 10, numConfigs, 0)) {
            // Something did not work ... handle error situation
        }
        Log.i(TAG, "success chose configs");

        int attribList2[] = {
                EGL14.EGL_RENDER_BUFFER, EGL14.EGL_BACK_BUFFER,
                EGL14.EGL_NONE
        };
        EGLSurface window = null;
        try {
            Log.i(TAG, "surface: " + mEGLView.getHolder().getSurface());
            window =
                    EGL14.eglCreateWindowSurface(display, configs[0], mEGLView.getHolder(), attribList2, 0);
        } catch (IllegalArgumentException e) {
            Log.e(TAG, "eglCreateWindowSurface: ", e);
        }
        if (window == EGL14.EGL_NO_SURFACE) {
            switch (EGL14.eglGetError()) {
                case EGL14.EGL_BAD_MATCH:
                    // Check window and EGLConfig attributes to determine
                    // compatibility, or verify that the EGLConfig
                    // supports rendering to a window
                    Log.e(TAG, "EGL_BAD_MATCH");
                    break;
                case EGL14.EGL_BAD_CONFIG:
                    // Verify that provided EGLConfig is valid
                    Log.e(TAG, "EGL_BAD_CONFIG");
                    break;
                case EGL14.EGL_BAD_NATIVE_WINDOW:
                    // Verify that provided EGLNativeWindow is valid
                    Log.e(TAG, "EGL_BAD_NATIVE_WINDOW");
                    break;
                case EGL14.EGL_BAD_ALLOC:
                    // Not enough resources available; handle and recover
                    Log.e(TAG, "EGL_BAD_ALLOC");
                    break;
                default:
                    Log.e(TAG, "UNKNOW_ERROR");
                    break;
            }
        }
        Log.i(TAG, "success create surface: " + window);
        return true;
    }

    @Override
    protected void onCreate ( Bundle savedInstanceState )
    {
        super.onCreate(savedInstanceState);
        mEGLView = new EGLView ( this );

        if ( detectOpenGLES30() )
        {
            // Tell the surface view we want to create an OpenGL ES 3.0-compatible
            // context, and set an OpenGL ES 3.0-compatible renderer.
//            mEGLView.setEGLContextClientVersion ( CONTEXT_CLIENT_VERSION );
//            mEGLView.setRenderer ( new HelloTriangleRenderer ( this ) );
        }
        else
        {
            Log.e ( "HelloTriangle", "OpenGL ES 3.0 not supported on device.  Exiting..." );
            finish();

        }
//        initEGL();
//        setContentView(mGLSurfaceView);
        boolean success = initializeWindow(mEGLView);
        Log.i(TAG, "initializeWindow: " + success);
    }

    public boolean initializeWindow(SurfaceView view) {
        int[] configAttribs = {
                EGL14.EGL_RENDERABLE_TYPE, EGL14.EGL_WINDOW_BIT,
                EGL14.EGL_RED_SIZE, 8,
                EGL14.EGL_GREEN_SIZE, 8,
                EGL14.EGL_BLUE_SIZE, 8,
                EGL14.EGL_DEPTH_SIZE, 24,
                EGL14.EGL_NONE
        };
        int[] contextAttribs = {
                EGL14.EGL_CONTEXT_CLIENT_VERSION, 3,
                EGL14.EGL_NONE
        };
        int[] surfaceAttribs = {};
        EGLDisplay display = EGL14.eglGetDisplay(EGL14.EGL_DEFAULT_DISPLAY);
        if (display == EGL14.EGL_NO_DISPLAY) {
            return false;
        }
        int[] major = new int[1];
        int[] minor = new int[1];
        if (!EGL14.eglInitialize(display, major, 0, minor, 0)) {
            return false;
        }
        EGLConfig[] configs = new EGLConfig[10];
        int[] numConfigs = new int[1];
        if (!EGL14.eglChooseConfig(display, configAttribs, 0, configs, 0, 10, numConfigs, 0)) {
            return false;
        }
        EGLSurface window =
                EGL14.eglCreateWindowSurface(display, configs[0], view.getHolder(), surfaceAttribs, 0);

        if (window == EGL14.EGL_NO_SURFACE) {
            return false;
        }
        EGLContext context =
                EGL14.eglCreateContext(display, configs[0], EGL14.EGL_NO_CONTEXT, contextAttribs, 0);
        if (!EGL14.eglMakeCurrent(display, window, window, context)) {
            return false;
        }
        return true;
    }

    private boolean detectOpenGLES30()
    {
        ActivityManager am =
                ( ActivityManager ) getSystemService ( Context.ACTIVITY_SERVICE );
        ConfigurationInfo info = am.getDeviceConfigurationInfo();
        return ( info.reqGlEsVersion >= 0x30000 );
    }

    @Override
    protected void onResume()
    {
        // Ideally a game should implement onResume() and onPause()
        // to take appropriate action when the activity looses focus
        super.onResume();
    }

    @Override
    protected void onPause()
    {
        // Ideally a game should implement onResume() and onPause()
        // to take appropriate action when the activity looses focus
        super.onPause();
    }

    private EGLView mEGLView;
}
