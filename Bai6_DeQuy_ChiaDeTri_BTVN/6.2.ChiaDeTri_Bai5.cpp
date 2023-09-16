#include <iostream>
using namespace std;

int power(int a, int n){
	if(n == 0){
		return 1;
	}
	else if(n == 1){
		return a;
	}
	else{
		int x = power(a,n/2);
		if(n%2==0){
			return x*x;
		}
		else{
			return x*x*a;
		}
	}
}
int main(){
	int a, n;
	cout<<"Nhap vao a: ";
	cin>>a;
	cout<<"Nhap vao n: ";
	cin>>n;
	cout<<"a^n = "<<power(a,n);
}
