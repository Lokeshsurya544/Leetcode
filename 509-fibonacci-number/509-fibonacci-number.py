class Solution:
    def fib(self, n: int) -> int:
        def func(n):
            if n==0:
                return 0
            if n<=2:
                return 1
            return func(n-1)+func(n-2)
        return func(n)