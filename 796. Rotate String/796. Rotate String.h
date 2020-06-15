/* PROBLEM DESCRIPTION
We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character 
to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea'
after one shift on A. Return True if and only if A can become B after some 
number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
*/
#ifndef STRINGMATCH_H
#define STRINGMATCH_H

#include <string>

bool StringMatch(std::string& A, std::string& B) {
	int length = A.size();
	//int count = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (A[i] == B[j])
			{
				for (int count = 1; count < length; count++)
				{
					if (A[(i + count) % length] == B[(j + count) % length])
					{
						if (count == length - 1) return true;
						continue;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	return false;
}

#endif // !STRINGMATCH_H