#include <iostream>
#include <vector>

#include "Bug.hpp"
#include "TestCases.hpp"


void printBugs(std::vector<Bug> bugs)
{
    //TODO:write a function that prints all the contents of the
    //     bug array.  Use Bug::print() for each bug.
    for (int i = 0; i < bugs.size(); i++)
    {
        bugs[i].print();
    }
}

void sortMass(std::vector<Bug>& bugs)
{
    //TODO:write a function to bubble sort the contents of a
    //     bug array based on the mass
    bool didSwap = false;
    
    do
    {
        didSwap = false;
        for (unsigned int i = 0; i < bugs.size() -1; i++)
        {
            if (bugs[i].getMass() < bugs[i+1].getMass())
            {
                std::swap(bugs[i],bugs[i+1]);
                didSwap = true;
            }
        }
    }while (didSwap);
}

int main()
{
    const unsigned int NUMBUGS = 5;
    const unsigned int DROP_BIG = 5;
    
    //TODO: make a vector of NUMBUGS bugs
    std::vector<Bug> bugs(NUMBUGS);
    //end of TODO
    
    std::cout << std::endl << "-- Initial Bugs --" << std::endl << std::endl;
    printBugs(bugs);
    executeTest(testCase1, bugs, "Initial Bugs");
    
    //TODO: add three more bugs to the vector
    bugs.resize(NUMBUGS + 3);
    //end of TODO
    
    std::cout << std::endl << "-- Three More Bugs --" << std::endl << std::endl;
    printBugs(bugs);
    executeTest(testCase2, bugs, "Three More Bugs");
    
    sortMass(bugs);
    
    std::cout << std::endl << "-- Sorted By Mass --" << std::endl << std::endl;
    printBugs(bugs);
    executeTest(testCase3, bugs, "Sorted By Mass");
    
    
    //TODO: get rid of the 5 bugs with the greatest mass
    for (int i=0; i < DROP_BIG; i++)
    {
        bugs.erase (bugs.begin());
    }
    //end of TODO
    
    std::cout << std::endl << "-- Removed Five Biggest --" << std::endl << std::endl;
    printBugs(bugs);
    executeTest(testCase4, bugs, "Removed Five Biggest");
    
    return 0;
}
