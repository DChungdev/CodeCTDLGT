#include <iostream>
using namespace std;
void sap_giam_dan(int a[], int n){
	for(int i = 1; i < n; i++){
		int t = a[i];
		int j = i-1;
		while (j > -1 && t > a[j]){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;
	}
}
int greedy(int a[], int n, int s){
	sap_giam_dan(a, n);
	int i = 0, p = 0;
	while (i < n && p <= s){
		p += a[i];
		i++;
	}
	if (p > s) return i;
	else return -1;
}

void nhapMang(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}
int main(){
	int n;
	cout<<"Nhap vao so phan tu mang: ";
	cin>>n;
	int a[n];
	nhapMang(a,n);
	cout<<"So it nhat can lay: "<<greedy(a,n,10);
}
