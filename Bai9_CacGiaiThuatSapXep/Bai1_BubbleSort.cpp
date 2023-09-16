#include <iostream>
using namespace std;
void bubbleSort(int x[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			if(x[j] > x[j-1]){
				int tg = x[j];
				x[j] = x[j-1];
				x[j-1] = tg;
			}
		}
	}
}
void in(int x[], int n){
	for(int i = 0; i < n; i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n = 6;
	int x[] = {34, 74, 94, 84, 54, 24};
	cout<<"Mang ban dau: ";
	in(x, n);
	bubbleSort(x, n);
	cout<<"Mang sau khi sap giam dan: ";
	in(x,n);
}
