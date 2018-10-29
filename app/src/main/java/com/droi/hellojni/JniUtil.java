package com.droi.hellojni;

public class JniUtil {
    /*static {
        // Load the respective library
        System.loadLibrary("OpenDevice_Jni");
    }*/

    public static native int openDevice(long CID);
    public static native void closeDevice(int fd);
}
