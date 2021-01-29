#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

vector<int>* howSum(int n, const vector<int>& arr, unordered_map<int, vector<int>*>* memo = new unordered_map<int, vector<int>*>){
	if (memo->find(n) != memo->end())
		return (*memo)[n];
	if (n < 0)
		return nullptr;
	if (n == 0)
		return new vector<int>;
	
	for (int i =0; i<arr.size();i++){
		vector<int>* resultingVector = howSum(n-arr[i], arr, memo);
		if (resultingVector != nullptr){
			resultingVector->push_back(arr[i]);
			(*memo)[n] = resultingVector;
			return resultingVector;
		}
	}
	(*memo)[n] = nullptr;
	return nullptr;
}

int main(int argc, char* argv[]){
	ui n = stoi(argv[1]);
	vector<int> arr = {7, 14};
	
	vector<int>* how = howSum(n, arr);
	if (how == nullptr)
		cout << "NULL" << "\n";
	else {
		cout << "Elements: " << "\n";
		for (int val : *how)
			cout << val << "\t";
	}
	delete how;
	return 0;
}