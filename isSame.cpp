// isSame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
template <typename T1, typename T2>
class isSame  {
    public:
        bool is_same() {
            return false;
        }
};

template <typename T>
class isSame<T, T> {
    public:
        bool is_same() {
            return true;
        }

};


int main()
{

    isSame<int, float> notSame;
    std::cout << notSame.is_same()<<std::endl;

    isSame<int, int> same;
    std::cout << same.is_same() << std::endl;
}

