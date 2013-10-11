#!/usr/bin/python
# -*- coding: utf-8 -*-


def solveIt(inputData):
    # Modify this code to run your optimization algorithm

    # parse the input
    lines = inputData.split('\n')

    firstLine = lines[0].split()
    items = int(firstLine[0])
    capacity = int(firstLine[1])

    values = []
    weights = []
    
    for i in range(1, items+1):
        line = lines[i]
        parts = line.split()

        values.append(int(parts[0]))
        weights.append(int(parts[1]))

    items = len(values)

    # a trivial greedy algorithm for filling the knapsack
    # it takes items in-order until the knapsack is full
    value = 0
    weight = 0
    taken = []
    knapsack = []

    for i in range(0,capacity+1):
        knapsack.append([0])

        
    for j in range(1,items+1):
        for i in range(capacity+1):
            if weights[j-1] <= i:
                knapsack[i].append(max(values[j-1] + knapsack[i-weights[j-1]][j-1], knapsack[i][j-1]))
            else:
                knapsack[i].append(knapsack[i][j-1])
    
    i = capacity
    j = items

    while i!=0 and j!=0:        
        if knapsack[i][j-1] == knapsack[i][j]:
            j = j - 1
            taken.append(0)
        else:
            taken.append(1)
            i = i - weights[j-1]
            j = j - 1
            
    taken.reverse() 
    
    value = knapsack[capacity][items]

    # prepare the solution in the specified output format
    outputData = str(value) + ' ' + str(1) + '\n'
    outputData += ' '.join(map(str, taken))
    return outputData


import sys

if __name__ == '__main__':
    if len(sys.argv) > 1:
        fileLocation = sys.argv[1].strip()
        inputDataFile = open(fileLocation, 'r')
        inputData = ''.join(inputDataFile.readlines())
        inputDataFile.close()
        print solveIt(inputData)
    else:
        print 'This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/ks_4_0)'
