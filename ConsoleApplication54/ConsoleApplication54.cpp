/*
github: mine counts 1

*/
#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int row;
	int col;
};
struct Cell {
	vector<Point> no_mine;
	vector<Point> mines;
	vector<Point> unkown;
};

vector<int> new_y{ -1, -1, -0, +1, +1 ,+1, -0, -1 };
vector<int> new_x{ -0, +1, +1, +1, -0, -1, -1, -1 };

void print32(Cell input) {
	for (const auto & point : input.mines) {
		cout << "(" << point.row << "," << point.col << ")";
	}
	for (const auto& point : input.no_mine) {
		cout << "(" << point.row << "," << point.col << ")";
	}

	for (const auto& point : input.unkown) {
		cout << "(" << point.row << "," << point.col << ")";
	}

}
void print(vector<vector<Cell>> input) {
	for (const auto& row : input) {
		for (const auto& cell : row) {
			print32(cell);
		}
		cout << "\n\n";
	}
	cout << "\n\n";
}

vector<vector<Cell>> find_mines(vector<vector<int>> mine_grid) {
	Cell tmp_cell{ {}, {}, {} };
	vector<Cell> tmp(mine_grid.size(),tmp_cell);
	int m = mine_grid.size();
	int n = mine_grid[0].size();
	int mines = 0;
	int no_mines = 0;
	int unkown = 0;
	vector < vector < Cell >> output(m, tmp);
	
	for (int row = 0; row < tmp.size(); row++) {
		for (int col = 0; col < mine_grid.size(); col++) {
			for (int i = 0; i < 8; i++) {
				

				if (col + new_y[i] < n && col + new_y[i] >= 0) {
					if (row + new_x[i] < m && row + new_x[i] >= 0) {
						if (mine_grid[row + new_x[i]][col + new_y[i]] == 1) {
							output[row][col].mines.push_back({ row, col });
						}
						if (mine_grid[row + new_x[i]][col + new_y[i]] == 0) {
							output[row][col].no_mine.push_back({ row, col });
						}

						if (mine_grid[row + new_x[i]][col + new_y[i]] == 2) {
							output[row][col].unkown.push_back({ row, col });
						}
					}
				}
			}

		}
	}
	return output;
}

int main()
{
	vector<vector<int>> input;
	vector<int> tmp1{ 0, 0, 1, 0 };
	vector<int> tmp2{ 0, 1, 2, 0 };
	vector<int> tmp3{ 0, 0, 0, 0 };
	vector<int> tmp4{ 1, 0, 2, 0 };
	input.push_back(tmp1);
	input.push_back(tmp2);
	input.push_back(tmp3);
	input.push_back(tmp4);
	vector<vector<Cell>> output = find_mines(input);
	print(output);
	return 0;

}