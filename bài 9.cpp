#include <stdio.h>
#include <string.h>
struct Dish{
	int id;
	char name[100];
	float price;
};
int main(){
	char findDish[100];
	int find = 0;
	int n = 5;	
	int choice, pos;
	int i, j;
	struct Dish menu[100]= {
		{1, "Thit bo", 20}, 
		{2, "Thit ga", 30},
		{3, "Pho", 45},
		{4, "Thit nuong", 10},
		{5, "Bun dau", 35},
	};
	struct Dish temp; // Bien tam thoi de sap xep
	do{
		printf("\nMENU\n");
		printf("1.In ra gia tri cac phan tu co trong menu mon an theo dang 1.member:value\n");
		printf("2.Them mot phan tu vao vi tri chi dinh\n");
		printf("3.Sua mot phan tu o vi tri chi dinh\n");
		printf("4.Xoa mot phan tu o vi tri chi dinh\n");
		printf("5.Sap xep cac phan tu tang dan theo price\n");
		printf("6.Tim kiem phan tu tuyen tinh theo name nhap vao\n");
		printf("7.Thoat\n");
		printf("Lua chon cua ban:\n");
		scanf("%d", &choice);
		switch(choice){
			// In ra gia tri cac phan tu co trong menu mon an
			case 1:
				printf("Cac phan tu co trong menu mon an: \n");
				for(i = 0; i < n; i++){
					printf("%d. %s: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
				}
				break;
			// Them mot phan tu vao vi tri chi dinh
			case 2:
				if (n >= 100) {
            		printf("Danh sach da day khong the them mon an\n");
            	} else {		
					printf("Moi ban nhap ten mon an: ");
                    getchar(); 
                    fgets(menu[n].name, sizeof(menu[n].name), stdin);
                    menu[n].name[strcspn(menu[n].name, "\n")] = 0; 
                    printf("Moi ban nhap gia mon an: ");
                    scanf("%f", &menu[n].price);
                    menu[n].id = n + 1;
                    n++;
                    printf("Da them mon an thanh cong\n"); 
                }
                break;
			// Sua mot phan tu o vi tri chi dinh
			case 3:
				printf("Nhap vi tri muon sua:");
                scanf("%d", &pos);
                getchar();  
                if(pos >= 1 && pos <= n){
                    pos--; 
                    printf("Moi ban nhap ten moi cua mon an:");
                    fgets(menu[pos].name, sizeof(menu[pos].name),stdin);
                    menu[pos].name[strcspn(menu[pos].name, "\n")] = 0; 
                    printf("Moi ban nhap gia tien moi:");
                    scanf("%f", &menu[pos].price);
                } else {
                    printf("Vi tri khong hop le.\n");
                }
                break;
            // Xoa mot phan tu o vi tri chi dinh
			case 4:
				printf("Nhap vi tri muon xoa phan tu: ");
				scanf("%d", &pos);
				if(pos < 1 || pos > n){
					printf("Vi tri khong hop le.\n");
				} else {
					for(i = pos; i < n - 1; i++){
						menu[i]=menu[i+1];
						menu[i].id=i+1;
					}
					n--;
				}
				break;
			// Sap xep cac phan tu tang dan theo price
			case 5:
				for(i = 0; i < n; i++){
					for(j = i + 1; j < n; j++){
						if(menu[i].price > menu[j].price){
							temp=menu[i];
							menu[i]=menu[j];
							menu[j]=temp;
						}
					}
				}
				for(i = 0; i < n; i++){
					printf("%d. %s: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
				}
				break;
			// Tim kiem phan tu tuyen tinh theo name nhap vao
			case 6:
				find = 0;
				printf("Nhap mon an can tim:");
                getchar();
                fgets(findDish, sizeof(findDish), stdin);
                findDish[strcspn(findDish, "\n")]=0;
				for(i=0; i<n; i++){
					if(strcmp(findDish, menu[i].name)== 0){
						printf("%d. %s: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
						find=1;
						break;
					}
				}
				if(find == 0){
					printf("Khong tim thay mon an vua nhap\n");
				}
				break;
			// Thoat chuong trinh		
			case 7:
				printf("Thoat chuong trinh.");
				break;
			default:
				printf("Lua chon khong hop le.Vui long nhap lai!");	
				break;	
		}
	} while (choice!=7);
	return 0;
}
