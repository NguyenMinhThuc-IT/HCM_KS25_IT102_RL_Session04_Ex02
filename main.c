#include <stdio.h>

int main(void) {
    int so_don_hang = 0;
    
    int so_don_thanh_cong = 0;
    int so_don_loi = 0;
    long long tong_doanh_thu = 0;
    long long don_hang_max = 0;

    printf("=== HE THONG POS - CHOT SO DOANH THU CA ===\n");
    printf("Nhap tong so don hang trong ca: ");
    if (scanf("%d", &so_don_hang) != 1) {
        printf("Loi: Du lieu nhap vao khong hop le!\n");
        return 0;
    }

    for (int i = 1; i <= so_don_hang; i++) {
        long long gia_co_so = 0;
        char size_ky_tu = ' ';
        int so_topping = 0;
        int la_hoi_vien = 0;

        printf("\n-----------------------------------\n");
        printf(">>> NHAP THONG TIN DON HANG THU %d/%d <<<\n", i, so_don_hang);
        
        printf("1. Nhap gia co so Size S (VND): ");
        scanf("%lld", &gia_co_so);

        // THÊM KHOẢNG TRẮNG TRƯỚC %c Ở ĐÂY
        printf("2. Nhap Size do uong (S, M, L): ");
        scanf(" %c", &size_ky_tu);

        printf("3. Nhap so luong topping: ");
        scanf("%d", &so_topping);

        printf("4. Hoi vien Vang? (1: Co, 0: Khong): ");
        scanf("%d", &la_hoi_vien);

        if (so_topping < 0) {
            printf("\n[CANH BAO AN NINH] Phat hien so topping am (%d)! Can thiep trai phep hoac su co POS.\n", so_topping);
            printf("[THONG BAO] NGAT KHAN CAP CA LAM VIEC! Dang xuat bao cao luy ke...\n");
            break;
        }

        if (gia_co_so <= 0 || (size_ky_tu != 'S' && size_ky_tu != 's' &&
                               size_ky_tu != 'M' && size_ky_tu != 'm' &&
                               size_ky_tu != 'L' && size_ky_tu != 'l')) {
            printf("\n[LOI DON RAC] Don hang thu %d co gia co so hoac Size khong hop le!\n", i);
            printf("[HE THONG] Bo qua don hang nay va chuyen sang don tiep theo.\n");
            so_don_loi++;
            continue;
        }

        long long phu_thu_size = 0;
        if (size_ky_tu == 'M' || size_ky_tu == 'm') {
            phu_thu_size = 6000;
        } else if (size_ky_tu == 'L' || size_ky_tu == 'l') {
            phu_thu_size = 10000;
        }

        long long phu_thu_topping = (long long)so_topping * 8000;
        long long tong_truoc_giam = gia_co_so + phu_thu_size + phu_thu_topping;
        long long tien_thanh_toan = tong_truoc_giam;

        if (la_hoi_vien == 1) {
            tien_thanh_toan = (long long)(tong_truoc_giam * 0.90);
        }

        so_don_thanh_cong++;
        tong_doanh_thu += tien_thanh_toan;

        if (tien_thanh_toan > don_hang_max) {
            don_hang_max = tien_thanh_toan;
        }

        printf("-> Thanh toan thanh cong! So tien: %lld VND\n", tien_thanh_toan);
    }

    printf("\n==================================================\n");
    printf("       BAO CAO TONG HOP DOANH THU CA LAM VIEC     \n");
    printf("==================================================\n");
    printf("Tong so don hang hop le : %d don\n", so_don_thanh_cong);
    printf("Tong so don hang loi/huy: %d don\n", so_don_loi);
    printf("Tong doanh thu thuc te  : %lld VND\n", tong_doanh_thu);
    printf("Don hang gia tri cao nhat: %lld VND\n", don_hang_max);
    printf("==================================================\n");

    return 0;
}