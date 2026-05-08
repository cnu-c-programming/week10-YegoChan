#include <stdio.h>
#include <string.h>

struct IPv4 {
    unsigned int version;
    unsigned int ihl;
    unsigned long long ttl;
    unsigned long long protocol;
    unsigned char data[1024];
};

void update_val(struct IPv4 s) {
    sprintf(s.data, "update_val");
}

void update_ptr(struct IPv4* s) {
    sprintf(s->data, "update_ptr");
}

int main() {
    struct IPv4 s1, s2 = {0};
    update_val(s1);
    update_ptr(&s2);
    printf("%s\n", s1.data);
    printf("%s\n", s2.data);
    // update_ptr 한 줄 출력
    // pass by value는 지역변수로 복사되기 때문에 main 내의 s1 구조체의 data는 비어있음
}