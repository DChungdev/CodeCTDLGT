#include <iostream>
using namespace std;
void chuyen(int n, char A, char B, char C){
	if(n == 1){
		cout<<"Chuyen "<<A<<" ----> "<<C<<endl;
	}
	else{
		chuyen(n - 1, A, C, B);
		chuyen(1, A, B, C);
		chuyen(n - 1, B, A, C);
	}
}
int main(){
	int n;
	char A = 'A', B = 'B', C = 'C';
	cout<<"Nhap vao n: "; cin>>n;
	chuyen(n,A,B,C);
}
