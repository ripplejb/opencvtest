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
    string path = "resources/cards.jpg";
    Mat img = imread(path);


    // King
    Point2f src[4] = {{529, 142}, {771, 190}, {405, 395},{674, 457}};
    float w = sqrtf((529 - 771)*(529 - 771) + (142 - 190) * (142 - 190));
    float h = sqrtf((529 - 405)*(529 - 405) + (142 - 395) * (142 - 395));
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    // Queen
    Point2f srcQ[4] = {{57, 324}, {338, 276}, {83, 634},{400, 573}};
    float wQ = sqrtf((57 - 338)*(57 - 338) + (324 - 276) * (324 - 276));
    float hQ = sqrtf((57 - 83)*(57 - 83) + (324 - 634) * (324 - 634));
    Point2f dstQ[4] = {{0.0f, 0.0f}, {wQ, 0.0f}, {0.0f, hQ}, {wQ, hQ}};

    Mat matrix, imgWarp, matrixQ, imgWarpQ;

    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix,Point(w,h));

    matrixQ = getPerspectiveTransform(srcQ, dstQ);
    warpPerspective(img, imgWarpQ, matrixQ,Point(wQ,hQ));

    imshow("Image", img);
    imshow("Image Warp", imgWarp);
    imshow("Image Warp Queen", imgWarpQ);
    waitKey(0);
    return 0;
}

int main()
{
    return image();
}
