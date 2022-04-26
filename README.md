# libyuv
libyuv android版本

## 支持的方法
```
 /**
     * NV21转Input20
     * @param nv12
     * @param i420
     * @param width
     * @param height
     */
    public static native void convertNV12ToI420(byte[] nv12, byte[] i420, int width, int height);
    /**
     * 最终合成的图像在 bigYuvArr 获取。
     *
     * @param bigYuvArr      大NV12 YUV图像数组
     * @param bigW           大YUV图像宽
     * @param bigH           大YUV图像高
     * @param smallYuvArr    小NV12 YUV图像数组，可以直接输入大分辨率，底层做缩小
     * @param smallW         小YUV图像实际宽
     * @param smallH         小YUV图像实际高
     * @param smallFinalW    最终缩小后小YUV图像宽
     * @param smallFinalH    最终缩小后小YUV图像高
     * @param smallStartPosX 最终缩小后小YUV图像起始坐标 X，相对于大YUV图像
     */
    public static native void mergeYuvPip(byte[] bigYuvArr, int bigW, int bigH,
                                   byte[] smallYuvArr, int smallW, int smallH,
                                   int smallFinalW, int smallFinalH,
                                   int smallStartPosX);


    /**
     * convert NV21 to ARGB_8888
     *
     * @param src      src NV21 byte array
     * @param dst      dst RGBA byte array, the length of the dst array must be >= width*height*4
     * @param width    image width
     * @param height   image height
     */
    public static native void NV21ToRGBA(byte[] src, byte[] dst, int width, int height);


    /**
     * convert I420 to ARGB_8888
     *
     * @param src      src I420 byte array
     * @param dst      dst RGBA byte array, the length of the dst array must be >= width*height*4
     * @param width    image width
     * @param height   image height
     */
    public static native void I420ToRGBA(byte[] src, byte[] dst, int width, int height);


    /**
     * convert NV21 to ARGB_8888
     *
     * @param src      src NV21 byte array
     * @param dst      dst RGBA byte array, the length of the dst array must be >= width*height*4
     * @param width    image width
     * @param height   image height
     */
    public static native void NV21ToRGBAByte(byte[] src, byte[] dst, int width, int height);

    /**
     * convert NV21 to ARGB_8888
     *
     * @param src      src NV21 byte array
     * @param dst      dst RGBA int array, the length of the dst array must be >= width*height
     * @param width    image width
     * @param height   image height
     */
    public static native void NV21ToRGBAInt(byte[] src, int[] dst, int width, int height);
    /**
     * convert I420 to ARGB_8888
     *
     * @param src           src I420 byte array
     * @param dst           dst RGBA byte array, the length of the dst array must be >= width*height*4
     * @param width         image width
     * @param height        image height
     * @param yRowStride    The row stride of plane y.
     * @param uvRowStride   The row stride of plane u or v.
     * @param uvPixelStride The pixel stride of plane u or v.
     */
    public static native void I420ToRGBAByte(byte[] src, byte[] dst, int width, int height,
                                             int yRowStride, int uvRowStride, int uvPixelStride);

    /**
     * convert I420 to ARGB_8888
     *
     * @param src           src I420 byte array
     * @param dst           dst RGBA int array, the length of the dst array must be >= width*height
     * @param width         image width
     * @param height        image height
     * @param yRowStride    The row stride of plane y.
     * @param uvRowStride   The row stride of plane u or v.
     * @param uvPixelStride The pixel stride of plane u or v.
     */
    public static native void I420ToRGBAInt(byte[] src, int[] dst, int width, int height,
                                            int yRowStride, int uvRowStride, int uvPixelStride);
```
