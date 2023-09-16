#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
#define max 100
struct CanBo{
	char maCB[10];
	char hoDem[25];
	char ten[8];
	char gioiTinh[4];
	int tuoi;
	double heSL;
	double luongCB;	
};
struct List{
	int count;
	CanBo e[max];
};
void Initialize(List &L){
	L.count = -1;
}
int Full(List L){
	return L.count == max-1;
}
int Empty(List L){
	return L.count == -1;
}
void nhapcb(CanBo &cb){
	cout<<"\tNhap ma can bo: "; fflush(stdin);
	gets(cb.maCB);
	cout<<"\tHo dem: "; fflush(stdin);
	gets(cb.hoDem);
	cout<<"\tTen: "; fflush(stdin);
	gets(cb.ten);
	cout<<"\tGioi tinh: "; fflush(stdin);
	gets(cb.gioiTinh);
	cout<<"\tTuoi: "; cin>>cb.tuoi;
	cout<<"\tHe so luong: "; cin>>cb.heSL;
	cb.luongCB = cb.heSL * 1490000;
}
int Add(List &L, CanBo X){
	if(Full(L)){
		return 0;
	}
	L.count++;
	L.e[L.count] = X;
	return 1;	
}
void nhapds(List &L, int n){
	Initialize(L);
	CanBo X;
	for(int i = 0; i < n; i++){
		cout<<"Nhap can bo thu "<<i+1<<endl;
		nhapcb(X);
		if(!Add(L,X)){
			return;
		}
	}
}
void hien_thi_ds(List L){
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma CB";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(10)<<"Gioi tinh";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(10)<<"He so luong";
	cout<<setw(20)<<"Luong co ban"<<endl;
	for(int i = 0; i <= L.count; i++){
		cout<<setw(5)<<(i+1);
		cout<<setw(10)<<L.e[i].maCB;
		cout<<setw(17)<<L.e[i].hoDem;
		cout<<setw(8)<<L.e[i].ten;
		cout<<setw(10)<<L.e[i].gioiTinh;
		cout<<setw(10)<<L.e[i].tuoi;
		cout<<setw(10)<<fixed<<setprecision(2)<<L.e[i].heSL;
		cout<<setw(20)<<fixed<<setprecision(2)<<L.e[i].luongCB<<endl;
	}
}
void hien_thi_cb_nu_duoi50(List L){
	int i = 0, d = 0;
	cout<<"Danh sach can bo nu duoi 50 tuoi\n";
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma CB";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(10)<<"Gioi tinh";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(10)<<"He so luong";
	cout<<setw(20)<<"Luong co ban"<<endl;
	while(i<=L.count){
		if(strcmp(L.e[i].gioiTinh,"nu")==0 && L.e[i].tuoi<=50){
			cout<<setw(5)<<(d+1);
			cout<<setw(10)<<L.e[i].maCB;
			cout<<setw(17)<<L.e[i].hoDem;
			cout<<setw(8)<<L.e[i].ten;
			cout<<setw(10)<<L.e[i].gioiTinh;
			cout<<setw(10)<<L.e[i].tuoi;
			cout<<setw(10)<<fixed<<setprecision(2)<<L.e[i].heSL;
			cout<<setw(20)<<fixed<<setprecision(2)<<L.e[i].luongCB<<endl;
			d++;
		}
		i++;
	}
	if(d == 0){
		cout<<"Khong co can bo nu nao duoi 50 tuoi\n";
	}
}void can_bo_Tung(List L){
	int d = 0;
	cout<<"Thong can can bo tung\n";
	for(int i = 0; i <= L.count; i++){
		if(strcmp(L.e[i].ten,"Tung")==0){
			cout<<setw(5)<<(d+1);
			cout<<setw(10)<<L.e[i].maCB;
			cout<<setw(17)<<L.e[i].hoDem;
			cout<<setw(8)<<L.e[i].ten;
			cout<<setw(10)<<L.e[i].gioiTinh;
			cout<<setw(10)<<L.e[i].tuoi;
			cout<<setw(10)<<fixed<<setprecision(2)<<L.e[i].heSL;
			cout<<setw(20)<<fixed<<setprecision(2)<<L.e[i].luongCB<<endl;
			d++;
			break;
		}
	}
	if(d==0){
		cout<<"\nKhong co can bo nao ten tung\n";
	}
}
void themvaovitrithu3(List &L){
	CanBo X;
	nhapcb(X);
	if(Full(L)){
		cout<<"Danh sach day\n";
		return;
	}
	for(int i = L.count; i > 2; i--){
		L.e[i] = L.e[i-1];
	}
	L.e[2] = X;
	L.count++;
	cout<<"Danh sach sau khi them cb vao vi tri thu 3\n";
	hien_thi_ds(L);
}
int main(){
	List L;
	int n;
	cout<<"Nhap so can bo: "; cin>>n;
	nhapds(L,n);
	cout<<"Danh sach vua nhap\n";
	hien_thi_ds(L);
	hien_thi_cb_nu_duoi50(L);
	can_bo_Tung(L);
	themvaovitrithu3(L);
}
