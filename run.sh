#!/bin/bash

# 定义执行次数
NUM_RUNS=50

# 定义文件路径
TEST_OPEN="./test_opencv/a.out"
TEST_OPEN_OFF="./test_opencv_off/a.out"

# 创建一个 HTML 文件来记录结果
OUTPUT_FILE="performance_results.html"
echo "<html><head><title>OpenCV Performance Test Results</title></head><body>" > $OUTPUT_FILE
echo "<h1>OpenCV Performance Test Results</h1>" >> $OUTPUT_FILE

# 函数：执行测试并记录时间
run_test() {
    local test_name=$1
    local test_file=$2
    local total_time=0

    echo "<h2>$test_name</h2>" >> $OUTPUT_FILE
    echo "<table border='1'><tr><th>Run</th><th>Time (ns)</th></tr>" >> $OUTPUT_FILE

    for i in $(seq 1 $NUM_RUNS); do
        # 执行测试并捕获输出
        output=$($test_file)

        # 使用 grep 提取输出中的时间值
        # 例如，输出 "Total Processing Time: 47 ms"
        duration=$(echo "$output" | grep -o 'Total Processing Time: [0-9]\+' | sed 's/Total Processing Time: //')

        # 如果没有捕获到时间信息，则跳过这一轮
        if [ -z "$duration" ]; then
            echo "Failed to extract time for run $i, skipping."
            continue
        fi

        # 将时间转换为纳秒（时间单位为毫秒，乘以 1000000）
        duration_ns=$((duration * 1000000))

        # 累加时间（单位为纳秒）
        total_time=$((total_time + duration_ns))

        # 将结果写入 HTML 文件
        echo "<tr><td>$i</td><td>$duration_ns</td></tr>" >> $OUTPUT_FILE
    done

    # 计算平均时间（单位为纳秒）
    avg_time=$((total_time / NUM_RUNS))

    # 输出计算出的平均时间到 HTML
    echo "<tr><td><b>Average</b></td><td><b>$avg_time</b></td></tr>" >> $OUTPUT_FILE
    echo "</table><br>" >> $OUTPUT_FILE
}

# 运行两个测试，并记录结果
run_test "Test Open (ON)" $TEST_OPEN
run_test "Test Open (OFF)" $TEST_OPEN_OFF

# 结束 HTML 文件
echo "</body></html>" >> $OUTPUT_FILE

# 输出生成的 HTML 文件路径
echo "Performance test results saved to $OUTPUT_FILE"
