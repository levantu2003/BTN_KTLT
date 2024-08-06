#include <stdio.h>

long long int tinhX(int n);
long long int tinhY(int n);

int main() {
    int n;
    printf("\nNhap so nguyen n: ");
    scanf("%d", &n);
    
    printf("\nSo hang thu %d cua day X la: %lld", n, tinhX(n));
    printf("\nSo hang thu %d cua day Y la: %lld", n, tinhY(n));
    
    return 0;
}

long long int tinhX(int n) {
    if (n == 0) {
        return 1;
    }
    return tinhX(n - 1) + tinhY(n - 1);
}

long long int tinhY(int n) {
    if (n == 0) {
        return 0;
    }
    return 3 * tinhX(n - 1) + 2 * tinhY(n - 1);
}