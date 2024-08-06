#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tạo ma trận với kích thước m x n và các phần tử ngẫu nhiên
void taoMaTranNgauNhien(int m, int n, int **a, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

// Hàm xuất ma trận ra màn hình
void xuatMaTran(int m, int n, int **a) {
    printf("Ma tran %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm xuất các cột chỉ chứa số lẻ
void xuatCotChiChuaSoLe(int m, int n, int **a) {
    printf("Cac cot chi chua so le:\n");

    for (int j = 0; j < n; j++) {
        int allOdd = 1; // Biến kiểm tra cột này có tất cả số lẻ không
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                allOdd = 0; // Có ít nhất một số chẵn trong cột
                break;
            }
        }
        if (allOdd) {
            printf("Cot %d: ", j + 1);
            for (int i = 0; i < m; i++) {
                printf("%4d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

// Hàm chính với menu
int main() {
    int **a = NULL;
    int m = 0, n = 0;
    int min = 0, max = 0;
    int luaChon;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Tao ma tran ngau nhien\n");
        printf("2. Xuat ma tran\n");
        printf("3. Xuat cac cot chi chua so le\n");
        printf("4. Thoat\n");
        printf("Chon tuyen (1-4): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so dong (m) va so cot (n) cua ma tran: ");
                scanf("%d %d", &m, &n);
                if (m <= 0 || n <= 0) {
                    printf("So dong va so cot phai lon hon 0.\n");
                    break;
                }

                // Cấp phát bộ nhớ cho ma trận
                a = (int **)malloc(m * sizeof(int *));
                for (int i = 0; i < m; i++) {
                    a[i] = (int *)malloc(n * sizeof(int));
                }

                printf("Nhap gia tri toi thieu (min) va gia tri toi da (max) cho cac phan tu: ");
                scanf("%d %d", &min, &max);
                if (min > max) {
                    printf("Gia tri toi thieu phai nho hon hoac bang gia tri toi da.\n");
                    break;
                }

                taoMaTranNgauNhien(m, n, a, min, max);
                printf("Ma tran da duoc tao.\n");
                break;

            case 2:
                if (a == NULL) {
                    printf("Ma tran chua duoc tao. Vui long chon lua chon 1 de tao ma tran truoc.\n");
                } else {
                    xuatMaTran(m, n, a);
                }
                break;

            case 3:
                if (a == NULL) {
                    printf("Ma tran chua duoc tao. Vui long chon lua chon 1 de tao ma tran truoc.\n");
                } else {
                    xuatCotChiChuaSoLe(m, n, a);
                }
                break;

            case 4:
                // Giải phóng bộ nhớ nếu ma trận đã được cấp phát
                if (a != NULL) {
                    for (int i = 0; i < m; i++) {
                        free(a[i]);
                    }
                    free(a);
                }
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 4);

    return 0;
}
