#ifndef FRAMEPROCESSING_H
#define FRAMEPROCESSING_H

#include <opencv2/highgui.hpp>


class MatteProcessing
{
public:
    // constructor / desctructor
    MatteProcessing() = default;
    virtual ~MatteProcessing() = default;

    // getters / setters

    // typical behaviour methods
    void processMatte(std::string pathMatte);

private:
    // typical behaviour methods
    void drawContours(cv::Mat& image);
    // private members
};


#endif
