class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        if (nums.size() == 1) {
            return true;
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (i > farthest) {
                return false;
            }
            
            farthest = max(farthest, i + nums[i]);

            if (farthest >= nums.size() - 1){
                return true;
            } 
        }

        return false;
    }
};