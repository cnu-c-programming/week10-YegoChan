#include <stdio.h>

union U {
    float f;
    unsigned char c[4];
    // 같은 메모리 공유
};

int main() {
    union U u;
    u.f = 3.14;
    for (int i = 0; i < 4; i++) {
        printf("%x\n", (unsigned) u.c[i]);
    }
    // float = 4바이트
    // 1바이트씩 끊어서 출력
}