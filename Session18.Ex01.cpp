#include<stdio.h>
#include<string.h>

int main(){
	struct sinhvien{
		char name[50];
		int age;
		char phoneNumber[50];
	};
	struct sinhvien sinhvienkhachsan;
	strcpy(sinhvienkhachsan.name,"Bill Gut");
	sinhvienkhachsan.age=3;
	strcpy(sinhvienkhachsan.phoneNumber,"0329955779");
	printf("Ten cua sinh vien la :%s\n",sinhvienkhachsan.name);
	printf("Tuoi cua sinh vien la:%d\n",sinhvienkhachsan.age);
	printf("So dien thoai cua sinh vien la:%s",sinhvienkhachsan.phoneNumber);
	return 0;
}
