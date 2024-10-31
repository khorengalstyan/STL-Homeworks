#include <iostream>
#include <vector>



std::vector<int> reverseArray(std::vector<int> myVector) {
    std::vector<int> reversedVector(myVector.size());

    if (myVector.size() > 0) {
        for (size_t i = 0; i < myVector.size(); ++i) {
            reversedVector[i] = myVector[myVector.size() - i - 1];
        }
    }
    return reversedVector;
}
