class Solution:
    
    
    def countBits(self, n: int) -> List[int]:
        result = [0 for _ in range(n+1)]
        num=1
        for i in range(1,n+1):
            if num * 2 == i:
                num*=2
            result[i] = result[i-num]+1
        return result