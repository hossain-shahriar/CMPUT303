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

import math

s, c, k = map(int, input().split())
sock = list(map(int, input().split()))

sock.sort()

machine = 1 
basket = [sock[0]]

for i in range(1, s):
    if sock[i] - basket[0] > k or len(basket) == c:
        machine += 1
        basket = [sock[i]] 
    else:
        basket.append(sock[i])

print(machine)