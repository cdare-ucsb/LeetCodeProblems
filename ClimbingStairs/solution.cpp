#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        int climbStairs(int n) {
            // std::vector<int> distinct_ways;
            // climbStairsHelper(n, distinct_ways, 0);
            // return distinct_ways.size();
            return improvedClimbStairs(n);
        }

        int improvedClimbStairs(int n) {
            /**
             * This is a Fibonacci like problem for the following reasons:
             *    - At each point, we can either take 1 step or 2 steps
             *    - If we want to have climbed n steps, the last step must either have been 1 step
             *      or 2 steps. 
             *    - If the last step was 1 step, all the previous steps must have come from the solution for n - 1 steps
             *    - If the last step was 2 steps, all the previous steps must have come from the solution for n - 2 steps
             *    - Therefore, the number of ways to climb n steps is the sum of the number of ways to climb n - 1 steps and n - 2 steps
             *    - This is the definition of the Fibonacci sequence
             */

             vector<int> table(n + 1, 0);
             table[0] = 1;
             table[1] = 1;
             table[2] = 2;
             table[3] = 3;

             for (int i = 4; i <= n; i++) {
                 table[i] = table[i - 1] + table[i - 2];
             }

            return table[n];
        }

    private:
        void climbStairsHelper(int target, std::vector<int>& distinct_ways, int current) {
            if (current == target) {
                distinct_ways.push_back(current);
                return;
            }
            if (current > target) {
                return;
            }
            climbStairsHelper(target, distinct_ways, current + 1);
            climbStairsHelper(target, distinct_ways, current + 2);
        }

};