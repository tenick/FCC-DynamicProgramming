#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

void display2dArr(ull* arr, int r, int c){
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			printf("%d\t", *(arr+(i*c)+j));
		}
		printf("\n");
		printf("\n");
	}
}

ull gridTravel(ui r, ui c){
	ull arr[r][c] = {};
	arr[1][1] = 1;

	int minNum = min(r, c);
	
	//display2dArr((ull*)arr, r, c);
	
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			int R = i+1;
			int C = j+1;
			if (R != r & C != c){
				arr[R][j] += arr[i][j];
				arr[i][C] += arr[i][j];
			}
			else if (R == r & C != c)
				arr[i][C] += arr[i][j];
			else if (R!= r & C == c)
				arr[R][j] += arr[i][j];
		}
	}
	
	//display2dArr((ull*)arr, r, c);
	
	return arr[r-1][c-1];
}

int main(int argc, char* argv[]){
	ui r = stoi(argv[1]);
	ui c = stoi(argv[2]);
	cout << gridTravel(++r, ++c) << endl;
	return 0;
}