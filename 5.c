#include <stdio.h>
#include <stdlib.h>

#include <string.h>


// def eratosthenes(n):
//     n = (n + 1) >> 1
//     i, j, p = 1, 3, np.ones(n, dtype=np.int8)
    
//     while i < n:
//         if p[i]:
//             p[j * j >> 1::j] = 0
//         i, j = i + 1, j + 2

#define ull unsigned long long
void sieve(ull n) {

    ull limit = (n + 1) >> 1;
    ull i = 1;
    ull j = 3;
    
    ull * arr;
    arr = (ull *) malloc(limit * sizeof(ull));

    for (ull i=0; i<limit; i++) {
        arr[i] = 1;
    }

    while (i < limit) {
        if (arr[i] == 1) {
            ull cursor = j * j >> 1;
            while (cursor < limit) {
                arr[cursor] = 0;
                cursor += j;
            }
        }
        i += 1;
        j += 2;
    }

    ull sum = 0;
    for (ull i=0; i<limit; i++) {
        if (arr[i] == 1) {
            sum += arr[i];
        }
    }
    printf("%lld", sum);
}

int main() {
    sieve(1000000);
}
