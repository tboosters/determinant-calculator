#include <iostream>
#include <vector>

using namespace std;

void init(int n, vector< vector<float> >& d){
	cout << "Please enter your determinant row by row. Separate the elements with spaces." << endl;
	for(int i = 0; i < n; i++){
		cout << "Row " << i+1 << ": " << endl;
		int j = 0;
		while(j < n){
			float dummy = -999;
			cin >> dummy;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "Invalid input! Please re-enter the row: ";
				j = 0;
			}else{
				d[i][j] = dummy;
				j++;
			};
		};
	};

	cout << "Your matrix: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << d[i][j];
			if(j == n-1){
				cout << endl;
			}else{
				cout << " ";
			};
		};
	};
};

float dc(int n, vector< vector<float> > d){
	vector< vector<float> > next(n,vector<float>(n,0));
	float det = 0;

	if(n == 1){
		det = d[0][0];
		return det;
	};
	if(n == 2){
		det = d[0][0]*d[1][1]-d[0][1]*d[1][0];
		return det;
	};

	for(int c = 0; c < n; c++){  //using first row to find coherent
		int y = 0, x = 0;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < n; j++){
				if(j != c){
					next[y][x] = d[i][j];
					x++;
				};
			};
			y++;
			x = 0;
		};
		if(c%2 == 0){
			det += d[0][c] * dc(n-1, next);
		}else{
			det -= d[0][c] * dc(n-1, next);
		};	
	};
	return det;
};



int main(){
	int n;
	cout << "Welcome to the Determinant Calculator. Please enter the size of your determinant: ";
	cin >> n;
	vector< vector<float> > d(n,vector<float>(n,0));
	init(n, d);
	cout << endl << "The determinant is: " << dc(n, d) << endl;
	cout << "Press enter to exit...";
	cin.ignore(1024, '\n');
	cin.get();
	return 0;
};