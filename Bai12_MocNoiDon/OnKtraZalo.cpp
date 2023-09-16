#include <bits/stdc++.h>
using namespace std;
//10h10
struct MatHang{
	char maHang[10];
	string tenHang;
	string tenNSX;
	int namSX;
	double gia;
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
	cout<<"\tTen hang: "; getline(cin, X.tenHang);
	cout<<"\tTen NSX: "; getline(cin, X.tenNSX);
	cout<<"\tNam SX: "; cin>>X.namSX;
	cout<<"\tGia: "; cin>>X.gia;
}
void NhapDS(TRO &L){
	int i = 1;
	Initialize(L);
	MatHang X;
	TRO Q, P;
	while(i<=3){
		cout<<"Nhap vao mat hang thu "<<i<<endl;
		NhapMH(X);
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
		i++;
	}	
}
void HienThiDS(TRO L){
	cout<<setw(5)<<"STT";
	cout<<setw(15)<<"Ten hang";
	cout<<setw(15)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia ban"<<endl;
	TRO Q = L;
	int i = 1;
	while(Q!=NULL){
		MatHang X = Q->infor;
		cout<<setw(5)<<i;
		cout<<setw(15)<<X.tenHang;
		cout<<setw(15)<<X.tenNSX;
		cout<<setw(10)<<X.namSX;
		cout<<setw(10)<<X.gia<<endl;
		Q = Q->next;
		i++;
	}
}
int Length(TRO L){
	int i = 0;
	TRO Q = L;
	while(Q!=NULL){
		i++;
		Q = Q->next;
	}
	return i;
}
void FirstAdd(TRO &L, MatHang X){
	TRO Q = new (Node);
	Q->infor = X;
	Q->next = L;
	L = Q;
}
void Insert(TRO &L, TRO Q, MatHang X){
	TRO T = new Node;
	T->infor = X;
	T->next = Q->next;
	Q->next = T;
}
void BoSung(TRO &L){
	int k;
	do{
		cout<<"Nhap vi tri can them\n"; cin>>k;
		if(k<1 && k>Length(L)+1){
			cout<<"Vi tri khong dung, nhap lai\n";
		}
	}while(k<1 && k>Length(L)+1);
	cout<<"Nhap thong tin mat hang can them\n";
	MatHang X;
	NhapMH(X);
	if(k==1){
		FirstAdd(L,X);
		HienThiDS(L);
	}
	else{
		int i = 1;
		TRO Q = L;
		while(i<k-1){
			Q = Q->next;
			i++;
		}
		Insert(L,Q,X);
		HienThiDS(L);
	}

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
void XoaViTri(TRO &L){
	TRO Q = L;
	int k;
	do{
		cout<<"Nhap vi tri can xoa\n"; cin>>k;
		if(k<1 && k>Length(L)+1){
			cout<<"Vi tri khong dung, nhap lai\n";
		}
	}while(k<1 && k>Length(L)+1);
	int i = 1;
	while(i<k){
		Q = Q->next;
		i++;
	}
	Remove(L,Q);
	cout<<"Danh sach sau khi xoa vi tri "<<k<<endl;
	HienThiDS(L);
}
//TRO Search(TRO L, int nam){
//	TRO Q = L;
//	while( && ){
//		Q = Q->next;
//	}
//	return Q;
//}
void Xoa_2000(TRO &L){
	TRO T = L; int d = 0;
	while(T!=NULL){
		if(T->infor.namSX==2000){
			Remove(L,T);
			d++;
		}
		T = T->next;
	}
	if(d == 0){
		cout<<"Khong co mat hang sx nam 2000\n";
		return;
	}
	else{
		cout<<"Danh sach vua xoa 2000\n";
		HienThiDS(L);
	}
}
void HienThiGiaMax(TRO L){
	TRO P = L;
	TRO Q = L->next;
	while(Q!=NULL){
		if(Q->infor.gia > P->infor.gia){
			P = Q;
		}
		Q = Q->next;
	}
	TRO M = L;
	cout<<setw(5)<<"STT";
	cout<<setw(15)<<"Ten hang";
	cout<<setw(15)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia ban"<<endl;
	int i = 1;
	while(M!=NULL){
		if(M->infor.gia == P->infor.gia){
			MatHang X = M->infor;
			cout<<setw(5)<<i;
			cout<<setw(15)<<X.tenHang;
			cout<<setw(15)<<X.tenNSX;
			cout<<setw(10)<<X.namSX;
			cout<<setw(10)<<X.gia<<endl;
			Q = Q->next;
			i++;
		}
		M = M->next;
	}
}
int main(){
	TRO L;
	cout<<"Nhap vao 5 mat hang\n";
	NhapDS(L);
	cout<<"Danh sach mat hang vua nhap\n";
	HienThiDS(L);
//	cout<<"=========================\n";
//	BoSung(L);
//	cout<<"=========================\n";
//	XoaViTri(L);
//	cout<<"=========================\n";
	Xoa_2000(L);
//	cout<<"=========================\n";
//	HienThiGiaMax(L);
}

