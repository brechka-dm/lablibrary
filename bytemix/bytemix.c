#include <stdio.h>
unsigned char invert(unsigned char x, unsigned char p, unsigned char n) {
    for (unsigned char i=p;i<=n;i++)x=x^(1<<i); //для всех битов с p до n сдвигаем единицу под нужный разряд числа x и выполняем побитовуюу XOR
    return x;
}

void cli(void) {
    int x, p, n;
    printf("Input number:");
    scanf("%d", &x);
    printf("Input start bit:");
    scanf("%d", &p);
    printf("Input final bit:");
    scanf("%d", &n);
    printf("Result: %d", invert(x,p,n));
}