class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> counts(n + 1, 0);
        
        for (int num : citations)  {
            if (num >= n) {
                counts[n]++;
            } else {
                counts[num]++;
            } 
        }

        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += counts[i];
            if (count >= i) {
                return i;
            }
        }
        return 0;
    }
};