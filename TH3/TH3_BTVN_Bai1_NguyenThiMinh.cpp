#include <bits/stdc++.h>

using namespace std;

struct List{
    int count;
    string e[1000];
};
void Input(List &L){
    do{
        cout << "Nhap tu trong tu dien: "; cin >> L.count;

    }while(L.count <= 0);
    cout << "Nhap tu dien" << endl;
    for(int i = 0; i < L.count; i++){
        cout << "\tNhap tu thu " << i+1 << " : "; fflush(stdin);
        getline(cin, L.e[i]);
    } 
}

void Find(List L, string s1){
    for(int i = 0; i < L.count; i++){
        if(L.e[i] == s1) {
            cout << "Tu " << s1 << " co nam trong tu dien" << endl;
            return;
        }
    }
    cout << "Tu " << s1 << " khong nam trong tu dien" << endl;
}

void B_Search(List L, int l, int r, string s1){
    if(r < l) {
        cout << "Tu " << s1 << " Khong nam trong tu dien " << endl;
    }
    else{
        int m = (l+r)/2;
        if(L.e[m] == s1){
            cout << "Tu " << s1 << " co nam trong tu dien" << endl;
        }
        else if(L.e[m] > s1)
            B_Search(L, l, m-1, s1);
        else 
            B_Search(L, m+1, r, s1);
    }
}
int main(){
    List L;
    Input(L);
    string s1;
    cout << "Nhap tu can tim: "; getline(cin, s1);
    Find(L, s1);
    B_Search(L, 0, L.count-1, s1);
}