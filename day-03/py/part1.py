
from sys import stdin
import re

def evaluate(str):
    res = eval(str[4:-1].replace(',', '*'))
    return res

rawString = ""
for line in stdin:
    rawString += line

# rawString = "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))"

doRegex = r"do()"
dontRegex = r"don't()"

doMatches = re.finditer(doRegex, rawString)
doIndices = [(0, 1)]
for matchObj in doMatches:
    doIndices.append((matchObj.start(), 1))
    
dontMatches = re.finditer(dontRegex, rawString)
dontIndices = []
for matchObj in dontMatches:
    dontIndices.append((matchObj.start(), -1))

control = doIndices + dontIndices
control.sort(key=lambda x:x[0])

regex = "mul\(\d{1,3},\d{1,3}\)"
matches = re.finditer(regex, rawString)

disableIntervals = []
for i in range(1, len(control)):
    if (control[i][1] == 1 and control[i - 1][1] == -1) or (control[i][1] == -1 and control[i - 1][1] == -1):
        disableIntervals.append((control[i - 1][0], control[i][0]))



k = 0  # control counter
totalSum = 0
for matchObj in matches:
    match = matchObj.group()
    start = matchObj.start()
    skip = False
    for lb, ub in disableIntervals:
        if lb <= start <= ub:
            skip = True
            break
    if start > control[-1][0] and control[-1][1] == 1:
        skip = False
    elif start > control[-1][0] and control[-1][1] == -1:
        skip = True
    if not skip:
        totalSum += evaluate(match)

print(disableIntervals)
print(totalSum)
