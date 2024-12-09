class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k = nums[0];
        int q = 0;
        for(int i = 0; i < nums.size(); i++ ) {
            if (nums[i] == k) {
                q++;
            }
            else {
                q--;
                if (q < 0) {
                    k = nums[i];
                    q = 1;
                }
            }
        }
    return k;
    } 
};