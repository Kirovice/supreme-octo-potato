# 整数溢出实验：int vs long long vs unsigned

本实验通过 C 语言程序，验证了 32 位整数乘法可能出现的**溢出**现象，并通过 `long long` 和 `unsigned int` 两种方式进一步说明了补码的行为和溢出的根源。

---

## 📁 文件结构

```bash
int-overflow/
├── overflow.c         # 原始版本，int 溢出
├── overflow_long.c    # 加入 long long 和 unsigned 版本
```

---

## 📄 源码一：`overflow.c`

```c
#include <stdio.h>

int main() {
    int a = 200;
    int b = 300;
    int c = 400;
    int d = 500;

    int result = a * b * c * d;

    printf("结果是：%d\n", result);

    return 0;
}
```

### 💡 编译运行

```bash
gcc overflow.c -o overflow
./overflow
```

**输出示例：**

```
结果是：-884901888
```

---

## 📄 源码二：`overflow_long.c`

```c
#include <stdio.h>

int main() {
    int a = 200;
    int b = 300;
    int c = 400;
    int d = 500;

    int result_int = a * b * c * d;
    printf("【int 结果】       %d\n", result_int);

    long long result_ll = (long long)a * b * c * d;
    printf("【long long 结果】%lld\n", result_ll);

    unsigned int result_unsigned = a * b * c * d;
    printf("【unsigned 结果】  %u\n", result_unsigned);

    return 0;
}
```

### 💡 编译运行

```bash
gcc overflow_long.c -o overflow_long
./overflow_long
```

**输出示例：**

```
【int 结果】       -884901888
【long long 结果】12000000000
【unsigned 结果】  3400065408
```

---

## ✅ 实验总结

| 数据类型      | 是否溢出 | 输出值        | 说明                           |
|---------------|----------|---------------|--------------------------------|
| `int`         | ✅ 是     | `-884901888`  | 超出 32 位上限，发生补码溢出   |
| `long long`   | ❌ 否     | `12000000000` | 使用 64 位，正确表示结果       |
| `unsigned int`| ✅ 是     | `3400065408`  | 同样溢出，但显示的是原始补码值 |

通过本实验，你能清晰理解：

- 补码如何“绕圈”导致溢出成负数
- long long 如何用于解决大整数运算问题
- unsigned 可用于查看补码的真实数值位模式
