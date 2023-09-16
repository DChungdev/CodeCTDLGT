#include <iostream>
using namespace std;
struct Balo{
	char v;
	int m;
	int c;	
};
void sapXep(Balo ds[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j > i; j--){
			int a = ds[j].c / ds[j].m;
			int b = ds[j-1].c / ds[j-1].m;
			if(a > b){
				Balo tg = ds[j];
				ds[j] = ds[j-1];
				ds[j-1] = tg;
			}
		}
	}
}
void hienThi(Balo ds[], int n){
	for(int i = 0; i < n; i++){
		cout<<i+1<<". ";
		cout<<ds[i].v<<", ";
		cout<<ds[i].m<<", ";
		cout<<ds[i].c<<endl;
	}
}
int main(){
	int n;
	cout<<"Nhap so do vat: ";
	cin>>n;
	Balo ds[n];
	for(int i = 0; i < n; i++){
		cout<<"Nhap thong tin do vat thu "<<i+1<<endl;
		cout<<"Nhap ky hieu do vat: "; cin>>ds[i].v;
		cout<<"Nhap khoi luong: "; cin>>ds[i].m;
		cout<<"Nhap gia tri: "; cin>>ds[i].c;
		cin.ignore();
	}
	cout<<"Danh sach ban dau: "<<endl;
	hienThi(ds,n);
	cout<<"Danh sach xep giam dan: "<<endl;
	sapXep(ds, n);
	hienThi(ds, n);
}
