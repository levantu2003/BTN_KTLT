#include <stdio.h>

int tinhFibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    return tinhFibonacci(n - 1) + tinhFibonacci(n - 2);
}

void xuatDayFibonacci(int m, int n) {
    int i = 1;
    int fib = tinhFibonacci(i);
    
    while (fib <= n) {
        if (fib >= m) {
            printf("%d ", fib);
        }
        i++;
        fib = tinhFibonacci(i);
    }
}

int main() {
    int m, n;
    
    printf("\nNhap m: ");
    scanf("%d", &m);
    
    printf("\nNhap n: ");
    scanf("%d", &n);
    
    printf("\nDay so Fibonacci trong doan [%d, %d] la: ", m, n);
    xuatDayFibonacci(m, n);
    
    return 0;
}