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

class Sudoku{
	private:
		pair<int, int> find_empty();
		bool valid(int num, pair<int, int> pos);
	public:
		vector<vector<int>> bo;
		bool solve();
		friend ostream& operator << (ostream& output, Sudoku& A);
};

pair<int, int> Sudoku::find_empty(){
	for(int i = 0; i<9; i++){
		for(int  j =0; j<9; j++){
			if(bo[i][j] == 0){
				return make_pair(i, j);
			}
		}
	}

	return make_pair(-1, -1);
}

bool Sudoku::valid(int num, pair<int, int> pos){
	//Row checking
	
	for(int  i =0; i<9; i++){
		if(bo[pos.first][i] == num and i != pos.second){
			return false;
		}
	}

	//Col checking
	
	for(int i = 0; i<9; i++){
		if(bo[i][pos.second] == num and i != pos.first){
			return false;
		}
	}

	//Box checking
	
	int box_x = floor(pos.second / 3);
	int box_y = floor(pos.first / 3);

	for(int i = box_y * 3; i < box_y *3 + 3; i++){
		for(int j = box_x * 3; j < box_x * 3 + 3; j++){
			if(bo[i][j] == num && i != pos.first && j != pos.second){
				return false;
			}
		}
	}

	return true;
}

bool Sudoku::solve(){
	pair<int, int> empty = find_empty();
	if(empty.first == -1 || empty.second == -1)
		return true;

	for(int i = 1; i<10; i++){
		if(valid(i, empty)){
			bo[empty.first][empty.second] = i;
		}
		else
			continue;
		if(solve())
			return true;
	}

	bo[empty.first][empty.second] = 0;


	return false;
}
ostream& operator<<(ostream& output, Sudoku& A){
	for(int i  =0; i<9; i++){
		if(i%3 == 0)
			output << "---------------------" << endl;
		for(int j = 0; j<9; j++){
			if(j %3 == 0)
				output << '|';
			output << A.bo[i][j] << " ";
			if(j == 8)
				output << endl;
		}
	}

	return output;
}

int main(){
	Sudoku A;
	A.bo = board;
	A.solve();
	cout << A << endl;


	return 0;
}

