#include <iostream>
#include <vector>


void newYearChaos(std::vector<int> queue) {
    for (int i = 0; i < queue.size(); i++) {
        if (queue[i] > i + 3) {
            std::cout << ("Too chaotic");
            return;
        }
    }

    int count = 0;
    for (int i = 0; i < queue.size(); i++) {
        for (int j = i + 1; j < queue.size(); j++) {
            if (queue[i] > i + 1) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
                count++;
            }
            if (queue[i] == i + 1) {
                break;
            }
        }
    }
    std::cout << count;
}