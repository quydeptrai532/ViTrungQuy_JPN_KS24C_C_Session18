#include<stdio.h>
#include<string.h>

int main(){
	struct sinhvien{
		char name[50];
		int age;
		char phoneNumber[50];
	};
	struct sinhvien sinhvienkhachsan;
	printf("Nhap vao ten sinh vien:\n");
	fgets(sinhvienkhachsan.name,sizeof(sinhvienkhachsan.name),stdin);
	printf("Nhap vao tuoi cua sinh vien:\n");
	scanf("%d",&sinhvienkhachsan.age);
	fflush(stdin);
	printf("Nhap vao so dien thoai cua sinh vien:\n");
	fgets(sinhvienkhachsan.phoneNumber,sizeof(sinhvienkhachsan.phoneNumber),stdin);
	printf("Ten cua sinh vien la:%s\n",sinhvienkhachsan.name);
	printf("Tuoi cua sinh vien la:%d\n",sinhvienkhachsan.age);
	printf("So dien thoai cua sinh vien la:%s\n",sinhvienkhachsan.phoneNumber);
	return 0;
}
