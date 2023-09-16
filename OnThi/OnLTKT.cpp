#include <bits/stdc++.h>
using namespace std;
#define max 100
struct IPAD{
	char maHang[10];
	char tenHang[30];
	char tenNSX[30];
	int namSX;
	double gia;
};
struct List{
	int count;
	IPAD e[max];
};
int Full(List L){
	return max-1 == L.count;
}
void Initialize(List &L){
	L.count = -1;
}
int Add(List &L, IPAD X){
	if(Full(L)){
		return 0;
	}
	L.count++;
	L.e[L.count] = X;
	return 1;
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
void nhapDS(List &L){
	Initialize(L);
	IPAD X;
	for(int i = 0; i < 3; i++){
		cout<<"Nhap vao mat hang thu "<<i+1<<endl;
		nhapIP(X);
		if(!Add(L,X)){
			return;
		}
	}
}
void hien_thi_ds(List L){
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma hang";
	cout<<setw(30)<<"Ten hang";
	cout<<setw(30)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia"<<endl;
	for(int i = 0; i <= L.count; i++){
		cout<<setw(5)<<(i+1);
		cout<<setw(10)<<L.e[i].maHang;
		cout<<setw(30)<<L.e[i].tenHang;
		cout<<setw(30)<<L.e[i].tenNSX;
		cout<<setw(10)<<L.e[i].namSX;
		cout<<setw(10)<<L.e[i].gia<<endl;
	}
}
int Insert(List &L, int k){
	IPAD X;
	if(!Full(L) && k<=L.count+2 && k>0){
		cout<<"Nhap mat hang can bo sung:\n";
		nhapIP(X);
		for(int i = L.count+1; i >= k; i--){
			L.e[i] = L.e[i-1];
		}
		L.e[k-1] = X;
		L.count++;
		return 1;
	}
	return 0;
	
}
int Empty(List L){
	return L.count == -1;
}
int Delete(List &L, int k){
	if(!Empty(L) && k<=L.count+1 && k>0){
		for(int i = k-1; i < L.count; i++){
			L.e[i] = L.e[i+1];
		}
		L.count--;	
		return 1;
	}
	return 0;
}
void XoaMH_1998(List &L){
	for(int i = 0; i <= L.count; i++){
		if(L.e[i].namSX == 1998){
			if(Delete(L,i+1)!=1){
				cout<<"Danh sach rong\n";
				return;
			}
		}
	}
	cout<<"Danh sach sau khi xoa\n";
	hien_thi_ds(L);
}
void hienThiIn4GiaMin(List L){
	int min = L.e[0].gia;
	int temp=0;
	for(int i=1; i<=L.count; i++){
		if(min > L.e[i].gia){
			min = L.e[i].gia;
			temp = i;
		}
	}
	cout<<"Thong tin ipad gia thap nhat\n";
	cout<<setw(10)<<"Ma hang";
	cout<<setw(30)<<"Ten hang";
	cout<<setw(30)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia"<<endl;
	cout<<setw(10)<<L.e[temp].maHang;
	cout<<setw(30)<<L.e[temp].tenHang;
	cout<<setw(30)<<L.e[temp].tenNSX;
	cout<<setw(10)<<L.e[temp].namSX;
	cout<<setw(10)<<L.e[temp].gia<<endl;
}
void HienThiGiaTren5m(List L){
	cout<<"Thong tin ipad gia tren 5m\n";
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma hang";
	cout<<setw(30)<<"Ten hang";
	cout<<setw(30)<<"Ten NSX";
	cout<<setw(10)<<"Nam SX";
	cout<<setw(10)<<"Gia"<<endl;
	int n = 0;
	for(int i = 0; i <= L.count; i++){
		if(L.e[i].gia > 5000000){
			cout<<setw(5)<<(n+1);
			cout<<setw(10)<<L.e[i].maHang;
			cout<<setw(30)<<L.e[i].tenHang;
			cout<<setw(30)<<L.e[i].tenNSX;
			cout<<setw(10)<<L.e[i].namSX;
			cout<<setw(10)<<L.e[i].gia<<endl;
			n++;
		}
	}
}
int main(){
	List L;
	nhapDS(L);
	cout<<"Danh sach vua nhap: "<<endl;
	hien_thi_ds(L);
//	int k;
//	cout<<"Nhap vi tri can bo sung: "; cin>>k;
//	if(Insert(L,k)==1){
//		cout<<"Danh sach vua bo sung\n";
//		hien_thi_ds(L);
//	}
//	else{
//		cout<<"Vi tri khong dung\n";
//	}
//	cout<<"Nhap vi tri can xoa: "; cin>>k;
//	if(Delete(L,k)==1){
//		cout<<"Danh sach sau khi xoa\n";
//		hien_thi_ds(L);
//	}
//	else{
//		cout<<"Vi tri khong dung";
//	}
	XoaMH_1998(L);
	hienThiIn4GiaMin(L);
	HienThiGiaTren5m(L);
}
