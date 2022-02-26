#include <bits/stdc++.h>

using namespace std;

struct SINHVIEN{
	string Sbd, Hoten;
	float Tongdiem;
};

struct NODE{
	SINHVIEN infor;
	NODE *next;
}; 

typedef NODE *TRO;

void NEWSINHVIEN(SINHVIEN &x){
	cout << "Nhap sbd: "; fflush(stdin); getline(cin, x.Sbd);
	cout << "Nhap ho ten: "; fflush(stdin); getline(cin, x.Hoten);
	cout << "Nhap tong diem: "; cin >> x.Tongdiem;
}

void INPUT_LIST(TRO &L){
	SINHVIEN x;
	TRO P, Q;
	int Tieptuc;
	L = NULL;
	do{
		NEWSINHVIEN(x);
		P = new NODE;
		P->infor = x;P->next = NULL;
		if(L == NULL) L = P;
		else Q->next = P;
		Q = P;
		cout << "Ban muon tiep tuc nhap?(1/0); "; cin >> Tieptuc;
	}while(Tieptuc == 1);
}

void Title(){
	cout << left << setw(10) << "Stt";
	cout << left << setw(15) << "Sbd";
	cout << left << setw(30) << "Ho va ten";
	cout << left << setw(15) << "Tong diem" << endl;
}

void OUTPUT_LIST(TRO L){
	int i = 1;
	TRO Q = L;
	while(Q!=NULL){
		cout << left << setw(10) << i; i++;
		cout << left << setw(15) << Q->infor.Sbd;
		cout << left << setw(30) << Q->infor.Hoten;
		cout << left << setw(15) << Q->infor.Tongdiem << endl;
		Q = Q->next;
	}
}

int ADD(TRO &L, int k, SINHVIEN sv){
	TRO Q = L;
	int i = 0;
	while(Q!=NULL && i < k-1){
		Q = Q->next; i++;
	}
	if(!Q){
		cout << "Vi tri chen khong phu hop" << endl;
		return 0;
	}
	else{
		TRO P;
		P = new NODE;
		P->infor = sv; P->next = Q->next;
		Q->next = P;
		return 1;
	}
}
int main(){
	SINHVIEN sv;
	TRO L;
	cout << endl << "Nhap danh sach sinh vien" << endl;
	INPUT_LIST(L);
	cout << endl << "\t\t\tDANH SACH DINH VIEN VUA NHAP" << endl;
	Title();
	OUTPUT_LIST(L);
	cout << "Nhap sinh vien can chen" << endl;
	NEWSINHVIEN(sv);
	if(ADD(L, 3, sv)!=0){
		cout << "\t\t\tDANH SACH SINH VIEN SAU KHI CHEN" << endl;
		Title();
		OUTPUT_LIST(L);	
	}
	
}
