#include <stdio.h>

// De quy
int timFibonacciLonNhatDeQuy(int n, int a, int b) {
    if (b >= n) {
        return a;
    }
    return timFibonacciLonNhatDeQuy(n, b, a + b);
}

// Khu de quy
int timFibonacciLonNhatKhuDeQuy(int n) {
    if (n <= 1) {
        return 0;
    }
    
    int a = 0, b = 1;
    while (b < n) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    printf("\nNhap so nguyen duong n: ");
    scanf("%d", &n);
    
    // De quy
    int ketQuaDeQuy = timFibonacciLonNhatDeQuy(n, 0, 1);
    printf("So Fibonacci lon nhat nho hon %d (de quy): %d\n", n, ketQuaDeQuy);
    
    // Khu de quy
    int ketQuaKhuDeQuy = timFibonacciLonNhatKhuDeQuy(n);
    printf("So Fibonacci lon nhat nho hon %d (khu de quy): %d\n", n, ketQuaKhuDeQuy);
    
    return 0;
}