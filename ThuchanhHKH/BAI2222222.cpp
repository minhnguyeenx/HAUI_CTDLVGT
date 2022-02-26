#include <bits/stdc++.h>

using namespace std;

struct SINHVIEN{
	string Sbd, Hoten;
	float Tongdiem;
};

struct LIST{
	SINHVIEN e[1000];
	int count;
};
void NEWSINHVIEN(SINHVIEN &x){
	cout << "Nhap sbd: "; fflush(stdin); getline(cin, x.Sbd);
	cout << "Nhap ho ten: "; fflush(stdin); getline(cin, x.Hoten);
	cout << "Nhap tong diem: "; cin >> x.Tongdiem;
}
void INPUT_LIST(LIST &L){
	cout << "Nhap so sinh vien: "; cin >> L.count;
	for(int i = 0; i < L.count; i++){
		cout << "Nhap sinh vien thu " << i+1 << endl;
		NEWSINHVIEN(L.e[i]);
	}
}

void Title(){
	cout << left << setw(10) << "Stt";
	cout << left << setw(15) << "Sbd";
	cout << left << setw(30) << "Ho va ten";
	cout << left << setw(15) << "Tong diem" << endl;
}

void OUTPUT_LIST(LIST L){
	for(int i = 0; i < L.count; i++){
		cout << left << setw(10) << i+1;
		cout << left << setw(15) << L.e[i].Sbd;
		cout << left << setw(30) << L.e[i].Hoten;
		cout << left << setw(15) << L.e[i].Tongdiem << endl;
	}
}

void ADD(LIST &L, int k, SINHVIEN sv){
	for(int i = L.count; i > k; i--){
		L.e[i] = L.e[i-1];
	}
	L.e[k] = sv;
	L.count++;
}

int DELETE(LIST &L, int k, SINHVIEN sv){
    for(int i = k; i < L.count; i++){
        L.e[i] = L.e[i+1];
    }
    L.count--;
}
int main(){
	SINHVIEN sv;
	LIST L;
    int k;
	cout << endl << "Nhap danh sach sinh vien" << endl;
	INPUT_LIST(L);
	cout << endl << "\t\t\tDANH SACH DINH VIEN VUA NHAP" << endl;
	Title();
	OUTPUT_LIST(L);

    // do{
    //     cout << "Nhap vi tri can chen: "; cin >> k;
    // }while(k < 0 || k > L.count);
	// cout << "Nhap sinh vien can chen" << endl;
	// NEWSINHVIEN(sv);
	// ADD(L, k, sv);
	// cout << "\t\t\tDANH SACH SINH VIEN SAU KHI CHEN" << endl;
	// Title();
	// OUTPUT_LIST(L);

    do{
        cout << "Nhap vi tri can xoa: "; cin >> k;
    }while(k < 0 || k > L.count);
	DELETE(L, k, sv);
	cout << "\t\t\tDANH SACH SINH VIEN SAU KHI XOA" << endl;
	Title();
	OUTPUT_LIST(L);
}
