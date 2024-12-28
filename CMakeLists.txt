CMAKE_MINIMUM_REQUIRED(VERSION 2.8) #指定CMake编译最低要求版本

PROJECT(test_opencv_t1) #给项目命名

set(CMAKE_SYSTEM_NAME Linux)
# 设置交叉编译器环境
SET(CMAKE_C_COMPILER /home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
SET(CMAKE_CXX_COMPILER /home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)


# 设置opencv路径
SET(OpenCV_LIBS  /home/share/jenkins_home/workspace/J148/install_on/lib/)
SET(OpenCV_INCLUDE_DIRS /home/share/jenkins_home/workspace/J148/install_on/include/opencv4/) 


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s -O3")

#指定头文件目录
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})



#FILE(GLOB SRC_LIST_CPP ${PROJECT_SOURCE_DIR}/*.cpp)
#FILE(GLOB SRC_LIST_C ${PROJECT_SOURCE_DIR}/*.c)



ADD_EXECUTABLE(test_opencv_t1 test_opencv.cpp)

# 设置lib绝对路径库链接
link_directories(${OpenCV_LIBS})
target_link_libraries(test_opencv_t1 /home/share/jenkins_home/workspace/J148/install_on/lib/libopencv_core.a
                                     /home/share/jenkins_home/workspace/J148/install_on/lib/libopencv_imgproc.a
                                     /home/share/jenkins_home/workspace/J148/install_on/lib/libopencv_highgui.a
                                     /home/share/jenkins_home/workspace/J148/install_on/lib/libopencv_imgcodecs.a

)