#include  "hls_video.h"
#include <ap_fixed.h>
#include "opencv.hpp"

#define MAX_WIDTH 240
#define MAX_HEIGHT 240


	typedef char mat_a_t;
	typedef char result_t;
typedef hls::stream<ap_axiu<24,1,1,1> >           AXI_STREAM;
typedef hls::Mat<MAX_HEIGHT,   MAX_WIDTH,   HLS_8UC3> RGB_IMAGE;
typedef hls::Mat<MAX_HEIGHT,   MAX_WIDTH,   HLS_8UC1> GRAY_IMAGE;

//void image_filter(RGB_IMAGE  img_0(MAX_HEIGHT, MAX_WIDTH),RGB_IMAGE  img_6(MAX_HEIGHT, MAX_WIDTH));//int rows, int cols);

//void image_filter(AXI_STREAM& INPUT_STREAM, AXI_STREAM& OUTPUT_STREAM);

void image_filter(mat_a_t a[MAX_HEIGHT][MAX_WIDTH],result_t res[MAX_HEIGHT][MAX_WIDTH]);
