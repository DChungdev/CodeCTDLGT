#include <bits/stdc++.h>
using namespace std;
#define max 100
struct CanBo{
	char maCB[10];
	char tenDem[26];
	char ten[10];
	char queQuan[100];
	int tuoi;
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
int Add(List &L, CanBo X){
	if(Full(L)){
		cout<<"Danh sach day";
		return 0;
	}
	else{
		L.count++;
		L.e[L.count] = X;
		return 1;
	}
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
void NhapDS(List &L){
	Initialize(L);
	CanBo X;
	
	int n, i = 0;
	cout<<"Nhap vao so luong can bo: "; cin>>n;
	while(i<n){
		cout<<"Nhap vao can bo thu "<<i+1<<endl;
		NhapCB(X);
		if(!Add(L,X)){
			return;
		}
		i++;
	}	
}
void HienThiDS(List L){
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma CB";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(25)<<"Que quan";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(10)<<"Luong CB"<<endl;
	for(int i = 0; i <= L.count; i++){
		cout<<setw(5)<<(i+1);
		cout<<setw(10)<<L.e[i].maCB;
		cout<<setw(17)<<L.e[i].tenDem;
		cout<<setw(8)<<L.e[i].ten;
		cout<<setw(25)<<L.e[i].queQuan;
		cout<<setw(10)<<L.e[i].tuoi;
		cout<<setw(10)<<L.e[i].luongCB<<endl;
	}
}
void HienThiDuoi50(List L){
	cout<<setw(5)<<"STT";
	cout<<setw(10)<<"Ma CB";
	cout<<setw(25)<<"Ho va ten";
	cout<<setw(25)<<"Que quan";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(10)<<"Luong CB"<<endl;
	int n = 0;
	for(int i = 0; i <= L.count; i++){
		if(L.e[i].tuoi <= 50){
			cout<<setw(5)<<(n+1);
			cout<<setw(10)<<L.e[i].maCB;
			cout<<setw(17)<<L.e[i].tenDem;
			cout<<setw(8)<<L.e[i].ten;
			cout<<setw(25)<<L.e[i].queQuan;
			cout<<setw(10)<<L.e[i].tuoi;
			cout<<setw(10)<<L.e[i].luongCB<<endl;
			n++;
		}
	}
}
void Remove(List &L, int k){
	for(int i = k-1; i < L.count; i++){
		L.e[i] = L.e[i+1];
	}
	L.count--;
}
int DeleteThaiBinh(List &L, char *que){
	int i = 0, n = 0;
	while(i<=L.count){
		if(strcmp(L.e[i].queQuan,que)==0){
			Remove(L,i+1);
			i--;
			n++;
		}	
	i++;
	} 
	if(n==0){
		return 0;
	}
	else return 1;
}
int Insert(List &L, int k){
	CanBo X;
	if(!Full(L) && k>0 && k<=L.count+1){
		cout<<"Nhap vao thong tin can chen\n";
		NhapCB(X);
		for(int i = L.count+1; i >= k; i--){
			L.e[i] = L.e[i-1];
		}
		L.e[k-1] = X;
		L.count++;
		return 1;
	}
	else{
		return 0;
	}	
}
int main(){
	List L;
	NhapDS(L);
	cout<<"Danh sach vua nhap\n";
	HienThiDS(L);
	cout<<"=========================\n";
	cout<<"Danh sach can bo tu 50 tro xuong\n";
	HienThiDuoi50(L);
	cout<<"=========================\n";
	if(DeleteThaiBinh(L,"Thai binh")==1){
		cout<<"Danh sach sau khi xoa can bo que Thai binh\n";
		HienThiDS(L);	
	}
	else{
		cout<<"Khong co can bo que Thai binh\n";
	}
	cout<<"=========================\n";
	if(Insert(L,2)==1){
		cout<<"Danh sach sau khi them vao sau phan tu thu 3\n";
		HienThiDS(L);
	}
	else{
		cout<<"Vi tri khong dung";
	}
}
