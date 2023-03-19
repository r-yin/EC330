#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>

#include "countOOO.h"
// your includes here


// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(std::vector<std::string> vec_cmp, std::vector<std::string> &vec, int const left, int const mid, int const right, int &count)
{
	auto const sub_one = mid - left + 1;
	auto const sub_two = right - mid;

	// Create temp vectors
	std::vector<std::string> left_vec(sub_one);
	std::vector<std::string> right_vec(sub_two);

	// Copy data to temp arrays left_vec[] and right_vec[]
	for (auto i = 0; i < sub_one; i++)
		left_vec[i] = vec[left + i];
	for (auto j = 0; j < sub_two; j++)
		right_vec[j] = vec[mid + 1 + j];

	auto ind_one = 0,	   // Initial index of first sub-vec
		ind_two = 0;	   // Initial index of second sub-vec
	int ind_merged = left; // Initial index of merged vec

	// Merge the temp vecs back into vec[left..right]
	while (ind_one < sub_one && ind_two < sub_two)
	{
		auto itr_l = std::find(vec_cmp.begin(), vec_cmp.end(), left_vec[ind_one]);
		auto itr_r = std::find(vec_cmp.begin(), vec_cmp.end(), right_vec[ind_two]);
		
		auto ind_l = std::distance(vec_cmp.begin(), itr_l);
		auto ind_r = std::distance(vec_cmp.begin(), itr_r);

		if ((ind_l - ind_r) <= 0) // if index of left value is small than the index of the right value, position unchanged
		{
			vec[ind_merged] = left_vec[ind_one];
			ind_one++;
		}
		else
		{
			// position needs to be swapped, then count increment
			count = count + ind_two + mid + 1 - ind_merged;
			vec[ind_merged] = right_vec[ind_two];
			ind_two++;
		}
		ind_merged++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (ind_one < sub_one)
	{
		vec[ind_merged] = left_vec[ind_one];
		ind_one++;
		ind_merged++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (ind_two < sub_two)
	{
		vec[ind_merged] = right_vec[ind_two];
		ind_two++;
		ind_merged++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(std::vector<std::string> vec_cmp, std::vector<std::string> &vec, int const begin, int const end, int &count)
{

	if (begin >= end)
		return; // Returns recursively


	auto mid = begin + (end - begin) / 2;
	mergeSort(vec_cmp, vec, begin, mid, count);
	mergeSort(vec_cmp, vec, mid + 1, end, count);
	merge(vec_cmp, vec, begin, mid, end, count);
}

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB)
{
	int count_ret = 0;

	// your implementation goes here
	// std::vector<std::vector<int>> A_temp(rankedListA.size());
	// std::vector<std::vector<int>> B_temp(rankedListB.size());

	// std::vector<int> A_ascii(rankedListA.size()); // create vector to hold ASCII values
	// std::vector<int> B_ascii(rankedListB.size()); // create vector to hold ASCII values


	mergeSort(rankedListB, rankedListA, 0, rankedListA.size()-1, count_ret);

	// int i = 0;
	// for(const std::string &s:rankedListA)
	// {
	// 	A_ascii[i] = static_cast<int>(s[0]);
	// 	i++;
	// }

	// i = 0;
	// for(const std::string &s:rankedListB)
	// {
	// 	B_ascii[i] = static_cast<int>(s[0]);
	// 	i++;
	// }


	// // print out vector of vector of ASCII values
	// for (auto x : rankedListA)
	// {
	// 	std::cout << x << " ";
	// }
	// std::cout << std::endl;

	// 	// print out vector of vector of ASCII values
	// for (auto x : rankedListB)
	// {
	// 	std::cout << x << " ";
	// }
	// std::cout << std::endl;

	// if ((countA == 0) ^ (countB == 0))
	// 	count++;
	return count_ret; // don"t forget to change this
}


// // Driver code
// int main()
// {
// 	std::vector<std::string> listA = {"Natural", "Hustler", "Legendary", "Glory"};
// 	std::vector<std::string> listB = {"Natural", "Legendary", "Glory", "Hustler"};
	
// 	int count = countOOO(listA, listB);
// 	std::cout << count << std::endl;
// 	// auto list_size = sizeof(listA) / sizeof(listA[0]);
// 	// printlist(l_ascii, list_size);


// 	// std::cout << "Given array is \n";
// 	// printArray(arr, arr_size);

// 	// mergeSort(arr, 0, arr_size - 1);

// 	// std::cout << "\nSorted array is \n";
// 	// printArray(arr, arr_size);
// 	return 0;
// }
