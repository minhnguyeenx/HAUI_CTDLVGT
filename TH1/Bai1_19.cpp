#include <bits/stdc++.h>

using namespace std;

long Bai1(long a, long b){
    if(b == 0)
        return a;
    else
        return Bai1(b, a%b);
}
long Bai2(int n){
    if(n == 0)
        return 1;
    else
        return n*Bai2(n-1);
}
long Bai3(int n){
    if(n == 0) 
        return 1;
    else
        return 2*Bai3(n-1);
}
long Bai4(int n){
    if(n <= 0)
        return 0;
    else
        return 2*n + Bai4(n-1);
}
long Bai5(int n){
    if(n == 1 || n == 2)
        return 1;
    else 
        return Bai5(n-1)+Bai5(n-2);
}
long Bai6(int n){
    if(n == 1) 
        return 4;
    else if(n == 2) 
        return 3;
    else 
        return Bai6(n-1)-Bai6(n-2)-1;
}
long Bai7(int m, int n){
    if(m == 0)
        return n+1;
    else if(n == 0)
        return Bai7(m-1, 1);
    else return 
        Bai7(m-1, Bai7(m, n-1));
}
long Bai8(int m, int n){
    if(n <= 0) 
        return m+1;
    else if(m <= 0) 
        return n+1;
    else 
        return Bai8(m-1, n)+Bai8(m, n-1);
}
long Bai9(int n){
    if( n == 1) 
        return 1;
    else{
        if(n%2 == 0) 
        return 2*Bai9(n-1)-1;
        
            else return 2*Bai9(n-1)+1;
    }
}
long Bai10(int n){
    if(n == 1) 
        return 1;
    else 
        return Bai10(n-1)*Bai10(n-1)+1;
}
long Bai11(int n, int a[], int x){
    if(n == 0) 
        return 0;
    else{
        if(a[n-1] == x)
            
                return Bai11(n-1, a, x)+1;
        else 
            return Bai11(n-1, a, x);
    }
}
long Bai12(int n, int a[]){
    if(n == 0) 
        return 0;
    else{
        
            return Bai12(n-1, a)+a[n-1];
    }
}
int Bai13(int n){
    if(n < 10) 
        return 1;
    else 
        return Bai13(n/10)+1;
}

long Bai14(int n){
    if(n == 0) 
        return 1;
    else 
        return n*Bai14(n-1);
}
long Bai15(int n){
    if(n== 0) 
        return 1;
    else 
        return (2*n-1)*Bai15(n-1);
}
long gt(int n){
    if(n == 0) 
        return 1;
    else 
        return n*gt(n-1);
}
long Bai16(int n){
    if(n == 1) 
        return 1;
    else 
        return gt(n)+Bai16(n-1);
}
long Bai17(int n){
    if(n == 1) 
        return 1;
    else 
        return n*n+Bai17(n-1);
}
long Bai19(int n){
    if(n == 0) 
        return 0;
    
        return Bai19(n/2)*10+(n%2);
}
void nhap(int n, int a[]){
    for(int i = 0; i < n; i++){
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
}
void xuat(int n, int a[]){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
void sort(int n, int a[]){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n;j++){
            if(a[i] > a[j]){
                int tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
}
int Binary_search(int n, int a[], int l, int r, int key){
    if(r < l) return -1;
    else{
        int m = (l+r)/2;
        if(a[m] == key) return m;
        else if(a[m] > key)
            return Binary_search(n, a, l, m-1, key);
        else
            return Binary_search(n, a, m+1, n, key);
    }
}
int main(){
    int m, n, x, y;
    long a;
    long b;
    //bai1
    cout << "Nhap so nguyen a: "; cin >> a;
    cout << "Nhap so nguyen b: "; cin >> b;
    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << Bai1(a, b) << endl;
    //bai2
    cout << "Nhap so nguyen n(n >= 0): "; cin >> n;
    cout << "n! = " << Bai2(n) << endl;
    //bai3
    cout << "Nhap so nguyen n(n >= 0): "; cin >> n;
    cout << "2^n = " << Bai3(n) << endl;
    //bai4
    cout << "Nhap so nguyen n: "; cin >> n;
    cout << "F(n) = " << Bai4(n) << endl;
    //bai5
    cout << "Nhap so nguyen n: "; cin >> n;
    cout << "F(n) = " << Bai5(n) << endl;
    //bai6
    cout << "Nhap so nguyen n: "; cin >> n;
    cout << "F(n) = " << Bai6(n) << endl;
    //bai7
    cout << "Nhap so nguyen m: "; cin >> m;
    cout << "Nhap so nguyen n: "; cin >> n;
    cout << "A(m,n) = " << Bai7(m, n) << endl;
    //bai8
    cout << "Nhap so nguyen m: "; cin >> m;
    cout << "Nhap so nguyen n: "; cin >> n;
    cout << "f(m,n) = " << Bai8(m, n) << endl;
    //bai9
    cout << "Nhap so nguyen n(n >= 1): "; cin >> n;
    cout << "F(n) = " << Bai9(n) << endl;
    //bai10
    cout << "Nhap so nguyen n(n>=1): "; cin >> n;
    cout << "F(n) = " << Bai10(n) << endl;
    //bai11
    cout << "Nhap so phan tu cua mang n(n>=1): "; cin >> n;
    int arr1[n];
    nhap(n, arr1);
    cout << "Nhap x: "; cin >> x;
    cout << "Cout so lan xuat hien cua x:  " << Bai11(n, arr1, x) << endl;
    //bai12
    cout << "Nhap so phan tu cua mang n(n>=1): "; cin >> n;
    int arr2[n];
    nhap(n, arr2);
    cout << "Tong cac phan tu trong mang: " << Bai12(n, arr2) << endl;
    //bai13
    cout << "Nhap so nguyen n: "; cin >> n;
    cout << "So chu so cua so " << n << " la: " << Bai13(n) << endl;
    //bai14
    cout << "Nhap so nguyen m: "; cin >> m;
    cout << "Nhap so nguyen y: "; cin >> y;
    cout << "F(n) = " << Bai14(m+y) << endl;
    //bai15
    cout << "Nhap so nguyen n(n >= 0): "; cin >> n;
    cout << "P(n) = " << Bai15(n) << endl;
    //bai16
    cout << "Nhap so nguyen n(n > 0): "; cin >> n;
    cout << "S(n) = " << Bai16(n) << endl;
    //bai7+18
    cout << "Nhap so nguyen n(n > 0): "; cin >> n;
    cout << "S(n) = " << Bai17(n) << endl;
    //bai19
    cout << "Nhap so nguyen n: "; cin >> n;
    cout << "F(n) = " << Bai19(n) << endl;
    //Timkiemnhiphan
    cout << "Nhap so phan tu cua mang: "; cin >> n;
    int arr3[n];
    nhap(n, arr3);
    sort(n, arr3);
    cout << "Mang da sap xep: "; xuat(n, arr3);
    cout << endl;
    int key;
    cout << "Nhap gia tri can tim kiem: "; cin >> key;
    int l = 0, r = n-1;
    if(Binary_search(n, arr3, l, r, key) == -1)
        cout << "Gia tri can tim khong co trong mang" << endl;
    else
        cout << "Gia tri can tim trong mang co vi tri: " << Binary_search(n, arr3, l, r, key) << endl;
}
