"""
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.programiz.com/dsa/graph-dfs
  https://brilliant.org/wiki/depth-first-search-dfs/
  
  Solved the problem using a DFS with memoization to efficiently find the minimum pebbles for each board state

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
"""

def dfs(board, memo):
    if board in memo:
        return memo[board]
    minPeb = board.count('o')
    for i in range(len(board)-2):
        if board[i:i+3] in ['oo-', '-oo']:
            new = board[:i] + ('--o' if board[i] == 'o' else 'o--') + board[i+3:]
            minPeb = min(minPeb, dfs(new, memo))
    memo[board] = minPeb
    return minPeb
n = int(input())
for _ in range(n):
    board = input()
    memo = {}
    minPeb = dfs(board, memo)
    print(minPeb)