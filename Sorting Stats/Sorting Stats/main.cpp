//A02093326
//Kelsye Anderson

#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

#include "TestCases.hpp"

void runTestCases();
SortStats bubbleSort(std::vector<int> &bubbleVtr);
SortStats selectionSort(std::vector<int> &selectionVtr);
std::vector<int> vtrSize(std::vector<int> &vector, int vtrSize);

// ------------------------------------------------------------------
//
// Run the test cases to help verify the code is correct.
//
// ------------------------------------------------------------------


int main()
{
    std::vector<int> bubbleVtr;
    std::vector<int> selectionVtr;
    SortStats Bubble;
    SortStats Selection;
    
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    runTestCases();
    
    std::cout << "--- Timing Results ---" << std::endl << std::endl;
    for (unsigned int i = 100; i < 1001; i += 100)
    {
        bubbleVtr = vtrSize(bubbleVtr, i);
        Bubble = bubbleSort(bubbleVtr);
        selectionVtr = vtrSize(selectionVtr, i);
        Selection = selectionSort(selectionVtr);
        std::cout << "Number of items: " << selectionVtr.size() << std::endl;
        std::cout << "Bubble sort time: " << Bubble.time << std::endl;
        std::cout << "Selection sort time: " << Selection.time << std::endl << std::endl;
        bubbleVtr.clear();
        selectionVtr.clear();
    }
    
    return 0;
}

std::vector<int> vtrSize(std::vector<int> &vector, int vtrSize)
{
    for (int i = 0; i < vtrSize; i++)
    {
        vector.push_back(rand());
    }
    
    return vector;
}

SortStats bubbleSort(std::vector<int> &bubbleVtr)
{
    SortStats Stat;
    Stat.swapCount = 0;
    Stat.compareCount = 0;
    Stat.time = 0;
    bool swapped = false;

    // Grab the starting time
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    //bubble sort part of the function
    do
    {
        swapped = false;
        for (unsigned int i = 0; i < bubbleVtr.size() -1; i++)
        {
            Stat.compareCount++;
            if(bubbleVtr[i] > bubbleVtr[i+1])
            {
                std::swap(bubbleVtr[i], bubbleVtr[i+1]);
                Stat.swapCount++;
                swapped = true;
            }
        }
        
    }while(swapped);
    // Grab the ending time
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    // Compute how long it took, then display that duration in seconds.
    std::chrono::duration<double> time = end - start;
    Stat.time = time.count();

    return Stat;
}

SortStats selectionSort(std::vector<int> &selectionVtr)
{
    SortStats Stat;
    Stat.swapCount = 0;
    Stat.compareCount = 0;
    Stat.time = 0;
    
    // Grab the starting time
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < selectionVtr.size() - 1; i++)
    {
        unsigned int minPos= i;
        for ( unsigned int scan = i; scan < selectionVtr.size(); scan++)
        {
            Stat.compareCount++;
            if(selectionVtr[scan] < selectionVtr[minPos])
            {
                minPos = scan;
            }
        }
        std::swap(selectionVtr[i],selectionVtr[minPos]);
        Stat.swapCount++;
    }
    // Grab the ending time
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    // Compute how long it took, then display that duration in seconds.
    std::chrono::duration<double> time = end - start;
    Stat.time = time.count();

    
    return Stat;
}
                         
void runTestCases()
{
    executeTest(testCase1, bubbleSort, "Bubble Sort: 10 items");
    executeTest(testCase2, bubbleSort, "Bubble Sort: 500 items");
    executeTest(testCase3, bubbleSort, "Bubble Sort: 500 to 1000 items");
    
    executeTest(testCase1, selectionSort, "Selection Sort: 10 items");
    executeTest(testCase2, selectionSort, "Selection Sort: 500 items");
    executeTest(testCase3, selectionSort, "Selection Sort: 500 to 1000 items");
    
    executeTest(testCaseCompare, bubbleSort, selectionSort, "Sort Compare Test");
}


