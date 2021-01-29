#include <bits/stdc++.h>
typedef unsigned long long int ull;
typedef unsigned int ui;

std::vector<int>* bestSum(int n, const std::vector<int>& arr){
	std::vector<std::vector<int>*>* table = new std::vector<std::vector<int>*>();
	// INITIALIZATION
	table->reserve(n+1);
	table->push_back(new std::vector<int>());
	for(int i = 0; i < n; i++)
		table->push_back(nullptr);
	
	// TABULATION
	for(int i = 0; i < n; i++){
		if ((*table)[i] != NULL){
			for(int j = 0; j < arr.size(); j++){
				if(i + arr[j] <= n){
					if ((*table)[i+arr[j]] == NULL){
						(*table)[i+arr[j]] = new std::vector<int>(*(*table)[i]);
						(*table)[i+arr[j]]->push_back(arr[j]);
					}
					if (i + arr[j] == n)
						return (*table)[n];
				}
			}
		}
	}
	delete(table);
	return nullptr;
}

int main(int argc, char* argv[]){
	ui n = std::stoi(argv[1]);
	std::vector<int> arr = {1, 2, 5, 25};
	//std::vector<int> arr = {2, 3, 5};
	//std::vector<int> arr = {3, 5, 4};
	//std::vector<int> arr = {7, 14};
	
	std::vector<int>* best = bestSum(n, arr);
	if (best == nullptr)
		std::cout << "NULL" << "\n";
	else {
		std::cout << "Elements: " << "\n";
		for (int val : *best)
			std::cout << val << "\t";
	}
	delete best;
	return 0;
}