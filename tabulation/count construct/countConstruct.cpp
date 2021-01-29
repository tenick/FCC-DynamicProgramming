#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

ull countConstruct(const string& targetWord, const vector<string>& wordBank){
	ull* arr = new ull[targetWord.length()+1];
	// INITIALIZATION
	*arr = 1;
	for (int i = 1; i < targetWord.length() + 1; i++)
		*(arr+i) = 0;
	
	for (int i = 0; i < targetWord.length(); i++){
		if (*(arr+i) != 0){
			for (int j = 0; j < wordBank.size(); j++){
				if (i+wordBank[j].length() > targetWord.length()) // if exceeds targetWord
					continue;
				if (targetWord[i] == wordBank[j][0]){ // if word from wordBank can add onto current word
					if (targetWord.find(wordBank[j], i) == i){ // if word from wordBank found in current index
						*(arr+i+wordBank[j].length()) += *(arr+i);
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
	//vector<string> wordBank = {"a", "p", "ent", "enter", "ot", "o", "t"};
	vector<string> wordBank = {"purp", "p", "ur", "le", "purpl"};
	
	cout << countConstruct(word, wordBank) << endl;
	
	return 0;
}