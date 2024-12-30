#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    // 增加图像分辨率，使用 4K 图像（3840x2160）
    int width = 3840;  // 图像宽度
    int height = 2160; // 图像高度
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

    // 1. 高斯模糊（复杂操作）
    Mat blurred_image;
    GaussianBlur(image, blurred_image, Size(15, 15), 0);

    // 2. 边缘检测（Canny） - 另一个计算密集型操作
    Mat edges;
    Canny(blurred_image, edges, 100, 200);

    // 3. 卷积操作：测试复杂矩阵运算
    Mat kernel = (Mat_<float>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1);  // 3x3 卷积核
    Mat convolved_image;
    filter2D(image, convolved_image, -1, kernel);

    // 4. 矩阵变换：图像缩放（另一种计算密集型操作）
    Mat resized_image;
    resize(convolved_image, resized_image, Size(width / 2, height / 2));  // 图像缩放为原来的一半

    // 5. 图像膨胀操作
    Mat dilated_image;
    dilate(resized_image, dilated_image, Mat(), Point(-1, -1), 1);

    // 6. 图像腐蚀操作
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
