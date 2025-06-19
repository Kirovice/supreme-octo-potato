#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    const char *text = "Hello from write() system call!\n";
    ssize_t bytes_written = write(fd, text, 31); // 文字长度要精确匹配

    if (bytes_written < 0) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Wrote %zd bytes to output.txt\n", bytes_written);

    close(fd);
    return 0;
}
