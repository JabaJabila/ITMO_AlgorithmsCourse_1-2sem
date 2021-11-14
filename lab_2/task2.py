def mergeSort(array):
    
    if len(array) > 1:
        mid = len(array) // 2
        left_half = array[:mid]
        right_half = array[mid:]

        mergeSort(left_half)
        mergeSort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            country1 = left_half[i]
            country1 = country1[:country1.index(' ')]
            country2 = right_half[j]
            country2 = country2[:country2.index(' ')]
            if country1 <= country2:
                array[k] = left_half[i]
                i += 1
            else:
                array[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            array[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            array[k] = right_half[j]
            j += 1
            k += 1


race_file = list(open('race.in'))
length = int(race_file[0])
array = [0] * length

for i in range(1, length + 1):
    array[i - 1] = race_file[i]
    array[i - 1] = array[i - 1].replace('\n', '')

mergeSort(array)
prev_country = ''

with open('race.out', 'w') as file:
    for line in array:
        country = line[:line.index(' ')]
        if country != prev_country:
            file.write('=== ' + country + ' ===\n')
            prev_country = country
        file.write(line[line.index(' ') + 1:] + '\n')