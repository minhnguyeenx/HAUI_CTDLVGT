#include <bits/stdc++.h>

using namespace std;

//vun dong
void Heapify(int x[], int n, int k){ //vun thanh dong
    if(k <= n/2-1){
        int j = 2*k+1; // con cua x[k] la x[j] va x[j+1]
        if(j < n-1 && x[j] > x[j+1])
            j++;
        if(x[k] > x[j]){ //x[k] nho hon 2 con
            swap(x[j], x[k]);
            Heapify(x, n, j);
        }
    }
}
void First_heap(int x[], int n){
    for(int k = n/2-1; k >= 0; k--){
        Heapify(x, n, k);
    }
}
void Heap_sort(int x[], int n){
    First_heap(x, n);
    for(int i = n-1; i >= 1; i--){
        swap(x[0], x[i]);
        Heapify(x, i, 0);
    }
}

int main(){
    int x[] =  {14, 24, 54, 84, 64, 94, 74};
    int n = sizeof(x)/sizeof(x[0]);
    cout << "Day sau khi sap xep: ";
    Heap_sort(x, n);
    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
}