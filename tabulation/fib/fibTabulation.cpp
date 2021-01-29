#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

ull fibTabulation(ui n){
	int arr[n+1] = {};
	arr[1] = 1;
	for (int i = 0; i < n; i++) {
		*(arr+i+1) = *(arr+i+1) + *(arr+i);
		*(arr+i+2) = *(arr+i+2) + *(arr+i);
	}
	return *(arr+n);
}

int main(int argc, char* argv[]){
	ui n = stoi(argv[1]);
	cout << fibTabulation(n) << endl;
	return 0;
}