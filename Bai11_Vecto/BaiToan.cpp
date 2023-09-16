#include <iostream>
using namespace std;
#define max 8
struct SinhVien{
	char maSV[6];
	char hoDem[23];
	char ten[10];
	char gioiTinh[4];
	int namSinh;
	double diemTK;
};
struct vector{
	int count;
	SinhVien e[max];
};
//Khoi tao danh sach rong
void Initialize(vector &v){
	L.count = -1;
}
//Kiem tra danh sach day
int Full(vector v){
	return L.count == max-1;
}
int Empty(vector v){
	return L.count == -1;
}
//Xoa phan tu dau tien trong danh sach
void xoa_pt_dau_tien(vector &v){
	if(Empty(v) == -1){
		return;
	}
	else{
		for(int i = 1; i <= v.count; i++){
			v.e[i-1] = v.e[i];
		}
		v.count--;
	}
}
int insert(vector &v, int k, SinhVien X){
 	if (k <= v.count + 1 && k > 0 && !Full(v)){
	 	for (int i = v.count; i >= k-1; i--)
			v.e[i + 1] = v.e[i];
			v.e[k - 1] = X;
			v.count++;
			return 1;
		}
		else return 0;
}
void chenSvVaoViTri3(vector &v){
	SinhVien sv;
	sv = taoSv(1006,"Le Thi","Doan","Nu",1998,7.6);
	if(insert(v,3,sv)){
		printf("\nChen thanh cong...!");
		printf("\nDanh sach sau khi chen");
		hienThiDs(v);
	}else{
	 	printf("\nChen khong thanh cong...!");
	}
}

