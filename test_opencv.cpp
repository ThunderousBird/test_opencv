#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    // 生成一个简单的图像（黑白渐变图像）
    int width = 1920;  // 图像宽度
    int height = 1080; // 图像高度
    Mat image(height, width, CV_8UC1);

    // 填充图像（黑白渐变）
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            image.at<uchar>(y, x) = static_cast<uchar>((x + y) % 256); // 渐变效果
        }
    }

    // 显示原始图像（可选，测试时可以注释掉）
    // imshow("Original Image", image);
    // waitKey(1);

    // 测量图像处理的时间
    auto start_time = high_resolution_clock::now();

    // 执行一些图像处理操作

    // 1. 高斯模糊
    Mat blurred_image;
    GaussianBlur(image, blurred_image, Size(15, 15), 0);

    // 2. 边缘检测（Canny）
    Mat edges;
    Canny(blurred_image, edges, 100, 200);

    // 3. 图像膨胀操作
    Mat dilated_image;
    dilate(edges, dilated_image, Mat(), Point(-1, -1), 1);

    // 4. 图像腐蚀操作
    Mat eroded_image;
    erode(dilated_image, eroded_image, Mat(), Point(-1, -1), 1);

    // 记录结束时间
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    cout << "Total Processing Time: " << duration.count() << " ms" << endl;

    // 显示最终结果（可选，测试时可以注释掉）
    // imshow("Processed Image", eroded_image);
    // waitKey(0);

    return 0;
}
