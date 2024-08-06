#include <stdio.h>

// De quy
int tinhU(int n) {
    if (n < 6) {
        return n;
    } else {
        return tinhU(n-5) + tinhU(n-4) + tinhU(n-3) + tinhU(n-2) + tinhU(n-1);
    }
}

int main() {
    int N;
    
    // Nhap n
    printf("\nNhap so nguyen duong n: ");
    scanf("%d", &N);
    
    // Kiem tra input so nguyen duong
    if (N <= 0) {
        printf("\nVui long nhap so nguyen duong");
        return 1;
    }
    
    // Tính và in kết quả
    int KET_QUA = tinhU(N);
    printf("\nU(%d) = %d", N, KET_QUA);
    
    return 0;
}