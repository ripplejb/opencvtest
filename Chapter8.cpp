//
// Created by ripalbarot on 1/30/22.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <chrono>

using namespace std;
using namespace cv;
using namespace chrono;

int WebCam()
{
    VideoCapture cam(0);
    Mat img;

    CascadeClassifier faceCascade;
    faceCascade.load("resources/haarcascade_frontalface_default.xml");



    while(true)    {
        cam >> img;
        vector<Rect> faces;
        faceCascade.detectMultiScale(img, faces, 1.1, 10);

        for (int i = 0; i < faces.size(); ++i) {
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255,255,255), 1);
        }

        imshow("Image", img);
        if (waitKey(10) > 0) break;
    }

    waitKey(0);

    return 0;
}


int main() {
//    string path = "resources/test.png";
//    Mat img = imread(path);
//
//    CascadeClassifier faceCascade;
//    faceCascade.load("resources/haarcascade_frontalface_default.xml");
//
//    if (faceCascade.empty()) {
//        cout << "Invalid XML or file not loaded." << endl;
//    }
//
//    vector<Rect> faces;
//    faceCascade.detectMultiScale(img, faces, 1.1, 10);
//
//    for (int i = 0; i < faces.size(); ++i) {
//        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255,255,255), 1);
//    }
//
//    imshow("Image", img);
//    waitKey(0);

    return WebCam();
}