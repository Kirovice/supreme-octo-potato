
# Unix I/O 实践练习：read 与 write 系统调用

本练习通过 C 语言实践 `read` 和 `write` 两个 Unix I/O 系统调用，进一步理解它们的使用方式和作用。

---

## 📁 准备工作

在当前 CLI 中创建一个新目录用于练习：

```bash
mkdir unix-io-practice
cd unix-io-practice
```

---

## ✍️ write 示例代码

文件名：`write_example.c`

```c
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) return 1;

    char *msg = "Hello, Unix write!\n";
    write(fd, msg, 20);
    close(fd);
    return 0;
}
```

### 编译与运行

```bash
gcc write_example.c -o write_example
./write_example
cat output.txt
```

---

## 📖 read 示例代码

文件名：`read_example.c`

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buf[100];
    int fd = open("output.txt", O_RDONLY);
    if (fd < 0) return 1;

    int n = read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';

    printf("Read: %s", buf);
    close(fd);
    return 0;
}
```

### 编译与运行

```bash
gcc read_example.c -o read_example
./read_example
```

---

## ✅ 总结

- `write()`：将数据写入文件描述符。
- `read()`：从文件描述符中读取数据。
- 本示例演示了如何打开文件、写入字符串、读取回字符串并输出。

