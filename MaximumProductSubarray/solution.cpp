#include <vector>
using namespace std;


class Solution {
    public:
        int maxProduct(vector<int>& nums) {

            int maxProduct = nums[0];
            size_t begin_idx = 0;
            size_t end_idx = 0;

            for (size_t i = 0; i < nums.size(); i++) {
                int product = 1;
                for (size_t j = i; j < nums.size(); j++) {
                    product *= nums[j];
                    if (product > maxProduct) {
                        maxProduct = product;
                        begin_idx = i;
                        end_idx = j;
                    }
                }
            }

            return maxProduct;
            
        }
};