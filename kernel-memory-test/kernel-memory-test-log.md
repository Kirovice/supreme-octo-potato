
# 🧪 内核虚拟内存访问实验笔记（Segmentation Fault 验证）

## 🧠 实验目的

- 验证用户程序是否能够访问操作系统保留的**内核虚拟内存区域**；
- 理解操作系统中用户态与内核态的地址隔离机制；
- 掌握 `Segmentation fault` 错误产生的实际场景。

---

## 📁 文件结构

```bash
~/for-learn/kernel-memory-test/
├── access_kernel_memory.c
├── access_kernel_memory         # 编译后生成的可执行文件
└── kernel_memory_test.log       # CLI 日志记录文件（可选）
```

---

## 📜 实验源码（access_kernel_memory.c）

```c
#include <stdio.h>

int main() {
    int *ptr = (int *)0xFFFFFFFF; // 通常为内核地址区域
    printf("Trying to read kernel memory at address %p...\n", ptr);
    int value = *ptr; // 尝试读取，将触发段错误
    printf("Value at address %p: %d\n", ptr, value);
    return 0;
}
```

---

## 💻 CLI 操作记录

```bash
# 1. 创建文件夹并进入
mkdir ~/for-learn/kernel-memory-test
cd ~/for-learn/kernel-memory-test

# 2. 创建源文件
nano access_kernel_memory.c

# 3. 编译程序
gcc access_kernel_memory.c -o access_kernel_memory

# 4. 运行程序
./access_kernel_memory
```

---

## 🧯 运行结果

```
Trying to read kernel memory at address 0xffffffff...
Segmentation fault (core dumped)
```

---

## 📦 日志记录方法（可选）

使用 `script` 工具记录操作过程：

```bash
script kernel_memory_test.log
# ... 执行 CLI 操作 ...
exit  # 停止记录
```

如需去除控制字符：

```bash
cat kernel_memory_test.log | sed 's/\x1B\[[0-9;]*[a-zA-Z]//g' > clean_kernel_memory_test.log
```

---

## ✅ 实验总结

- 内核虚拟内存区域对用户态程序不可见，不允许直接访问；
- 访问这一区域将产生 `Segmentation fault` 错误；
- 这是操作系统通过内存保护机制保障系统稳定性和安全性的体现；
- 用户程序如需与内核交互，必须通过**系统调用（如 write、read）**的方式由内核代为处理。

---

## 📚 延伸阅读

- 第 1 章：虚拟内存空间结构（图 1-13）
- 第 9 章：内存管理机制与虚拟内存实现原理
