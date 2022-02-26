#include <bits/stdc++.h>

using namespace std;

struct Hocsinh{
	string Hovaten, Gioitinh;
	int Namsinh;
	float Diemtk;
};

struct List{
	Hocsinh e[10000];
	int count;
};

void Input(List &L){
	do{
		cout << "Nhap so hoc sinh: "; cin >> L.count;
	}while(L.count <= 0 || L.count > 10000);
	for(int i = 0; i < L.count; i++){
		cout << "Nhap thong tin hoc sinh thu " << i+1 << endl;
		cout << "Nhap ho va ten: ";fflush(stdin); getline(cin, L.e[i].Hovaten);
		cout << "Nhap gioi tinh: ";fflush(stdin); getline(cin, L.e[i].Gioitinh);
		cout << "Nhap nam sinh: "; cin >> L.e[i].Namsinh;
		cout << "Nhap diem tong ket: "; cin >> L.e[i].Diemtk;
	}
}
void Title(){
	cout << left << setw(30) << "Ho va ten";
	cout << left << setw(15) << "Gioi tinh";
	cout << left << setw(15) << "Nam sinh";
	cout << left << setw(15) << "Diemtk" << endl;
}
void Output(List L){
	Title();
	for(int i = 0; i < L.count; i++){
		cout << left << setw(30) << L.e[i].Hovaten;
		cout << left << setw(15) << L.e[i].Gioitinh;
		cout << left << setw(15) << L.e[i].Namsinh;
		cout << left << setw(15) << L.e[i].Diemtk << endl;
	}	
}
void Bubble_Sort(List &L){
	for(int i = 0; i < L.count-1; i++){
		for(int j = 0; j < L.count - i- 1; j++){
			if(L.e[j].Hovaten> L.e[j+1].Hovaten){
				Hocsinh tg = L.e[j];
				L.e[j] = L.e[j+1];
				L.e[j+1] = tg;
			}
		}
	}
}
int main(){
	List L;
	Input(L);
	cout << endl << "\t\t\tDANH SACH HOC SINH VUA NHAP" << endl;
	Output(L);
	Bubble_Sort(L);
	cout << endl << "\t\t\tDANH SACH HOC SINH SAP XEP THEO THU TU TU DIEN" << endl;
	Output(L);
}
