"""
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
"""

n, m = map(int, input().split())
processTime = []

for _ in range(n):
    time = input().split()
    values = []
    for i in time:
        values.append(int(i))
    processTime.append(values)

endTime = [0]*n
available = [0]*m

for i in range(n):
    for j in range(m):
        available[j] = max(available[j], endTime[i])
        if j > 0:
            available[j] = max(available[j], available[j-1])
        endTime[i] = available[j] + processTime[i][j]
        available[j] = endTime[i]
print(' '.join(map(str, endTime)))