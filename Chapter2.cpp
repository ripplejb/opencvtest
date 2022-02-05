//
// Created by ripalbarot on 1/15/22.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/**
 * Importing images
 */
int image()
{
    string path = "resources/test.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur,Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 15, 75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);
    erode(imgDil, imgErode, kernel);

    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilation", imgDil);
    imshow("Image Erosion", imgErode);
    waitKey(0);
    return 0;
}

int main()
{
    return image();
}
