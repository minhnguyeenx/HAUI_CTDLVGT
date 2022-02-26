#include <bits/stdc++.h>

using namespace std;

struct Hocsinh{
    char Hovaten[30], Gioitinh[10];
    int Namsinh;
    float Diemtk;
};
struct List{
    int count;
    Hocsinh e[1000];
};
void Input(List &L){
    do{
        cout << "Nhap so sinh vien: "; cin >> L.count;

    }while(L.count <= 0);
    cout << "Nhap sanh sach hoc sinh" << endl;
    for(int i = 0; i < L.count; i++){
        cout << "\tNhap hoc sinh thu " << i+1 << endl;
        cout << "\tNhap ho va ten: "; fflush(stdin); gets(L.e[i].Hovaten);
        cout << "\tNhap gioi tinh: "; fflush(stdin); gets(L.e[i].Gioitinh);
        cout << "\tNhap nam sinh: "; cin >> L.e[i].Namsinh;
        cout << "\tNhap diem tong ket: "; cin >> L.e[i].Diemtk;
    } 
}
void Title(){
    cout << setw(30) << left << "Ho va ten";
    cout << setw(10) << left << "Gioi tinh";
    cout << setw(10) << left << "Nam sinh";
    cout << setw(10) << left << "Diem tk" << endl;
}
void Output(List L){
    Title();
    for(int i = 0; i < L.count; i++){
        cout << setw(30) << left << L.e[i].Hovaten;
        cout << setw(10) << left << L.e[i].Gioitinh;
        cout << setw(10) << left << L.e[i].Namsinh;
        cout << setw(10) << left << L.e[i].Diemtk << endl;        
    }
}
void Find(List L, float DTK){
    int cnt = 0;
    for(int i = 0; i < L.count; i++){
        if(DTK == L.e[i].Diemtk){
            cnt++;
        }
    }
    if(cnt == 0) cout << endl << "Khong co sinh vien nao hop le" << endl;
    else {
        cout << "Danh sach sinh vien hop le" << endl;
        Title();
        for(int i = 0; i < L.count; i++){
            if(DTK == L.e[i].Diemtk){
                cout << setw(30) << left << L.e[i].Hovaten;
                cout << setw(10) << left << L.e[i].Gioitinh;
                cout << setw(10) << left << L.e[i].Namsinh;
                cout << setw(10) << left << L.e[i].Diemtk << endl; 
            }
        }
    }
}
void B_search(List L, int l, int r, float key){
    int cnt = 0;
    if(r < l) cout << endl << "Khong co hoc sinh nao hop le" << endl;
    else{
        int m = (l+r)/2;
        if(L.e[m].Diemtk == key){
            cnt++;
            if(cnt == 1) Title();
            cout << setw(30) << left << L.e[m].Hovaten;
            cout << setw(10) << left << L.e[m].Gioitinh;
            cout << setw(10) << left << L.e[m].Namsinh;
            cout << setw(10) << left << L.e[m].Diemtk << endl; 
        }
        else if(L.e[m].Diemtk > key) 
            B_search(L, m+1, r, key);
        else 
            B_search(L, l, m-1, key);
    }
}
int main(){
    List L;
    Input(L);
    Output(L);
    char HT[30];
    float DTK;
    cout << "Nhap diem tong ket can tim kiem: ";
    cin >> DTK;
    Find(L, DTK);
    B_search(L, 0, L.count-1, DTK);
}