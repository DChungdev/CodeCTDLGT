#include <iostream>
using namespace std;

int dem(int x){
	if(x < 10){
		return 1;
	}
	else{
		return 1 + dem(x / 10);
	}
}
int main(){
	int x;
	cout<<"Nhap vao x: ";
	cin>>x;
	cout<<"So chu so cua "<<x<<": "<<dem(x);
}
