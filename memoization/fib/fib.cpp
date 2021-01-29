#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

enum FibMethod {RECURSIVE, RECURSIVE_MEMOIZED, ITERATIVE};

ll fib(ll n){
	if (n <= 2)
		return 1;
	return fib(n - 2) + fib(n - 1);
}

ll fib_memoized(int n, unordered_map<ll, ll>* fibs_umap = new unordered_map<ll, ll>()){
	if ((*fibs_umap).find(n) != (*fibs_umap).end())
		return (*fibs_umap)[n];
	if (n <= 2)
		return 1;
	(*fibs_umap)[n] = fib_memoized(n - 2, fibs_umap) + fib_memoized(n - 1, fibs_umap);
	return (*fibs_umap)[n];
}

ll fib_iterative(int n){
    ll prev = 0;
    ll fib = 1;
    for (int i = 0; i < n-1; i++){
        ll temp = fib;
        fib += prev;
        prev = temp;
    }
	return fib;
}

int main(int argc, char* argv[]){
	string num = argv[1];
	int n = stoi(num);
	try {
		string fib_type = argv[2];
		int fib_method = stoi(fib_type);
		switch(fib_method){
			case RECURSIVE:
				cout << fib(n) << "\n";
				break;
			case RECURSIVE_MEMOIZED:
				cout << fib_memoized(n) << "\n";
				break;
			case ITERATIVE:
				cout << fib_iterative(n) << "\n";
				break;
			default:
				break;
		}
	}
	catch(...){
		cout << fib_memoized(n) << "\n";
	}
	
	return 0;
}