#include <math.h>
#include <stdio.h>
int ncount(long n) {
int count = 0;
while (n > 0) {
n = n / 10;
count++;
}
return count;
}

int palindrom2(long n) {
int nc = ncount(n); //считаем кол-во цифр в числе
while (nc > 0) {
int x = n % 10; //берем последнюю цифру
int y = n / (int)round(pow(10, nc - 1)); //берем первую цифру
if (x != y) return 0; //сравниваем цифры
n = n - y * (int)round(pow(10, nc - 1)); //избавляемся от первой цифры
n = n / 10; //избавляемся от последней
nc = nc - 2; //общее кол-во цифр уменьшилось на 2
}
return 1;
}

void cli() {
printf("Input a number: ");
long x;
scanf("%ld", &x);
if (palindrom2(x))
printf("%ld - palindrom", x);
else
printf("%ld - not palindrom", x);
}

int main() {
cli();
/*printf("%d\n", polindrom2(0));
printf("%d\n", polindrom2(123321));
printf("%d\n", polindrom2(12321));
printf("%d\n", polindrom2(657756));
printf("%d\n", polindrom2(42240));
printf("%d\n", polindrom2(45643));*/
}