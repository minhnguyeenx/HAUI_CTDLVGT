#include <bits/stdc++.h>

using namespace std;

void Bubble_sort(string x[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(x[j] > x[j+1]){
                string tg = x[j];
                x[j] = x[j+1];
                x[j+1] = tg;
            }
        }
    }
}

int main(){
    string x[7] = {"John", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    Bubble_sort(x, 7);
    for(int i = 0; i < 7; i++){
        cout << x[i] << " ";
    }
}
