#include <stdio.h>

// Cach 1: De quy truc tiep
int tinhYn_deQuyTrucTiep(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return tinhYn_deQuyTrucTiep(n-1) + 2*tinhYn_deQuyTrucTiep(n-2) + 3*tinhYn_deQuyTrucTiep(n-3);
}

// Cach 2: De quy co nho
int tinhYn_deQuyCoNho(int n, int *MANG_NHO) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    
    if (MANG_NHO[n] != 0) {
        return MANG_NHO[n];
    }
    
    MANG_NHO[n] = tinhYn_deQuyCoNho(n-1, MANG_NHO) + 
                  2*tinhYn_deQuyCoNho(n-2, MANG_NHO) + 
                  3*tinhYn_deQuyCoNho(n-3, MANG_NHO);
    
    return MANG_NHO[n];
}

int main() {
    int n;
    printf("\nNhap n: ");
    scanf("%d", &n);
    
    printf("\nKet qua cach 1 (de quy truc tiep): %d", tinhYn_deQuyTrucTiep(n));
    
    int MANG_NHO[1000] = {0};  // Gia su n khong vuot qua 1000
    printf("\nKet qua cach 2 (de quy co nho): %d", tinhYn_deQuyCoNho(n, MANG_NHO));
    
    return 0;
}