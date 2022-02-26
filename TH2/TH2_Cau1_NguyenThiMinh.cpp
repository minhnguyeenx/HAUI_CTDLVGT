#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int a[], int n)
{
	for (int i =0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (a[ j ]>a[ j + 1 ])
            {
                int tg = a[ j ];
                a[ j ] = a[ j +1];
                a[ j + 1] = tg;
            }       
        }
    }
}
void nhap(int a[], int &n, int &s){
    do{
        cout << "Nhap n: "; cin >> n;
    }while(n <= 0);
    for(int i = 0; i< n; i++){
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "Nhap s: "; cin >> s;
}
//tham lam tinh tong
void solve(int a[], int n, int s){
    bubble_sort(a, n);
    int cnt = 0, p = 0;
    for(int i = n-1; i >= 0; i--){
        p += a[i];
        cnt++;
        if(p > s){
            cout << "Tong p can tim: " << p << endl;
            return;
        }
    }
    cout << "Khong tim duoc tong p" << endl;
}
int main(){
    int a[1000];
    int n, s;
    nhap(a, n, s);
    solve(a, n, s);
}