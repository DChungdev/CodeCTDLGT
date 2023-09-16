#include <iostream>
using namespace std;
int TKTT(int x[], int n, int k){
	int i = 0;
	while(i<n && x[i] != k){
		i++;
	}
	if(i < n) return i;
	return -1;
}
int main(){
	int n = 9;
	int x[n] = {34, 14, 24, 54, 84, 64, 94, 74, 4};
	int k = 94;
	if(TKTT(x,n,k) == -1){
		cout<<"Khong tim thay";
	}
	else{
	cout<<"So "<<k<<" o vi tri thu "<<TKTT(x,n,k)+1;
	}
}
