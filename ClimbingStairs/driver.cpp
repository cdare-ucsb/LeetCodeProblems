#include <vector>
#include <iostream>
using namespace std;

#include "solution.cpp"


bool test1() {
    Solution solution;
    int result = solution.climbStairs(2);
    return result == 2;
}

bool test2() {
    Solution solution;
    int result = solution.climbStairs(3);
    return result == 3;
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