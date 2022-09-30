class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        ycoord = collections.deque([])
        xcoord = collections.deque([])
        for x1, x2, y in buildings:
            start_idx = bisect.bisect_left(xcoord, x1)
            end_idx = bisect.bisect_left(xcoord, x2)
    
            # Case 1: Building starts beyond current skyline
            if start_idx == len(xcoord):
                # Continuation of skyline
                if len(xcoord) and (x1 == xcoord[-1]):
                    ycoord[-1] = y
                # Disjointed skyline
                else:
                    xcoord.append(x1)
                    ycoord.append(y)
                xcoord.append(x2)
                ycoord.append(0)
    
            # Case 2: Building ends before current skyline
            elif not end_idx:
                # Disjointed skyline
                if x2 != xcoord[0]:
                    xcoord.appendleft(x2)
                    ycoord.appendleft(0)
                xcoord.appendleft(x1)
                ycoord.appendleft(y)
    
            # Case 3-6 (all other cases)
            else:
                # Building starts before current skyline
                if (not start_idx) and (x1 < xcoord[0]):
                    xcoord.appendleft(x1)
                    ycoord.appendleft(y)
    
                # Building ends after current skyline
                if (end_idx == len(xcoord)):
                    if x2 != xcoord[-1]:
                        ycoord[-1] = y
                    xcoord.append(x2)
                    ycoord.append(0)
    
                # Get index again; building is definitely within current skyline
                start_idx = bisect.bisect_left(xcoord, x1)
                end_idx = bisect.bisect_left(xcoord, x2)
    
                # Building between same gap
                if start_idx == end_idx:
                    if y > ycoord[start_idx - 1]:
                        xcoord.insert(start_idx, x1)
                        ycoord.insert(start_idx, y)
                        if x2 != xcoord[start_idx + 1]:
                            xcoord.insert(start_idx + 1, x2)
                            ycoord.insert(start_idx + 1, ycoord[start_idx - 1])
    
                # Building spans over multiple gaps
                else:
                    ycoord[end_idx] = max(ycoord[end_idx], 0)
                    if (x2 not in xcoord) and (y > ycoord[end_idx - 1]):
                        xcoord.insert(end_idx, x2)
                        ycoord.insert(end_idx, ycoord[end_idx - 1])
                    for idx in range(start_idx, end_idx):
                        ycoord[idx] = max(ycoord[idx], y)
                    if (x1 not in xcoord) and (y > ycoord[start_idx - 1]):
                        xcoord.insert(start_idx, x1)
                        ycoord.insert(start_idx, y)
    
        # Post processing
        idx_to_delete = [idx for idx, num in enumerate(ycoord) if ycoord[idx] == ycoord[idx - 1]]
        idx_to_delete.reverse()
        for idx in idx_to_delete:
            del xcoord[idx]
            del ycoord[idx]
        return list(zip(xcoord, ycoord))