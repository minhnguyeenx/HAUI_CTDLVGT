#include <bits/stdc++.h>

using namespace std;

struct SINHVIEN{
    string Mabd, Hovaten;
    float Diemtk;
};

struct NODE{
    SINHVIEN infor;
    NODE *next;
};

typedef NODE *TRO;

void NEWSINHVIEN(SINHVIEN &x){
    cout << "Nhap ma bao danh: "; fflush(stdin); getline(cin, x.Mabd);
    cout << "Nhap ho va ten: "; fflush(stdin); getline(cin, x.Hovaten);
    cout << "Nhap diem tong ket: "; cin >> x.Diemtk;
}

void INPUT(TRO &L){
    L = NULL;
    SINHVIEN x;
    TRO P, Q;
    int Tieptuc;
    do{
        NEWSINHVIEN(x);
        P = new NODE;
        P->infor = x; P->next = NULL;
        if(L == NULL) L = P;
        else Q->next = P;
        Q = P;
        cout << "Ban muon tiep tuc nhap(1/0): "; cin >> Tieptuc;
    }while(Tieptuc == 1);
}

void Title(){
    cout << left << setw(10) << "STT";
    cout << left << setw(10) << "mABD";
    cout << left << setw(10) << "Ho va ten";
    cout << left << setw(10) << "Diemtk" << endl;
}

void OUTPUT(TRO L){
    TRO Q = L; int i = 1;
    while(Q!=NULL){
        cout << left << setw(10) << i;i++;
        cout << left << setw(10) << Q->infor.Mabd;
        cout << left << setw(10) << Q->infor.Hovaten;
        cout << left << setw(10) << Q->infor.Diemtk << endl;
        Q = Q->next;
    }
}

void FIRST_ADD(TRO &L, SINHVIEN x){
    TRO P;
    P = new NODE;
    P->infor = x;P->next = L;
    L = P;
}

void LAST_ADD(TRO &L, SINHVIEN x){
    TRO P;
    P = new NODE;
    P->infor = x;
    if(!L){
        L = P;
        return;
    }
    TRO Q = L;
    while(Q->next){
        Q = Q->next;
    }
    Q->next = P;
}


int ADD1(TRO &L, int k){
	TRO Q = L;
	int i = 0;
    SINHVIEN x;
    cout << "Nhap sinh vien can them: " << endl;
    NEWSINHVIEN(x);
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
		P->infor = x; P->next = Q->next;
		Q->next = P;
		return 1;
	}
}

//them 1 sinh vien vao sau sinh vien co ma 123
void ADD2(TRO &L){
    TRO Q = L;
    SINHVIEN x;
    cout << "Nhap sinh vien can them: " << endl;
    NEWSINHVIEN(x);
    while(Q != NULL && Q->infor.Mabd != "123"){
        Q = Q->next;
    }
    if(!Q){
        cout << "Khong co mon hoc nao ma 123" << endl;
    }
    else{
        TRO P;
        P = new NODE;
        P->infor = x;
        P->next = Q->next; Q->next = P;
    }
}


void FIRST_DELETE(TRO &L){
    TRO Q = L;
    L = L->next;
    delete Q;
}

void LAST_DELETE(TRO &L){
    TRO Q = L, T;
    while(Q->next != NULL){
        T = Q;
        Q = Q->next;
    }
    T->next = NULL;
    delete Q;
}

void DELETE1(TRO &L, int k){
    TRO Q = L, T;
    int i = 0;
    while(Q!=NULL && i < k){
        T = Q;
        Q = Q->next;
        i++;
    }
    if(!Q) cout << "Vi tri xoa khong phu hop" << endl;
    else{
        TRO P;
        if(Q == L){
            L = L->next;
        }
        else{
            T->next = Q->next;
        }
        delete Q;
    }
}

void DELETE2(TRO &L){
    TRO Q = L, T;
    while(Q!= NULL && Q->infor.Mabd != "123"){
        T = Q; // t la node truoc node co ma 123
        Q = Q->next;
    }
    if(!Q) cout << "Khong co sinh vien nao ma 123" << endl;
    else {
        if(Q == L){
            L = L->next;
        }
        //node o giua, cuoi
        else{
            T->next = Q->next;
        }
        delete Q;
    }
}

//tim thong tin sinh vien co mabd "123"
void FIND(TRO L){
    TRO Q = L;
    while(Q != NULL && Q->infor.Mabd != "123"){
        Q = Q->next;
    }
    if(!Q) cout << "Khong co so bao danh nao la 123" << endl;
    else{
        cout << endl;
        cout << "Ma bd: " << Q->infor.Mabd << endl;
        cout << "Ho va ten: " << Q->infor.Hovaten << endl;
        cout << "Diem tk: " << Q->infor.Diemtk << endl;
    }
}

void FIX(TRO &L){
    TRO Q = L;
    while(Q != NULL && Q->infor.Mabd != "123"){
        Q = Q->next;
    }
    if(!Q) cout << "Khong co sinh vien nao co ma 123" << endl;
    else{
        Q->infor.Hovaten = "Da doi";
    }
}
int main(){
    TRO L;
    INPUT(L);
    cout << endl << "\t\t\tDANH SACH VUA NHAP" << endl;
    Title();
    OUTPUT(L);

    SINHVIEN x;
    // cout << endl << "SINH VIEN CAN THEM" << endl;
    // NEWSINHVIEN(x);

    // FIRST_ADD(L, x);
    // cout << endl << "\t\t\tDANH SACH THEM VAO DAU" << endl;
    // Title();
    // OUTPUT(L);

    // LAST_ADD(L, x);
    // cout << endl << "\t\t\tDANH SACH THEM VAO CUOI" << endl;
    // Title();
    // OUTPUT(L);

    // FIRST_DELETE(L);
    // Title();
    // OUTPUT(L);

    // LAST_DELETE(L);
    // Title();
    // OUTPUT(L);

    // DELETE1(L, 1);
    // Title();
    // OUTPUT(L);
    
    // DELETE2(L);
    // Title();
    // OUTPUT(L);

    // ADD1(L, 1);
    // Title();
    // OUTPUT(L);
    
    // ADD2(L);
    // Title();
    // OUTPUT(L);

    // FIND(L);

    // FIX(L);
    // Title();
    // OUTPUT(L);
}