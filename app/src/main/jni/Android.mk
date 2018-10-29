LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

CFLAGS := -Werror

LOCAL_LDLIBS    := -lm -llog 

LOCAL_MODULE := libOpenDevice_Jni
LOCAL_SRC_FILES := OpenDevice.cpp
##########
TARGET_PLATFORM := android-14
#LOCAL_MULTILIB := 32
include $(BUILD_SHARED_LIBRARY)
