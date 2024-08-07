#include <stdio.h>

// Ham de quy tinh An
int tinhAn(int n) {
    // Truong hop co so
    if (n == 1) {
        return 1;
    }
    
    // Truong hop de quy
    if (n % 2 == 0) {
        // A2n = n + An + 2
        return n/2 + tinhAn(n/2) + 2;
    } else {
        // A2n+1 = n^2 + An.An+1 + 1
        return ((n-1)/2)*((n-1)/2) + tinhAn((n-1)/2) * tinhAn((n+1)/2) + 1;
    }
}

int main() {
    int n;
    
    // Nhap gia tri n tu nguoi dung
    printf("\nNhap gia tri n: ");
    scanf("%d", &n);
    
    // Tinh va in ket qua
    int ketQua = tinhAn(n);
    printf("\nA(%d) = %d", n, ketQua);
    
    return 0;
}