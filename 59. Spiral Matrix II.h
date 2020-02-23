/*
Given a positive integer n, generate a square matrix filled with elements 
from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/*
EXAMPLE CALL:
std::vector<std::vector<int>> MATRIX (7, std::vector<int>(7, 0));
	MATRIX = generateMatrix(7);
*/

#pragma once
#ifndef SPIRALMATRIX_H
#define SPIRALMATRIX_H
#include <vector>
#include <string>


std::vector<std::vector<int>> generateMatrix(int n) {
	enum direction { UP, DOWN, LEFT, RIGHT };
	std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
	int count = 1;
	direction current_direction = RIGHT;
	for (int i = 0, j = 0; count <= n * n;)
	{
		switch (current_direction)
		{
		case RIGHT:
			if (j < n)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][j] = count;
					count++;
					j++;
				}
				else
				{
					current_direction = DOWN;
					j--;
					i++;
				}
			}
			else
			{
				current_direction = DOWN;
				j--;
				i++;
			}
			break;
		case DOWN:
			if (i < n)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][j] = count;
					count++;
					i++;
				}
				else
				{
					current_direction = LEFT;
					i--;
					j--;
				}
			}
			else
			{
				current_direction = LEFT;
				i--;
				j--;
			}
			break;
		case LEFT:
			if (j >= 0)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][j] = count;
					count++;
					j--;
				}
				else
				{
					current_direction = UP;
					j++;
					i--;
				}
			}
			else
			{
				current_direction = UP;
				j++;
				i--;
			}
			break;
		case UP:
			if (i >= 0)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][j] = count;
					count++;
					i--;
				}
				else
				{
					current_direction = RIGHT;
					i++;
					j++;
				}
			}
			else
			{
				current_direction = RIGHT;
				i++;
				j++;
			}
			break;
		}

	}
	return matrix;
}


#endif