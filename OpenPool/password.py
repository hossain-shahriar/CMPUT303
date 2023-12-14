"""
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  no resources. Solved the problem by sorting the passwords in descending order of their probabilities and then calculating the expected number of attempts as the sum of each password's probability multiplied by its position in the sorted list

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
"""

n = int(input())
passList = []
for _ in range(n):
    pwd, prob = input().split()
    passList.append((pwd, float(prob)))
sorted = sorted(passList, key=lambda x: x[1], reverse=True)
expected = sum(prob*(index+1) for index, (_, prob) in enumerate(sorted))
print(f"{expected:.4f}")