#include <bits/stdc++.h>
using namespace std;
struct CanBo{
	char maCB[10];
	char tenDem[26];
	char ten[10];
	char queQuan[100];
	int tuoi;
	double luongCB;
};
struct Node{
	CanBo infor;
	Node *next;
};
typedef Node *TRO;
void Initialize(TRO &L){
	L = NULL;
}
int Empty(TRO L){
	return L == NULL;
}
void NhapCB(CanBo &cb){
	cout<<"\tNhap ma cb: "; fflush(stdin);
	gets(cb.maCB);
	cout<<"\tNhap ten dem: "; fflush(stdin);
	gets(cb.tenDem);
	cout<<"\tNhap ten: "; fflush(stdin);
	gets(cb.ten);
	cout<<"\tNhap que quan: "; fflush(stdin);
	gets(cb.queQuan);
	cout<<"\tNhap tuoi: ";
	cin>>cb.tuoi;
	cout<<"\tLuong co ban: ";
	cin>>cb.luongCB;
}
void NhapDS(TRO &L){
	int n;
	CanBo X;
	TRO P,Q;
	Initialize(L);
	cout<<"Nhap vao so phan tu: "; cin>>n;
	for(int i = 1; i <= n; i++){
		cout<<"Nhap can bo thu "<<i<<endl;
		NhapCB(X);
		P = new (Node);
		P->infor = X;
		P->next = NULL;
		if(L == NULL){
			L = P;
		}
		else{
			Q->next = P;
		}
		Q = P;
	}
}
void HienThiDS(TRO L){
	int i = 0;
	TRO Q = L;
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma CB";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(25)<<"Que quan";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(10)<<"Luong CB"<<endl;
	while(Q!=NULL){
		CanBo cb = Q->infor;
		cout<<setw(5)<<(i+1);
		cout<<setw(10)<<cb.maCB;
		cout<<setw(17)<<cb.tenDem;
		cout<<setw(8)<<cb.ten;
		cout<<setw(25)<<cb.queQuan;
		cout<<setw(10)<<cb.tuoi;
		cout<<setw(10)<<cb.luongCB<<endl;
		i++;
		Q = Q->next;
	}
}
void HienThiDuoi50(TRO L){
	int i = 0;
	TRO Q = L;
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma CB";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(25)<<"Que quan";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(10)<<"Luong CB"<<endl;
	while(Q!=NULL){
		if(Q->infor.tuoi<=50){
			CanBo cb = Q->infor;
			cout<<setw(5)<<(i+1);
			cout<<setw(10)<<cb.maCB;
			cout<<setw(17)<<cb.tenDem;
			cout<<setw(8)<<cb.ten;
			cout<<setw(25)<<cb.queQuan;
			cout<<setw(10)<<cb.tuoi;
			cout<<setw(10)<<cb.luongCB<<endl;
			i++;
			Q = Q->next;	
		}
		
	}
}
int Length(TRO L){
	int i = 0;
	TRO Q = L;
	while(Q != NULL){
		Q = Q->next;
		i++;
	}
	return i;
}
void Remove(TRO &L, TRO T){
	TRO Q;
	if(T == L){
		L = T->next;
	}
	else{
		Q = L;
		while(Q->next != T){
			Q = Q->next;
		}
		Q->next = T->next;
	}
	delete T;
}
int XoaThaiBinh(TRO &L){
	int n = 0;
	TRO Q = L;
	while(Q!=NULL){
		if(strcmp(Q->infor.queQuan,"Thai binh")==0){
			Remove(L,Q);
			n++;
		}
		Q = Q->next;
	}
	if(n == 0){
		return 0;
	}
	else{
		return 1;	
	}
}
void Insert(TRO &L, TRO Q, CanBo X){
	TRO P;
	P = new (Node);
	P->infor = X;
	P->next = Q->next;
	Q->next = P;
}
void BoSung(TRO &L, int k){
	CanBo X;
	if(k>Length(L)+1){
		cout<<"Vi tri chen khong hop le\n";
		return;
	}
	cout<<"Nhap thong tin sinh vien can bo sung"<<endl;
	NhapCB(X);	
	TRO Q = L;
	int d = 1;
	while(d<k-1){
		Q = Q->next;
		d++;
	}
	Insert(L,Q,X);
	cout<<"Danh sach vua bo sung\n";
	HienThiDS(L);
}
int main(){
	TRO L;
	NhapDS(L);
	cout<<"Danh sach vua nhap\n";
	HienThiDS(L);
	cout<<"=========================\n";
	cout<<"Danh sach can bo tu 50 tro xuong\n";
	HienThiDuoi50(L);
	cout<<"=========================\n";
	if(XoaThaiBinh(L)==1){
		cout<<"Danh sach sau khi xoa Thai binh\n";
		HienThiDS(L);
	}
	else{
		cout<<"Khong co can bo que Thai binh\n";
	}
	cout<<"=========================\n";
	BoSung(L,4);
}

