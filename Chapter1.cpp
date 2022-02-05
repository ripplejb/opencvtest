#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <chrono>
#include <list>

using namespace std;
using namespace cv;
using namespace chrono;

/**
 * Importing images
 */
int image()
{
    string path = "resources/test.png";
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);
    return 0;
}

int video()
{
    string path = "resources/test_video.mp4";
    VideoCapture cap(path);

    Mat img;
    while (cap.read(img))
    {
        imshow("Image", img);
        waitKey(105);
    }
    return 0;
}

int WebCam()
{
    VideoCapture cap(0);
    Mat img, imgGray;
    list<Mat> imgs;
    std::list<Mat>::iterator it;
    for (auto start = std::chrono::steady_clock::now(),
            now = start; now < start + std::chrono::seconds{60};
            now = std::chrono::steady_clock::now())
    {
        cap >> img;
        imgs.push_back(img);
        waitKey(1);
    }

    for (it = imgs.begin(); it != imgs.end(); it++)
    {
        imshow("Image", *it);
        waitKey(1);

    }
    waitKey(0);
//    while(true)
//    {
//        cap >> img;
//        cvtColor(img, imgGray, COLOR_BGR2GRAY);
//        imshow("Image", imgGray);
//        // wait (1ms) for a key to be pressed
//        if (cv::waitKey(1) >= 0)
//            break;
//    }

    return 0;
}

int main()
{
    return WebCam();
}