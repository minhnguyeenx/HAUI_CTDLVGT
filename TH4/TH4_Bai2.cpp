#include <bits/stdc++.h>

using namespace std;

void Selection_sort(int x[], int n){
    for(int i = 0; i < n-1; i++){
        int m = i;
        for(int j = i+1; j < n; j++){
        	if(x[m] < x[j]){
        		m = j;
        	}
        }
        int tg = x[m];
        x[m] = x[i];
        x[i] = tg;
    }   
}

int main(){
    int x[10] = {34, 14, 24, 54, 84, 64, 94, 97, 74, 04};
    Selection_sort(x, 10);
    for(int i = 0; i < 10; i++){
        cout << x[i] << " ";
    }
}
