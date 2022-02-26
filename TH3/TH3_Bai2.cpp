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

void Bubble_sort(int a[], int n)
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

int B_search(int x[], int l, int r, int key){
    if(r < l) return -1;
    else{
        int m = (l+r)/2;
        if(x[m] == key) return m;
        else if(x[m] > key) return B_search(x, l, m-1, key);
        else return B_search(x, m+1, r, key);
    }
}

void Output(int x[], int n, int k){
    if(B_search(x, 0, n-1, k) == -1) cout << "So " << k << " khong co trong day" << endl;
    else {
        cout << "So " << k << " nam o vi tri " << B_search(x, 0, n-1, k)+1 << " trong day" << endl;
    }
}
int main(){
    int n, x[10000];
    Input(x, n);
    Bubble_sort(x, n);
    int k1, k2;
    cout << "Nhap so nguyen k1 can tim kiem: "; cin >> k1;
    Output(x, n, k1);
    cout << "Nhap so nguyen k2 can tim kiem: "; cin >> k2;
    Output(x, n, k2);
}