#include <bits/stdc++.h>

using namespace std;

struct MON{
    char Mamh[10], Tenmh[30];
    int Sotc;
};

struct NODE{
    MON infor;
    NODE *next;
};
typedef NODE *TRO;

void FIRST_ADD(TRO &L, MON m){
    TRO P;
    P = new NODE;
    P->infor = m;
    P->next = L;
    L = P;
}
void LAST_ADD(TRO &L, MON m){
    TRO P;
    P = new NODE;
    P->infor = m;
    if(!L){ //!L = L==NULL
        L = P;
        return;
    }
    TRO Q = L;
    while(Q->next){
        Q = Q->next;
    }
    Q->next = P;
}

void CREAT_MON(MON &m){
    cout << "Nhap ma mon: "; fflush(stdin); gets(m.Mamh);
    cout << "Nhap ten mon: "; fflush(stdin); gets(m.Tenmh);
    cout << "Nhap so tin chi: "; cin >> m.Sotc;
}

void INPUT_LIST(TRO &L){
    TRO P, Q;
    MON X;
    char Tieptuc;
    L = NULL;
    do{
        CREAT_MON(X);
        LAST_ADD(L, X);
    }while(strcmp(X.Mamh, "*") != 0);
}
void OUTPUT_LIST(TRO &L){
    int i = 1;
    TRO  Q = L;
    while(Q){ //Q = Q!=NULL
        cout << "Mon hoc thu " << i << endl;
        i++;
        cout << "\tMa mon: " << Q->infor.Mamh << endl;
        cout << "\tTen mon: " << Q->infor.Tenmh << endl;
        cout << "\tSo tin chi: " << Q->infor.Sotc << endl;
        Q = Q->next;
    }
}

void FIND_123(TRO L){
    TRO Q = L;
    while(Q != NULL && strcmp(Q->infor.Mamh, "123") != 0){
        Q = Q->next;
    }
    if(!Q) cout << "Khong co mon nao co ma MH la 123" << endl;
    else {
        cout << endl;
        cout << "\tMa mon: " << Q->infor.Mamh << endl;
        cout << "\tTen mon: " << Q->infor.Tenmh << endl;
        cout << "\tSo tin chi: " << Q->infor.Sotc << endl;
    }
}
void ADD_123(TRO &L){
    MON X;
    CREAT_MON(X);
    TRO Q = L;
    while(Q != NULL && strcmp(Q->infor.Mamh, "123") != 0){
        Q = Q->next;
    }
    if(!Q) cout << "Khong co mon hoc nao co ma 123" << endl;
    else{
        TRO P;
        P = new NODE;
        P->infor = X;
        P->next = Q->next;
        Q->next = P;
    }
    //OUTPUT_LIST(L);
}
void FIX_123(TRO &L){
    TRO Q = L;
    while(Q != NULL && strcmp(Q->infor.Mamh, "123") != 0){
        Q = Q->next;
    }
    if(Q == NULL) cout << "Khong co mon hoc nao ma 123" << endl;
    else {
        strcpy(Q->infor.Tenmh, "toan cao cap");
    }
}
void DELETE_123(TRO &L){
    TRO Q = L, T;
    while(Q!= NULL && strcmp(Q->infor.Mamh, "123") != 0){
        T = Q; // t la node truoc node co ma 123
        Q = Q->next;
    }
    if(!Q) cout << "Khong co mon hoc nao ma 123" << endl;
    else {
        //node o cuoi
        if(Q->next == NULL){
            T->next = NULL;
        }
        //node o dau
        else if(Q == L){
            L = L->next;
        }
        //node o giua
        else{
            T->next = Q->next;
        }
        delete Q;
    }
}
int main(){
    TRO L;
    cout << "Nhap danh sach: " << endl;
    INPUT_LIST(L);

    cout << endl << "Danh sach vua nhap: " << endl;
    OUTPUT_LIST(L);

    cout << endl << "Thong tin mon hoc ma la 123: ";
    FIND_123(L);

    cout << endl << "Them mon hoc X, chen sau mon hoc co ma 123: " << endl;
    ADD_123(L);
    OUTPUT_LIST(L);

    cout << endl << "Sua ten mon hoc co ma 123 thanh \"toan cao cap\" " << endl;
    FIX_123(L);
    OUTPUT_LIST(L);

    cout << endl << "Xoa mon hoc co ma 123" << endl;
    DELETE_123(L);
    OUTPUT_LIST(L);
}