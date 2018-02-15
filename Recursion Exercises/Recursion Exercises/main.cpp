#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "TestCases.hpp"

std::string collapseSpaces(std::string s);
std::vector<std::string> split(std::string s);
int partition(std::vector<int>& data, int start, int end);
void quickSort(std::vector<int>& data, int start, int end);

bool isPalindrome(std::string word, int start, int end);
bool isWordSymmetric(const std::vector<std::string>& words, int start, int end);
long vectorSum(const std::vector<int>& data, unsigned int position);
int vectorMin(const std::vector<int>& data, unsigned int position);
void selectionSort(std::vector<int>& data, int pivot);



int main()
{
	TestCases::runTestCases();
}

/*goes through a string and compares the last letter with the first letter and then
 incriments both */
bool isPalindrome(std::string word, int start, int end)
{
    if(start >= end){return true;}
    
    if(word[start]==word[end])
    {
        return isPalindrome(word, start + 1, end - 1);
    }
    
    return false;
}

bool isWordSymmetric(const std::vector<std::string>& words, int start, int end)
{
    if(start == end){return true;}
    
    if(words[start]==words[end])
    {
        isWordSymmetric(words, start + 1, end - 1);
        return (isWordSymmetric(words, start + 1, end - 1));
    
    }
    
    return false;
}

long vectorSum(const std::vector<int>& data, unsigned int position)
{
    if (position == (data.size()))
    {
        return 0;
    }
    
    return data[position] + vectorSum(data, position + 1);
    
}

int vectorMin(const std::vector<int>& data, unsigned int position)
{
    if (position == (data.size() - 1))
    {
        return data[position];
    }
    
    int min = vectorMin(data, position + 1);
    
    if ( min < data[position])
    {
        return min;
    }
    else
    {
        return data[position];
    }
}

void selectionSort(std::vector<int>& data, int pivot)
{
    for (int i =0; i < pivot - 1; i++)
    {
        int minPos = i;
        for (int j = i; j < pivot; j++)
        {
            if (data[j] < data[minPos])
            {
                minPos = j;
            }
        }
        std::swap(data[i], data[minPos]);
    }
    
}


//---------------------Provided-Code------------------------------------------

// ------------------------------------------------------------------
//
// Provided quicksort code
//
// ------------------------------------------------------------------
void quickSort(std::vector<int>& data, int start, int end)
{
    if (start < end)
        {
            int pivot = partition(data, start, end);
            if(pivot < 10)
            {
                selectionSort(data, pivot);
            }
            quickSort(data, start, pivot - 1);
            quickSort(data, pivot + 1, end);
        }
}

// ------------------------------------------------------------------
//
// Provided code to remove spaces from a string (and capitalize it)
//
// ------------------------------------------------------------------
std::string collapseSpaces(std::string s)
{
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
    std::transform(s.begin(), s.end(), s.begin(), toupper);    // Capitalize all
    return s;
}

// ------------------------------------------------------------------
//
// Solution string split code
//
// ------------------------------------------------------------------
std::vector<std::string> split(std::string s)
{
    std::istringstream is(s);
    std::vector<std::string> words;
    
    do
    {
        std::string word;
        is >> word;
        if (word.length() > 0)
        {
            words.push_back(word);
        }
    } while (is);
    
    return words;
}

// ------------------------------------------------------------------
//
// Provided quicksort partition code
//
// ------------------------------------------------------------------
int partition(std::vector<int>& data, int start, int end)
{
    int middle = (start + end) / 2;
    std::swap(data[start], data[middle]);
    int pivotIndex = start;
    int pivotValue = data[start];
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (data[scan] < pivotValue)
        {
            pivotIndex++;
            std::swap(data[scan], data[pivotIndex]);
        }
    }
    
    std::swap(data[pivotIndex], data[start]);
    
    return pivotIndex;
}
