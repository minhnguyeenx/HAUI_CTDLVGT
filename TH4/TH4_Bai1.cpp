#include <bits/stdc++.h>

using namespace std;

void Bubble_sort(int x[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(x[j] < x[j+1]){
                int tg = x[j];
                x[j] = x[j+1];
                x[j+1] = tg;
            }
        }
    }
}

int main(){
    int x[10] = {34, 14, 24, 54, 84, 64, 94, 97, 74, 04};
    Bubble_sort(x, 10);
    for(int i = 0; i < 10; i++){
        cout << x[i] << " ";
    }
}
