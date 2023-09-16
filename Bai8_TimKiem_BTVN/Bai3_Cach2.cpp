#include <iostream>
using namespace std;
struct HocSinh {
	string hoTen;
	char gioiTinh;
	int namSinh;
	float diemTK;
};
void sapXep(HocSinh dsHocSinh[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			if(dsHocSinh[j].diemTK > dsHocSinh[j-1].diemTK){
				HocSinh tg = dsHocSinh[j];
				dsHocSinh[j] = dsHocSinh[j-1];
				dsHocSinh[j-1] = tg;
			}
		}
	}
}
int main() {
	const int N = 2;
	HocSinh dsHocSinh[N];
	for (int i = 0; i < N; i++) {
		cout << "Nhap thong tin hoc sinh thu " << i+1 << endl;
		cout << "Ho va ten: "; getline(cin, dsHocSinh[i].hoTen);
		cout << "Gioi tinh (M/F): "; cin >> dsHocSinh[i].gioiTinh;
		cout << "Nam sinh: "; cin >> dsHocSinh[i].namSinh;
		cout << "Diem tong ket: "; cin >> dsHocSinh[i].diemTK;
		cin.ignore();
		}	
		sapXep(dsHocSinh, N);	
		cout << "\nDanh sach hoc sinh da sap xep theo thu tu diem tong ket giam dan:\n";
		for (int i = 0; i < N; i++) {
		cout << i+1 << ". ";
		cout << dsHocSinh[i].hoTen << ", ";
		cout << dsHocSinh[i].gioiTinh << ", ";
		cout << dsHocSinh[i].namSinh << ", ";
		cout << dsHocSinh[i].diemTK << endl;
		}
	
	return 0;
}
