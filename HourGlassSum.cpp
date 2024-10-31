#include <iostream>
#include <vector>

int hourglassSum(std::vector<std::vector<int>> arr) {
    int max = INT_MIN;
    int sum;
    for (int i = 0; i < arr.size() - 2; i++) {
        for (int j = 0; j < arr.size() - 2; j++) {

            sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            sum += arr[i + 1][j + 1];
            sum += arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];


            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}

