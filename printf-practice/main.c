#include <stdio.h>      // 提供 printf
#include <stdint.h>     // 提供 int32_t, PRId32 等宏
#include <inttypes.h>   // 提供 PRId32 格式宏

int main() {
    int age = 28;
    float temperature = 36.5;
    char grade = 'S';
    const char *name = "张三";

    int32_t fixedNum = 123456789;

    // 基本格式化输出
    printf("你好，%s！\n", name);             // 输出字符串
    printf("年龄是：%d 岁\n", age);           // 输出整数
    printf("体温是：%.3f 摄氏度\n", temperature); // 输出浮点数，保留1位小数
    printf("等级为：%c\n", grade);           // 输出字符

    // 输出固定宽度整数类型
    printf("固定大小的整数是：%" PRId32 "\n", fixedNum);

    return 0;
}
