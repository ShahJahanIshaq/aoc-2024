from typing import List
import sys

def main():
    grid = []  # n x n grid
    getInput(grid)
    searchString = "XMAS"
    count = getWordCount(grid, searchString)
    print(count)

def getInput(grid):
    for line in sys.stdin:
        grid.append(list(line.strip()))

def getHorizontalCount(grid, searchString) -> int:
    searchString = list(searchString)
    count = 0
    for row in grid:
        for c in range(len(row) - len(searchString) + 1):
            if row[c : c + len(searchString)] == searchString or row[c : c + len(searchString)] == searchString[::-1]:
                count += 1
    return count

def transposeGrid(grid) -> List[List]:
    transpose = [['.'] * len(grid[0]) for _ in range(len(grid))]
    print(len(transpose), len(transpose[0]))
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            transpose[j][i] = grid[i][j]  
    return transpose

def getVerticalCount(grid, searchString) -> int:
    transpose = transposeGrid(grid)
    count = getHorizontalCount(transpose, searchString)
    return count

def getDiagonalCount(grid, searchString) -> int:
    return getMainDiagonalCount(grid, searchString) + getSecondDiagonalCount(grid, searchString)

def getMainDiagonalCount(grid, searchString) -> int:
    searchString = list(searchString)
    count = 0
    for i in range(len(grid) - len(searchString) + 1):
        for j in range(len(grid[i]) - len(searchString) + 1):
            word = []
            for k in range(len(searchString)):
                word.append(grid[i + k][j + k])
            if word == searchString or word == searchString[::-1]:
                count += 1
    return count

def getSecondDiagonalCount(grid, searchString) -> int:
    searchString = list(searchString)
    count = 0
    for i in range(len(grid) - len(searchString) + 1):
        for j in range(len(searchString) - 1, len(grid[i])):
            word = []
            for k in range(len(searchString)):
                word.append(grid[i + k][j - k])
            if word == searchString or word == searchString[::-1]:
                count += 1
    return count

def getWordCount(grid, searchString) -> int:
    return getHorizontalCount(grid, searchString) + getVerticalCount(grid, searchString) + getDiagonalCount(grid, searchString)

main()