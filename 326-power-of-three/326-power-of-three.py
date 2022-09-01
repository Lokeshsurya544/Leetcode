class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1:
            return True
        if n < 1:
            return False
        # if n % 2 == 0:
        #     if n == (3**(math.floor(math.log(n, 4)))):
        #         return True
        # if n % 2 != 0:
        if n == (3**(math.ceil(math.log(n, 3)))):
            return True
        return False