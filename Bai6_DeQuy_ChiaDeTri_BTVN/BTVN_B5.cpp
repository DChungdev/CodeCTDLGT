#include <iostream>
using namespace std;
void sapXep(int a[], int left, int right){
	if(left = right-1){
		if(a[left] > a[right]){
			int x = a[left];
			a[left] = a[right];
			a[right] = x;
		}
		
	}
	else{
		int mid = (left + right) / 2;
		sapXep(a,left,mid);
		sapXep(a,mid+1,right);
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
	sapXep(a,0,n-1);
	cout<<"Mang tang dan: ";
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}

}
