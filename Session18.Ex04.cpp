#include <stdio.h>
#include <string.h>

int main() {
    struct sinhvien {
        int id;
        char name[50];
        int age;
        char phoneNumber[50];
    };

    struct sinhvien sinhvienkhachsan[50];
    for (int i = 0; i < 5; i++) {
        sinhvienkhachsan[i].id = i + 1;
        printf("Nhap ten cua sinh vien thu %d:\n", i + 1);
        fgets(sinhvienkhachsan[i].name, sizeof(sinhvienkhachsan[i].name), stdin);
        printf("Nhap tuoi cua sinh vien thu %d:\n", i + 1);
        scanf("%d", &sinhvienkhachsan[i].age);
        getchar();
        printf("Nhap so dien thoai cua sinh vien thu %d:\n", i + 1);
        fgets(sinhvienkhachsan[i].phoneNumber, sizeof(sinhvienkhachsan[i].phoneNumber), stdin);
    }

    printf("\nThong tin cua cac sinh vien:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", sinhvienkhachsan[i].id);
        printf("Ten: %s", sinhvienkhachsan[i].name);
        printf("Tuoi: %d\n", sinhvienkhachsan[i].age);
        printf("So dien thoai: %s", sinhvienkhachsan[i].phoneNumber);
    }

    return 0;
}

