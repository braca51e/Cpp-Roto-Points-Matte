#include "MatteProcessing.h"
#include "opencv2/imgproc.hpp"
#include <iostream>

void MatteProcessing::processMatte(std::string pathMatte){

    cv::Mat image = cv::imread(pathMatte, cv::IMREAD_GRAYSCALE);
    drawContours(image);
}
void MatteProcessing::drawContours(cv::Mat& image){
    cv::Mat imageLocal = image;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::namedWindow("Contours");
    //cv::blur(imageLocal, imageLocal, cv::Size(3,3));
    cv::findContours(imageLocal, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::Scalar color(0, 255, 0);
    cv::Mat drawing = cv::Mat::zeros(imageLocal.size(), CV_8UC3);
    for(auto contour : contours){
        auto area = cv::contourArea(contour);
        std::cout << "area: " << area << std::endl;
        if(area < 10000) break;
        int count = 0;
        for(auto point : contour){
            count += 1;
            //std::cout << "count: " << count << std::endl;
            //std::cout << "point: " << point << std::endl;
            //only draw every 3th point
            if(count % 3 == 0){
                cv::circle(drawing, point, 1, color, 2);
            }
        }
        cv::imshow("Contours", drawing);
        cv::waitKey(0);
    }
    std::cout << "Total Contours Detected: " << contours.size() << std::endl;
    //cv::drawContours(drawing, contours, -1, color, cv::LINE_4, 4);
    //cv::imshow("Contours", drawing);
    //cv::waitKey(0);
}

