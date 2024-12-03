from collections import Counter
arr1 = []
arr2 = []
with open("input.txt", "r") as file:
    for line in file:
        line = line.rstrip('\n').split()
        arr1.append(int(line[0]))
        arr2.append(int(line[1]))

arr1.sort()
arr2.sort()
diffSum = 0
for i in range(len(arr1)):
    diffSum += abs(arr1[i] - arr2[i])

print(diffSum)