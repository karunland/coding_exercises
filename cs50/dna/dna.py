import csv
from sys import argv, exit


def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)
    return longest_run


def main():

    # TODO: Check for command-line usage

    if len(argv) != 3:
        exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable

    database = []
    # store csv file in database list
    with open(argv[1], 'r') as file:
        for item in csv.reader(file):
            database.append(item)

    # TODO: Read DNA sequence file into a variable

    sequence = ''
    # read file's first line and assign it to a vatiable
    with open(argv[2], 'r') as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence

    dna = []
    k = int(0)

    # start from index 1 and check how many time does it repeat for each elemt
    for i in database[0][1:]:
        tempstr = str(i)
        # use cs50 s longest run function for longest matched string
        temp = longest_match(sequence=sequence, subsequence=tempstr)
        dna.append(str(temp))
        k += 1

    # TODO: Check database for matching profiles

    successfull = 0
    t = 1

    for i in database[1:]:
        tomatch = i[1:]

        # print(tomatch)

        if dna == tomatch:
            print(f'{database[t][0]}')
            return 0
        t += 1

    print("No match")
    return 0


if __name__ == "__main__":
    main()
