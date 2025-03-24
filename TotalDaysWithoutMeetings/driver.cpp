#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#include "solution.cpp"


bool test1() {
    Solution solution;
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
    int result = solution.countDays(10, meetings);
    return result == 2;
}

bool test2() {
    Solution solution;
    vector<vector<int>> meetings = {{2,4},{1,3}};
    int result = solution.countDays(5, meetings);
    return result == 1;
}

int main() {
    if (test1() && test2()) {
        cout << "Test Cases 1 and 2 Passed" << endl;
        return 1;
    } else if (test1()) {
        cout << "Test Case 1 Passed, Test Case 2 Failed" << endl;
        return 0;
    } else if (test2()) {
        cout << "Test Case 1 Failed, Test Case 2 Passed" << endl;
        return 0;
    }
    else {
        cout << "Test Cases 1 and 2 Failed" << endl;
        return 0;
    }
}