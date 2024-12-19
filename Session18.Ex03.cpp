#include<stdio.h>
#include<string.h>
int main(){
	struct sinhvien{
		char name[50];
		int age;
		char phoneNumber[50];
	};
	struct sinhvien sinhvienkhachsan[5];
	for(int i=0;i<5;i++){
		printf("Nhap ten cua sinh vien thu:%d\n",i+1);
		fgets(sinhvienkhachsan[i].name,sizeof(sinhvienkhachsan[i].name),stdin);
		printf("Nhap tuoi cua sinh vien thu:%d\n",i+1);
		scanf("%d",&sinhvienkhachsan[i].age);
		fflush(stdin);
		printf("Nhap so dien thoai cua sinh vien thu:%d\n",i+1);
		fgets(sinhvienkhachsan[i].phoneNumber,sizeof(sinhvienkhachsan[i].phoneNumber),stdin);
	}
	printf("Thong tin cua 5 sinh vien vua nhap la:\n");
	for(int i=0;i<5;i++){
		printf("Sinh vien thu %d:\n",i+1);
		printf("Ten:%s\n",sinhvienkhachsan[i].name);
		printf("Tuoi:%d\n",sinhvienkhachsan[i].age);
		printf("So dien thoai:%s\n",sinhvienkhachsan[i].phoneNumber);
	}
	return 0;
}
