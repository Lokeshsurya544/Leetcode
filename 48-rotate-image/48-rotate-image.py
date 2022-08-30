class Solution:
    def rotate(self, mat):
        l = 0
        r = len(mat)-1
        top = 0
        bottom = len(mat)-1
        while l <= r:
            left = l
            right = r
            for i in range(r-l):
                temp = mat[top][left+i]
                mat[top][left+i] = mat[bottom-i][left]
                mat[bottom-i][left] = mat[bottom][right-i]
                mat[bottom][right-i] = mat[top+i][right]
                mat[top+i][right] = temp
            l += 1
            r -= 1
            top += 1
            bottom -= 1
        return mat