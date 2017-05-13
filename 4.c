#include <stdio.h>
#include <string.h>

#define MEM_COPY(ptr_dest, ptr_origin) \
    memcpy(ptr_dest, ptr_origin, sizeof(*ptr_origin)); \

int count_1bits(int i) {
    int n = 0;
    int temp;
    MEM_COPY(&temp, &i);
    while(temp > 0) {
        temp &= temp - 1;
        n += 1;   
    }
    return n;
}

int main() {
    int res = count_1bits(99);
    printf("%d", res);
}
