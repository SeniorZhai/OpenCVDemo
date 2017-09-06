package shou.tv.opencvdemo;

import android.graphics.Bitmap;

/**
 * Created by zhai on 2017/9/6.
 */

public class ImageUtils {

    public static Bitmap blur(Bitmap srcBitmap) {
        int width = srcBitmap.getWidth();
        int height = srcBitmap.getHeight();

        int[] pixels = new int[width * height];

        srcBitmap.getPixels(pixels, 0, width, 0, 0, width, height);

        blurImage(pixels, width, height);

        Bitmap newBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.RGB_565);
        newBitmap.setPixels(pixels, 0, width, 0, 0, width, height);
        return newBitmap;
    }

    public static native void blurImage(int[] pixels, int w, int h);

    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("opencv_java");
    }
}
