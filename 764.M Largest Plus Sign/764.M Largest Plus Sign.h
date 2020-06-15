/*
PROBLEM DESCRIPTION:
n a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells
 in the given list mines which are 0. What is the largest axis-aligned plus sign
 of 1s contained in the grid? Return the order of the plus sign. If there is none,
 return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along
with 4 arms of length k-1 going up, down, left, and right, and made of 1s. This
is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond
the arms of the plus sign, only the relevant area of the plus sign is checked for
1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
Example 1:

Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked
in bold.
*/


/*
EXAMPLE CALL:
	std::vector<std::vector<int>> zeros{ {4, 2} };
	std::cout << "Order of the largest plus sign in the matrix of size 5x5 with the 0
	in the position of {4,2} equals " << Solution().orderOfLargestPlusSign(5, zeros) << '\n';
*/

#ifndef ORDEROFLARGESTPLUSSIGN_H
#define ORDEROFLARGESTPLUSSIGN_H
#include <vector>
#include <algorithm>

int orderOfLargestPlusSign(int N, std::vector<std::vector<int>>& mines) {
	//int N = mines.size(); //probably compiler will optimize it, but just in case
	std::vector < std::vector<int>> matrix(N, std::vector<int>(N, 1));
	if (!mines.empty())
	{
		if (!mines[0].empty())
		{
			for (int i = 0; i < mines.size(); i++)
			{
				matrix[mines[i][0]][mines[i][1]] = 0;
			}
		}
	}
	int localMax = 0;
	int currentMax = 0;
	std::vector<int> armLength;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			int k = i;
			int m = j;
			int u = 0, d = 0, l = 0, r = 0; //counting the length sign up down left right. 
			if (matrix[k][m] == 1)
			{
				u = 1, d = 1, l = 1, r = 1;
			}
			else
			{
				continue;
			}
			m--;
			while (m >= 0)
			{

				if (matrix[k][m] == 1)
				{
					l++;
					m--;
					continue;
				}
				break;
			}

			m = j;
			m++;
			while (m < N)
			{
				if (matrix[k][m] == 1)
				{
					r++;
					m++;
					continue;
				}
				break;
			}
			m = j;
			k--;
			while (k >= 0)
			{
				if (matrix[k][m] == 1)
				{
					u++;
					k--;
					continue;
				}
				break;
			}

			k = i;
			k++;
			while (k < N)
			{
				if (matrix[k][m] == 1)
				{
					d++;
					k++;
					continue;
				}
				break;
			}
			k = i;
			armLength = { l,r,u,d };
			localMax = *std::min_element(armLength.begin(), armLength.end());
			if (localMax > currentMax)
			{
				currentMax = localMax;
			}
		}
	}
	return currentMax;
}
#endif