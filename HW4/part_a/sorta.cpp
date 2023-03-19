#include <string>
#include <vector>
#include <iostream>
#include "sorta.h"

/* C++ implementation of QuickSort */
#include <bits/stdc++.h>

void quicksort(char arr[], int left, int right)
{
    int i = left, j = right;
    char tmp;
    char pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}
// void remove_element(std::vector<char> &vec, char c)
// {
//     bool found = false;
//     int n = vec.size();
//     int ind_c;

//     for (int i : vec)
//     {
//         if (i == c)
//         {
//             found = true;

//             for (int j = i; j < n - 1; j++)
//             {
//                 myArray[j] = myArray[j + 1];
//             }

//             break;
//         }
//     }

//     return myArray;
// }

std::string sortByFreq(std::string s)
{
    std::string ret_s = "";
    int s_length = s.length();
    int characters[36] = {};

    // allocate an array of points
    std::string *char_occur[s_length];
    // 0 occurence should always point to null
    char_occur[0] = nullptr;
    // for each non zero occurence, allocate a vector of chars
    for (int i = 1; i < s_length; i++)
    {
        char_occur[i] = new std::string();
    }

    for (int i = 0; i < s_length; i++)
    {
        int int_c;
        if (isdigit(s[i]))
        {
            int_c = s[i] - '0';
        }
        else
        {
            int_c = static_cast<int>(s[i]) - 87;
        }

        if (characters[int_c] > 0)
        {
            size_t index = char_occur[characters[int_c]]->find(s[i]);
            char_occur[characters[int_c]]->erase(index, 1);
        }
        characters[int_c]++;
        for (int k = 0; k < characters[int_c]; k++)
        {
            *(char_occur[characters[int_c]]) += s[i];
        }
    }

    for (int j = 1; j < s_length; j++)
    {
        int c_size = char_occur[j]->size();
        char arr[c_size + 1];
        strcpy(arr, char_occur[j]->c_str());
        quicksort(arr, 0, c_size - 1);
        ret_s.append(arr, sizeof(arr) / sizeof(arr[0])); // add each array to the returning string in order
    }

    return ret_s; // you will need to change this
}

// // Driver Code
// int main()
// {
//     std::string str = "hello330";
//     std::string sorted = sortByFreq(str);

//     std::cout << sorted << std::endl;
// }