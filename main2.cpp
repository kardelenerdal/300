#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <utility>

using namespace std;

bool QueensLasVegas2(int n, int k, vector<int>& columns){

	bool successfull = true;
	set<int> allColumns;
	vector<int> newAvailableColumns;
	vector<pair<int,int>> usedColumns;
	for(int i=0; i<n; i++){
		allColumns.insert(i);
	}
	
	newAvailableColumns.assign(allColumns.begin(), allColumns.end());
	int r = 0;
	
	while(newAvailableColumns.size() >= 0 && r<k){
		if(newAvailableColumns.size() == 0){
			successfull = false;
			return successfull;
		}
		set<int> forbidden;
		int c = newAvailableColumns[rand() % newAvailableColumns.size()];

		columns[r] = c;
		r++;
		usedColumns.push_back(make_pair(c, r));
		for(int i=0; i<usedColumns.size(); i++){

			int when = usedColumns.at(i).second;
			int who = usedColumns.at(i).first;

			forbidden.insert(who);

			if(who+r-when+1 >= 0 && who+r-when+1 <=n-1){
				forbidden.insert(who + r - when+1);
			}
			if(who-r+when-1 >= 0 && who-r+when -1<=n-1){
				forbidden.insert(who - r + when-1);
			}
		}
	
		set<int> result;
		std::set_difference(allColumns.begin(), allColumns.end(), forbidden.begin(), forbidden.end(), std::inserter(result, result.end()));
		newAvailableColumns.assign(result.begin(), result.end());
	}	

	return successfull;
}

void printSolution(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(vector<vector<int>> board, int row, int col) {
	int N = board.size();
	for(int i=0; i<N; i++){
		if(board[row][i]){
			return false;
		}
	}

	for(int i=0; i<N; i++){
		if(board[i][col]){
			return false;
		}
	}
    
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0){
        if (board[i][j]) {
            return false;
        }
        i--;
        j--;
    }

    i = row;
    j = col;
    while (i >= 0 && j < N){
        if (board[i][j]){
            return false;
        }
        i--;
        j++;
     }   

    
    i = row;
    j = col;
    while(i < N && j >= 0){
        if(board[i][j]) {
            return false;
        }
        i++;
        j--;
    }
   
    i = row;
    j = col;
    while(i < N && j < N){
        if (board[i][j]){
            return false;
        }
        i++;
        j++;       
    }
    
    return true;

}

bool solveNQUtil(vector<vector<int>>& board, int k) {
	int N = board.size();
    if (k >= N)
        return true;
  
    for (int i = 0; i < N; i++) {
        if (isSafe(board, k, i)) {
            board[k][i] = 1;
  
            if (solveNQUtil(board, k+1)) {
            	return true;
            }
           
            board[k][i] = 0; // BACKTRACK
        }
    }
  
    return false;
}

bool solveNQ(int n, int k, vector<int> columns) {
	if(!QueensLasVegas2(n, k, columns)){
		printf("Solution does not exist \n");
		return false;
	}

    //int board[n][n];
    vector<vector<int>> board;
	board.resize(n, vector<int>(n, 0));

    for(int i=0; i<k; i++){
    	board[i][columns.at(i)] = 1;
    }

    if (solveNQUtil(board, k) == false) {
        printf("Solution does not exist \n");
        return false;
    }
    
  
    return true;
}


int main(int argc, char const *argv[]) {

	srand((unsigned int)time(NULL));

	int n = 6;
	int nofSuc6 = 0;
	vector<int> columnsfor6(n);
	cout << "--------------- 6 ---------------" << endl;
	for(int k=0; k<6; k++){
		for(int i = 0; i<10000; i++){
			if(QueensLasVegas2(n, k, columnsfor6)) {
				nofSuc6++;
			}
		}
		cout << "k is " << k << endl;
		cout << "Number of successfull placements is " << nofSuc6 << endl;
		cout << "Number of trials is " << 10000 << endl;
		cout << "Probability that it will come to a solution is " << nofSuc6/10000.0 << endl;
		nofSuc6 = 0;
	}


	n = 8;
	int nofSuc8 = 0;
	vector<int> columnsfor8(n);
	cout << "--------------- 8 ---------------" << endl;
	for(int k=0; k<8; k++){
		for(int i = 0; i<10000; i++){
			if(QueensLasVegas2(n, k, columnsfor8)) {
				nofSuc8++;
			}
		}
		cout << "k is " << k << endl;
		cout << "Number of successfull placements is " << nofSuc8 << endl;
		cout << "Number of trials is " << 10000 << endl;
		cout << "Probability that it will come to a solution is " << nofSuc8/10000.0 << endl;
		nofSuc8 = 0;
	}

	n = 10;
	int nofSuc10 = 0;
	vector<int> columnsfor10(n);
	cout << "--------------- 10 ---------------" << endl;
	for(int k=0; k<10; k++){
		for(int i = 0; i<10000; i++){
			if(QueensLasVegas2(n, k, columnsfor10)) {
				nofSuc10++;
			}
		}
		cout << "k is " << k << endl;
		cout << "Number of successfull placements is " << nofSuc10 << endl;
		cout << "Number of trials is " << 10000 << endl;
		cout << "Probability that it will come to a solution is " << nofSuc10/10000.0 << endl;
		nofSuc10 = 0;
	}

	return 0;

}