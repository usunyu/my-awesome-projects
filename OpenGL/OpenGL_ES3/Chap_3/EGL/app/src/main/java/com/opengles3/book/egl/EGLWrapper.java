package com.opengles3.book.egl;

import android.content.Context;
import android.opengl.EGL14;
import android.opengl.EGLConfig;
import android.opengl.EGLDisplay;
import android.opengl.EGLSurface;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.View;

/**
 * Created by yusun on 9/1/15.
 */
public class EGLWrapper {
    private static final String TAG = "EGLWrapper";

    public EGLWrapper(Context context) {
        init(context);
    }

    private void init(Context context) {
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
                EGL14.EGL_RENDER_BUFFER, EGL14.EGL_SINGLE_BUFFER,
                EGL14.EGL_RED_SIZE, 5,
                EGL14.EGL_GREEN_SIZE, 6,
                EGL14.EGL_BLUE_SIZE, 5,
                EGL14.EGL_DEPTH_SIZE, 1,
                EGL14.EGL_NONE
        };
        int MaxConfigs = 10;
        EGLConfig[] configs = new EGLConfig[MaxConfigs]; // We'll accept only 10 configs
        int numConfigs[] = new int[1];
        if (!EGL14.eglChooseConfig(display, attribList, 0, configs, 0, 10, numConfigs, 0)) {
            // Something did not work ... handle error situation
        }
        Log.i(TAG, "success chose configs");

        int attribList2[] = {
                EGL14.EGL_RENDER_BUFFER, EGL14.EGL_SINGLE_BUFFER,
                EGL14.EGL_NONE
        };
        GLSurfaceView view = new GLSurfaceView (context);
        EGLSurface window = null;
        try {
            window =
                    EGL14.eglCreateWindowSurface(display, configs[0], view, attribList2, 0);
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
    }
}
