#include <iostream>

int UCLN(int p, int q){
	if(p % q == 0){
		return q;
	}
	else{
		int r = p % q;
		return UCLN(q,r);
	}
}
int main(){
	int p,q;
	std :: cout<<"Nhap vao p: ";
	std::cin>>p;
	std :: cout<<"Nhap vao q: ";
	std::cin>>q;
	std::cout<<"UCLN = "<<UCLN(p,q);
}
