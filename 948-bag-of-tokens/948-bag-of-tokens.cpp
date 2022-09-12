class Solution:
    def bagOfTokensScore(self, tokens, power):
        tokens.sort()
        score = 0
        res=0
        while tokens:
            if power >= tokens[0]:
                power -= tokens.pop(0)
                score += 1
                if res<score:
                    res=score
            elif score > 0:
                power += tokens.pop()
                score -= 1
            else:
                break
        return res