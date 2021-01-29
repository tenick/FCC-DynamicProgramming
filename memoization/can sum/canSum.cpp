#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

bool canSum(int n, const vector<int>& arr, unordered_map<int, bool>* memo = new unordered_map<int, bool>()){
	if ((*memo).find(n) != (*memo).end())
		return (*memo)[n];
	if (n < 0)
		return false;
	if (n == 0)
		return true;
	
	for (int i =0; i<arr.size();i++){
		if (canSum(n-arr[i], arr, memo)){
			(*memo)[n] = true;
			return true;
		}
	}
	(*memo)[n] = false;
	return false;
}

int main(int argc, char* argv[]){
	vector<int> arr = {7, 14};
	ui n = stoi(argv[1]);
	cout << canSum(n, arr) << endl;
	return 0;
}