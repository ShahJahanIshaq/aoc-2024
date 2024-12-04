import sys

def main():
    grid = []  # n x n grid
    getInput(grid)
    searchString = "MAS"
    m = len(searchString)
    possibleConfigs = [
        [
            ['M', '.', 'S'],
            ['.', 'A', '.'],
            ['M', '.', 'S']
        ],
        [
            ['M', '.', 'M'],
            ['.', 'A', '.'],
            ['S', '.', 'S']
        ],
        [
            ['S', '.', 'M'],
            ['.', 'A', '.'],
            ['S', '.', 'M']
        ],
        [
            ['S', '.', 'S'],
            ['.', 'A', '.'],
            ['M', '.', 'M']
        ],
    ]
    compressConfigs(possibleConfigs)
    count = getXMASCount(grid, possibleConfigs, m)
    print(count)

def getInput(grid):
    for line in sys.stdin:
        grid.append(list(line.strip()))

def compressConfigs(configs):
    for idx, config in enumerate(configs):
        compressed = ""
        for i in range(len(config)):
            for j in range(len(config[0])):
                compressed += config[i][j]
        configs[idx] = compressed


def getXMASCount(grid, possibleConfigs, m):
    count = 0
    for i in range(len(grid) - m + 1):
        for j in range(len(grid) - m + 1):
            thisSection = ""
            x = 0
            for ki in range(m):
                for kj in range(m):
                    thisSection += grid[i + ki][j + kj] if x % 2 == 0 else '.'
                    x += 1
            for candidate in possibleConfigs:
                if thisSection == candidate:
                    count += 1
                    break
    return count
                    
main()