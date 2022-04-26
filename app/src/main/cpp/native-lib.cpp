#include <jni.h>
#include <string>
#include "Log.h"
#include "libyuv_utils.h"
#include "native_utils.h"
using namespace native_utils;

extern "C" JNIEXPORT jstring JNICALL
Java_com_sr_hj_libyuv_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
/**
 * Nv21转YUV
 */

extern "C"
JNIEXPORT void JNICALL
Java_com_sr_hj_libyuv_Libyuv_convertNV12ToI420(JNIEnv *env, jclass clazz, jbyteArray nv12,
                                               jbyteArray i420, jint width, jint height) {
    Log("libyuv---convertNV12ToI420");
}
extern "C"
JNIEXPORT void JNICALL
Java_com_sr_hj_libyuv_Libyuv_mergeYuvPip(JNIEnv *env, jclass clazz, jbyteArray big_yuv_arr,
                                         jint big_w, jint big_h, jbyteArray small_yuv_arr,
                                         jint small_w, jint small_h, jint small_final_w,
                                         jint small_final_h, jint small_start_pos_x) {
    Log("libyuv---mergeYuvPip");
}
extern "C"
JNIEXPORT void JNICALL
Java_com_sr_hj_libyuv_Libyuv_NV21ToRGBA(JNIEnv *env, jclass clazz, jbyteArray src, jbyteArray dst,
                                        jint width, jint height) {
    Log("libyuv---NV21ToRGBA");
    jbyte *_src = env->GetByteArrayElements(src, nullptr);
    jbyte *_dst = env->GetByteArrayElements(dst, nullptr);
    libyuvNV21ToRGBA(reinterpret_cast<unsigned char *>(_src),
                     reinterpret_cast<unsigned char *>(_dst), width, height);
    env->ReleaseByteArrayElements(src, _src, JNI_ABORT);
    env->ReleaseByteArrayElements(dst, _dst, 0);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_sr_hj_libyuv_Libyuv_I420ToRGBA(JNIEnv *env, jclass clazz, jbyteArray src, jbyteArray dst,
                                        jint width, jint height) {
    jbyte *_src = env->GetByteArrayElements(src, nullptr);
    jbyte *_dst = env->GetByteArrayElements(dst, nullptr);
    libyuvI420ToRGBA(reinterpret_cast<unsigned char *>(_src),
                     reinterpret_cast<unsigned char *>(_dst), width, height);
    env->ReleaseByteArrayElements(src, _src, JNI_ABORT);
    env->ReleaseByteArrayElements(dst, _dst, 0);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_sr_hj_libyuv_Libyuv_NV21ToRGBAByte(JNIEnv *env, jclass clazz, jbyteArray src,
                                            jbyteArray dst, jint width, jint height) {
    jbyte *_src = env->GetByteArrayElements(src, NULL);
    jbyte *_dst = env->GetByteArrayElements(dst, NULL);
    YUV420SPToRGBAByte(reinterpret_cast<unsigned char *>(_src),
                       reinterpret_cast<unsigned char *>(_dst), width, height, YUV420SP_NV21);
    env->ReleaseByteArrayElements(src, _src, JNI_ABORT);
    env->ReleaseByteArrayElements(dst, _dst, 0);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_sr_hj_libyuv_Libyuv_NV21ToRGBAInt(JNIEnv *env, jclass clazz, jbyteArray src, jintArray dst,
                                           jint width, jint height) {
    jbyte *_src = env->GetByteArrayElements(src, NULL);
    jint *_dst = env->GetIntArrayElements(dst, NULL);
    YUV420SPToRGBAInt(reinterpret_cast<unsigned char *>(_src), _dst, width, height, YUV420SP_NV21);
    env->ReleaseByteArrayElements(src, _src, JNI_ABORT);
    env->ReleaseIntArrayElements(dst, _dst, 0);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_sr_hj_libyuv_Libyuv_I420ToRGBAByte(JNIEnv *env, jclass clazz, jbyteArray src,
                                            jbyteArray dst, jint width, jint height,
                                            jint yRowStride, jint uvRowStride,
                                            jint uvPixelStride) {
    jbyte *_src = env->GetByteArrayElements(src, nullptr);
    jbyte *_dst = env->GetByteArrayElements(dst, nullptr);
    YUV420PToRGBAByte(reinterpret_cast<unsigned char *>(_src),
                      reinterpret_cast<unsigned char *>(_dst),
                      width, height, yRowStride, uvRowStride, uvPixelStride, YUV420P_I420);
    env->ReleaseByteArrayElements(src, _src, JNI_ABORT);
    env->ReleaseByteArrayElements(dst, _dst, 0);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_sr_hj_libyuv_Libyuv_I420ToRGBAInt(JNIEnv *env, jclass clazz, jbyteArray src, jintArray dst,
                                           jint width, jint height, jint yRowStride,
                                           jint uvRowStride, jint uvPixelStride) {
    jbyte *_src = env->GetByteArrayElements(src, NULL);
    jint *_dst = env->GetIntArrayElements(dst, NULL);
    YUV420PToRGBAInt(reinterpret_cast<unsigned char *>(_src), _dst, width, height, yRowStride,
                     uvRowStride, uvPixelStride, YUV420P_I420);
    env->ReleaseByteArrayElements(src, _src, JNI_ABORT);
    env->ReleaseIntArrayElements(dst, _dst, 0);
}