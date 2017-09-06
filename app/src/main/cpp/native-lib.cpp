#include <jni.h>
#include <android/log.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#define TAG "OpenCV"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE,TAG,__VA_ARGS__)

using namespace cv;

extern "C"
JNIEXPORT void JNICALL
Java_shou_tv_opencvdemo_ImageUtils_blurImage(JNIEnv *env, jclass jcls, jintArray pixels_,
                                             jint width,
                                             jint height) {
    jint *pixels = env->GetIntArrayElements(pixels_, NULL);

    if (pixels == NULL) {
        return;
    }

    LOGV("width:%d,height:%d", width, height);

    Mat mat_image_src(height, width, CV_8UC4, pixels);
    Mat temp = mat_image_src.rowRange(height / 3, 2 * height / 3);
    blur(temp, temp, Size(85, 85));
    cvtColor(temp,temp,CV_RGBA2GRAY,4);

    env->ReleaseIntArrayElements(pixels_, pixels, 0);
}
