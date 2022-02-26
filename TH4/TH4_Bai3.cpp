#include <bits/stdc++.h>

using namespace std;

void Insertion_sort(int x[], int n){
    for(int i = 0; i < n; i++){
        int tam = x[i];
        int j = i-1;
        while(j > -1 && x[j] < tam){
        	x[j+1] = x[j];
        	j--;
        }
        x[j+1] = tam;
    }
}

int main(){
    int x[10] = {34, 14, 24, 54, 84, 64, 94, 97, 74, 04};
    Insertion_sort(x, 10);
    for(int i = 0; i < 10; i++){
        cout << x[i] << " ";
    }
}
