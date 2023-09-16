#include <iostream>
using namespace std;
int tinhTong(int a[], int left, int right){
	if(left == right){
		return a[left];
	}
	else{
		int mid = (left + right) / 2;
		int sumLeft = tinhTong(a,left,mid);
		int sumRight = tinhTong(a,mid+1,right);
		return sumLeft + sumRight;
	}
}
int main(){
	int n;
	cout<<"Nhap vao so phan tu mang: ";
	cin>>n;
	int a[n-1];
	cout<<"Nhap vao cac phan tu mang: "<<endl;
	for(int i = 0; i < n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	cout<<"Tong: "<<tinhTong(a,0,n-1);
}
