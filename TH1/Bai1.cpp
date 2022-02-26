#include <bits/stdc++.h>

using namespace std;
/*
input: 2 so nguyen a, b
output:
ucln =   a nếu b=0
        ucln(b,a%b)nếu b≥0
*/
long ucln(long a, long b){
    if(b == 0) return a;
    else return ucln(b, a%b);
}
int main(){
    long a, b;
    cout << "Nhap so nguyen a: "; cin >> a;
    cout << "Nhap so nguyen b: "; cin >> b;
    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << ucln(a, b);
}