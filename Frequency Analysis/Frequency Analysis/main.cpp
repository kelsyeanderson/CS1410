//A02093326
//Kelsye Anderson

#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>
#include <vector>

#include "Record.hpp"
#include "TestCases.hpp"

/*This function reads the first number of the txt file as keeps it as the size, then puts that number of integers into a vector*/
std::vector<unsigned int> readNumbersFromFile(std::string fileName);
/*This function creates a vector of pointers to Records. It sorts the vector in order from least to greatest int and increments any duplicates of the ints in the Record*/
std::vector<Record*> createVectorOfRecordsFromVectorOfNumbers(std::vector<unsigned int> input);
/*This function sorts the vector by frequency*/
void sortByFrequency(std::vector<Record*>& ptrVtr);
/*This function couts the frequencys that we have sorted*/
void reportFrequencies(std::vector<Record*>& ptrVtr);
/*This function cleans up the vector and sets all the pointers to nullptr*/
//void cleanUp(std::vector<Record*>& ptrVtr);

int main()
{
    std::vector<unsigned int> numbers = readNumbersFromFile("input.txt");
    std::vector<Record*> records = createVectorOfRecordsFromVectorOfNumbers(numbers);
    
    sortByFrequency(records);
    reportFrequencies(records);
    //cleanUp(records);
    cleanDynamicMemory(records);	// Function stub found in TestCases.cpp
    
    // Test cases
    executeFreqTest(FreqTestCase1, createVectorOfRecordsFromVectorOfNumbers, "Frequency Test Case 1");
    executeFreqTest(FreqTestCase2, createVectorOfRecordsFromVectorOfNumbers, "Frequency Test Case 2");
    executeSortTest(SortTestCase1, sortByFrequency, "Sort Test Case 1");
    executeSortTest(SortTestCase2, sortByFrequency, "Sort Test Case 2");
    return 0;
}

std::vector<unsigned int> readNumbersFromFile(std::string fileName)
{
    std::ifstream myfile(fileName);
    std::vector<unsigned int> vtr;
    int size;
    myfile >> size;
    
    for(int i = 0; i < size; i++)
    {
        int num;
        myfile >> num;
        vtr.push_back(num);
    }
    
    return vtr;
}

std::vector<Record*> createVectorOfRecordsFromVectorOfNumbers(std::vector<unsigned int> input)
{
    std::vector<Record*> ptrVtr;
    
    ptrVtr.push_back(new Record(input[0],1));
    
    for (int i = 1; i < input.size(); i++)
    {
        int lower = 0;
        int upper = 0;
        bool found = false;
        upper = static_cast<int>(ptrVtr.size()) - 1;
        while(!found && lower <= upper)
        {
            int middle = (upper + lower)/2;
            if(ptrVtr[middle]->getNumber() == input[i])
            {
                found = true;
                ptrVtr[middle]->incrementFrequency();
            }
            else if (ptrVtr[middle]->getNumber() < input[i])
            {
                lower = middle + 1;
            }
            else
            {
                upper = middle - 1;
            }
        }
        if (!found)
        {
            int pos = 0;
            for (int j = 0; j < ptrVtr.size(); j++)
            {
                if (input[i] > ptrVtr[j]->getNumber())
                {
                    pos++;
                }
            }
            
            ptrVtr.insert(ptrVtr.begin() + pos, new Record(input[i],1));
        }
    }
    
    return ptrVtr;
}

void sortByFrequency(std::vector<Record*>& ptrVtr)
{
    for (unsigned int i = 0; i < ptrVtr.size() - 1; i++)
    {
        unsigned int minPos = i;
        for (unsigned int scan = i; scan < ptrVtr.size(); scan++)
        {
            if(ptrVtr[scan]->getFrequency() > ptrVtr[minPos]->getFrequency())
            {
                minPos = scan;
            }
        }
        std::swap(ptrVtr[i],ptrVtr[minPos]);
    }
}


void reportFrequencies(std::vector<Record*>& ptrVtr)
{
    int index = 0;
    int count = 1;
    for(int i = 0; i < ptrVtr.size() - 1; i++)
    {
        if(ptrVtr[i]->getFrequency() == ptrVtr[i+1]->getFrequency())
        {
            count++;
        }
        else
        {
            std::cout << count << " numbers with a count of " << ptrVtr[i]->getFrequency() << std::endl;
            index += count * ptrVtr[i] -> getFrequency();
            count = 1;
        }
    }
    std::cout << count << " numbers with a count of " << ptrVtr[ptrVtr.size()-1]->getFrequency() << std::endl;
    index += count * ptrVtr[ptrVtr.size()-1] -> getFrequency();
    std:: cout << "There were " << index << " identified during the frequency analysis" << std::endl;
}

/*void cleanUp(std::vector<Record*>& ptrVtr)
{
    for(auto ptr: ptrVtr)
    {
        delete ptr;
        ptr = nullptr;
    }
}
*/






