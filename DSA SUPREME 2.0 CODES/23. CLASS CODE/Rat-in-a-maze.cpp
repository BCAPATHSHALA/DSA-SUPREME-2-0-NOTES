// ✅Rat in a maze (Print all possible ways)
#include <iostream>
#include<vector>
#include<string>
using namespace std;

// isSafe() Function that will handle all the below mentioned possibilities:
// Condition 1: Out of bound
// Condition 2: Path Closed
// Condition 3: Check if position is already visited
bool isSafe(int newx, int newy, int maze[][4], int row, int col,  vector<vector<bool > > &visited) {
	if(
		(newx >=0 && newx <row) && (newy >=0 && newy < col) &&
		(maze[newx][newy] == 1) &&
		(visited[newx][newy] == false)
        ) {
		return true;
		}
	else {
		return false;
	}
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool > > &visited) {

	// Base Case --> Destination Coordinates are [row-1] and [col-1]
	if(srcx == row-1 && srcy == col-1) {
		// Reached to destination
		cout << output << endl;
		return;
	}

	//1 case hum solve karenge and baaki ka recursion sambhal lega for URDL
	// ✅UP (Rat/src move kab kar skta hu to yeh sab isSafe() method decide karega)
	int newx = srcx-1;
	int newy = srcy;
	if(isSafe(newx, newy,maze,row,col,visited )) {
		// Mark visited
		visited[newx][newy] = true;
		// Call recursion
		output.push_back('U');
		printAllPath(maze, row, col, newx, newy, output , visited );
		// Backtracking
		output.pop_back();
		visited[newx][newy] = false;
	}


	// ✅RIGHT
	newx = srcx;
	newy = srcy+1;
	if(isSafe(newx, newy,maze,row,col,visited )) {
		// Mark visited
		visited[newx][newy] = true;
		// Call recursion
		output.push_back('R');
		printAllPath(maze, row, col, newx, newy, output , visited );
		// Backtracking
		output.pop_back();
		visited[newx][newy] = false;
	}

	// ✅DOWN
	newx = srcx+1;
	newy = srcy;
	if(isSafe(newx, newy,maze,row,col,visited )) {
		// Mark visited
		visited[newx][newy] = true;
		// Call recursion
		output.push_back('D');
		printAllPath(maze, row, col, newx, newy, output , visited );
		// Backtracking
		output.pop_back();
		visited[newx][newy] = false;
	}


	// ✅LEFT
	newx = srcx;
	newy = srcy-1;
	if(isSafe(newx, newy,maze,row,col,visited )) {
		// Mark visited
		visited[newx][newy] = true;
		// Call recursion
		output.push_back('L');
		printAllPath(maze, row, col, newx, newy, output , visited );
		// Backtracking
		output.pop_back();
		visited[newx][newy] = false;
	}
	
}

int main() {

	int maze[4][4] = {
	{1,0,0,0},
	{1,1,0,0},
	{1,1,1,0},
	{1,1,1,1}
	};
	int row = 4;
	int col = 4;

	int srcx = 0;
	int srcy = 0;
	string output = "";

	// Create visited 2D array
	vector<vector<bool > > visited(row, vector<bool>(col, false));
	
	if(maze[0][0] == 0) {
		// src position is closed, that means RAT connot move
		cout << "No Path Exists" << endl;
	}
	else {
		visited[srcx][srcy] = true;
		printAllPath(maze, row, col, srcx, srcy, output, visited);
	}
	return 0;
}

/*
Example 01:
input: maze = 
{
	{1,1,0},
	{1,1,1},
	{0,0,1}
}
output: total possible way to achieve destination 
WAY 1 --> RDRD
WAY 2 --> DRRD

Example 02:
input: maze = 
{
	{1,0,0,0},
	{1,1,0,0},
	{1,1,1,0},
	{1,1,1,1}
}
output: total possible way to achieve destination 
WAY 1 --> DRDRDR
WAY 2 --> DRDDRR
WAY 3 --> DRDLDRRR
WAY 4 --> DDRRDR
WAY 5 --> DDRDRR
WAY 6 --> DDDRURDR
WAY 7 --> DDDRRR
*/