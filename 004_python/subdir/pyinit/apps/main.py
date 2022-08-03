# from service import student 
import sys
import os
# sys.path.append(os.path.join(os.path.dirname(__file__), '../'))
# sys.path.insert(1, '/home/karu/Desktop/python/004_python/pyinit/service')
# import services.student. as student

# from services.student import Student


class cars:
    def __init__(self, name, age, date, color):
        self.name = name
        self.age = age
        self.date = date
        self.color = color
    def print_cars(self):
        print(f'{self.name}:{self.age}:{self.date}:{self.color}')


def main():
    print(__file__)
    students = [
        Student('Bob', 20, 88),
        Student('Alice', 19, 99),
        Student('Cindy', 20, 100),
        Student('Bob', 20, 88),
        Student('Alice', 19, 99),
        Student('Cindy', 20, 100),
        Student('Bob', 20, 88),
        Student('Alice', 19, 99),
        Student('Cindy', 20, 100),
    ]
    for i in range(len(students)):
        print(f'new student:{students[i].__str__()}')

if __name__ == "__main__":
    exit(main())