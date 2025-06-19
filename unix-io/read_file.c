#include <fcntl.h>     // open
#include <unistd.h>    // read, write, close
#include <stdio.h>     // perror
#include <stdlib.h>    // exit

int main() {
    char buffer[100];
    int fd = open("input.txt", O_RDONLY);  // 以只读方式打开文件
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    int bytesRead = read(fd, buffer, sizeof(buffer) - 1);  // 读取内容
    if (bytesRead < 0) {
        perror("read");
        close(fd);
        exit(1);
    }

    buffer[bytesRead] = '\0';  // 添加字符串终止符
    write(STDOUT_FILENO, buffer, bytesRead);  // 将读取的内容输出到终端

    close(fd);
    return 0;
}
