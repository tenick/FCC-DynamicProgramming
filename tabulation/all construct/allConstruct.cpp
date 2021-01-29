#include <bits/stdc++.h>
typedef unsigned long long int ull;
typedef unsigned int ui;

void display2dVector(std::vector<std::vector<std::string>> v){
	std::cout << "{" << "\n";
	for (std::vector<std::string> vec : v) {
		std::cout << "\t{";
		for (int i = 0; i < vec.size(); i++) {
			std::cout << vec[i];
			if (i != vec.size()-1)
				std::cout << ", ";
		}
		std::cout << "}\n";
	}
	std::cout << "}" << "\n";
}

std::vector<std::vector<std::string>> allConstruct(const std::string& targetWord, const std::vector<std::string>& wordBank){
	// INITIALIZATION
	std::vector<std::vector<std::vector<std::string>>> constructs = std::vector<std::vector<std::vector<std::string>>>(targetWord.length()+1);
	constructs[0].push_back({});
	
	// allConstruct
	for (int i = 0; i < targetWord.length(); i++){
		if (constructs[i].size() != 0){
			for (int j = 0; j < wordBank.size(); j++){
				if (i+wordBank[j].length() > targetWord.length()) // if exceeds targetWord
					continue;
				if (targetWord[i] == wordBank[j][0]){ // if word from wordBank can add onto current word
					if (targetWord.find(wordBank[j], i) == i){ // if word from wordBank found in current index
						std::vector<std::vector<std::string>> tempConstruct = constructs[i];
						for(int k = 0; k < constructs[i].size(); k++) // add each word inside each vector inside the 2d vector
							tempConstruct[k].push_back(wordBank[j]);
						
						// merging tempConstruct with 2d vector at constructs[i+wordBank[j].length()]
						int index = i+wordBank[j].length();
						constructs[index].reserve(constructs[index].size() + tempConstruct.size());
						constructs[index].insert(constructs[index].end(), tempConstruct.begin(), tempConstruct.end());
					}
				}
			}
		}
	}
	return constructs[targetWord.length()];
}

int main(int argc, char* argv[]){
	std::string word = argv[1];
	//std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
	//std::vector<std::string> wordBank = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	std::vector<std::string> wordBank = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	//std::vector<std::string> wordBank = {"a", "p", "ent", "enter", "ot", "o", "t"};
	//std::vector<std::string> wordBank = {"purp", "p", "ur", "le", "purpl"};
	
	display2dVector(allConstruct(word, wordBank));
	
	return 0;
}