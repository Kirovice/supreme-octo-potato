
# 🧪 ASCII 表输出练习笔记

本练习包含三个阶段：
1. 输出可打印字符（ASCII 32~126）
2. 输出完整 ASCII（0~127），包括控制字符
3. 使用混合模式输出：可打印字符显示字符，控制字符显示缩写

---

## ✅ 阶段 1：输出可打印字符（32~126）

```c
#include <stdio.h>

int main() {
    printf("Dec\tHex\tChar\n");
    printf("----------------------\n");

    for (int i = 32; i <= 126; i++) {
        printf("%3d\t0x%02X\t%c\n", i, i, i);
    }

    return 0;
}
```

编译运行：

```bash
gcc -o ascii_table ascii_table.c
./ascii_table
```

---

## ✅ 阶段 2：完整输出 ASCII（0~127）

```c
#include <stdio.h>

const char *control_chars[33] = {
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS",  "HT",  "LF",  "VT",  "FF",  "CR",  "SO",  "SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM",  "SUB", "ESC", "FS",  "GS",  "RS",  "US",
    "DEL"
};

int main() {
    printf("Dec\tHex\tChar\n");
    printf("----------------------\n");

    for (int i = 0; i <= 127; i++) {
        printf("%3d\t0x%02X\t", i, i);
        if (i < 32) {
            printf("%s\n", control_chars[i]);
        } else if (i == 127) {
            printf("%s\n", control_chars[32]);
        } else {
            printf("%c\n", i);
        }
    }

    return 0;
}
```

---

## ✅ 阶段 3：混合版本总结

- 通过判断 `i < 32` 或 `i == 127` 来识别控制字符；
- 用 `control_chars` 数组显示不可打印字符缩写；
- 32~126 直接打印字符本身（`%c`）。

---

## 📌 命令提示

在 Linux/macOS 中也可以通过命令获取 ASCII 表：

```bash
man ascii
```

此命令会显示带十六进制/八进制/字符对照的完整 ASCII 表。
