//
// Created by ripalbarot on 1/29/22.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void colorDetection() {
    string path = "resources/shapes.png";
    Mat img = imread(path);
    Mat imgHSV;

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    Mat mask;
    int hmin = 0, smin = 63, vmin = 142;
    int hmax = 76, smax = 255, vmax = 255;

    namedWindow("TrackBars", (640, 200));
    createTrackbar("Hue Min", "TrackBars", nullptr, 179);
    setTrackbarPos("Hue Min", "TrackBars", hmin);
    createTrackbar("Hue Max", "TrackBars", nullptr, 179);
    setTrackbarPos("Hue Max", "TrackBars", hmax);
    createTrackbar("Sat Min", "TrackBars", nullptr, 255);
    setTrackbarPos("Sat Min", "TrackBars", smin);
    createTrackbar("Sat Max", "TrackBars", nullptr, 255);
    setTrackbarPos("Sat Max", "TrackBars", smax);
    createTrackbar("Val Min", "TrackBars", nullptr, 255);
    setTrackbarPos("Val Min", "TrackBars", vmin);
    createTrackbar("Val Max", "TrackBars", nullptr, 255);
    setTrackbarPos("Val Max", "TrackBars", vmax);

    while (true) {
        hmin = getTrackbarPos("Hue Min", "TrackBars");
        smin = getTrackbarPos("Sat Min", "TrackBars");
        vmin = getTrackbarPos("Val Min", "TrackBars");
        hmax = getTrackbarPos("Hue Max", "TrackBars");
        smax = getTrackbarPos("Sat Max", "TrackBars");
        vmax = getTrackbarPos("Val Max", "TrackBars");
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);

        imshow("Image", img);
        imshow("Image HSV", imgHSV);
        imshow("Image Mask", mask);
        waitKey(1);
    }

    waitKey(0);
}

int main() {
    colorDetection();
    return 0;
}
