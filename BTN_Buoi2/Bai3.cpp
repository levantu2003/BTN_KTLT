#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KHACHHANG 100
#define MAX_LEN 100
#define GIA_VE_NGUOI_LON 40000
#define GIA_VE_TRE_EM 20000
#define MAX_PHIM 100

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

// Định nghĩa cấu trúc Phim
typedef struct {
    char tenPhim[MAX_LEN];
    int tongDoanhThu;
} Phim;

// Khai báo mảng lưu danh sách khách hàng và phim
KhachHang dskh[MAX_KHACHHANG];
Phim dsPhim[MAX_PHIM];
int soLuongKhachHang = 0;
int soLuongPhim = 0;

// Hàm tính tiền phải trả cho mỗi khách hàng
void tinhTienPhaiTra(KhachHang *kh) {
    kh->tienPhaiTra = (kh->soVeNguoiLon * GIA_VE_NGUOI_LON) + (kh->soVeTreEm * GIA_VE_TRE_EM);
}

// Hàm đọc danh sách khách hàng từ file
void docDanhSachKhachHang(const char *tenFile) {
    FILE *file = fopen(tenFile, "r");
    if (file == NULL) {
        perror("Khong the mo file");
        printf("Vui long kiem tra ten file: '%s' va duong dan.\n", tenFile);
        return;
    }

    while (fscanf(file, "%[^|]|%[^|]|%d|%d|%[^|]|%[^|]|%[^|]|%d\n",
                  dskh[soLuongKhachHang].hoTen,
                  dskh[soLuongKhachHang].soDienThoai,
                  &dskh[soLuongKhachHang].soVeNguoiLon,
                  &dskh[soLuongKhachHang].soVeTreEm,
                  dskh[soLuongKhachHang].tenPhim,
                  dskh[soLuongKhachHang].phongChieu,
                  dskh[soLuongKhachHang].xuatChieu,
                  &dskh[soLuongKhachHang].tienPhaiTra) != EOF) {
        tinhTienPhaiTra(&dskh[soLuongKhachHang]); // Tính tiền cho khách hàng

        // Cập nhật doanh thu cho từng phim
        int found = 0;
        for (int i = 0; i < soLuongPhim; i++) {
            if (strcmp(dsPhim[i].tenPhim, dskh[soLuongKhachHang].tenPhim) == 0) {
                dsPhim[i].tongDoanhThu += dskh[soLuongKhachHang].tienPhaiTra;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(dsPhim[soLuongPhim].tenPhim, dskh[soLuongKhachHang].tenPhim);
            dsPhim[soLuongPhim].tongDoanhThu = dskh[soLuongKhachHang].tienPhaiTra;
            soLuongPhim++;
        }

        soLuongKhachHang++;
        if (soLuongKhachHang >= MAX_KHACHHANG) {
            printf("Danh sach khach hang da day.\n");
            break;
        }
    }

    fclose(file);
}

// Hàm tính tổng doanh thu
int tinhTongDoanhThu() {
    int tongDoanhThu = 0;
    for (int i = 0; i < soLuongKhachHang; i++) {
        tongDoanhThu += dskh[i].tienPhaiTra;
    }
    return tongDoanhThu;
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

// Hàm xuất doanh thu theo từng phim
void xuatDoanhThuTheoPhim() {
    if (soLuongPhim == 0) {
        printf("Danh sach phim rong.\n");
    } else {
        for (int i = 0; i < soLuongPhim; i++) {
            printf("\nPhim: %s\n", dsPhim[i].tenPhim);
            printf("Tong Doanh Thu: %d VND\n", dsPhim[i].tongDoanhThu);
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
        printf("3. Xem tong doanh thu\n");
        printf("4. Xem doanh thu theo tung phim\n");
        printf("5. Thoat\n");
        printf("Chon tuyen (1-5): ");
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
                printf("Tong doanh thu: %d VND\n", tinhTongDoanhThu());
                break;
            case 4:
                xuatDoanhThuTheoPhim();
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 5);

    return 0;
}
