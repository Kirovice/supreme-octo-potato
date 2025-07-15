# C语言移位运算练习：负数的左移、逻辑右移、算术右移

## 📁 1. 创建实验环境

```bash
mkdir shift-test
cd shift-test
```

---

## ✍️ 2. 创建源代码文件 `shift_test.c`

```c
#include <stdio.h>

int main() {
    int x = -107;

    printf("原始值 x = %d\n", x);
    printf("二进制（32位）表示：\n");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n\n");

    // 左移
    int left = x << 4;
    printf("x << 4 = %d\n", left);

    // 逻辑右移（先转为 unsigned int）
    unsigned int ux = (unsigned int)x;
    unsigned int logical = ux >> 4;
    printf("逻辑右移 ux >> 4 = %u\n", logical);

    // 算术右移（直接右移 int）
    int arith = x >> 4;
    printf("算术右移 x >> 4 = %d\n", arith);

    return 0;
}
```

---

## ⚙️ 3. 编译运行

```bash
gcc -o shift_test shift_test.c
./shift_test
```

---

## ✅ 4. 示例输出（结果视平台可能略有不同）

```text
原始值 x = -107
二进制（32位）表示：
11111111 11111111 11111111 10010101 

x << 4 = -1712
逻辑右移 ux >> 4 = 268435449
算术右移 x >> 4 = -7
```

---

## 📌 5. 结果分析

| 操作                 | 十进制结果 | 说明                                           |
|----------------------|-------------|------------------------------------------------|
| `x << 4`             | -1712       | 左移破坏符号位，结果不可用于有符号数计算       |
| `(unsigned)x >> 4`   | 268435449   | 逻辑右移补0，保持位模式，不保符号               |
| `x >> 4`             | -7          | 算术右移补符号位（1），正确保持负数含义         |

---

## 📝 总结建议

- 左移操作可能破坏符号位，**对负数谨慎使用左移！**
- 如果要进行位操作，建议使用 `unsigned int` 类型。
- 算术右移能保持符号不变，适合处理负数的“除法”运算。