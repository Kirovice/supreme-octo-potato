#include <stdio.h>

// 控制字符缩写名称（ASCII 0~31 + 127）
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
            // ASCII 0~31：控制字符
            printf("%s\n", control_chars[i]);
        } else if (i == 127) {
            // ASCII 127：DEL
            printf("%s\n", control_chars[32]);
        } else {
            // ASCII 32~126：可打印字符
            printf("%c\n", i);
        }
    }

    return 0;
}
