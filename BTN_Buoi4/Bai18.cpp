#include <stdio.h>

// Ham de quy tinh Xn
long long tinhXN(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    
    long long ketqua = 0;
    for (int i = 0; i < n; i++) {
        ketqua += (n - i) * tinhXN(i);
    }
    
    return ketqua;
}

int main() {
    int N;
    printf("\nNhap gia tri n: ");
    scanf("%d", &N);
    
    if (N < 0) {
        printf("\nVui long nhap n >= 0");
        return 1;
    }
    
    long long KETQUA = tinhXN(N);
    printf("\nx(%d) = %lld", N, KETQUA);
    
    return 0;
}