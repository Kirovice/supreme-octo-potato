#include <stdio.h>
#include <x86intrin.h>  // 包含 SIMD 指令（如 AVX）

int main() {
    // 定义两个包含8个float的SIMD寄存器
    __m256 a = _mm256_set_ps(8, 7, 6, 5, 4, 3, 2, 1);  // 倒序初始化
    __m256 b = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);  // 正序初始化

    // 执行并行加法
    __m256 c = _mm256_add_ps(a, b);

    // 将结果存储到普通数组中以便打印
    float result[8];
    _mm256_storeu_ps(result, c);

    printf("SIMD 加法结果：\\n");
    for (int i = 0; i < 8; i++) {
        printf("result[%d] = %f\\n", i, result[i]);
    }

    return 0;
}
