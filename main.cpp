
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    string path = "resources/test.png";
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);
    return 0;


//    //create a gui window:
//    namedWindow("Output",1);
//
//    //initialize a 120X350 matrix of black pixels:
//    Mat output = Mat::zeros( 120, 350, CV_8UC3 );
//
//    //write text on the matrix:
//    putText(output,
//            "Hello World :)",
//            cv::Point(15,70),
//            FONT_HERSHEY_PLAIN,
//            3,
//            cv::Scalar(0,255,0),
//            4);
//
//    //display the image:
//    imshow("Output", output);
//
//    //wait for the user to press any key:
//    waitKey(0);
//
//    return 0;

}