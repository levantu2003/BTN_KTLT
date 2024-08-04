#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KHACHHANG 100
#define MAX_LEN 100

// Định nghĩa cấu trúc KhachHang
typedef struct {
    char hoTen[MAX_LEN];
    char soDienThoai[15];
    int soVeNguoiLon;
    int soVeTreEm;
    char tenPhim[MAX_LEN];
    char phongChieu[MAX_LEN];
    char xuatChieu[MAX_LEN];
    int tienPhaiTra;
} KhachHang;

// Khai báo mảng lưu danh sách khách hàng
KhachHang dskh[MAX_KHACHHANG];
int soLuongKhachHang = 0;

// Hàm đọc danh sách khách hàng từ file
void docDanhSachKhachHang(const char *tenFile) {
    FILE *file = fopen(tenFile, "r");
    if (file == NULL) {
        perror("Khong the mo file");
        printf("Vui long kiem tra ten file: '%s' va duong dan.\n", tenFile);
        return;
    }

    // Đọc từng dòng trong file
    while (fscanf(file, "%[^|]|%[^|]|%d|%d|%[^|]|%[^|]|%[^|]|%d\n",
                  dskh[soLuongKhachHang].hoTen,
                  dskh[soLuongKhachHang].soDienThoai,
                  &dskh[soLuongKhachHang].soVeNguoiLon,
                  &dskh[soLuongKhachHang].soVeTreEm,
                  dskh[soLuongKhachHang].tenPhim,
                  dskh[soLuongKhachHang].phongChieu,
                  dskh[soLuongKhachHang].xuatChieu,
                  &dskh[soLuongKhachHang].tienPhaiTra) != EOF) {
        soLuongKhachHang++;
        if (soLuongKhachHang >= MAX_KHACHHANG) {
            printf("Danh sach khach hang da day.\n");
            break;
        }
    }

    fclose(file);
}

// Hàm xuất danh sách khách hàng ra màn hình
void xuatDanhSachKhachHang() {
    if (soLuongKhachHang == 0) {
        printf("Danh sach khach hang rong.\n");
    } else {
        for (int i = 0; i < soLuongKhachHang; i++) {
            printf("\nKhach hang %d:\n", i + 1);
            printf("Ho va Ten: %s\n", dskh[i].hoTen);
            printf("So Dien Thoai: %s\n", dskh[i].soDienThoai);
            printf("So Ve Nguoi Lon: %d\n", dskh[i].soVeNguoiLon);
            printf("So Ve Tre Em: %d\n", dskh[i].soVeTreEm);
            printf("Ten Phim: %s\n", dskh[i].tenPhim);
            printf("Phong Chieu: %s\n", dskh[i].phongChieu);
            printf("Xuat Chieu: %s\n", dskh[i].xuatChieu);
            printf("Tien Phai Tra: %d VND\n", dskh[i].tienPhaiTra);
        }
    }
}

// Hàm chính
int main() {
    int luaChon;
    char tenFile[MAX_LEN];

    do {
        printf("\n===== QUAN LY DAT VE RAP CHIEU PHIM =====\n");
        printf("1. Doc danh sach khach hang tu file\n");
        printf("2. Xem danh sach khach hang\n");
        printf("3. Thoat\n");
        printf("Chon tuyen (1-3): ");
        scanf("%d", &luaChon);

        // Xóa ký tự newline còn lại
        while (getchar() != '\n');

        switch (luaChon) {
            case 1:
                printf("Nhap ten file (bao gom duong dan neu can): ");
                fgets(tenFile, sizeof(tenFile), stdin);
                tenFile[strcspn(tenFile, "\n")] = 0; // Xóa ký tự newline
                docDanhSachKhachHang(tenFile);
                break;
            case 2:
                xuatDanhSachKhachHang();
                break;
            case 3:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 3);

    return 0;
}
