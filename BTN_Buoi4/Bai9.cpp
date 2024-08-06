#include <stdio.h>
#include <math.h>

// S1
double tinhS1_dequy(int n) {
    if (n == 1) return 1.0 / 6.0;
    return 1.0 / (n * (n + 1) * (n + 2)) + tinhS1_dequy(n - 1);
}

double tinhS1_khudequy(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

// S2
int tinhS2_dequy(int n) {
    if (n == 1) return 1;
    return n * n + tinhS2_dequy(n - 1);
}

int tinhS2_khudequy(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

// S3
int tinhS3_dequy(int n) {
    if (n == 1) return 1;
    return tinhS3_dequy(n - 1) + (n * (n + 1)) / 2;
}

int tinhS3_khudequy(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (i * (i + 1)) / 2;
    }
    return sum;
}

// S4
double tinhS4_dequy(int n) {
    if (n == 1) return 0.5;
    return pow(-1, n - 1) * ((2 * n - 1) + (2 * n)) / (2 * n * (2 * n - 1)) + tinhS4_dequy(n - 1);
}

double tinhS4_khudequy(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i - 1) * ((2 * i - 1) + (2 * i)) / (2 * i * (2 * i - 1));
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    printf("S1 (de quy): %f\n", tinhS1_dequy(n));
    printf("S1 (khu de quy): %f\n", tinhS1_khudequy(n));

    printf("S2 (de quy): %d\n", tinhS2_dequy(n));
    printf("S2 (khu de quy): %d\n", tinhS2_khudequy(n));

    printf("S3 (de quy): %d\n", tinhS3_dequy(n));
    printf("S3 (khu de quy): %d\n", tinhS3_khudequy(n));

    printf("S4 (de quy): %f\n", tinhS4_dequy(n));
    printf("S4 (khu de quy): %f\n", tinhS4_khudequy(n));

    return 0;
}