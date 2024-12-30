pipeline {
    agent any
    environment {
        ARM_HOST = '192.168.15.179'      // ARM 开发板 IP 地址
        ARM_USER = 'ci'                // ARM 开发板用户名
        ARM_PASSWORD = 'ci'            // ARM 开发板密码
        ARM_DEST_DIR = '/home/ci/opencv/'  // ARM 目錄
        OPENCV_REPO = 'git@github.com:opencv/opencv.git'  // OpenCV 仓库地址
        OPENCV_BRANCH = '4.x'  // 拉取的分支
        BUILD_DIR_ON = '/home/share/jenkins_home/workspace/J148/build_on'  // OpenCV 构建目录 on
        BUILD_DIR_OFF = '/home/share/jenkins_home/workspace/J148/build_off'  // OpenCV 构建目录 off
        INSTALL_DIR_ON = "/home/share/jenkins_home/workspace/J148/install_on"  // 安装目录 on
        INSTALL_DIR_OFF = "/home/share/jenkins_home/workspace/J148/install_off"  // 安装目录 off
        REMOTE_PATH = "./opencv/"
        LOCAL_PATH = '/home/share/jenkins_home/workspace/J148/install_on/bin/'
        REPORT_DIR = '/home/share/jenkins_home/workspace/J148/reports' // 存放性能报告的目录
        TOOLCHAIN_URL = 'https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu.tar.xz'  // 工具链下载链接
        TOOLCHAIN_DIR = '/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin'  // 工具链安装目录
        TEST_PROGRAM = "test_opencv"  // 编译后的 C++ 可执行程序
    }
    parameters {
        booleanParam(name: 'ENABLE_NEON', defaultValue: true, description: 'Enable ARM Neon extensions for OpenCV build')
    }
    stages {
        stage('pull code from opencv/4.x') {
            steps {
                echo "OpenCV Source Directory:"
                
                // sh 'rm -rf /home/share/jenkins_home/workspace/J148/opencv'

                // 克隆最新的代码到指定目录
                // sh """
                // git clone https://github.com/opencv/opencv.git /home/share/jenkins_home/workspace/J148/opencv
                // """
                // script {
                //     // 确保拉取最新的代码
                //     echo "Cloning OpenCV repository from GitHub..."
                //     sh 'mkdir -p /home/share/jenkins_home/workspace/J148/opencv'
                //     // sh 'cd /home/share/jenkins_home/workspace/J148/opencv'
                //     // sh '''
                //     // git clone --branch $OPENCV_BRANCH $OPENCV_REPO /home/share/jenkins_home/workspace/J148/opencv
                //     // '''
                //     sh "git clone --branch $OPENCV_BRANCH $OPENCV_REPO /home/share/jenkins_home/workspace/J148/opencv"
                    
                //     // git branch: "$OPENCV_BRANCH", url: "$OPENCV_REPO"
                // }
            }
        }
        // stage('Download ARM Toolchain') { //下载更早的工具链
        //     steps {
        //         script {
        //             echo "Downloading ARM toolchain..."
        //             // 下载 ARM 工具链文件
        //             // sh """
        //             // wget -P $TOOLCHAIN_DIR $TOOLCHAIN_URL
        //             // """
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/arm-gnu-toolchain"
        //         }
        //     }
        // }
        // stage('Extract ARM Toolchain') {
        //     steps {
        //         script {
        //             echo "Extracting ARM toolchain..."
        //             // 解压工具链文件到指定目录
        //             // sh 'mkdir -p $TOOLCHAIN_DIR'
        //             // sh """
        //             // tar -xvf arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu.tar.xz -C $TOOLCHAIN_DIR 
        //             // """
        //         }
        //     }
        // }
        // stage('Setup ARM Toolchain') {
        //     steps {
        //         script {
        //             echo "Setting up ARM Toolchain..."
                    
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/arm-gnu-toolchain"
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin"
                    
        //             sh '''
        //             echo "Setting up ARM Toolchain..."
        //             export TOOLCHAIN_DIR=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu
        //             export PATH=$TOOLCHAIN_DIR/bin:$PATH  # 将工具链目录添加到 PATH 环境变量中
        //             echo "Updated PATH: $PATH"  # 输出更新后的 PATH
        //             ls -la $TOOLCHAIN_DIR/bin  # 列出 bin 目录中的内容
        //             sh 'which aarch64-none-linux-gnu-gcc'
        //             sh 'aarch64-none-linux-gnu-gcc --version'
        //             '''
        //             sh "echo $PATH"
                    
        //             // 验证工具链安装是否成功
                    
        //         }
        //     }
        // }
        
        
        // stage('Build OpenCV with Neon ON') {
        //     steps {
        //         script {
        //             echo "Build OpenCV with Neon ON"
        //             // 根据参数决定是否启用 Neon 扩展
        //             def enableNeon = 'ON'  // 启用 Neon 扩展
        //             // 创建构建目录
        //             // sh 'mkdir -p /home/share/jenkins_home/workspace/J148/build_on'
        //             // // sh "ls -la /home/share/jenkins_home/workspace/J148/"
        //             // // sh "ls -la /home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu"
        //             // // sh 'mkdir -p /home/share/jenkins_home/workspace/J148/build_on'
        //             // sh 'rm -rf /home/share/jenkins_home/workspace/J148/build_on/*'
        //             // 配置并构建 OpenCV（启用 Neon 扩展）
        //             // sh """
        //             // cd /home/share/jenkins_home/workspace/J148/build_on/
        //             // make clean
        //             // """
        //             // sh """
        //             // cd /home/share/jenkins_home/workspace/J148/build_on
        //             // cmake -DCMAKE_TOOLCHAIN_FILE=/home/share/jenkins_home/workspace/J148/opencv/platforms/linux/arm.toolchain.cmake \
        //             //       -DCMAKE_C_COMPILER=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc \
        //             //       -DCMAKE_CXX_COMPILER=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ \
        //             //       -DENABLE_NEON=$enableNeon  \
        //             //       -DCMAKE_CXX_FLAGS="" \
        //             //       -DCMAKE_C_FLAGS="" \
        //             //       -DBUILD_SHARED_LIBS=OFF \
        //             //       -DWITH_1394=OFF \
        //             //       -DWITH_LIBV4L=OFF \
        //             //       -DBUILD_PERF_TESTS=OFF \
        //             //       -DWITH_OPENMP=OFF \
        //             //       -DBUILD_SHARED_LIBS=OFF \
        //             //       -DWITH_CUDA=OFF \
        //             //       -DWITH_OPENCL=OFF \
        //             //       -DWITH_TBB=OFF \
        //             //       -DWITH_IPP=OFF \
        //             //       -DWITH_CAROTENE=OFF \
        //             //       -DWITH_JASPER=ON \
        //             //       -DWITH_OPENEXR=ON \
        //             //       -DWITH_TEGRA=ON \
        //             //       -DWITH_JPEG=ON \
        //             //       -DWITH_ZLIB=ON \
        //             //       -DZLIB_INCLUDE_DIR=/home/share/jenkins_home/workspace/J148/zlib-output/include \
        //             //       -DZLIB_LIBRARY=/home/share/jenkins_home/workspace/J148/zlib-output/lib/libz.a \
        //             //       -D CMAKE_EXE_LINKER_FLAGS="-static" \
        //             //       -D CMAKE_MODULE_LINKER_FLAGS="-static" \
        //             //       -D CMAKE_SHARED_LINKER_FLAGS="-static" \
        //             //       -DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY \
        //             //       /home/share/jenkins_home/workspace/J148/opencv
        //             // """
        //             // sh "cd /home/share/jenkins_home/workspace/J148/build_on && make -j16"
        //             // // //-DCMAKE_FORCE_C_COMPILER=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc \
        //             // // //-DCMAKE_FORCE_CXX_COMPILER=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ \
        //             // // //-DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY     -DCMAKE_EXE_LINKER_FLAGS="-static" \  -DCMAKE_CXX_FLAGS="-static" \
        //             // // // -DCMAKE_SHARED_LINKER_FLAGS="" \
        //             // // //       -DCMAKE_EXE_LINKER_FLAGS="" \
        //             // // //       -DCMAKE_MODULE_LINKER_FLAGS="" \
        //             // // // -DCMAKE_CXX_FLAGS="" \  -DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY \
        //             // // // // 进入编译目录并运行 CMake 配置
        //             // sh """
        //             //     mkdir -p ${INSTALL_DIR_ON}
        //             //     cd ${BUILD_DIR_ON}
        //             //     cmake /home/share/jenkins_home/workspace/J148/opencv -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR_ON}
        //             // """
        //             // sh """
        //             //     cd ${BUILD_DIR_ON}
        //             //     make install
        //             // """
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/"
        //             // sh "file /home/share/jenkins_home/workspace/J148/install_on/bin/opencv_visualisation"
        //             // sh "stat /home/share/jenkins_home/workspace/J148/install_on/bin/opencv_visualisation"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/lib/opencv4/3rdparty/"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/build_on/3rdparty/"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/bin"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/share"
        //         }
        //     }
        // }
        // stage('Build OpenCV with Neon Disabled') {
        //     steps {
        //         script {
        //             // 禁用 ARM Neon 扩展
        //             def enableNeon = 'OFF'  // 禁用 Neon 扩展

        //             // 创建构建目录
        //             // sh 'mkdir -p /home/share/jenkins_home/workspace/J148/build_off'
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/build_off/"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/build_off/lib"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/build_off/bin"
        //             // 进入编译目录并运行 CMake 配置
        //             // sh """
        //             //     mkdir -p ${INSTALL_DIR_OFF}
        //             //     cd ${BUILD_DIR_OFF}
        //             //     cmake /home/share/jenkins_home/workspace/J148/opencv -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR_OFF}
        //             // """
        //             // sh """
        //             //     cd ${BUILD_DIR_OFF}
        //             //     make install
        //             // """
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/install_off/"
                    
        //             // 配置并构建 OpenCV（禁用 Neon 扩展）
        //             sh """
        //             cd /home/share/jenkins_home/workspace/J148/build_on/
        //             make clean
        //             """
        //             sh """
        //             cd /home/share/jenkins_home/workspace/J148/build_off
                    
        //             cmake -DCMAKE_TOOLCHAIN_FILE=/home/share/jenkins_home/workspace/J148/opencv/platforms/linux/arm.toolchain.cmake \
        //                   -DCMAKE_C_COMPILER=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc \
        //                   -DCMAKE_CXX_COMPILER=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ \
        //                   -DENABLE_NEON=$enableNeon  \
        //                   -DOPENCV_DNN_CUDA=OFF \
        //                   -DOPENCV_DNN_OPENCL=OFF \
        //                   -DOPENCV_DNN_OPENVINO=OFF \
        //                   -DOPENCV_DNN_PERF_CAFFE=OFF \
        //                   -DOPENCV_DNN_PERF_CL=OFF \
        //                   -DOPENCV_DNN_TFLITE=OFF \
        //                   -DBUILD_opencv_dnn=OFF \
        //                   -DBUILD_opencv_dnn_objdetect=OFF \
        //                   -DBUILD_opencv_dnn_superres=OFF \
        //                   -DOPENCV_TEST_DNN_CANN=OFF \
        //                   -DOPENCV_TEST_DNN_OPENVINO=OFF \
        //                   -DOPENCV_TEST_DNN_TFLITE=OFF \
        //                   -DOPENCV_TEST_DNN_TIMVX=OFF \
        //                   -DWITH_DNN=OFF \
        //                   -DBUILD_opencv_cvv=OFF \
        //                   -DBUILD_opencv_world=OFF \
        //                   -DENABLE_VTUNE=OFF \
        //                   -DCMAKE_CXX_FLAGS="" \
        //                   -DCMAKE_C_FLAGS="" \
        //                   -DBUILD_SHARED_LIBS=OFF \
        //                   -DWITH_1394=OFF \
        //                   -DWITH_LIBV4L=OFF \
        //                   -DBUILD_PERF_TESTS=OFF \
        //                   -DWITH_OPENMP=OFF \
        //                   -DBUILD_SHARED_LIBS=OFF \
        //                   -DWITH_CUDA=OFF \
        //                   -DWITH_OPENCL=OFF \
        //                   -DWITH_TBB=OFF \
        //                   -DWITH_IPP=OFF \
        //                   -DWITH_CAROTENE=OFF \
        //                   -DWITH_JASPER=ON \
        //                   -DWITH_OPENEXR=ON \
        //                   -DWITH_TEGRA=ON \
        //                   -DWITH_JPEG=ON \
        //                   -DWITH_ZLIB=ON \
        //                   -DZLIB_INCLUDE_DIR=/home/share/jenkins_home/workspace/J148/zlib-output/include \
        //                   -DZLIB_LIBRARY=/home/share/jenkins_home/workspace/J148/zlib-output/lib/libz.a \
        //                   -D CMAKE_EXE_LINKER_FLAGS="-static" \
        //                   -D CMAKE_MODULE_LINKER_FLAGS="-static" \
        //                   -D CMAKE_SHARED_LINKER_FLAGS="-static" \
        //                   -DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY \
        //                   /home/share/jenkins_home/workspace/J148/opencv
        //             """
        //             sh "cd /home/share/jenkins_home/workspace/J148/build_off && make -j16"
        //             // 进入编译目录并运行 CMake 配置
        //             sh """
        //                 mkdir -p ${INSTALL_DIR_OFF}
        //                 cd ${BUILD_DIR_OFF}
        //                 cmake /home/share/jenkins_home/workspace/J148/opencv -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR_OFF}
        //             """
        //             sh """
        //                 cd ${BUILD_DIR_OFF}
        //                 make install
        //             """
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/install_off/"
        //         }
        //     }
        // }
        
        
        // stage('pull code from thunder') {
        //     steps {
        //             echo "Thunder Source Directory:"
        //         // 克隆最新的代码到指定目录
        //         script {
        //             // 确保拉取最新的代码
        //             echo "Cloning repository from GitHub..."
        //             // sh """
        //             // wget http://prdownloads.sourceforge.net/libpng/zlib-1.2.11.tar.gz
        //             // tar -zxvf zlib-1.2.11.tar.gz
        //             // cd zlib-1.2.11
        //             // """
        //             // sh 'ls -la /home/share/jenkins_home/workspace/J148/'
        //             // sh """
        //             //     mkdir -p /home/share/jenkins_home/workspace/J148/zlib-output
        //             //     export CC=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc
        //             //     export CXX=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++
        //             //     export AR=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-ar
        //             //     export RANLIB=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-ranlib
        //             //     export STRIP=/home/share/jenkins_home/workspace/J148/arm-gnu-toolchain/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-strip
        //             //     cd zlib-1.2.11
        //             //     ./configure --prefix=/home/share/jenkins_home/workspace/J148/zlib-output --static \
        //             // """
        //             // sh """
        //             // cd zlib-1.2.11 && make && make install
        //             // """
        //             // sh 'ls -la /home/share/jenkins_home/workspace/J148/zlib-output/include'
        //             sh 'mkdir -p /home/share/jenkins_home/workspace/J148/test_opencv'
        //             sh 'mkdir -p /home/share/jenkins_home/workspace/J148/test_opencv_off'
        //             // 拉取最新的测试代码到test on
        //             // sh 'rm -rf /home/share/jenkins_home/workspace/J148/test_opencv/'
        //             // sh "git clone --branch 'main' git@github.com:ThunderousBird/test_opencv.git /home/share/jenkins_home/workspace/J148/test_opencv"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/test_opencv/"
        //             // 拉取最新的测试代码到test off
        //             sh 'rm -rf /home/share/jenkins_home/workspace/J148/test_opencv_off/'
        //             sh "git clone --branch 'main' git@github.com:ThunderousBird/test_opencv.git /home/share/jenkins_home/workspace/J148/test_opencv_off"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/test_opencv_off/"
        //         }
        //     }
        // }
        // stage('Cross Compile Test Program') {
        //     steps {
        //         script {
        //             echo "Start Compile Test Program"
        //             // sh "ls -la /home/share/jenkins_home/workspace/J148/test_opencv/"
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/install_off/include"
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/install_off/lib/opencv4/3rdparty/"
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/zlib-output/lib/"
        //             // sh "stat /home/share/jenkins_home/workspace/J148/install_on/lib/opencv4/3rdparty/libzlib.a"
        //             // 使用交叉编译工具链编译 C++ 程序 ON
        //             sh """
        //             cd /home/share/jenkins_home/workspace/J148/test_opencv/
        //             export PATH=${TOOLCHAIN_DIR}:\$PATH
        //             aarch64-none-linux-gnu-g++ test_opencv.cpp -static \
        //             -I/home/share/jenkins_home/workspace/J148/install_on/include/opencv4/ \
        //             -L/home/share/jenkins_home/workspace/J148/install_on/lib/ \
        //             -lopencv_imgcodecs -lopencv_photo -lopencv_imgproc -lopencv_core \
        //             -L/home/share/jenkins_home/workspace/J148/install_on/lib/opencv4/3rdparty/ \
        //             -llibprotobuf -llibjpeg -llibjpeg-turbo -llibopenjp2 -llibwebp -llibpng  -llibtiff -llibjasper -lIlmImf -ltegra_hal -littnotify -lade -lstdc++ -ldl -lm -lpthread -lrt \
        //             -L/home/share/jenkins_home/workspace/J148/zlib-output/lib/ \
        //             -lz -lstdc++ -ldl -lm -lpthread -lrt
        //             """
        //             // 使用交叉编译工具链编译 C++ 程序 OFF
        //             // sh """
        //             // cd /home/share/jenkins_home/workspace/J148/test_opencv_off/
        //             // export PATH=${TOOLCHAIN_DIR}:\$PATH
        //             // aarch64-none-linux-gnu-g++ test_opencv.cpp -static \
        //             // -I/home/share/jenkins_home/workspace/J148/install_off/include/opencv4/ \
        //             // -L/home/share/jenkins_home/workspace/J148/install_off/lib/ \
        //             // -lopencv_imgcodecs -lopencv_photo -lopencv_imgproc -lopencv_core \
        //             // -L/home/share/jenkins_home/workspace/J148/install_off/lib/opencv4/3rdparty/ \
        //             // -llibprotobuf -llibjpeg-turbo -llibopenjp2 -llibwebp -llibpng  -llibtiff -lIlmImf -littnotify -lade -lstdc++ -ldl -lm -lpthread -lrt \
        //             // -L/home/share/jenkins_home/workspace/J148/zlib-output/lib/ \
        //             // -lz -lstdc++ -ldl -lm -lpthread -lrt 
        //             // """
        //             // sh 'ls -la /home/share/jenkins_home/workspace/J148/test_opencv_off/'
        //         }
        //     }
        // }
        // stage('Transfer Files to ARM') {
        //     steps {
        //         script {
        //             echo "Copying OpenCV libraries to ARM board"
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/"
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/bin/"
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/lib/"
        //             sh "ls -la /home/share/jenkins_home/workspace/J148/install_on/share/"
        //             // 使用 Publish Over SSH 插件将文件传输到 ARM 设备
        //             def remote = [:]
        //             remote.name = 'atompi-4'  // 设置远程设备的名称
        //             remote.host = '192.168.15.179'  // ARM 设备的 IP 地址
        //             remote.user = 'ci'  // 远程设备的用户名
        //             remote.password = 'ci'  // 远程设备的密码（如果不使用密钥）
        //             remote.allowAnyHosts = true  // 允许任意主机连接（通常用于测试）
        //             // sshCommand remote: remote, command: "ls"
        //             // sshPut remote: remote, from: "/home/share/jenkins_home/workspace/J148/install_on/bin", into: "/home/ci/opencv/"
        //             // sshPut remote: remote, from: "/home/share/jenkins_home/workspace/J148/install_on/lib", into: "/home/ci/opencv/"
        //             // sshPut remote: remote, from: "/home/share/jenkins_home/workspace/J148/install_on/share", into: "/home/ci/opencv/"
        //             // sshPut remote: remote, from: "/home/share/jenkins_home/workspace/J148/install_on/include", into: "/home/ci/opencv/"
        //             sshPut remote: remote, from: "/home/share/jenkins_home/workspace/J148/test_opencv/", into: "/home/ci/" 
        //             // sshPut remote: remote, from: "/home/share/jenkins_home/workspace/J148/test_opencv_off/", into: "/home/ci/" 
        //             def result = sshCommand remote: remote, command: "hostname"
        //             echo "Remote hostname: ${result}"
        //         }
        //     }
        // }
        stage('CONNECT TO ARM AND TEST') {
            steps {
                script {
                    echo "Connect ARM"
                    def remote = [:]
                    remote.name = 'atompi-4'  // 设置远程设备的名称
                    remote.host = '192.168.15.179'  // ARM 设备的 IP 地址
                    remote.user = 'ci'  // 远程设备的用户名
                    remote.password = 'ci'  // 远程设备的密码（如果不使用密钥）
                    remote.allowAnyHosts = true  // 允许任意主机连接（通常用于测试）
                    sshCommand remote: remote, command: "./run.sh"
                    sh 'rm -f /home/share/jenkins_home/workspace/J148/performance_results.html'
                    sshGet remote: remote, from: "/home/ci/performance_results.html", into: "/home/share/jenkins_home/workspace/J148/performance_results.html" 
                    def result = sshCommand remote: remote, command: "hostname"
                    echo "Remote hostname: ${result}"
                    // sh 'ls -la /home/share/jenkins_home/workspace/J148/'
                    sh 'stat /home/share/jenkins_home/workspace/J148/performance_results.html'
                }
            }
        }
    }
    post {
    always {
        publishHTML(target: [
            reportName: 'OpenCV Performance Test Results',
            reportDir: '/home/share/jenkins_home/workspace/J148/',
            reportFiles: 'performance_results.html',
            keepAll: false
        ])
        }
    }
}
