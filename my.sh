while true; do
    # 获取所有文件信息并找出总大小最大的用户及其最大文件
    output=$(find . -type f -printf "%u:%s:%p\n" 2>/dev/null | awk -F: '
        {
            user = $1
            size = $2
            path = $3
            total[user] += size
            if (size > max_size[user]) {
                max_size[user] = size
                max_file[user] = path
            }
        }
        END {
            max_total = 0
            selected_user = ""
            for (u in total) {
                if (total[u] > max_total) {
                    max_total = total[u]
                    selected_user = u
                }
            }
            if (selected_user != "") {
                print selected_user ":" max_total ":" max_size[selected_user] ":" max_file[selected_user]
            } else {
                print "::0:"
            }
        }')

    # 解析输出结果
    IFS=':' read -r user total_size max_file_size max_file_path <<< "$output"

    # 清屏并显示结果
    clear
    echo "[更新时间：$(date +'%Y-%m-%d %H:%M:%S')]"
    if [[ -n "$user" ]]; then
        echo "当前目录下占用空间最大的用户：$user (总占用：$(numfmt --to=iec $total_size))"
        echo "该用户最大的文件信息："
        ls -lh "$max_file_path" | awk '{print "  大小：" $5, " 路径：" $9, " 修改时间：" $6" "$7" "$8}'
    else
        echo "当前目录下未找到任何文件。"
    fi

    sleep 2
done
