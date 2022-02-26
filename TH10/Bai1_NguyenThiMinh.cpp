#include <bits/stdc++.h>

using namespace std;

double f(double a, int n){
	if(n == 0) return 1.0;
	else return a*f(a,n-1);
}
int main(){
	float a, n;
	a = 2.0; n = 7;
	cout << f(a, n);
}
