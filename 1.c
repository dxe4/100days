#include <stdio.h>
#include <string.h>

void hanoi(int height, char left[], char right[], char middle[]) {
    if (height > 0) {
        hanoi(height - 1, left, middle, right);
        printf("%s => %s\n", left, right);
        hanoi(height - 1, middle, right, left);
    }
}

int main() {
    hanoi(3, "left\0", "right\0", "middle\0");
}