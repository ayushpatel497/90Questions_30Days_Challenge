class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start_index = 0;
        int end_index = 0;
        std::unordered_map<int, int> frequency_map;
        int max_length = 0;

        for (end_index = 0; end_index < nums.size(); ++end_index) {
            int current_num = nums[end_index];

            if (frequency_map.find(current_num) == frequency_map.end()) {
                frequency_map[current_num] = 0;
            }

            frequency_map[current_num] += 1;

            if (frequency_map[current_num] <= k) {
                if (end_index - start_index > max_length) {
                    max_length = end_index - start_index;
                }
            } else {
                // Keep moving left until we find a num
                while (start_index <= end_index) {
                    if (nums[start_index] == current_num) {
                        start_index += 1;
                        frequency_map[current_num] -= 1;
                        break;
                    }

                    frequency_map[nums[start_index]] -= 1;
                    start_index += 1;
                }
            }
        }
        return max_length + 1;
    }
};