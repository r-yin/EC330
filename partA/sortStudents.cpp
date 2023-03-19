// your includes here
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "sortStudents.h"

std::vector<int> sortStudents(std::vector<int> days, std::vector<int> ids) {
	/* your implementation here */
	int ind_cnt = 1;

	int ids_size = ids.size();
	int days_size = days.size();

	std::vector<int> days_out;

	/*
	 - loop through days by index
	 - if index range is within ids, check ocurrnece of ids[index] in days, add all to days_out
	 - if index out of range of ids, push_back each element in days while checking for duplicates
	*/
	for(int i = 0; i < ids_size; i++)
	{
		if (std::count(days_out.begin(), days_out.end(), ids[i]) == 0)
		{
			int occur_in_days = std::count(days.begin(), days.end(), ids[i]);
			// add number to days_out occur_in_days times
			for (int j = 0; j < occur_in_days; j++)
			{
				days_out.push_back(ids[i]);
				// std::cout << ids[i] << " ";
			}
		} else
		{
			ind_cnt++;
		}
	}

	for(int i = 0; i < days_size; i++)
	{
			// if days[i] has never been added to days_out
			// else skipp to next loop
			if (std::count(days_out.begin(), days_out.end(), days[i]) == 0)
			{
				int occur_in_days = std::count(days.begin(), days.end(), days[i]);
				// std::cout << days[i] << " " << std::endl;
				for (int j = 0; j < occur_in_days; j++)
				{
					days_out.push_back(days[i]);
					// std::cout << days[i] << " " << std::endl;
				}
			}
		
	}
	return days_out;
}

int main()
{
	std::vector<int> days_out;
	std::vector<int> days = {1, 4, 6, 8, 19, 23};
	std::vector<int> ids = {23, 19, 4, 6, 1};

	days_out = sortStudents(days, ids);

	for (int x : days_out)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;
	
	return 0;
}
