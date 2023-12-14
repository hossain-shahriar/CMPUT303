"""
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Was struggling to extract key using value in python dictionary. Used this link: https://www.geeksforgeeks.org/python-get-key-from-value-in-dictionary/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
"""

mydict = {}

def calc(line):
    temp = []
    temp = [s if s in ['+', '-'] else mydict.get(s, "unknown") for s in line[:-1]]
    if "unknown" in temp:
        return " ".join(line) + " unknown"
    temp_str = ' '.join(temp)
    output = str(eval(temp_str))
    values = {val:key for key,val in mydict.items()}
    output = values.get(output, "unknown")
    return f"{' '.join(line)} {output}"

flag = True
while flag:
    try:
        instruct = input().split()
        if instruct[0] == 'def':
            mydict[instruct[1]] = instruct[2]
        elif instruct[0] == 'calc':
            line = instruct[1:]
            print(calc(line))
        elif instruct[0] == "clear":
            mydict.clear()
    except EOFError:
        break