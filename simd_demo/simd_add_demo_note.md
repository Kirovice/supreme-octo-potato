# SIMD 并行加法示例笔记

本练习通过一个简单的 C 程序，演示了如何使用 GCC 编译器的 `-mavx` 参数启用 SIMD（单指令多数据）指令集，实现浮点数组的并行加法。

## 示例源码

```c
#include <stdio.h>
#include <immintrin.h>

int main() {
    float a[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    float b[8] = {8, 8, 8, 8, 8, 8, 8, 8};
    float result[8];

    __m256 va = _mm256_loadu_ps(a);
    __m256 vb = _mm256_loadu_ps(b);
    __m256 vresult = _mm256_add_ps(va, vb);
    _mm256_storeu_ps(result, vresult);

    printf("SIMD 加法结果：\n");
    for (int i = 0; i < 8; i++) {
        printf("result[%d] = %f\n", i, result[i]);
    }

    return 0;
}
```

## 编译与运行

```bash
gcc -mavx simd_add_demo.c -o simd_add_demo
./simd_add_demo
```

## 输出结果

```
SIMD 加法结果：
result[0] = 9.000000
result[1] = 9.000000
...
result[7] = 9.000000
```

## 小结

- 本例使用了 AVX SIMD 指令 `_mm256_add_ps` 实现了 8 个 `float` 类型数值的并行加法；
- SIMD 提供了数据级并行能力，在处理图像、视频、音频等向量数据时能显著提升性能；
- 使用 SIMD 可节省大量 CPU 时钟周期，是现代 CPU 性能提升的关键机制之一。
