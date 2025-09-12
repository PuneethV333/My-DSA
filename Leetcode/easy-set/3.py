class Solution:
    def numberGame(self, nums: list[int]) -> list[int]:
        nums.sort()
        arr = []
        n = len(nums)
        for i in range(0,n,2):
            alice = nums[i]
            bob = nums[i+1]
            arr.append(bob)
            arr.append(alice)
        return arr