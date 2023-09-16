#include <iostream>
using namespace std;

void inNguoc(){
	char x;
	cin.get(x);
	if(x != '\n'){
		inNguoc();
	}
	cout<<x;
	
}
int main(){
	cout<<"Nhap vao chuoi: ";	
	inNguoc();
}
