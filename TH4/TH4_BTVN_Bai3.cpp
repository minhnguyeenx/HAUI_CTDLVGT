#include <bits/stdc++.h>

using namespace std;

void Insertion_sort(string x[], int n){
    for(int i = 0; i < n; i++){
        string tam = x[i];
        int j = i-1;
        while(j > -1 && x[j] > tam){
        	x[j+1] = x[j];
        	j--;
        }
        x[j+1] = tam;
    }
}

int main(){
    string x[7] = {"John", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    Insertion_sort(x, 7);
    for(int i = 0; i < 7; i++){
        cout << x[i] << " ";
    }
}
