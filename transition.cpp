/*  This is a sample program to create a video transitioning from one image to another 
    using opencv
*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

int main(int argc, char** argv) {
    cv::Mat first = cv::imread(argv[1]);
    cv::Mat second = cv::imread(argv[2]);

    if (first.empty() or second.empty()) {
        std::cout << "The image could not be found, quitting..." << std::endl;
        std::cin.get();
        return -1;
    }
    int firstcol = first.cols;
    int firstrow = first.rows;
    int secondcol = second.cols;
    int secondrow = second.rows;
    cv::Mat temp;
    cv::Scalar value(0, 0, 0);
    cv::Mat temp1, temp2;
    //Adding border to the shorter image
    int row_diff = abs((firstrow - secondrow) / 2);
    int col_diff = abs((firstcol - secondcol) / 2);
    if (firstrow >= secondrow) {
        cv::copyMakeBorder(second, second, row_diff, row_diff, 0, 0, cv::BORDER_CONSTANT, value);
    } else if (firstrow < secondrow) {
        cv::copyMakeBorder(first, first, row_diff, row_diff, 0, 0, cv::BORDER_CONSTANT, value);
    }
    if (firstcol >= secondcol) {
        cv::copyMakeBorder(second, second, 0, 0, col_diff, col_diff, cv::BORDER_CONSTANT, value);
    } else if (secondcol > firstcol) {
        cv::copyMakeBorder(first, first, 0, 0, col_diff, col_diff, cv::BORDER_CONSTANT, value);
    }

    cv::Mat transition;

    std::string win = "Transition";

    cv::namedWindow(win, cv::WINDOW_NORMAL);

    cv::Size frame_size(first.rows, first.cols);
    cv::VideoWriter oVideoWriter("newVid.mp4", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 15, frame_size, true);

    for (double a = 0; a <= 1.01; a += 0.05) {
        transition = (1 - a) * first + a * second;
        oVideoWriter.write(transition);
        cv::imshow(win, transition);
        cv::waitKey(100);
    }

    oVideoWriter.release();
    cv::waitKey(0);
    return 0;
}