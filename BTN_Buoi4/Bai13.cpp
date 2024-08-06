#include <stdio.h>

// De quy cap so nhan
double timHangThuN(double HANG_DAU, double CONG_BOI, int N) {
    if (N == 1) {
        return HANG_DAU;
    } else {
        return CONG_BOI * timHangThuN(HANG_DAU, CONG_BOI, N - 1);
    }
}

int main() {
    double HANG_DAU, CONG_BOI;
    int N;

    // Nhap gia tri
    printf("Nhap hang dau (a): ");
    scanf("%lf", &HANG_DAU);

    printf("Nhap cong boi (q): ");
    scanf("%lf", &CONG_BOI);

    printf("Nhap vi tri can tim (n): ");
    scanf("%d", &N);

    // Kiem tra dieu kien
    if (N <= 0) {
        printf("Vi tri n phai lon hon 0.\n");
        return 1;
    }

    // In ket qua 
    double KET_QUA = timHangThuN(HANG_DAU, CONG_BOI, N);
    printf("Gia tri phan tu thu %d cua cap so nhan la: %lf\n", N, KET_QUA);

    return 0;
}