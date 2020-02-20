/* PROBLEM DESCRIPTION
Given an array of integers that is already sorted in ascending order,
 find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that
 they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you 
may not use the same element twice.

Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

vector<int> twoSum(vector<int>& numbers, int target) {
    
        vector<int> result;
        if (numbers.empty()) return result;
        for (int i = 0; i < numbers.size();i++)
        {
            for (int j = i + 1; j < numbers.size(); j++)
            {
				//if sum is smaller choose a new j
                if (numbers[i] + numbers[j] < target) continue;
				//if found push back the indices into result
                else if (numbers[i] + numbers[j] == target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                }
				//if sum is larger than targer break from inner for loop and choose a new i
                else
                    break;
            }
			//if target is matched break from outer for loop as well
            if (!result.empty()) break;
        }
    return result;
    }