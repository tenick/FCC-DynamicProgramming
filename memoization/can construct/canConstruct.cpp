#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

bool canConstruct(const string& targetWord, const vector<string>& wordBank, unordered_map<string, bool>* memo = new unordered_map<string, bool>){
	if (memo->find(targetWord) != memo->end())
		return (*memo)[targetWord];
	if (targetWord.length() == 0)
		return true;
	
	//cout << "Target Word: " << targetWord << "\n";
	for (string word : wordBank) {
		// because std::string::erase also modifies the string itself, rather than just returning the removed result
		string targetWordCopy = targetWord;
		//cout << word << "\n";
		
		// find starting index of the string argument passed in std::string::find, returns std::string::npos (const max value of size_t = -1) if not found
		size_t removeAtIndex = targetWord.find(word);
		
		// means word is found inside targetWord
		if (removeAtIndex != targetWord.npos) {
			//cout << "Can construct using: " << word << "\n";
			
			// check if substring is not in the middle of the string
			if (removeAtIndex == 0) // remove this if you can insert inside substrings to construct the target string
				// early returns true if base case is satisfied, meaning possible to be constructed
				if (canConstruct(targetWordCopy.erase(removeAtIndex, word.length()), wordBank, memo)) {
					(*memo)[targetWord] = true;
					return true;
				}
		}
	}
	//cout << "can't construct: " << targetWord << "\n";
	(*memo)[targetWord] = false;
	return false;
}

int main(int argc, char* argv[]){
	string word = argv[1];
	//vector<string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
	//vector<string> wordBank = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	vector<string> wordBank = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	
	bool result = canConstruct(word, wordBank);
	if (result)
		cout << "CAN CONSTRUCT" << "\n";
	else
		cout << "CAN'T CONSTRUCT" << "\n";
	
	return 0;
}