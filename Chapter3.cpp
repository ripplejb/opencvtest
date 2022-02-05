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
    Mat imgResize, imgCrop;
    Mat img = imread(path);
    cout << img.size() << endl;

    resize(img, imgResize, Size(), .75, .75);
    Rect roi(275, 25, 300, 250);
    imgCrop = img(roi);

    imshow("Image", img);
    imshow("Half Image", imgResize);
    imshow("Half Crop", imgCrop);
    waitKey(0);
    return 0;
}

int main()
{
    return image();
}
