#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n = 5;  //声明了一个指针变量 ptr，以及一个整数变量 n，代表你要分配的数组大小是 5。

    // 使用 malloc 分配堆内存
    ptr = (int *)malloc(n * sizeof(int));   //你调用了 C 的标准库函数 malloc（memory allocate）来从“堆”中分配一块可以存放 5 个 int 的连续内存。
                                            //sizeof(int) 是每个整数的字节数，乘上 n 就是你需要的总字节数。
                                            //malloc 会返回这块内存的起始地址（指针），你用 ptr 来接收。

    if (ptr == NULL) {
        printf("内存分配失败\n");
        return 1;  //这是一个很重要的健壮性检查：如果堆没有足够空间，malloc 会返回 NULL，你通过这个检查来避免崩溃。
    }

    // 给分配的内存赋值
    for (int i = 0; i < n; i++) {
        ptr[i] = i * 10;  //使用 ptr[i] 就像访问普通数组一样操作堆内存：把值写入堆。
    }

    // 打印内存中的值
    printf("分配到堆上的数组内容：\n");
    for (int i = 0; i < n; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);  //打印出堆上的内容，验证数据确实存进去了。
    }

    // 释放内存
    free(ptr);  //最重要的一步！你必须手动用 free() 释放堆内存，否则程序结束前这块堆空间不会归还，会造成“内存泄漏”。

    return 0;
}
