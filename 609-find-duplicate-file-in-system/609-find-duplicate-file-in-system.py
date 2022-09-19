import os
from collections import defaultdict
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        dic = defaultdict(list)
        for path in paths:
            parent, *temp = path.split(' ')
            for file in temp:
                # "a.b.c".partition('.') -> ("a", ".", "b.c")
                stem, _, key = file.partition('(')
                dic[key[:-1]].append(os.path.join(parent, stem))
        return [v for v in dic.values() if len(v) > 1] 