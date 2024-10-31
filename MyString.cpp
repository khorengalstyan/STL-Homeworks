// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class MyString {

private:
    static const int ssoSize = 15;
    char stackString[ssoSize + 1];
    char* heapString;
    size_t length;
    bool isInHeap;

public:
    MyString() {
        stackString[0] = '\0';
        length = 0;
        isInHeap = false;
        heapString = nullptr;
    }

    MyString(const char* string) {
        length = strlen(string);
        if (length <= ssoSize) {
            isInHeap = false;
            strcpy_s(stackString, string);
        } else {
            heapString = new char[length + 1];
            strcpy(heapString, string);
            isInHeap = true;
        }
    }

    ~MyString() {
        delete[] heapString;
    }

    size_t size() {
        return length;
    }
    

    bool isOptimized() {
        return !isInHeap;
    }
    //////

    //Jamanaks chi heriqum mnacac constructornern el grem
    //

    //////
};

int main()
{
    MyString str("asdsssssssssssssssssssssssssssss");

    std::cout << str.size();
    std::cout << str.isOptimized();
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
