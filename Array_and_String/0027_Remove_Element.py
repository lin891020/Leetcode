class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        j = n - 1
        i = 0
        for i in range(n):
            if (i >= j):
                break
            while (val == nums[i]):
                if (val != nums[j]):
                    nums[i], nums[j] = nums[j], nums[i]
                    
                if (val == nums[j]):
                    j -= 1
                    if i >= j:
                        break  
                    nums[i], nums[j] = nums[j], nums[i]
        count = 0
        
        for num in nums:
            if num != val:
                count += 1
    
        nums = nums[:count]

        # 將 i 放到迴圈外部定義
        return count