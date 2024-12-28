#include "opencv2/core/core.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // 确保命令行参数正确
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_image_path> <output_image_path>" << endl;
        return -1;
    }

    // 获取命令行参数：输入图片路径和输出图片路径
    string inputImagePath = argv[1];
    string outputImagePath = argv[2];

    // 加载输入图片
    Mat inputImage = imread(inputImagePath, IMREAD_COLOR);
    if (inputImage.empty()) {
        cerr << "Could not open or find the image: " << inputImagePath << endl;
        return -1;
    }

    // 进行简单的图像处理：高斯模糊
    // Mat outputImage;
    // GaussianBlur(inputImage, outputImage, Size(15, 15), 0);

    // // 保存输出图片
    // bool isSuccess = imwrite(outputImagePath, outputImage);
    // if (!isSuccess) {
    //     cerr << "Failed to save the output image: " << outputImagePath << endl;
    //     return -1;
    // }

    cout << "Image processed successfully and saved to: " << outputImagePath << endl;

    return 0;
}
