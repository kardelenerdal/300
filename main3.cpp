#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <utility>

using namespace std;


int minisuc6 = 0;
int miniunsuc6 = 0;
int minisuc8 = 0;
int miniunsuc8 = 0;
int minisuc10 = 0;
int miniunsuc10 = 0;



bool QueensLasVegas(int n, vector<int> columns, ostream& outfile,vector<string> &suc,vector<string> &unsuc){

	string result = "";
	bool successfull = true;
	set<int> availableColumns;
	vector<int> newAvailableColumns;
	vector<pair<int,int>> usedColumns;
	vector<string> mini;
	for(int i=0; i<n; i++){
		availableColumns.insert(i);
	}
	
	newAvailableColumns.assign(availableColumns.begin(), availableColumns.end());
	int r = 0;
	string a ="Step " + to_string(r+1) + ": Columns: ";
	outfile << "Step " << r+1 << ": Columns: ";
	string b;
	for(int i=0; i<columns.size(); i++){
		outfile << columns.at(i) << " ";
		b = b + to_string(columns.at(i)) + " ";
	}
	outfile << endl;
	mini.push_back(a + b);
	
	string a2 = "Step " + to_string(r+1) + ": Available: ";
	outfile << "Step " << r+1 << ": Available: ";
	string b2;
	for(int i=0; i<newAvailableColumns.size(); i++){
		outfile << newAvailableColumns.at(i) << " ";
		b2 = b2 + to_string(newAvailableColumns.at(i)) + " ";
	}
	outfile << endl;	
	mini.push_back(a2 + b2);
	
	
	
	while(newAvailableColumns.size() >= 0 && r<=n-1){
		if(newAvailableColumns.size() == 0){
			successfull = false;
			break;
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
		std::set_difference(availableColumns.begin(), availableColumns.end(), forbidden.begin(), forbidden.end(), std::inserter(result, result.end()));
		newAvailableColumns.assign(result.begin(), result.end());
		string x ="Step " + to_string(r+1) + ": Columns: ";
		
		outfile << "Step " << r+1 << ": Columns: ";
		string y;
		for(int i=0; i<columns.size(); i++){
			outfile << columns.at(i) << " ";
			y = y + to_string(columns.at(i)) + " ";
		}
		if(n==6 && ( minisuc6<3 || miniunsuc6<3 ) ){
			mini.push_back(x+y);
		}
		if(n==8 && ( minisuc8<3 || miniunsuc8<3 )) {
			mini.push_back(x+y);
		}
		if(n==10 && ( minisuc10<3 || miniunsuc10<3) ){
			mini.push_back(x+y);
		}
		outfile << endl;
		string x2 ="Step " + to_string(r+1) + ": Available: ";
		outfile << "Step " << r+1 << ": Available: ";
		string y2;
		for(int i=0; i<newAvailableColumns.size(); i++){
			outfile << newAvailableColumns.at(i) << " ";
			y2 = y2 + to_string(newAvailableColumns.at(i)) + " ";
		}
		if(n==6 && ( minisuc6<3 || miniunsuc6<3 )){
			mini.push_back(x2+y2);
		}
		if(n==8 && ( minisuc8<3 || miniunsuc8<3) ) {
			mini.push_back(x2+y2);
		}
		if(n==10 && ( minisuc10<3 || miniunsuc10<3)) {
			mini.push_back(x2+y2);
		}
		outfile << endl;

	}	

	if(successfull){
		outfile << "Successful" << endl;
		
		if(n==6){
			minisuc6++;
			if(minisuc6<3){
				string text="n=" + to_string(n) +", Successful:";
				string t;
				//outfilemini<<"n="<<n<<", Successful:"<<endl;
				
				for(int i=0; i<mini.size(); i++){
					//outfilemini << mini.at(i) << "\n";
					t = t + mini.at(i) + "\n";
				}
				suc.push_back(text);
				suc.push_back(t);
			}
		}
		if(n==8){
			minisuc8++;
			if(minisuc8<3){
				string text="n=" + to_string(n) +", Successful:";
				string t;
				//outfilemini<<"n="<<n<<", Successful:"<<endl;
				for(int i=0; i<mini.size(); i++){
					//outfilemini << mini.at(i) << "\n";
					t = t + mini.at(i) + "\n";
				}
				suc.push_back(text);
				suc.push_back(t);
			}
		}
		if(n==10){
			minisuc10++;
			if(minisuc10<3){
				string text="n=" + to_string(n) +", Successful:";
				string t;
				//outfilemini<<"n="<<n<<", Successful:"<<endl;
				for(int i=0; i<mini.size(); i++){
					//outfilemini << mini.at(i) << "\n";
					t = t + mini.at(i) + "\n";
				}
				suc.push_back(text);
				suc.push_back(t);
			}
		}
	} else {
		outfile << "Unsuccessful" << endl;
		if(n==6){
			miniunsuc6++;
			if(miniunsuc6<3){
				string text="n=" + to_string(n) +", Unsuccessful:";
				string t;
				//outfilemini<<"n="<<n<<", Unsuccessful:"<<endl;
				for(int i=0; i<mini.size(); i++){
					//outfilemini << mini.at(i) << "\n";
					t = t + mini.at(i) + "\n";
				}
				unsuc.push_back(text);
				unsuc.push_back(t);
			}
		}
		if(n==8){
			miniunsuc8++;
			if(miniunsuc8<3){
				string text="n=" + to_string(n) +", Unsuccessful:";
				string t;
				//outfilemini<<"n="<<n<<", Unsuccessful:"<<endl;
				for(int i=0; i<mini.size(); i++){
					//outfilemini << mini.at(i) << "\n";
					t = t + mini.at(i) + "\n";
				}
				unsuc.push_back(text);
				unsuc.push_back(t);
			}
		}
		if(n==10){
			miniunsuc10++;
			if(miniunsuc10<3){
				string text="n=" + to_string(n) +", Unsuccessful:";
				string t;
				//outfilemini<<"n="<<n<<", Unsuccessful:"<<endl;
				for(int i=0; i<mini.size(); i++){
					//outfilemini << mini.at(i) << "\n";
					t = t + mini.at(i) + "\n";
				}
				unsuc.push_back(text);
				unsuc.push_back(t);
			}
		}
	}
	
	

	return successfull;
}

void part1() {
	ofstream outfile6;
	ofstream outfile8;
	ofstream outfile10;	
	ofstream outfilemini;	
    outfile6.open("results_6.txt", fstream::out);
    outfile8.open("results_8.txt", fstream::out);
	outfile10.open("results_10.txt", fstream::out);
	outfilemini.open("results_mini.txt", fstream::out);

	vector<string> suc;
	vector<string> unsuc;

	
	int n = 6;
	int nofSuc6 = 0;
	vector<int> columnsfor6(n);
	for(int i=0; i<10000; i++){
		if(QueensLasVegas(n, columnsfor6, outfile6,suc,unsuc)){
			nofSuc6++;
		}
	}
	
	for(int i=0; i<suc.size(); i++){
		outfilemini<< suc[i]<<endl;
	}
	for(int i=0; i<unsuc.size(); i++){
		outfilemini<< unsuc[i]<<endl;
	}

	suc.clear();
	unsuc.clear();


	cout << "LasVegas Algorithm With n=" << 6 << endl;
	cout << "Number of successfull placements is " << nofSuc6 << endl;
	cout << "Number of trials is " << 10000 << endl;
	cout << "Probability that it will come to a solution is " << nofSuc6/10000.0 << endl;
	
	n=8;
	int nofSuc8 = 0;
	vector<int> columnsfor8(n);
	for(int i=0; i<10000; i++){
		if(QueensLasVegas(n, columnsfor8, outfile8,suc,unsuc)){
			nofSuc8++;
		}
	}

	for(int i=0; i<suc.size(); i++){
		outfilemini<< suc[i]<<endl;
	}
	for(int i=0; i<unsuc.size(); i++){
		outfilemini<< unsuc[i]<<endl;
	}

	suc.clear();
	unsuc.clear();

	cout << "LasVegas Algorithm With n=" << 8 << endl;
	cout << "Number of successful placements is " << nofSuc8 << endl;
	cout << "Number of trials is " << 10000 << endl;
	cout << "Probability that it will come to a solution is " << nofSuc8/10000.0 << endl;

	n=10;
	int nofSuc10 = 0;
	vector<int> columnsfor10(n);
	for(int i=0; i<10000; i++){
		if(QueensLasVegas(n, columnsfor10, outfile10,suc,unsuc)){
			nofSuc10++;
		}
	}

	for(int i=0; i<suc.size(); i++){
		outfilemini<< suc[i]<<endl;
	}
	for(int i=0; i<unsuc.size(); i++){
		outfilemini<< unsuc[i]<<endl;
	}

	

    cout << "LasVegas Algorithm With n=" << 10 << endl;
	cout << "Number of successful placements is " << nofSuc10 << endl;
	cout << "Number of trials is " << 10000 << endl;
	cout << "Probability that it will come to a solution is " << nofSuc10/10000.0 << endl;


}


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
		return false;
	}

    vector<vector<int>> board;
	board.resize(n, vector<int>(n, 0));

    for(int i=0; i<k; i++){
    	board[i][columns.at(i)] = 1;
    }

    if (solveNQUtil(board, k) == false) {
        return false;
    }
    
  
    return true;
}

void part2(){
	int n = 6;
	int nofSuc6 = 0;
	vector<int> columnsfor6(n);
	cout << "--------------- 6 ---------------" << endl;
	for(int k=0; k<6; k++){
		for(int i = 0; i<10000; i++){
			if(solveNQ(n, k, columnsfor6)) {
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
			if(solveNQ(n, k, columnsfor8)) {
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
			if(solveNQ(n, k, columnsfor10)) {
				nofSuc10++;
			}
		}
		cout << "k is " << k << endl;
		cout << "Number of successfull placements is " << nofSuc10 << endl;
		cout << "Number of trials is " << 10000 << endl;
		cout << "Probability that it will come to a solution is " << nofSuc10/10000.0 << endl;
		nofSuc10 = 0;
	}

}

int main(int argc, char const *argv[]) {
	srand((unsigned int)time(NULL));
	string arg = argv[1];
	if(arg.compare("part1") == 0){
		part1();
	} else {
		part2();
	}
	return 0;
}