#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

int countConstruct(const string& targetWord, const vector<string>& wordBank, unordered_map<string, ull>* memo = new unordered_map<string, ull>){
	if (memo->find(targetWord) != memo->end())
		return (*memo)[targetWord];
	if (targetWord.length() == 0)
		return 1;
	
	ull count = 0;
	//cout << "Target Word: " << targetWord << "\n";
	for (string word : wordBank) {
		// find starting index of the string argument passed in std::string::find, returns std::string::npos (const max value of size_t = -1) if not found
		size_t removeAtIndex = targetWord.find(word);
		
		// because std::string::erase also modifies the string itself, rather than just returning the removed result
		string targetWordCopy = targetWord;
		
		// check if substring is not in the middle of the string
		if (removeAtIndex == 0) {
			ull result = countConstruct(targetWordCopy.erase(removeAtIndex, word.length()), wordBank, memo);
			count += result;
		}
	}
	(*memo)[targetWord] = count;
	return count;
}

int main(int argc, char* argv[]){
	string word = argv[1];
	//vector<string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
	//vector<string> wordBank = {"purp", "p", "ur", "le", "purpl"};
	//vector<string> wordBank = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	vector<string> wordBank = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	
	ull result = countConstruct(word, wordBank);
	cout << result << " way(s) to construct \"" << word << "\"\n";
	
	return 0;
}