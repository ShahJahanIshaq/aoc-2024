comeBefore = {}
comeAfter = {}

for i in range(101):
    comeAfter[i] = []
    comeBefore[i] = []

with open("../input1.txt", "r") as rules:
    for rule in rules:
        parent, child = [int(_) for _ in rule.strip().split('|')]
        comeBefore[child].append(parent)
        comeAfter[parent].append(child)

queries = []
with open("../input2.txt", "r") as prints:
    for seq in prints:
        queries.append([int(_) for _ in seq.strip().split(',')])

correctSeqs = []
incorrectSeqs = set()
for seqNum in range(len(queries)):
    correct = False
    while not correct:
        correct = True
        seq = queries[seqNum]
        for idx in range(len(seq)):
            page = seq[idx]
            # check pages before this page
            for j in range(0, idx):
                # incorrect if the j-th page must be after our current page instead
                if seq[j] in comeAfter[page]:
                    correct = False
                    # correction time
                    queries[seqNum] = seq[:j] + seq[j + 1 : idx] + [seq[idx]] + [seq[j]] + seq[idx + 1:] 
                    break
            if not correct:
                break
            # check pages after this page
            for j in range(idx + 1, len(seq)):
                # incorrect if the j-th page must be before our current page instead
                if seq[j] in comeBefore[page]:
                    correct = False
                    # correction time
                    queries[seqNum] = seq[:idx] + [seq[j]] + [seq[idx]] + seq[idx + 1:j] + seq[j + 1:]
                    break
            # stop checking further
            if not correct:
                break
        if not correct:
            incorrectSeqs.add(seqNum)

middleSum = 0
for seqNum in list(incorrectSeqs):
    seq = queries[seqNum]
    length = len(seq)
    if length % 2 == 0:
        middle = (seq[length // 2] + seq[length // 2 - 1]) / 2
    else:
        middle = seq[length // 2]
    middleSum += middle

print(middleSum)