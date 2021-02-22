
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;
int main()
{
	//打开一个默认的相机
	VideoCapture capture(0);
	//检查是否成功打开
	if (!capture.isOpened())
		return -1;
	Mat edges;
	while (1)
	{
		Mat frame;
		capture >> frame;					 //从相机读取新一帧
		cvtColor(frame, edges, CV_BGR2GRAY); //变为灰度图
		blur(edges, edges, Size(3, 3));		 //均值滤波降噪
		Canny(edges, edges, 5, 38, 3);		 //canny算子
		imshow("被canny后的视频", edges);	 //显示
		if (waitKey(1) == 'q')
			break;
	}
	return 0;
}