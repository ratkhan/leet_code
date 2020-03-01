/* PROBLEM DESCRIPTION
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/
#pragma once
#ifndef UNIQUEPATHS_H
#define UNIQUEPATHS_H

#include <math.h>

long double factorial(long double n)
{
	if (n <= 1) return 1;
	long double result = n;
	for (long double i = n - 1; i > 0; i--)
	{
		result *= i;
	}
	return result;
}

int uniquePaths(int m, int n) {
	long double result = 0;
	long double x = factorial(m - 1 + n - 1);
	long double y = factorial(m - 1);
	long double z = factorial(n - 1);
	result = round(x / (y * z));
	return result;
}

#endif 