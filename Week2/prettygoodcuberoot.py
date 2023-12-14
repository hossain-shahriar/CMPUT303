"""
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  googled how to find cube root of a number. Found this link helpful: https://www.geeksforgeeks.org/python-program-for-find-cubic-root-of-a-number/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
"""

import sys

def cuberoot(num):
    low = 0
    high = num

    while low <= high:
        mid = (low+high)//2
        cube = mid**3

        if cube == num:
            return mid
        elif cube < num:
            low = mid + 1
        else:
            high = mid - 1

    if abs(low**3-num) < abs(high**3-num):
        return low
    else:
        return high

for line in sys.stdin:
    num = int(line.strip())
    ans = cuberoot(num)
    print(ans)