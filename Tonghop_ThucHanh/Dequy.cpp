#include <bits/stdc++.h>

using namespace std;

// tinh n!
long Factorial(int n){
    if(n == 0 || n == 1) return 1;
    else return Factorial(n-1);
}

//Fibonacci
long Fibonacci(int n){
    if(n == 1 || n == 2) return 1;
    else return Fibonacci(n-1)+Fibonacci(n-2);
}

//Hanoi Tower
void Tower(int n, char a, char b, char c){
    if(n == 1){
        cout << a << "---->" << c << endl;
        return;
    }
    Tower(n-1, a, c, b);
    Tower(1, a, b, c);
    Tower(n-1, b, a, c);
}

//sum
long Sum(int a[], int l, int r){
    if(l == r){
        return a[l];
    }
    else{
        int m = (l+r)/2;
        return Sum(a, l, m) + Sum(a, m+1, r);
    }
}

//count the number of times x appears in the sequence
int CountX(int a[], int l, int r, int x){
    if(l == r){
        if(a[l] == x) return 1;
        else return 0;
    }
    else{
        int m = (l+r)/2;
        return CountX(a, l, m, x)+CountX(a, m+1, r, x); 
    }
}

//count even numbers in the sequence
int CountEven(int a[], int l, int r){
    if(l == r){
        if(a[l]%2 == 0) return 1;
        else return 0;
    }
    else{
        int m = (l+r)/2;
        return CountEven(a, l, m)+CountEven(a, m+1, r);
    }
}
int main(){
    int n;
    int a[10000];
    cout << "n?  "; cin >> n;
    // tinh n!
    cout << "n! = " << Factorial(n) << endl;
    //Fibonacci
    cout << "Fibo(n) = " << Fibonacci(n) << endl;
    //Hanoi Tower
    Tower(n, 'A', 'B', 'C');
    //sum
    cout << "Array?" << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Sum == " << Sum(a, 0, n-1) << endl;
    //count the number of times x appears in the sequence
    int x;
    cout << "X?  "; cin >> x;
    cout << "Times = " << CountX(a, 0, n-1, x) << endl;
    //count even numbers in the sequence
    cout << "Even numbers = " << CountEven(a, 0, n-1) << endl;
}
