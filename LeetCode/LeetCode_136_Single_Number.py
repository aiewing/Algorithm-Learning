class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = nums[0]
        for i in range(1, len(nums)):
            result ^= nums[i]
        return result



so = Solution()
result = so.singleNumber([1, 2, 3, 2, 1])
print "结果为：", result
