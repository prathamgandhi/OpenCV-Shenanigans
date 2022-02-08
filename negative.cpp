//This program creates negative of given image

#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char **) {
    cv::Mat image = cv::imread("1.jpg");

    if (image.empty()) {
        std::cout << "Failed to open the image, bailing out..." << std::endl;
        std::cin.get();
        return -1;
    }

    cv::Mat subMat = cv::Mat::ones(image.size(), image.type()) * 255;
    cv::Mat final;
    cv::subtract(subMat, image, final);
    cv::namedWindow("negative");
    cv::imshow("negative", final);
    cv::waitKey(0);
    return 0;
}
