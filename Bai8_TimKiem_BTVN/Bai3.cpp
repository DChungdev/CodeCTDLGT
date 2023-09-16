#include <iostream>
#include <algorithm> // thý vi?n ð? s? d?ng hàm sort()
using namespace std;

struct HocSinh {
	string hoTen;
	char gioiTinh;
	int namSinh;
	float diemTK;
};

bool compare(HocSinh a, HocSinh b) {
	return a.diemTK > b.diemTK;
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
		cin.ignore(); // dùng de loai bo \n sau khi nhap so 
		}
		// sap xep theo thu tu diem tong ket giam dan
		sort(dsHocSinh, dsHocSinh+N, compare);
		
		// in ra
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
