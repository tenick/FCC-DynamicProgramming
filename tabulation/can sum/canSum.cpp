#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

bool canSum(int n, const vector<int>& nums){
	bool* canSumArr = (bool*)calloc(n+1, sizeof(bool));
	*canSumArr = 1;
	for(int i = 0; i < n; i++){
		if (*(canSumArr+i)){
			for(int j = 0; j < nums.size(); j++){
				if (i + nums[j] <= n) 
					*(canSumArr + i + nums[j]) = true;
			}
		}
	}
	bool answer = *(canSumArr+n);
	free(canSumArr);
	return answer;
}

int main(int argc, char* argv[]){
	vector<int> nums = {7, 14};
	ui n = stoi(argv[1]);
	cout << canSum(n, nums) << endl;
	return 0;
}