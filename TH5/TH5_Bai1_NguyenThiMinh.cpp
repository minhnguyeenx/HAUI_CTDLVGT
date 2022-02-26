#include <bits/stdc++.h>

using namespace std;

//sap xep phan doan
void Quick_sort(int x[], int n, int l, int r){
    if(l < r){
        int k = (l+r)/2;
        int t = x[k];
        int i = l;
        int j = r;
        do{
            while(x[i] > t) i++; // lấy số đầu tiên lớn hơn t
            while(x[j] < t) j--; //lấy số đầu tiên(từ cuối xuống) nhỏ hơn t
            if(i <= j){
                swap(x[i], x[j]);
                i++;
                j--;
            }
        }while(i <= j);
        Quick_sort(x, n, l, j);
        Quick_sort(x, n, i, r);
    }
}

int main(){
    int x[] =  {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(x)/sizeof(x[0]);
    cout << "Day sau khi sap xep: ";
    Quick_sort(x, n, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
}