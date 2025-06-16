# 汇编分析练习：test.c

本练习通过一个简单的 C 程序，了解它在汇编层面是如何运作的，结合 `objdump` 反汇编结果做了注释。

## C 源代码

```c
int main() {
    int a = 1;
    int b = 2;
    int c = a + b;
    return 0;
}


0000000000001129 <main>:
1129: f3 0f 1e fa                endbr64           ; 用于控制流保护（Intel CET）
112d: 55                         push   %rbp       ; 保存旧的栈帧指针
112e: 48 89 e5                   mov    %rsp,%rbp  ; 设置新的栈帧基址

1131: c7 45 f4 01 00 00 00       movl   $0x1,-0xc(%rbp) ; int a = 1
1138: c7 45 f8 02 00 00 00       movl   $0x2,-0x8(%rbp) ; int b = 2

113f: 8b 55 f4                   mov    -0xc(%rbp),%edx ; 把 a 取到 edx
1142: 8b 45 f8                   mov    -0x8(%rbp),%eax ; 把 b 取到 eax
1145: 01 d0                      add    %edx,%eax       ; edx + eax → eax（即 a + b）
1147: 89 45 fc                   mov    %eax,-0x4(%rbp) ; 把结果写入 c

114a: b8 00 00 00 00             mov    $0x0,%eax       ; return 0
114f: 5d                         pop    %rbp
1150: c3                         ret


| 指令              | 含义                 |
| --------------- | ------------------ |
| `movl`          | 将立即数或内存值移入寄存器或内存   |
| `push`/`pop`    | 压栈/出栈，用于保存或恢复寄存器现场 |
| `mov %rsp,%rbp` | 设置当前函数的栈帧基地址       |
| `add`           | 加法操作，两个寄存器值相加      |
| `ret`           | 返回到调用函数的位置         |


| 变量 | 偏移地址       |
| -- | ---------- |
| a  | -0xc(%rbp) |
| b  | -0x8(%rbp) |
| c  | -0x4(%rbp) |



