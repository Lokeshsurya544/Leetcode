class Solution:
    def bagOfTokensScore(self, tokens, power):
        tokens.sort()
        ptr1 = 0
        ptr2 = len(tokens)-1
        score = 0
        res=0
        while ptr1 <= ptr2:
            print(score,res)
            if power >= tokens[ptr1]:
                power -= tokens[ptr1]
                score += 1
                if res<score:
                    res=score
                ptr1 += 1
            elif score > 0 and tokens[ptr1] > power:
                power += tokens[ptr2]
                score -= 1
                if res<score:
                    res=score
                ptr2 -= 1
            else:
                break
        return res