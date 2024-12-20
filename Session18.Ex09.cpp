#include<stdio.h>
#include<string.h>

struct dish {
    int id;
    char name[50];
    double price;
};

int total = 5;
struct dish menu[100] = {
    {1, "Tom Hum", 165.000},
    {2, "Cua Ca Mau", 200.000},
    {3, "Mi Xao Boa", 35.000},
    {4, "Thit Trau Xao Khe", 500.000},
    {5, "Nuoc Cot Dua", 50.000},
};

void printMenu();
void addValue();
void editValue();
void deleteValue();
void arrangeValue();
void arrangeValueDown();
void arrangeValueUp();
void searchValue();
void linearSearch();
void binarySearch();

int main() {
    int choice;
    while(1) {
        printf("\n----------MENU------------\n");
        printf("1. In ra gia tri cac phan co trong menu mon an\n");
        printf("2. Them mot phan tu vao vi tri co dinh\n");
        printf("3. Sua mot phan tu o vi tri co dinh\n");
        printf("4. Xoa mot tu o vi tri co dinh\n");
        printf("5. Sap xep cac phan tu\n");
        printf("6. Tim kiem phan tu theo ten nhap vao\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: printMenu(); 
			   break;
            case 2: addValue(); 
			   break;
            case 3: editValue(); 
		   	   break;
            case 4: deleteValue();
			   break;
            case 5: arrangeValue(); 
			   break;
            case 6: searchValue(); 
			   break;
            case 7: 
			      printf("Thoat khoi chuong trinh\n"); 
				  return 0;
            default: 
			      printf("Gia tri nhap vao khong hop le\n");
        }
    }
    return 0;
}

void printMenu() {
    printf("\n-------------MENU-----------\n");
    for (int i = 0; i < total; i++) {
        printf("%d %s %lf\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void addValue() {
    int add;
    printf("Nhap vi tri phan tu muon them: ");
    scanf("%d", &add);
    getchar();
    if (add < 0 || add > total) {
        printf("Vi tri muon them vao khong hop le\n");
    } else {
        for (int i = total; i > add; i--) {
            menu[i] = menu[i - 1];
        }
        menu[add].id = total + 1;
        printf("Nhap ten mon an muon them: ");
        fgets(menu[add].name, sizeof(menu[add].name), stdin);
        printf("Nhap gia tien mon an muon them: ");
        scanf("%lf", &menu[add].price);
        total++;
    }
}

void editValue() {
    int found, isfound = 0;
    printf("Nhap vi tri phan tu can chinh sua: ");
    scanf("%d", &found);
    getchar();
    for (int i = 0; i < total; i++) {
        if (found == i) {
            isfound = 1;
            printf("Ten mon an ban dau la: %s\n", menu[i].name);
            printf("Nhap ten mon an muon sua: ");
            fgets(menu[i].name, sizeof(menu[i].name), stdin);
            printf("Gia tien mon an ban dau la: %lf\n", menu[i].price);
            printf("Nhap gia tien mon an muon sua: ");
            scanf("%lf", &menu[i].price);
            break;
        }
    }
    if (isfound == 0) {
        printf("Khong tim thay vi tri phan tu can sua hoac phan tu khong co trong menu\n");
    } else {
        printf("Phan tu da duoc sua thanh cong\n");
    }
}

void deleteValue() {
    int del;
    printf("Nhap vi tri phan tu muon xoa: ");
    scanf("%d", &del);
    getchar();
    if (del < 0 || del >= total) {
        printf("Vi tri can xoa khong co trong Menu\n");
    } else {
        printf("Phan tu da duoc xoa thanh cong\n");
        for (int i = del; i < total - 1; i++) {
            menu[i] = menu[i + 1];
        }
        total--;
    }
}

void arrangeValue() {
    int choice;
    while (1) {
        printf("1. Giam dan theo gia tien\n");
        printf("2. Tang dan theo gia tien\n");
        printf("3. Khong sap xep nua, chan roi thoat ra ngoai\n");
        printf("Moi ban lua chon: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1: printf("Da sap xep giam dan theo gia tien:\n");
			          arrangeValueDown(); 
			break;
            case 2: printf("Da sap xep tang dan theo gia tien:\n");
			          arrangeValueUp(); 
			break;
            case 3: printf("Thoat\n");
			 return;
            default: printf("Lua chon khong hop le\n");
        }
    }
}

void arrangeValueDown() {
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (menu[j].price > menu[j + 1].price) {
                struct dish temp = menu[j];
                menu[j] = menu[j + 1];
                menu[j + 1] = temp;
            }
        }
    }
}

void arrangeValueUp() {
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (menu[j].price < menu[j + 1].price) {
                struct dish temp = menu[j];
                menu[j] = menu[j + 1];
                menu[j + 1] = temp;
            }
        }
    }
}

void searchValue() {
	int choice;
    while (1) {
        printf("1.Tim kiem tuyen tinh\n");
        printf("2.Tim kiem nhi phan\n");
        printf("3.Khong tim kiem nua thoat ra ngoai\n");
        printf("Moi ban lua chon: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1: printf("Phan tu can tim o vi tri:\n");
			          linearSearch();
			break;
            case 2:
			          binarySearch(); 
			break;
            case 3: printf("Thoat\n");
			 return;
            default: printf("Lua chon khong hop le\n");
    
} } }
void linearSearch() {
    char searchName[50];
    printf("Nhap ten mon an can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    int found = 0;
    for (int i = 0; i < total; i++) {
        if (strstr(menu[i].name, searchName)) {
            printf("Tim thay mon an: %d %s %lf\n", menu[i].id, menu[i].name, menu[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an nao phu hop\n");
    }
}

void binarySearch() {
    arrangeValueUp();
    char searchName[50];
    printf("Nhap ten mon an can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    int start = 0, end = total - 1;
    int found = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int cmp = strcmp(menu[mid].name, searchName);
        if (cmp == 0) {
            printf("Tim thay mon an: %d %s %lf\n", menu[mid].id, menu[mid].name, menu[mid].price);
            found = 1;
            break;
        } else if (cmp < 0) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an nao phu hop\n");
    }
}


