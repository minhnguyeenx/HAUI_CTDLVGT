#include <bits/stdc++.h>

using namespace std;

void Bubble_sort(int x[], int n){
	for(int i = 0; i< n-1; i++){
		for(int j = 0; j < n- i- 1; j++){
			if(x[j] < x[j+1]){
				int tg = x[j];
				x[j] = x[j+1];
				x[j+1] = tg;
			}
		}
	}
}
int main(){
	int x[] = {18, 73, 17, 56, 10, 86};
	int n = sizeof(x)/sizeof(x[0]);
	Bubble_sort(x, n);
	cout << "Mang sau khi sap xep giam dan: ";
	for(int i = 0; i < n; i++){
		cout << x[i] << " ";
	}
}
