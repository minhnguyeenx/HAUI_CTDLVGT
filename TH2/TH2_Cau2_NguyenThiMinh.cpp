#include <bits/stdc++.h>

using namespace std;

struct Dovat{
    float Trongluong, Giatri, Dongia;
};
void bubble_sort(Dovat a[], int n)
{
	for (int i =0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (a[j].Dongia > a[j+1].Dongia)
            {
                int tg = a[j].Dongia;
                a[j].Dongia = a[j+1].Dongia;
                a[j+1].Dongia = tg;
            }       
        }
    }
}
void nhap(Dovat a[], int &n, int &w){
    cout << "Nhap so luong do vat: "; cin >> n;
    cout << "Nhap trong luong toi da: "; cin >> w;
    for(int i = 0; i < n; i++){
        cout <<"Nhap do vat thu " << i+1 << endl;
        cout << "Nhap trong luong: "; cin >> a[i].Trongluong;
        cout << "Nhap gia tri: "; cin >> a[i].Giatri;
        a[i].Dongia = a[i].Giatri/a[i].Trongluong;
    }
}
//tham lam xep ba lo
void solve(Dovat a[], int n, int w){
    bubble_sort(a, n);
    cout << "So do vat cho vao balo: " << endl;
    for(int i = 0; i < n; i++){
        if(w >= a[i].Trongluong){
            w-=a[i].Trongluong;
            cout << a[i].Trongluong << " " << a[i].Giatri << endl;
        }
        else break;
    }

}
int main(){
    Dovat a[1000];
    int n, w;
    nhap(a, n, w);
    solve(a, n, w);
}