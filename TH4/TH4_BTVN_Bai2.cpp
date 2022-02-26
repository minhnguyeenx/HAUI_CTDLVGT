#include <bits/stdc++.h>

using namespace std;

void Selection_sort(string x[], int n){
    for(int i = 0; i < n-1; i++){
        int m = i;
        for(int j = i+1; j < n; j++){
        	if(x[m] > x[j]){
        		m = j;
        	}
        }
        string tg = x[m];
        x[m] = x[i];
        x[i] = tg;
    }   
}

int main(){
    string x[7] = {"John", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    Selection_sort(x, 7);
    for(int i = 0; i < 7; i++){
        cout << x[i] << " ";
    }
}
