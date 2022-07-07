#!/bin/python3
# from apps.main import cars

import sys
import os
sys.path.append(os.path.join(os.path.dirname(__file__), '../'))

from apps.main import cars

# create student class
class Student:
    def __init__(self, name, age, score):
        self.name = name
        self.age = age
        self.score = score
    def __str__(self):
        return 'Student(name=%s, age=%d, score=%d)' % (self.name, self.age, self.score)
    __repr__ = __str__
    def print_score(self):
        print('%s: %s' % (self.name, self.score))


def main():
    print(__file__)
    my_cars = [
        cars('BMW', 'X5', '2018', 'black'),
        cars('AUDI', 'A5', '2014', 'white'),
    ]
    for i in range(len(my_cars)):
        my_cars[i].print_cars()

if __name__ == "__main__":
    exit(main())
