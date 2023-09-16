#include <bits/stdc++.h>
using namespace std;
struct MatHang{
	char maHang[10];
	char tenHang[50];
	char tenNSX[50];
	int namSX;
	double giaBan;
};
struct Node{
	MatHang infor;
	Node *next;
};
typedef Node *TRO;
void Initialize(TRO &L){
	L = NULL;
}
int Empty(TRO L){
	return L == NULL;
}
void NhapMH(MatHang &X){
	cout<<"\tNhap ma hang: "; fflush(stdin);
	gets(X.maHang);
	cout<<"\tTen hang: "; fflush(stdin);
	gets(X.tenHang);
	cout<<"\tTen NSX: "; fflush(stdin);
	gets(X.tenNSX);
	cout<<"\tNam SX: "; cin>>X.namSX;
	cout<<"\tGia ban: "; cin>>X.giaBan;
}
void NhapDS(TRO &L){
	Initialize(L);
	MatHang X;
	TRO P, Q;
	int i = 1;
	do{
		cout<<"Nhap vao mat hang thu "<<i<<endl;
		NhapMH(X);
		P = new Node;
		P->infor = X;
		P->next = NULL;
		if(L==NULL){
			L = P;
		}
		else{
			Q->next = P;
		}
		Q = P;
		i++;
	}while(i<=5);
}
void HienThiDS(TRO L){
	if(L==NULL){
		cout<<"Danh sach rong"<<endl;
		return;
	}
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma hang";
	cout<<setw(25)<<"Ten hang";
	cout<<setw(25)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia ban"<<endl;
	TRO Q = L;
	int i = 0;
	while(Q!=NULL){
		MatHang X = Q->infor;
		cout<<setw(5)<<(i+1);
		cout<<setw(10)<<X.maHang;
		cout<<setw(25)<<X.tenHang;
		cout<<setw(25)<<X.tenNSX;
		cout<<setw(10)<<X.namSX;
		cout<<setw(10)<<X.giaBan<<endl;
		Q = Q->next;
	}
}
int main(){
	TRO L;
	cout<<"Nhap danh sach hang hoa\n";
	NhapDS(L);
	cout<<"===============================\n";
	cout<<"Danh sach hang hoa vua nhap\n";
	HienThiDS(L);
}
