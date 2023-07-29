#include <hls_opencv.h>
#include "image_filter_header.hpp"
#include <iostream>
using namespace std;
int main (int argc, char** argv) {
//IplImage* src;
IplImage* dst;
AXI_STREAM src_axi, dst_axi;
IplImage* src = cvLoadImage("tests_bmp.bmp");
    if (!src->imageData) {
        cout << "Sorry";
        return -1;
    }
dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
IplImage2AXIvideo(src, src_axi);
image_filter(src_axi, dst_axi);//src->height,src->width);
AXIvideo2IplImage(dst_axi, dst);
cvSaveImage("op1.bmp", dst);
cvReleaseImage(&src);
cvReleaseImage(&dst);
}

