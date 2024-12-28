CMAKE_MINIMUM_REQUIRED(VERSION 3.0) # 推荐使用 3.0 或更高版本

PROJECT(test_opencv_t1) # 给项目命名

# 设置交叉编译器环境
SET(CMAKE_C_COMPILER /home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
SET(CMAKE_CXX_COMPILER /home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)

# 设置 OpenCV 库路径
SET(OpenCV_LIBS /home/share/jenkins_home/workspace/J148/opencv/lib/)
SET(OpenCV_INCLUDE_DIRS /home/share/jenkins_home/workspace/J148/opencv/include/opencv4/)

# 设置编译优化选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

# 添加 OpenCV 头文件目录
target_include_directories(test_opencv_t1 PRIVATE ${OpenCV_INCLUDE_DIRS})

# 添加源文件
ADD_EXECUTABLE(test_opencv_t1 test_opencv.cpp)

# 设置 OpenCV 静态库链接路径
link_directories(${OpenCV_LIBS})

# 链接 OpenCV 静态库
target_link_libraries(test_opencv_t1
    /home/share/jenkins_home/workspace/J148/opencv/lib/libopencv_core.a
    /home/share/jenkins_home/workspace/J148/opencv/lib/libopencv_imgproc.a
    /home/share/jenkins_home/workspace/J148/opencv/lib/libopencv_highgui.a
    /home/share/jenkins_home/workspace/J148/opencv/lib/libopencv_imgcodecs.a
)
