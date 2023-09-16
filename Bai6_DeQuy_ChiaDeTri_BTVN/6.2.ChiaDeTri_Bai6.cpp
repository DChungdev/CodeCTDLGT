#include <iostream>
using namespace std;

int count(int a[], int x,int left, int right){
	if(left == right){
		if(x == a[right]){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		int mid = (left + right) / 2;
		return count(a,x,left,mid) + count(a,x,mid+1,right);
	}
}
int main(){
	int n,x;
	cout<<"Nhap vao so phan tu mang: ";
	cin>>n;
	int a[n-1];
	cout<<"Nhap vao cac phan tu mang: "<<endl;
	for(int i = 0; i < n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	cout<<"Nhap vao so can dem: ";
	cin>>x;
	cout<<"So lan xuat hien cua "<<x<<": "<<count(a,x,0,n-1);
}
