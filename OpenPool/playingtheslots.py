"""
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources. Solved the problem by calculating the minimum width of a polygon at various orientations, determined by projecting its vertices onto lines perpendicular to each edge. The smallest width across these projections indicates the minimum slot size needed

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
"""

import math
n = int(input())
arrVert = []
for _ in range(n):
    x, y = map(float, input().split())
    arrVert.append((x, y))
minSlot = float('inf')
for i in range(n):
    currV = arrVert[i]
    nextV = arrVert[(i + 1) % n]
    edge = math.atan2(nextV[1]-currV[1], nextV[0]-currV[0])
    perp = edge + math.pi / 2
    minP = maxP = None
    for i in arrVert:
        proj = i[0]*math.cos(perp) + i[1]*math.sin(perp)
        if minP is None or proj < minP:
            minP = proj
        if maxP is None or proj > maxP:
            maxP = proj
    minSlot = min(minSlot, maxP-minP)
print(minSlot)