/*
Study Assignment-A classic problem that can be solved by backtracking is called the Eight
Queens problem, which comes from the game of chess. The chess board consists of 64
square arranged in an 8 by 8 grid. The board normally alternates between black and white
square, but this is not relevant for the present problem. The queen can move as far as she
wants in any direction, as long as she follows a straight line, Vertically, horizontally, or
diagonally. Write C++ program with recursive function for generating all possible
configurations for 4-queen's problem.
*/
#include<iostream>
using namespace std;
#define SIZE 8
class NQueen
{
private:
	int board[SIZE];
	int count;
public:
	NQueen();
	void Queen(int row, int n);
	void print_board(int n);
	int place(int row, int column);
};
NQueen::NQueen()//constructor defined for initialization of board
{
	count = 0;
	for (int i = 0; i < SIZE; i++)
		board[i] = 0;
}
/* By this function we try the next free slot
and check for proper positioning of queen
*/
void NQueen::Queen(int row, int n)
{
	int column;
	for (column = 1; column <= n; column++)
	{
		if (place(row, column))
		{
			board[row] = column;//no conflict so place queen
			if (row == n)//dead end
				print_board(n);//printing the board configuration
			else  //try next queen with next position
				Queen(row + 1, n);
		}
	}
}
/* This function is for printing the solution to n-queen's problem */
void NQueen::print_board(int n)
{
	int i, j;
	cout << "\n\nSolution#" << ++count << ":\n";
	cout << "-------------------------------------------\n";
	//number of solution
	for (i = 1; i <= n; i++)
	{
		cout << "\t" << i;
	}
	for (i = 1; i <= n; i++)
	{
		cout << "\n\n" << i;
		for (j = 1; j <= n; j++)// for  board
		{
			if (board[i] == j)
				cout << "\tQ";//Queen at i,j position
			else
				cout << "\t-";// empty slot
		}
	}
	cout << "\n";
}
/* This function is for checking for the conflicts.
If there is no conflict for the desired position
it returns 1 otherwise it returns 0
*/
int NQueen::place(int row, int column)
{
	int i;
	for (i = 1; i <= row - 1; i++)
	{ //checking for column and diagonal conflicts
		if (board[i] == column)
			return 0;
		else
			if (abs(board[i] - column) == abs(i - row))
				return 0;
	}
	//no conflicts hence Queen can be placed
	return 1;
}
int main()
{
	int n;
	NQueen obj;
	cout << "\n\t Program for n-Queen's Using Backtracking";
	cout << "\nEnter Number of Queen's: ";
	cin >> n;
	obj.Queen(1, n);//trace using basscktrack
	return 0;

}
