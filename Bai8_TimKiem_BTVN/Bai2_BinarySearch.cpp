#include <iostream>
using namespace std;
int binarySearch(int x[], int l, int r, int k){
	if(l > r){
		return -1;
	}
	else{
		int m = (l + r) / 2;
		if(x[m] == k)
			return m;
		else if(x[m] > k){
			return binarySearch(x,l,m-1,k);
		}
		else{
			return binarySearch(x,m+1,r,k);
		}
	}
} 
int main(){
	int x[] = {04, 14, 24, 34, 54, 64, 74, 84, 94};
	int k;
	cout<<"Nhap vao so can tim: ";
	cin>>k;
	cout<<"So "<<k<<" can tim o vi tri thu "<<binarySearch(x,0,8,k)+1;
}
