#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

ull gridTravel(ui r, ui c, unordered_map<pair<int, int>, ull, hash_pair>* gridsTravelled_umap = new unordered_map<pair<int, int>, ull, hash_pair>){
	pair<int, int> p1 = pair<int, int>(r, c);
	pair<int, int> p2 = pair<int, int>(c, r);
    if ((*gridsTravelled_umap).find(p1) != (*gridsTravelled_umap).end())
        return (*gridsTravelled_umap)[p1];
	else if ((*gridsTravelled_umap).find(p2) != (*gridsTravelled_umap).end())
		return (*gridsTravelled_umap)[p2]; 
	if (r == 0 | c == 0)
		return 0;
	if (r == 1 & c == 1)
		return 1;
	(*gridsTravelled_umap)[p1] = gridTravel(r - 1, c, gridsTravelled_umap) + gridTravel(r, c - 1, gridsTravelled_umap);
	return (*gridsTravelled_umap)[p1];	
}

int main(int argc, char* argv[]){
	ui r = stoi(argv[1]);
	ui c = stoi(argv[2]);
	cout << gridTravel(r, c) << endl;
	return 0;
}