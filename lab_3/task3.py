def countsort(array, size, c):
    output = [0] * size
    count = [0] * 26
 
    for i in range(0, size):
        count[array[i][c]] += 1
 
    for i in range(1, 26):
        count[i] += count[i - 1]
 
    i = size - 1
 
    while i >= 0:
        output[count[array[i][c]] - 1] = array[i]
        count[array[i][c]] -= 1
        i -= 1
 
    for i in range(0, size):
        array[i] = output[i]
 
def radixsort(array, n, m, phases):
    for i in range(0, phases):
        countsort(array, n, m - 1 - i)
 
inputf = list(open("radixsort.in"))
outputf = open("radixsort.out", "w")
array = []
tmp = str(inputf[0])
tmp = tmp.split()
n, m, phases = int(tmp[0]), int(tmp[1]), int(tmp[2])
 
for line in inputf[1:]:
    array.append(line[:m])
 
sarray = []
  
for i in range(n):
    sarray.append([])
    for j in range(m):
        sarray[i].append(ord(array[i][j]) - 97)
 
radixsort(sarray, n, m, phases)
 
answer = []
 
for i in range(n):
    answer.append("")
    for j in range(m):
        answer[i] += chr(sarray[i][j] + 97)
 
for line in answer:
    outputf.write(line + "\n")