#include <bits/stdc++.h>
using namespace std;
#define max 100
struct MatHang{
	char maHang[10];
	string tenHang;
	string tenNSX;
	int namSX;
	double gia;
};
struct List{
	int count;
	MatHang e[max];
};
void Initialize(List &L){
	L.count = -1;
}
int Empty(List L){
	return L.count == -1;
}
int Full(List L){
	return L.count == max-1;
}
int Add(List &L, MatHang X){
	if(Full(L)){
		cout<<"Danh sach day\n";
		return 0;
	}
	L.count++;
	L.e[L.count] = X;
	return 1;
}
void NhapMH(MatHang &X){
	cout<<"\tNhap ma hang: "; fflush(stdin);
	gets(X.maHang);
	cout<<"\tTen hang: "; getline(cin, X.tenHang);
	cout<<"\tTen NSX: "; getline(cin, X.tenNSX);
	cout<<"\tNam SX: "; cin>>X.namSX;
	cout<<"\tGia: "; cin>>X.gia;
}
void NhapDS(List &L){
	Initialize(L);
	int i = 0;
	MatHang X;
	do{
		cout<<"Nhap vao mat hang thu "<<i+1<<endl;
		NhapMH(X);
		if(Add(L,X)==0){
			return;
		}
		i++;
	}while(i<3);
}
void HienThiDS(List L){
	cout<<setw(5)<<"STT";
	cout<<setw(15)<<"Ten hang";
	cout<<setw(15)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia ban"<<endl;
	for(int i = 0; i <= L.count; i++){
		cout<<setw(5)<<i+1;
		cout<<setw(15)<<L.e[i].tenHang;
		cout<<setw(15)<<L.e[i].tenNSX;
		cout<<setw(10)<<L.e[i].namSX;
		cout<<setw(10)<<L.e[i].gia<<endl;
	}
}

int main(){
	List L;
	NhapDS(L);
	cout<<"Danh sach vau nhap\n";
	HienThiDS(L);
}
