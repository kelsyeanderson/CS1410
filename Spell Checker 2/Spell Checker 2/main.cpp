//A02093326
//Kelsye Anderson

#include <iostream>
#include "BinaryTree.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

void testTree();
int myrandom (int i) {return std::rand()%i;}
//std::ifstream openFile(std::string name);
std::string punctuation(std::string word);
std::vector<std::string> punctuation(std::vector<std::string> data);
std::vector<std::string> fileToVec(std::ifstream &data);
std::vector<std::string> lowerCase(std::vector<std::string> data);

int main()
{
    std::srand ( unsigned ( std::time(NULL)));
    std::ifstream data("Dictionary.txt");
    if(!data)
    {
        std::cout << "You failed :(" << std::endl;
    }
    
    std::vector<std::string> temp;
    BinaryTree<std::string> Dictionary;
    
    temp = fileToVec(data);
    std::random_shuffle(temp.begin(), temp.end(), myrandom);
    
    for (int i = 0; i < temp.size(); i++)
    {
        Dictionary.insert(temp[i]);
    }
    
    std::cout << "-- Tree Stats --" << std::endl << std::endl;
    std::cout << "Total Nodes: " << Dictionary.numberNodes() << std::endl;
    std::cout << "Leaf Nodes: " << Dictionary.numberLeafNodes() << std::endl;
    std::cout << "Tree Height: " << Dictionary.height() << std::endl;
    
    
    std::ifstream data2("letter.txt");
    if(!data2)
    {
        std::cout << "You failed :(" << std::endl;
    }
    std::vector<std::string> letter;
    letter = fileToVec(data2);
    letter = punctuation(letter);
    letter = lowerCase(letter);
    
    std::cout << std::endl << "--------- Misspelled Words------" << std::endl;
    for(int i = 0; i < letter.size(); i++)
    {
        if(!(Dictionary.search(letter[i])))
        {
            std::cout << letter[i] << std::endl;
        }
    }
    
    testTree();
    
    return 0;
}

//std::ifstream openFile(std::string name)
//{
//    std::ifstream data(name);
//
//    if(!data)
//    {
//        std::cout << "You failed :(" << std::endl;
//    }
//
//    return data;
//}

std::vector<std::string> fileToVec(std::ifstream& data)
{
    std::vector<std::string> temp;
    std::string input;
    while (data >> input)
    {
        temp.push_back(input);
    }
    return temp;
}

std::string punctuation(std::string word)
{
    if (word[word.size()-1] == '.')
    {
        return word.erase(word.size()-1);
    }
    if (word[word.size()-1] == '"')
    {
        return word.erase(word.size()-1);
    }
    if (word[word.size()-1] == ',')
    {
        return word.erase(word.size()-1);
    }
    if (word[word.size()-1] == ':')
    {
        return word.erase(word.size()-1);
    }
    if (word[word.size()-1] == '!')
    {
        return word.erase(word.size()-1);
    }
    if (word[word.size()-1] == '?')
    {
        return word.erase(word.size()-1);
    }
    if ((word[word.size()-1] == '(' ) && ( word[word.size()-1] == ')' ))
    {
        std::string tmp = word.erase(word.size()-1);
        return tmp.erase(tmp.size()-1);
    }
    else
    {
        return word;
    }
}

std::vector<std::string> punctuation(std::vector<std::string> data)
{
    for(int i=0; i < data.size(); i++)
    {
        std::string oldWord;
        do
        {
            oldWord = data[i];
            data[i] = punctuation(oldWord);
        }while(data[i] != oldWord);
    }
    return data;
}

std::vector<std::string> lowerCase(std::vector<std::string> data)
{
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data[i].size(); j++)
        {
            if(data[i][j] >= 65 && data[i][j] <= 92)
            {
                data[i][j] = data[i][j] +32;
            }
        }
    }
    return data;
}

void testTree()
{
    BinaryTree<std::string> tree;
    //
    // Add a bunch of values to the tree
    tree.insert("Olga");
    tree.insert("Tomeka");
    tree.insert("Benjamin");
    tree.insert("Ulysses");
    tree.insert("Tanesha");
    tree.insert("Judie");
    tree.insert("Tisa");
    tree.insert("Santiago");
    tree.insert("Chia");
    tree.insert("Arden");
    
    
    // Make sure it displays in sorted order
    std::cout << std::endl << std::endl << "------- Display ---------" << std::endl;
    tree.display();
    
    //
    // Try to add a duplicate
    std::cout << std::endl << "---- adding a duplicate ----" << std::endl;
    if (tree.insert("Tomeka"))
    {
        std::cout << "oops, shouldn't have returned true from the insert" << std::endl;
    }
    tree.display();
    
    //
    // Remove an existing value from the tree
    std::cout << std::endl << "---- removing an existing value ----" << std::endl;
    tree.remove("Olga");
    tree.display();
    
    //
    // Remove a value that was never in the tree, hope it doesn't crash!
    std::cout << std::endl << "----- removing nonexistant value -----" << std:: endl;
    tree.remove("Karl");
    
    //
    // Check the tree stats
    std::cout << std::endl << "---- checking the tree stats ----" << std::endl;
    std::cout << "Expecting 9 nodes, found " << tree.numberNodes() << std::endl;
    std::cout << "Expecting 4 leaf nodes, found " << tree.numberLeafNodes() << std::endl;
    std::cout << "Expecting height of 6, found " << tree.height() << std::endl;
}



