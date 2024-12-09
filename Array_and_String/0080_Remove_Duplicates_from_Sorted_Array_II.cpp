class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int write = 1;
        int count = 1;

        for (int read = 1; read < nums.size(); read++) {
            if (nums[read] == nums[read - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) {
                nums[write] = nums[read];
                write++;
            }
        }
        return write;
    }
};