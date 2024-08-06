#include <stdio.h>

long long tinhTongDay(int n);
long long tinhAnDeQuy(int n);

int main() {
    int N;
    printf("\nNhap so N: ");
    scanf("%d", &N);

    long long ketQua = tinhAnDeQuy(N);
    printf("\nA(%d) = %lld\n", N, ketQua);

    return 0;
}

long long tinhTongDay(int n) {
    if (n == 1) {
        return 1;
    }
    return tinhAnDeQuy(n - 1) + tinhTongDay(n - 1);
}

long long tinhAnDeQuy(int n) {
    if (n == 1) {
        return 1;
    }
    return n * tinhTongDay(n - 1);
}