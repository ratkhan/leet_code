/*
Given a string date representing a Gregorian calendar date formatted
as YYYY-MM-DD, return the day number of the year.

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61

Constraints:
date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
*/

/*
EXAMPLE CALL:
	dayOfYear("2003-03-01")
*/
#pragma once
#ifndef COUNTDAYS_H
#define COUNTDAYS_H
#include <vector>
#include <string>

bool isLeapYear(int);

int dayOfYear(std::string date) {
	std::vector<int> DayInMonth{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	std::string year_str = date.substr(0, 4);
	int year_int = stoi(year_str);

	int month = stoi(date.substr(5, 2));

	int day = stoi(date.substr(8, 2));

	int NumberOfDays = 0;

	if (isLeapYear(year_int))
	{
		DayInMonth[2] += 1;
	}

	for (int i = 1; i < month; i++)
	{
		NumberOfDays += DayInMonth[i];
	}

	NumberOfDays += day;

	return NumberOfDays;

}

bool isLeapYear(int year) {
	if (year % 4== 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}

#endif