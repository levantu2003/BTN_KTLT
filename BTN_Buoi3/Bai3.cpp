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
void xuatCotSoLe(int m, int n, int **a) {
    for (int j = 0; j < n; j++) {
        int allOdd = 1; // Biến kiểm tra nếu tất cả các phần tử trong cột là số lẻ
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) { // Nếu có ít nhất một số chẵn
                allOdd = 0;
                break;
            }
        }
        if (allOdd) {
            printf("Cot %d chua toan so le:\n", j + 1);
            for (int i = 0; i < m; i++) {
                printf("%4d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

// Hàm tìm phần tử lớn nhất trên biên của ma trận
int timMaxTrenBien(int m, int n, int **a) {
    int max = a[0][0];

    // Kiểm tra hàng đầu tiên
    for (int j = 0; j < n; j++) {
        if (a[0][j] > max) max = a[0][j];
    }

    // Kiểm tra hàng cuối cùng
    if (m > 1) { // Đảm bảo có nhiều hơn một hàng
        for (int j = 0; j < n; j++) {
            if (a[m-1][j] > max) max = a[m-1][j];
        }
    }

    // Kiểm tra cột đầu tiên
    for (int i = 1; i < m-1; i++) { // Đảm bảo không lặp lại các phần tử ở hàng đầu tiên và hàng cuối cùng
        if (a[i][0] > max) max = a[i][0];
    }

    // Kiểm tra cột cuối cùng
    if (n > 1) { // Đảm bảo có nhiều hơn một cột
        for (int i = 1; i < m-1; i++) { // Đảm bảo không lặp lại các phần tử ở hàng đầu tiên và hàng cuối cùng
            if (a[i][n-1] > max) max = a[i][n-1];
        }
    }

    return max;
}

// Hàm kiểm tra xem số có chứa chữ số 2 không
int coChuaSo2(int so) {
    char buffer[12];
    snprintf(buffer, sizeof(buffer), "%d", so); // Chuyển số thành chuỗi

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '2') {
            return 1; // Có chứa chữ số 2
        }
    }
    return 0; // Không chứa chữ số 2
}

// Hàm đếm số lượng phần tử có chữ số 2 trong ma trận
int demPhanTuChuaSo2(int m, int n, int **a) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (coChuaSo2(a[i][j])) {
                dem++;
            }
        }
    }
    return dem;
}

// Hàm xuất các phần tử cực tiểu của ma trận
void xuatPhanTuCucTieu(int m, int n, int **a) {
    for (int i = 0; i < m; i++) {
        int min = a[i][0];
        for (int j = 1; j < n; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
        printf("Phan tu cuc tieu cua hang %d: %d\n", i + 1, min);
    }
}

// Hàm sắp xếp một hàng tăng dần
void sapXepTangDan(int n, int *hang) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (hang[j] > hang[j + 1]) {
                int temp = hang[j];
                hang[j] = hang[j + 1];
                hang[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp một hàng giảm dần
void sapXepGiamDan(int n, int *hang) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (hang[j] < hang[j + 1]) {
                int temp = hang[j];
                hang[j] = hang[j + 1];
                hang[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp một cột tăng dần
void sapXepCotTangDan(int m, int **a, int cot) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (a[j][cot] > a[j + 1][cot]) {
                int temp = a[j][cot];
                a[j][cot] = a[j + 1][cot];
                a[j + 1][cot] = temp;
            }
        }
    }
}

// Hàm sắp xếp một cột giảm dần
void sapXepCotGiamDan(int m, int **a, int cot) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (a[j][cot] < a[j + 1][cot]) {
                int temp = a[j][cot];
                a[j][cot] = a[j + 1][cot];
                a[j + 1][cot] = temp;
            }
        }
    }
}

// Hàm sắp xếp ma trận theo yêu cầu
void sapXepMaTran(int m, int n, int **a) {
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            sapXepTangDan(n, a[i]);
        } else {
            sapXepGiamDan(n, a[i]);
        }
    }
}

// Hàm sắp xếp ma trận theo yêu cầu cột lẻ giảm dần, cột chẵn tăng dần
void sapXepCotTheoYeuCau(int m, int n, int **a) {
    for (int j = 0; j < n; j++) {
        if (j % 2 == 0) {
            sapXepCotTangDan(m, a, j);
        } else {
            sapXepCotGiamDan(m, a, j);
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
        printf("3. Xuat cac cot chua toan so le\n");
        printf("4. Tim phan tu lon nhat tren bien ma tran\n");
        printf("5. Dem so phan tu co chu so 2\n");
        printf("6. Xuat cac phan tu cuc tieu\n");
        printf("7. Sap xep ma tran hang le giam dan, hang chan tang dan\n");
        printf("8. Sap xep ma tran cot le giam dan, cot chan tang dan\n");
        printf("9. Thoat\n");
        printf("Chon tuyen (1-9): ");
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
                    xuatCotSoLe(m, n, a);
                }
                break;

            case 4:
                if (a == NULL) {
                    printf("Ma tran chua duoc tao. Vui long chon lua chon 1 de tao ma tran truoc.\n");
                } else {
                    int maxBien = timMaxTrenBien(m, n, a);
                    printf("Phan tu lon nhat tren bien ma tran la: %d\n", maxBien);
                }
                break;

            case 5:
                if (a == NULL) {
                    printf("Ma tran chua duoc tao. Vui long chon lua chon 1 de tao ma tran truoc.\n");
                } else {
                    int dem = demPhanTuChuaSo2(m, n, a);
                    printf("So phan tu co chu so 2 la: %d\n", dem);
                }
                break;

            case 6:
                if (a == NULL) {
                    printf("Ma tran chua duoc tao. Vui long chon lua chon 1 de tao ma tran truoc.\n");
                } else {
                    xuatPhanTuCucTieu(m, n, a);
                }
                break;

            case 7:
                if (a == NULL) {
                    printf("Ma tran chua duoc tao. Vui long chon lua chon 1 de tao ma tran truoc.\n");
                } else {
                    sapXepMaTran(m, n, a);
                    printf("Ma tran da duoc sap xep.\n");
                }
                break;

            case 8:
                if (a == NULL) {
                    printf("Ma tran chua duoc tao. Vui long chon lua chon 1 de tao ma tran truoc.\n");
                } else {
                    sapXepCotTheoYeuCau(m, n, a);
                    printf("Ma tran da duoc sap xep.\n");
                }
                break;

            case 9:
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
    } while (luaChon != 9);

    return 0;
}
