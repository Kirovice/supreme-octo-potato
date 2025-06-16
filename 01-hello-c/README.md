# 第一次实验：hello.c 的四阶段编译

本次实验基于《深入理解计算机系统》第一章，手动执行了 C 程序从源码到可执行文件的完整编译流程，了解了程序如何通过预处理、编译、汇编、链接逐步变为机器能运行的程序。

---

## 💡 hello.c 内容

```c
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}


| 阶段      | 工具    | 作用            | 命令                          | 输出文件      |
| ------- | ----- | ------------- | --------------------------- | --------- |
| 1️⃣ 预处理 | `cpp` | 展开宏、引入头文件     | `gcc -E hello.c -o hello.i` | `hello.i` |
| 2️⃣ 编译  | `cc1` | 转换为汇编语言       | `gcc -S hello.i -o hello.s` | `hello.s` |
| 3️⃣ 汇编  | `as`  | 汇编转为目标文件（机器码） | `gcc -c hello.s -o hello.o` | `hello.o` |
| 4️⃣ 链接  | `ld`  | 与标准库链接生成可执行文件 | `gcc hello.o -o hello`      | `hello`   |


执行结果
$ ./hello
Hello, world!
