#include <iostream>
using namespace std;
void selectionSort(int x[], int n){
	for(int i = 0; i < n-1; i++){
		int m = i;
		for(int j = i+1; j < n; j++){
			if(x[j] > x[m]){
				m = j;
			}
		}
		int tg = x[i];
		x[i] = x[m];
		x[m] = tg;
	}
}
void in(int x[], int n){
	for(int i = 0; i < n; i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n = 15;
	int x[n] = {50, 8, 34, 6, 98, 17, 83, 25, 66, 42, 21, 59, 63, 71, 85};
	cout<<"Mang ban dau: ";
	in(x,n);
	selectionSort(x,n);
	cout<<"Sap giam dan: ";
	in(x,n);
}
