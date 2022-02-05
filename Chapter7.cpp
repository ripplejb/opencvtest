//
// Created by ripalbarot on 1/30/22.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void printShapes(Mat img, int polyCount, Rect boundRect) {
    switch (polyCount) {
        case 3:
            putText(img, "Triangle", Point(boundRect.x + boundRect.width / 4, boundRect.y), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 69, 255), 1);
            break;
        case 4: {
            float aspRatio = (float)boundRect.width / (float)boundRect.height;
            string objName = "Rectangle";
            if (aspRatio < 1.05f && aspRatio > 0.95f) {
                objName = "Square";
            }
            putText(img, objName, boundRect.tl(), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 69, 255), 1);
            break;
        }
        case 8:
            putText(img, "Circle", Point(boundRect.x + boundRect.width / 4, boundRect.y), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 69, 255), 1);
            break;
    }

}

void getContours(Mat imgDil, Mat img) {

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // TODO: Read documentation
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    for (int i = 0; i < contours.size(); ++i) {
        int area = contourArea(contours[i]);

        if (area > 1000) {
            double peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);
            boundRect[i] = boundingRect(conPoly[i]);
            printShapes(img, conPoly[i].size(), boundRect[i]);
        }
    }

}

int shapeDetection() {
    string path = "resources/shapes.png";
    Mat img = imread(path);

    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    // Preprocessing image

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur,Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 75, 55);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);

    getContours(imgDil, img);

    imshow("Image", img);
    waitKey(0);
    return 0;
}

int main() {
    return shapeDetection();
}

