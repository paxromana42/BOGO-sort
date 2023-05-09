/*
    Name: Erick Almeida
    Program: main.cpp
    Purpose: Run the sorting algorithms
    Date: 5 May 2023
*/

#include <iostream>
#include <ctime>
#include <random>


//The sorting and validating algorithm for Bogo sort.
bool bogo(int*, const int);
bool checkOrder(int*, const int);
void printArray(int*, const int&, int&);

int main(){
    const int SIZE = 5; //Size of toSort
    int tracker = 0;
    int* toSort =  new int[SIZE];
    std::random_device numSource;
    std::uniform_int_distribution<int> dist(0, 100);

    std::cout << "Activating BOGO sort!" << std::endl;

    for (auto i = 0; i < SIZE; ++i){
        auto toAdd = dist(numSource);
        toSort[i] = toAdd;    
    }

    while (!bogo(toSort, SIZE))
        printArray(toSort, SIZE, tracker);
    

    std::cout << "It's finally sorted!" << std::endl;
    printArray(toSort, SIZE, tracker);

    delete[] toSort;
    return 0;
}

bool bogo (int* inArray, const int SIZE){
    int* temp = new int[SIZE];
    std::copy(inArray, inArray + SIZE, temp);
    std::random_device numOrder;
    std::uniform_int_distribution<int> dist(0, SIZE);
    
    delete[] inArray;
    inArray = new int[SIZE];

    for (auto i = 0; i < SIZE; ++i)
        inArray[i] = -1;

    for (auto i = 0; i < SIZE; ++i){
        auto randomindex = dist(numOrder);
        if (inArray[randomindex] == -1)
            inArray[randomindex] = temp[i];
        else
            --i;
    }

    delete[] temp;
    return checkOrder(inArray, SIZE);
}

bool checkOrder(int* in, const int SIZE){
    for (auto i = 0; i < SIZE; ++i)
        for (auto j = i; j < SIZE; ++j)
            if (in[i]>in[j])
                return false;
    return true;
}

void printArray(int * toSort, const int& SIZE, int& tracker){
    std::cout <<"\t";
    for (auto i = 0; i < SIZE; ++i)
        std::cout << toSort[i] << " ";
    std::cout << "Attempt #"<< ++tracker<< std::endl;
}
