#include <stdio.h>

long long tinhXN(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return tinhXN(n - 1) + (n - 1) * tinhXN(n - 2);
}

int main() {
    int N;
    printf("\nNhap gia tri N: ");
    scanf("%d", &N);

    if (N < 1) {
        printf("\nN phai lon hon hoac bang 1.");
        return 1;
    }

    long long KETQUA = tinhXN(N);
    printf("\nGia tri X%d la: %lld", N, KETQUA);

    return 0;
}