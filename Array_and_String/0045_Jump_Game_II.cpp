class Solution {
public:
    int jump(vector<int>& nums) {

        if (nums.size() == 1) {
            return 0;
        }

        int steps = 0;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            
            farthest = max(farthest, i + nums[i]);

            if (i == current_end) {
                steps++;
                current_end = farthest;

                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return steps;
    }
};