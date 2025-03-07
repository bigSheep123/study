# 循环每5秒检查一次
while true; do
    # 获取占用 CPU 最大的进程的 PID、CPU 使用率和用户
    # `ps aux` 列出所有进程
    # `sort -rk3` 按照CPU使用率降序排序
    # `head -n 1` 获取占用 CPU 最大的进程
    # `awk` 用于提取进程信息

    max_cpu_process=$(ps aux --sort=-%cpu | head -n 2 | tail -n 1)

    # 提取进程的用户和 CPU 使用率
    user=$(echo "$max_cpu_process" | awk '{print $1}')
    cpu_usage=$(echo "$max_cpu_process" | awk '{print $3}')
    # pid=$(echo "$max_cpu_process" | awk '{print $2}')

    # 输出占用最大 CPU 的进程信息
    echo "At $(date):"
    echo "User: $user"
    # echo "PID: $pid"
    echo "CPU Usage: $cpu_usage%"
    echo "---------------------------------"

    # 每5秒输出一次
    sleep 5
done
