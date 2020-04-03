#include "MatteProcessing.h"
#include "opencv2/imgproc.hpp"

void processMatte(std::string pathMatte){

    cv::Mat image = cv::imread(pathMatte, cv::IMREAD_GRAYSCALE);

}
void drawContours(cv::Mat& image){
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(image, contours, cv::noArray(), cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    cv::drawContours(image, contours, -1, cv::Scalar::all(255));
    cv::imshow("Contours", image);
    cv::waitKey(0);
}

