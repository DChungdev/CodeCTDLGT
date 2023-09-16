#include <bits/stdc++.h>
using namespace std;
struct IPAD{
	char maHang[10];
	char tenHang[30];
	char tenNSX[30];
	int namSX;
	double gia;
};
struct Node{
	IPAD infor;
	Node *next;
};
typedef Node *TRO;
void Initialize(TRO &L){
	L = NULL;
}
int Empty(TRO L){
	return L == NULL;
}
void nhapIP(IPAD &X){
	cout<<"\tNhap ma Ipad: "; fflush(stdin);
	gets(X.maHang);
	cout<<"\tTen hang: "; fflush(stdin);
	gets(X.tenHang);
	cout<<"\tTen NSX: ";fflush(stdin);
	gets(X.tenNSX);
	cout<<"\tNam sx: "; 
	cin>>X.namSX;
	cout<<"\tGia: ";
	cin>>X.gia;
}
void nhapDS(TRO &L){
	Initialize(L);
	IPAD X;
	TRO P,Q;
	for(int i = 0; i < 3; i++){
		cout<<"Nhap vao mat hang thu "<<i+1<<endl;
		nhapIP(X);
		P = new Node();
		P->infor = X;
		P->next = NULL;
		if(L==NULL){
			L = P;
		}
		else{
			Q->next = P;
		}
		Q=P;
	}
}
void hienThiDS(TRO L){
	TRO P = L;
	int i = 0;
	if(L == NULL){
		cout<<"Danh sach rong\n";
		return;
	}
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma hang";
	cout<<setw(30)<<"Ten hang";
	cout<<setw(30)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia"<<endl;
	while(P != NULL){
		IPAD X = P->infor;
		cout<<setw(5)<<(i+1);
		cout<<setw(10)<<X.maHang;
		cout<<setw(30)<<X.tenHang;
		cout<<setw(30)<<X.tenNSX;
		cout<<setw(10)<<X.namSX;
		cout<<fixed<<setw(15)<<setprecision(2)<<X.gia<<endl;
		P = P->next;
	}
}
int Length(TRO L){
	int i = 0;
	TRO P = L;
	while(P != NULL){
		P = P->next;
		i++;
	}
	return i;
}
void firstAdd(TRO &L, IPAD X){
	TRO P = new (Node);
	P->infor = X;
	P->next = L;
	L = P;
}
void Insert(TRO &L, int k){
	int i = 1;
	TRO P, Q = L;
	IPAD X;
	if(L!=NULL && k>=1 && k<=Length(L)+1){
		cout<<"Nhap vao thong tin mat hang can chen\n";
		nhapIP(X);
		if(k==1){
			firstAdd(L,X);
		}
		else{
			int d = 1;
			while(d<k-1){
				Q = Q->next;
				d++;
			}
			P = new (Node);
			P->infor = X;
			P->next = Q->next;
			Q->next = P;
		}
	}
	else{
		cout<<"Vi tri chen khong hop le!\n";
	}
}
TRO Search(TRO L, int nam){
	TRO Q = L;
	while(Q!=NULL && Q->infor.namSX != nam){
		Q = Q->next;
		
	}
	return Q;
}
void Remove(TRO &L, TRO Q){
	TRO P;
	if(Q == L){
		L = Q->next;
	}
	else{
		P = L;
		while(P->next != Q){
			P = P->next;
		}
		P->next = Q->next;
	}
	delete Q;
}
void xoa_1998(TRO &L){
	TRO Q = L;
	int d = 0;
	while(Q!=NULL){
		if(Q->infor.namSX == 1998){
			Remove(L,Q);
			d++;
		}
		Q = Q->next;
	}
	if(d==0){
		cout<<"Khong co mat hang san xuat nam 1998\n";
		return;
	}
	else{
		cout<<"Danh sach sau khi xoa mat hang sx nam 1998:\n";
		hienThiDS(L);
	}
}
void ShowIpadMin(TRO L){
	TRO P = L;
	IPAD X = P->infor;
	while(P!=NULL){
		if(X.gia > P->infor.gia){
			X = P->infor;
		}
		P = P->next;
	}
	cout<<"Thong tin mat hang gia min\n";
	cout<<setw(5)<<"Ma hang";
	cout<<setw(30)<<"Ten hang";
	cout<<setw(30)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia"<<endl;
	cout<<setw(5)<<X.maHang;
	cout<<setw(30)<<X.tenHang;
	cout<<setw(30)<<X.tenNSX;
	cout<<setw(10)<<X.namSX;
	cout<<fixed<<setw(15)<<setprecision(2)<<X.gia<<endl;
}
void ShowUnder5m(TRO L){
	TRO P = L;
	int i = 0;
	cout<<"Thong tin mat hang tren 5m\n";
	cout<<setw(5)<<"Ma hang";
	cout<<setw(30)<<"Ten hang";
	cout<<setw(30)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia"<<endl;
	while(P!=NULL){
		IPAD X = P->infor;
		if(X.gia > 5000000){
			X = P->infor;					
			cout<<setw(5)<<X.maHang;
			cout<<setw(30)<<X.tenHang;
			cout<<setw(30)<<X.tenNSX;
			cout<<setw(10)<<X.namSX;
			cout<<fixed<<setw(15)<<setprecision(2)<<X.gia<<endl;
			i++;
		}
		P = P->next;
	}
	if(i==0){
		cout<<"Khong co mat hang nao tren 5m\n";
	}
}
int main(){
	TRO L;
	nhapDS(L);
	cout<<"Danh sach vua nhap: \n";
	hienThiDS(L);
//	int k;
//	cout<<"Nhap vao vi tri can chen: \n"; cin>>k;
//	Insert(L,k);
//	cout<<"Danh sach sau khi chen: \n";
//	hienThiDS(L);
	xoa_1998(L);
	ShowIpadMin(L);
	ShowUnder5m(L);
}
