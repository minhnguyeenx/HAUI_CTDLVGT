#include <bits/stdc++.h>

using namespace std;

struct Taisan{
    char Mats[10], Tents[30], Tinhtrangts[15];
    long Giatrits;
};
struct List{
    int count;
    Taisan e[1000];
};
void Input(List &L){
    do{
        cout << "Nhap so tai san: "; cin >> L.count;

    }while(L.count <= 0);
    cout << "Nhap sanh sach tai san" << endl;
    for(int i = 0; i < L.count; i++){
        cout << "\tNhap tai san thu  " << i+1 << endl;
        cout << "\tNhap ma tai san: "; fflush(stdin); gets(L.e[i].Mats);
        cout << "\tNhap ten tai san: "; fflush(stdin); gets(L.e[i].Tents);
        cout << "\tNhap gia tri tai san: "; cin >> L.e[i].Giatrits;
        cout << "\tNhap tinh trang tai san: "; fflush(stdin); gets(L.e[i].Tinhtrangts);
    } 
}
void Title(){
    cout << setw(10) << left << "Ma ts";
    cout << setw(30) << left << "Ten ts";
    cout << setw(20) << left << "Gia tri";
    cout << setw(15) << left << "Tinh trang" << endl;
}
void Output(List L){
    Title();
    for(int i = 0; i < L.count; i++){
        cout << setw(10) << left << L.e[i].Mats;
        cout << setw(30) << left << L.e[i].Tents;
        cout << setw(20) << left << L.e[i].Giatrits;
        cout << setw(15) << left << L.e[i].Tinhtrangts << endl;        
    }
}
void Find(List L, char *MA){
    int cnt = 0;
    for(int i = 0; i < L.count; i++){
        if(strcmp(L.e[i].Mats,MA) == 0){
            cnt++;
        }
    }
    if(cnt == 0) cout << endl << "Khong co sinh vien nao hop le" << endl;
    else {
        cout << "Danh sach sinh vien hop le" << endl;
        Title();
        for(int i = 0; i < L.count; i++){
            if(strcmp(L.e[i].Mats,MA) == 0){
                cout << setw(10) << left << L.e[i].Mats;
                cout << setw(30) << left << L.e[i].Tents;
                cout << setw(20) << left << L.e[i].Giatrits;
                cout << setw(15) << left << L.e[i].Tinhtrangts << endl; 
            }
        }
    }
}
void B_search(List L, int l, int r, long key){
    int cnt = 0;
    if(r < l) cout << endl << "Khong co hoc sinh nao hop le" << endl;
    else{
        int m = (l+r)/2;
        if(L.e[m].Giatrits == key){
            cnt++;
            if(cnt == 1) Title();
            cout << setw(10) << left << L.e[m].Mats;
            cout << setw(30) << left << L.e[m].Tents;
            cout << setw(20) << left << L.e[m].Giatrits;
            cout << setw(15) << left << L.e[m].Tinhtrangts << endl; 
        }
        else if(L.e[m].Giatrits > key) 
            B_search(L, m+1, r, key);
        else 
            B_search(L, l, m-1, key);
    }
}
int main(){
    List L;
    Input(L);
    Output(L);
    char MA[100];
    cout << "Nhap ma ts can tim kiem: ";fflush(stdin); gets(MA);
    Find(L, MA);

    long GT;
    cout << "Nhap gia tri tai san can tim kiem: "; cin >> GT;
    B_search(L, 0, L.count-1, GT);
}