#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

void chuyenChuThuong(char* Str)
{
    for (int i = 0; Str[i]; i++)
    {
        Str[i] = tolower((unsigned char)Str[i]);
    }
}

int tinhTuoi(int Ngay, int Thang, int Nam)
{
    time_t t = time(NULL);
    struct tm tm;
    localtime_s(&tm, &t);
    int Tuoi = tm.tm_year + 1900 - Nam;
    if (tm.tm_mon + 1 < Thang || (tm.tm_mon + 1 == Thang && tm.tm_mday < Ngay))
    {
        Tuoi--;
    }
    return Tuoi;
}

void nhapThongTin(char* HoTen, int* Ngay, int* Thang, int* Nam, char* GioiTinh)
{
    printf("\nNhap ho ten: ");
    fgets(HoTen, 100, stdin);
    HoTen[strcspn(HoTen, "\n")] = 0;

    printf("\nNhap ngay sinh (dd/mm/yyyy): ");
    scanf("%d/%d/%d", Ngay, Thang, Nam);
    (void)getchar(); // Doc ky tu newline con lai

    printf("\nNhap gioi tinh (nam/nu): ");
    fgets(GioiTinh, 4, stdin);
    GioiTinh[strcspn(GioiTinh, "\n")] = 0;
    chuyenChuThuong(GioiTinh);
}

int kiemTraHopLe(char* GioiTinh, int TuoiHienTai)
{
    if (strcmp(GioiTinh, "nam") != 0 && strcmp(GioiTinh, "nu") != 0)
    {
        printf("Loi: Gioi tinh khong hop le.\n");
        return 0;
    }
    if (TuoiHienTai < 18)
    {
        printf("Loi: Tuoi khong nam trong do tuoi lao dong.\n");
        return 0;
    }
    return 1;
}

void tinhTuoiNghiHuu(int NamSinh, int ThangSinh, char* GioiTinh, int* TuoiNghiHuu, int* ThangNghiHuu, int* NamNghiHuu)
{
    int namDuTuoiNghiHuu = 2021;
    int tuoiNghiHuu = 60;
    int thangNghiHuu = 3;

    if (strcmp(GioiTinh, "nu") == 0)
    {
        tuoiNghiHuu = 55;
        thangNghiHuu = 4;
    }

    while (1)
    {
        if (namDuTuoiNghiHuu >= 2035 || 
            (strcmp(GioiTinh, "nam") == 0 && namDuTuoiNghiHuu >= 2028) ||
            (strcmp(GioiTinh, "nu") == 0 && namDuTuoiNghiHuu >= 2035))
        {
            break;
        }

        if (NamSinh < namDuTuoiNghiHuu - tuoiNghiHuu || 
            (NamSinh == namDuTuoiNghiHuu - tuoiNghiHuu && ThangSinh <= thangNghiHuu))
        {
            break;
        }

        namDuTuoiNghiHuu++;
        if (strcmp(GioiTinh, "nam") == 0)
        {
            thangNghiHuu += 3;
            if (thangNghiHuu > 12)
            {
                thangNghiHuu -= 12;
                tuoiNghiHuu++;
            }
        }
        else
        {
            thangNghiHuu += 4;
            if (thangNghiHuu > 12)
            {
                thangNghiHuu -= 12;
                tuoiNghiHuu++;
            }
        }
    }

    *TuoiNghiHuu = tuoiNghiHuu;
    *ThangNghiHuu = thangNghiHuu;
    *NamNghiHuu = NamSinh + tuoiNghiHuu;
}

void tinhVaHienThiKetQua(char* HoTen, int Ngay, int Thang, int Nam, char* GioiTinh)
{
    int TuoiHienTai = tinhTuoi(Ngay, Thang, Nam);

    if (!kiemTraHopLe(GioiTinh, TuoiHienTai))
    {
        return;
    }

    time_t t = time(NULL);
    struct tm tm;
    localtime_s(&tm, &t);
    int NamHienTai = tm.tm_year + 1900;

    int TuoiNghiHuu, ThangNghiHuu, NamNghiHuu;
    tinhTuoiNghiHuu(Nam, Thang, GioiTinh, &TuoiNghiHuu, &ThangNghiHuu, &NamNghiHuu);

    char* Ten = strrchr(HoTen, ' ');
    Ten = (Ten != NULL) ? Ten + 1 : HoTen;

    printf("\n%s, gioi tinh %s, sinh ngay %02d/%02d/%d.", HoTen, GioiTinh, Ngay, Thang, Nam);
    printf("\nHien tai (nam %d) %s da %d tuoi. ", NamHienTai, Ten, TuoiHienTai);
    printf("\nThoi gian %s duoc nghi huu la thang %02d/%d (luc %d tuoi %d thang).\n", Ten, ThangNghiHuu, NamNghiHuu, TuoiNghiHuu, ThangNghiHuu);
}

int main()
{
    char HoTen[100], GioiTinh[4];
    int Ngay, Thang, Nam;

    nhapThongTin(HoTen, &Ngay, &Thang, &Nam, GioiTinh);
    tinhVaHienThiKetQua(HoTen, Ngay, Thang, Nam, GioiTinh);

    return 0;
}