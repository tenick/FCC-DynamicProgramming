#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

void display2dVector(vector<vector<string>> v){
	cout << "{" << "\n";
	for (vector<string> vec : v) {
		cout << "\t{";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i != vec.size()-1)
				cout << ", ";
		}
		cout << "}\n";
	}
	cout << "}" << "\n";
}

vector<vector<string>> allConstruct(const string targetWord, 
									const vector<string>& wordBank,
									unordered_map<string, vector<vector<string>>>* memo = new unordered_map<string, vector<vector<string>>>){
	if (memo->find(targetWord) != memo->end())
		return (*memo)[targetWord];
	if (targetWord.length() == 0)
		return {{}};
	
	vector<vector<string>> constructs = {};
	//cout << "Target Word: " << targetWord << "\n";
	for (string word : wordBank) {
		// find starting index of the string argument passed in std::string::find, returns std::string::npos (const max value of size_t = -1) if not found
		size_t removeAtIndex = targetWord.find(word);
		
		// check if substring is not in the middle of the string
		if (removeAtIndex == 0) {
			// because std::string::erase also modifies the string itself, rather than just returning the removed result
			string targetWordCopy = targetWord;
			
			vector<vector<string>> result = allConstruct(targetWordCopy.erase(removeAtIndex, word.length()), wordBank, memo);
			
			// inserting the word at the start
			for (int i = 0; i < result.size(); i++)
				result[i].insert(result[i].begin(), word);
			
			// merging result with constructs
			constructs.reserve(constructs.size() + result.size());
			constructs.insert(constructs.end(), result.begin(), result.end());
		}
	}
	(*memo)[targetWord] = constructs;
	return constructs;
}

int main(int argc, char* argv[]){
	string word = argv[1];
	//vector<string> wordBank = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
	//vector<string> wordBank = {"purp", "p", "ur", "le", "purpl"};
	//vector<string> wordBank = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	vector<string> wordBank = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	
	vector<vector<string>> result = allConstruct(word, wordBank);
	display2dVector(result);
	
	cout << result.size() << " way(s) to construct \"" << word << "\"\n";
	
	return 0;
}