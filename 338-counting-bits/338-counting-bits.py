class Solution:
    def bits(self,n):
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n & 1 == 1:
            return self.bits(n>>1) +1
        else:
            return self.bits(n>>1)
    
    
    
    def countBits(self, n: int) -> List[int]:
        result = []
        for i in range(n+1):
            result.append(self.bits(i))
        return result
        