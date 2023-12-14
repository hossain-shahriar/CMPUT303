"""
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources, used bottom-up dynamic programming approach

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
"""

n, a, b, c = map(int, input().split())
sol = []
for _ in range(n + 1):
    sol.append([0, 0, 0, 0])

sol[1][1] = a
sol[1][2] = b
sol[1][3] = c
mod = 1000000007
for i in range(2, n + 1):
    sol[i][1] = (sol[i-1][2]+sol[i-1][3])*a % mod
    sol[i][2] = (sol[i-1][1]+sol[i-1][3])*b % mod
    sol[i][3] = (sol[i-1][1]+sol[i-1][2])*c % mod
    
print(sum(sol[n]) % mod)