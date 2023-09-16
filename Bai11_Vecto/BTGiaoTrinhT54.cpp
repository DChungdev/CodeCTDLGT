#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
#define max 100
struct SINHVIEN{
	char maSV[10];
	char hoDem[26];
	char ten[10];
	int namSinh;
	double diemTK;
};
struct List{
	int count;
	SINHVIEN e[max];
};
void Initialize(List &L){
	L.count = -1;
}
int Full(List L){
	return L.count == max - 1;
}
int Empty(List L){
	return L.count == -1;
}
int Add(List &L, SINHVIEN X){
	if(Full(L)){
		return 0;
	}
	else{
		L.count++;
		L.e[L.count] = X;
		return 1;
	}
}
void nhapsv(SINHVIEN &sv){
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
void nhapDS(List &L){
	Initialize(L);
	SINHVIEN X;
	int i = 1;
	do{
		cout<<"Nhap sinh vien thu "<<i<<endl;
		nhapsv(X);
		if(strcmp(X.maSV,"***")==0){
			return;
		}
		if(!Add(L,X)){
			return;
		}
		i++;
	}while(1);
}
void hien_thi_ds(List L){
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma SV";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(10)<<"Nam sinh";
	cout<<setw(10)<<"Diem TK"<<endl;
	for(int i = 0; i <= L.count; i++){
		cout<<setw(5)<<(i+1);
		cout<<setw(10)<<L.e[i].maSV;
		cout<<setw(17)<<L.e[i].hoDem;
		cout<<setw(8)<<L.e[i].ten;
		cout<<setw(10)<<L.e[i].namSinh;
		cout<<setw(10)<<L.e[i].diemTK<<endl;
	}
}
void del_first(List &L){
	if(Empty(L)){
		return;
	}
	for(int i = 0; i < L.count; i++){
		L.e[i] = L.e[i+1];
	}
	L.count--;
}
int Search(List L, char *ma){
	int i = 0;
	while(i<=L.count && strcmp(L.e[i].maSV,ma)!=0){
		i++;
	}
	if(i<=L.count) return i+1;
	else return 0;
}
void Remove(List &L, int k){
	for(int i = k-1; i<L.count; i++){
		L.e[i] = L.e[i+1];
	}
	L.count--;
}
int Xoa_sv8089(List &L){
	int k = Search(L,"sv8089");
	if(k==0){
		return 0;
	}
	else{
		Remove(L,k);
		return 1;
	}
}
int Insert(List &L, int k){
	SINHVIEN X;
	if(!Full(L) && k<=L.count+2 && k>=1){
		cout<<"\nNhap sinh vine can bo sung\n";
		nhapsv(X);
		for(int i=L.count+1; i>=k; i--){
			L.e[i] = L.e[i-1];
		}
		L.count = L.count+1;
		L.e[k-1] = X;
		return 1;
	}
	else return 0;
}
void Lietke(List L){
	int i = 0, d = 0;
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma SV";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(10)<<"Nam sinh";
	cout<<setw(10)<<"Diem TK"<<endl;
	while(i<=L.count){
		if(strcmp(L.e[i].ten,"Doanh")==0){
			cout<<setw(5)<<(d+1);
			cout<<setw(10)<<L.e[i].maSV;
			cout<<setw(17)<<L.e[i].hoDem;
			cout<<setw(8)<<L.e[i].ten;
			cout<<setw(10)<<L.e[i].namSinh;
			cout<<setw(10)<<L.e[i].diemTK<<endl;
			d++;
		}
		i++;
	}
	if(d==0){
		cout<<"Khong co sinh vien ten Doanh"<<endl;
	}
}
void sort(List &L){
	for(int i = 0; i < L.count; i++){
		for(int j = L.count; j > i; j--){
			if(L.e[j].diemTK > L.e[j-1].diemTK){
				SINHVIEN tg = L.e[j];
				L.e[j] = L.e[j-1];
				L.e[j-1] = tg;
			}
		}
	}
}
int SortInsert(List &L){
	if(Full(L)){
		return 0;
	}
	SINHVIEN X;
	nhapsv(X);
	int i = L.count;
	while(i>=0 && L.e[i].diemTK<X.diemTK){
		L.e[i+1] = L.e[i];
		i--;
	}
	L.count++;
	L.e[i+1] = X;
}
int main(){
	List L;
	nhapDS(L);
	cout<<"Danh sach vua nhap\n";
	hien_thi_ds(L);
	cout<<"Danh sach sau khi xoa sv dau tien\n";
	del_first(L);
	hien_thi_ds(L);
	if(Xoa_sv8089(L)==1){
		cout<<"Danh sach sau khi xoa sv8089\n";
		hien_thi_ds(L);
	}
	else{
		cout<<"Khong co sinh vien ma sv8089\n";
	}
	//Insert sv
	int k;
	cout<<"Nhap vi tri bo sung: "; cin>>k;
	if(Insert(L,k)==1){
		cout<<"\nDanh sach sv vua bo sung\n";
		hien_thi_ds(L);
	}
	else{
		cout<<"Vi tri khong phu hop\n";
	}
	Lietke(L);
	sort(L);
	cout<<"Danh sach sau khi duoc sap xep giam theo diem\n";
	hien_thi_ds(L);
	//insert ko doi trat tu diem giam dan
	if(SortInsert(L)==0){
		cout<<"Danh sach day\n";
	}
	else{
		cout<<"\nDanh sach bo sung sau sap xep\n";
		hien_thi_ds(L);
	}
}
