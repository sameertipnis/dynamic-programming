#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArraySum(const std::vector<int>& nums) {
    int max_so_far = nums[0];
    int max_ending_here = nums[0];
    int st_index = 0;
    int en_index = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > max_ending_here + nums[i])
            st_index = i;
        max_ending_here = std::max(nums[i], max_ending_here + nums[i]);
        if (max_ending_here > max_so_far)
            en_index = i;
        max_so_far = std::max(max_so_far, max_ending_here);
    }
    std::cout << st_index << "::" << en_index << "::";
    return max_so_far;
}

int main() {
    std::vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, -39, 42 };
    //std::vector<int> nums = { -2, 7, 3, 1 };
    std::cout << "Maximum subarray sum is " << maxSubArraySum(nums) << std::endl;
    return 0;
}
