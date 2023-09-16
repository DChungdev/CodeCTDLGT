#include <bits/stdc++.h>
using namespace std;
struct SinhVien{
	char maSV[10];
	char hoDem[26];
	char ten[7];
	int namSinh;
	double diemTK;
}; 
struct Node{
	SinhVien infor;
	Node *next;
};
typedef Node *TRO;
void Initialize(TRO &L){
	L = NULL;
}
int Empty(TRO L){
	return L == NULL;
}
void NhapSV(SinhVien &sv){
	cout<<"\tNhap ma sv: "; fflush(stdin);
	gets(sv.maSV);
	if(strcmp(sv.maSV,"***")==0){
		return;
	}
	cout<<"\tHo dem: "; fflush(stdin);
	gets(sv.hoDem);
	cout<<"\tTen: ";fflush(stdin);
	gets(sv.ten);
	cout<<"\tNam sinh: "; 
	cin>>sv.namSinh;
	cout<<"\tDiem TK: ";
	cin>>sv.diemTK;
}
void NhapDS(TRO &L){
	Initialize(L);
	SinhVien X;
	TRO Q, P;
	int i = 1;
	do{
		cout<<"Nhap vao sinh vien thu "<<i<<endl;
		NhapSV(X);
		if(strcmp(X.maSV,"***")==0)
			return;
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
	}while(1);
}
void HienThiDS(TRO L){
	if(L==NULL){
		cout<<"Danh sach rong"<<endl;
		return;
	}
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma SV";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(10)<<"Nam sinh";
	cout<<setw(10)<<"Diem TK"<<endl;
	TRO Q = L;
	int i = 0;
	while(Q!=NULL){
		SinhVien X = Q->infor;
		cout<<setw(5)<<(i+1);
		cout<<setw(10)<<X.maSV;
		cout<<setw(17)<<X.hoDem;
		cout<<setw(8)<<X.ten;
		cout<<setw(10)<<X.namSinh;
		cout<<setw(10)<<X.diemTK<<endl;
		Q = Q->next;
	}
}
int Length(TRO L){
	int n = 0;
	TRO Q = L;
	while(Q!=NULL){
		Q = Q->next;
		n++;
	}
	return n;
}
void XoaSVDauTien(TRO &L){
	if(Empty(L)){
		cout<<"Danh sach trong\n";
		return;
	}
	TRO Q = L;
	L = L->next;
	delete Q;
	cout<<"Danh sach sau khi xoa sv dau tien\n";
	HienThiDS(L);
}
//Xoa sv8089
TRO Search(TRO L, char *ma){
	TRO Q = L;
	while(Q!=NULL && strcmp(Q->infor.maSV,ma)!=0){
		Q = Q->next;
	}
	return Q;
}
void Remove(TRO &L, TRO T){
	TRO Q;
	if(T==L){
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
void Xoa_sv8089(TRO &L){
	TRO T = Search(L,"sv8089");
	if(T==NULL){
		cout<<"Khong co sv ma sv8089";
		return;
	}
	Remove(L,T);
	cout<<"Danh sach vua xoa sv8089\n";
	HienThiDS(L);
}
void FirstAdd(TRO &L, SinhVien X){
	TRO P = new (Node);
	P->infor = X;
	P->next = L;
	L = P;
}
void Insert(TRO &L, TRO Q, SinhVien X){
	TRO P;
	P = new (Node);
	P->infor = X;
	P->next = Q->next;
	Q->next = P;
}
void BoSung(TRO &L){
	int k;
	SinhVien X;
	do{
		cout<<"Nhap vi tri bo sung(0<k<="<<Length(L)<<"): ";
		cin>>k;
	}while(k<=0 || k>Length(L));
	cout<<"Nhap thong tin sinh vien can bo sung"<<endl;
	do{
		NhapSV(X);
		if(strcmp(X.maSV,"***")==0){
			cout<<"Ma sv phai khac ***, nhap lai"<<endl;
		}
	}while(strcmp(X.maSV,"***")==0);
	if(k==1){
		FirstAdd(L,X);
	}
	else{
		TRO Q = L;
		int d = 1;
		while(d<k-1){
			Q = Q->next;
			d++;
		}
		Insert(L,Q,X);
	}
	cout<<"Danh sach vua bo sung\n";
	HienThiDS(L);
}
void HienThiSVDoanh(TRO L){
	if(L==NULL){
		cout<<"Danh sach rong\n";
		return;
	}
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma SV";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(10)<<"Nam sinh";
	cout<<setw(10)<<"Diem TK"<<endl;
	TRO Q = L;
	int i = 0;
	while(Q!=NULL){
		SinhVien X = Q->infor;
		if(strcmp(X.ten,"Doanh")==0){
			cout<<setw(5)<<(i+1);
			cout<<setw(10)<<X.maSV;
			cout<<setw(17)<<X.hoDem;
			cout<<setw(8)<<X.ten;
			cout<<setw(10)<<X.namSinh;
			cout<<setw(10)<<X.diemTK<<endl;
			i++;
		}
		Q = Q->next;
	}
	if(i == 0){
		cout<<"Khong co sinh vien Doanh nao trong ds\n";
	}	
}
void SapXepTheoDtk(TRO &L){
	TRO P,Q,R;
	P = L;
	while(P->next != NULL){
		R = P;
		Q = P->next;
		while(Q!=NULL){
			if(Q->infor.diemTK > R->infor.diemTK)
				R = Q;
			Q = Q->next;
		}
		SinhVien tg = P->infor;
		P->infor = R->infor;
		R->infor = tg;
		P = P->next;
	}
	cout<<"Danh sach sap giam theo diem tk"<<endl;
	HienThiDS(L);
}
void BoSungTheoTratTuDaSap(TRO &L){
	SinhVien X;
	cout<<"Nhap thong tin sv can bo sung\n";
	do{
		NhapSV(X);
		if(strcmp(X.maSV,"***")==0){
			cout<<"Ma sv phai khac ***, nhap lai"<<endl;
		}
	}while(strcmp(X.maSV,"***")==0);
	if(X.diemTK > L->infor.diemTK){
		FirstAdd(L,X);
	}
	else{
		TRO Q = L;
		TRO T = Q->next;
		while(T!=NULL && T->infor.diemTK > X.diemTK){
			Q = Q->next;
			T = T->next;
		}
		Insert(L,Q,X);
	}
	cout<<"Danh sach sau khi bo sung\n";
	HienThiDS(L);
}
int main(){
	TRO L;
	cout<<"Nhap danh sach sinh vien"<<endl;
	NhapDS(L);
	cout<<"=================================================\n";
	cout<<"Danh sach sinh vien vua nhap\n";
	HienThiDS(L);
	cout<<"=================================================\n";
	cout<<"Chieu dai danh sach: "<<Length(L)<<endl;
	cout<<"=================================================\n";
	XoaSVDauTien(L);
	cout<<"=================================================\n";
	Xoa_sv8089(L);
	cout<<"=================================================\n";
	BoSung(L);
	cout<<"=================================================\n";
	cout<<"Danh sach sinh vien ten Doanh\n";
	HienThiSVDoanh(L);
	cout<<"=================================================\n";
	SapXepTheoDtk(L);
	cout<<"=================================================\n";
	BoSungTheoTratTuDaSap(L);
}
