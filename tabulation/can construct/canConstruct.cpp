#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

bool canConstruct(const string& targetWord, const vector<string>& wordBank){
	bool* arr = new bool[targetWord.length()+1];
	// INITIALIZATION
	*arr = true;
	for (int i = 1; i < targetWord.length() + 1; i++)
		*(arr+i) = false;
	// CAN?
	for (int i = 0; i < targetWord.length(); i++){
		if (*(arr+i) == true){
			for (int j = 0; j < wordBank.size(); j++){
				if (i+wordBank[j].length() > targetWord.length()) // if exceeds targetWord
					continue;
				if (targetWord[i] == wordBank[j][0]){ // if word from wordBank can add onto current word
					if (targetWord.find(wordBank[j], i) == i){ // if word from wordBank found in current index
						if (i+wordBank[j].length() == targetWord.length()){ // if targetWord reached
							return true;
						}
						*(arr+i+wordBank[j].length()) = true;
					}
				}
			}
		}
	}
	return *(arr+targetWord.length());
}

int main(int argc, char* argv[]){
	string word = argv[1];
	//vector<string> wordBank = {"ab", "abc", "cd", "def", "abcd", "aeff"};
	//vector<string> wordBank = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	//vector<string> wordBank = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	vector<string> wordBank = {"a", "p", "ent", "enter", "ot", "o", "t"};
	
	bool result = canConstruct(word, wordBank);
	if (result)
		cout << "CAN CONSTRUCT" << "\n";
	else
		cout << "CAN'T CONSTRUCT" << "\n";
	
	return 0;
}