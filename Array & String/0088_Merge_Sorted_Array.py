class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        for i in range(1, m + n + 1):
            if n == 0:
                break
            elif m == 0:
                nums1[-i] = nums2[n - 1]
                n -= 1
                continue
            
            if nums1[m - 1] < nums2[n - 1]:
                nums1[-i] = nums2[n - 1]
                n -= 1
            else:
                nums1[-i] = nums1[m - 1]
                m -= 1



        