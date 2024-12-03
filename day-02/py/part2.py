with open("input.txt", "r") as file:
    safe_count = 0
    for line in file:
        reports = [int(x) for x in line.strip().split()]
        if len(reports) > 1:
            for toRemove in range(len(reports)):
                safe = True
                dupReports = reports[:toRemove] + reports[toRemove + 1:]
                order = 1 if dupReports[1] > dupReports[0] else -1
                for i in range(1, len(dupReports)):
                    diff = dupReports[i] - dupReports[i - 1]
                    if order == 1:
                        if not (1 <= diff <= 3):
                            safe = False
                            break
                    else:
                        if not (-3 <= diff <= -1):
                            safe = False
                            break
                if safe:
                    safe_count += 1
                    break

print(safe_count)