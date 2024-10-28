#include <stdio.h>

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main() {
    printf("%d", getbits(0b11010110, 4, 3));
    return 0;
}