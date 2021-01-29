#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

vector<int>* bestSum(int n, const vector<int>& arr, unordered_map<int, vector<int>*>* memo = new unordered_map<int, vector<int>*>){
	if (memo->find(n) != memo->end())
		return (*memo)[n];
	if (n < 0)
		return nullptr;
	if (n == 0)
		return new vector<int>;
	
	vector<int>* bestSumVec = nullptr;
	
	for (int i=0; i<arr.size(); i++){
		vector<int>* resultingVector = bestSum(n-arr[i], arr, memo);
		if (resultingVector != nullptr){
			vector<int>* bestSumPartVec = new vector<int>;
			*bestSumPartVec = *resultingVector;
			bestSumPartVec->push_back(arr[i]);
			
			// updating bestSum vector
			if (bestSumVec == nullptr)
				bestSumVec = bestSumPartVec;
			else if (resultingVector->size() < bestSumVec->size())
				bestSumVec = bestSumPartVec;
		}
	}
	(*memo)[n] = bestSumVec;
	return bestSumVec;
}

int main(int argc, char* argv[]){
	ui n = stoi(argv[1]);
	vector<int> arr = {1, 2, 5, 25};
	
	vector<int>* best = bestSum(n, arr);
	if (best == nullptr)
		cout << "NULL" << "\n";
	else {
		cout << "Elements: " << "\n";
		for (int val : *best)
			cout << val << "\t";
	}
	delete best;
	return 0;
}