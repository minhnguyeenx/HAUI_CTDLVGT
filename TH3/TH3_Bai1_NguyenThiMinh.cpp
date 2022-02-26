#include <bits/stdc++.h>

using namespace std;

void Input(int x[], int &n){
    cout << "Nhap so luong phan tu cua day: ";
    cin >> n;
    cout << "Nhap day so: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Nhap x[" << i << "] = ";
        cin >> x[i];
    }
}

int Find(int x[], int n, int &k){
    for(int i = 0; i < n; i++){
        if(x[i] == k) 
            return i;
    }
    return -1;
}

void Output(int x[], int n, int k){
    if(Find(x, n, k) == -1) cout << "So " << k << " khong co trong day" << endl;
    else {
        cout << "So " << k << " nam o vi tri " << Find(x, n, k)+1<< " trong day" << endl;
    }    
}
int main(){
    int n, x[10000];
    Input(x, n);
    int k1, k2;
    cout << "Nhap so nguyen k1 can tim kiem: "; cin >> k1;
    Output(x, n, k1);
    cout << "Nhap so nguyen k2 can tim kiem: "; cin >> k2;
    Output(x, n, k2);
}