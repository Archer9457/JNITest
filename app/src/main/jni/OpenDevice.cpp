/*
 * Copyright 2009-2011 Cedric Priscal
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <jni.h>

#include "com_droi_hellojni_JniUtil.h"

#include <android/log.h>
static const char *TAG="JniUtil_Wiegand";

#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO,  TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args)


#define	DEVICE_NAME	"/dev/Wiegand_Out"

/*
 * Class:     android_serialport_SerialPort
 * Method:    open
 * Signature: (Ljava/lang/String;II)Ljava/io/FileDescriptor;
 */
JNIEXPORT jint JNICALL Java_com_droi_hellojni_JniUtil_openDevice
  (JNIEnv *env, jclass thiz, jlong face_id)
{
	int fd = -1;
    unsigned char buf[10];
    int ret = -1;

    LOGD("Opening serial port %s with flags 0x%x", DEVICE_NAME, O_RDWR);
    fd = open(DEVICE_NAME, O_RDWR);
    LOGD("open() fd = %d", fd);
    if (fd == -1)
    {
        /* Throw an exception */
        LOGE("Cannot open port");
        /* TODO: throw an exception */
        return -1;
    }

    memcpy(buf, &face_id, 4);
    buf[4] = 0;
    ret = write(fd, buf, 4);
    if (ret < 0)
    {
        LOGE("write() failed");
        close(fd);
        /* TODO: throw an exception */
        return -1;
    }

	return fd;
}

/*
 * Class:     cedric_serial_SerialPort
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_droi_hellojni_JniUtil_closeDevice
  (JNIEnv *env, jobject thiz, jint fd)
{
	LOGD("close(fd = %d)", fd);
	close(fd);
}
