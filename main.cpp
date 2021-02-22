
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

/**
 * @brief  loading image
 * 
 * @param src_path 
 * @param binary_img
 * @return bool 
 */
bool loadImage(const char * src_path, cv::Mat& img)
{
	// 原图以灰度图形式加载
	// 以及加载异常的处理
	img = cv::imread(src_path);
	if (img.empty())
	{
		std::cout << "IMAGE LOAD FAILDED!"<< std::endl;
		return false;
	}
	return true;
}

int main()
{
    char src[]="/home/holmes/Engineer_Competition/Obeject_Detect/test.jpg";
    cv::Mat img,grey;
    if(!loadImage(src,img))return -1;
    cv::cvtColor(img,grey,CV_BGR2GRAY);
    cv::adaptiveThreshold(grey,img,255, 0, 1, 101, 10);
    cv::imshow("show",img);
    waitKey(0);
    cv::destroyAllWindows();
	return 0;
}