#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> board = {
        {7,8,0,4,0,0,1,2,0},
        {6,0,0,0,7,5,0,0,9},
        {0,0,0,6,0,1,0,7,8},
        {0,0,7,0,4,0,2,6,0},
        {0,0,1,0,5,0,9,3,0},
        {9,0,4,0,6,0,0,0,5},
        {0,7,0,3,0,0,0,1,2},
        {1,2,0,0,0,7,4,0,0},
        {0,4,9,2,0,6,0,0,7}
        };

vector<vector<int>> actual = board;


void Print(vector<vector<int>> &bo){
	for(int i = 0; i<9; i++){
		if(i%3 == 0)
			puts("---------------------");
		for(int j = 0; j<9; j++){
			if(j%3 == 0){
				printf("|");
			}
			cout << bo[i][j] << " ";
			if(j == 8)
				cout << endl;
		}
	}

}


pair<int, int> find_empty(vector<vector<int>> &bo){

	pair<int, int> a;
	for(int  i =0; i<9; ++i){
		for(int j = 0; j<9; j++){
			if(bo[i][j] == 0){
				a = make_pair(i, j);
				return a;
			}
		}
	}

	a.first = -1;
	a.second = -1;
	return a;
}

bool valid(vector<vector<int>> &bo, int num, pair<int, int> pos){
	 //Row checking
	 //
	
	for(int  i =0; i<9; i++){
		if(bo[i][pos.second] == num && pos.first != i)
			return false;
	}

	//Column checking
	//
	
	for(int  i =0; i<9; i++){
		if(bo[pos.first][i] == num && pos.second != i)
			return false;
	}

	//Box Checking
	
	int box_x = (int) pos.second / 3;
	int box_y = (int) pos.first / 3;

	for(int i = box_y*3; i<box_y*3 + 3; i++){
		for(int j = box_x*3; j<box_x*3 + 3; j++){
			if(bo[i][j] == num && i != pos.first && j != pos.second)
				return false;
		}
	}

	return true;
}
bool solve(vector<vector<int>> &bo){
	int row = find_empty(bo).first;
	int col = find_empty(bo).second;

	pair<int, int> pos = make_pair(row, col);
	pair<int, int> nothing = make_pair(-1, -1);

	if(pos == nothing){
		return true;
	}
	else{
		for(int  i =1; i<10; i++){
			if(valid(bo, i, pos)){
				bo[row][col] = i;
			}
			else
				continue;
			if(solve(bo)){
				return true;
			}
		}
		bo[row][col] = 0;
	}

	return false;
}


	




int main(){
	bool thing = solve(board);

	Print(board);


	return 0;
}

