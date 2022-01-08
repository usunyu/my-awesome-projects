import sys
from functools import reduce

input_files = sys.argv[1:]


def count_lines(input_file: str):
    with open(input_file) as f:
        lines = f.readlines()
        return len(lines)

# for input_file in input_files:
#     print(count_lines(input_file))


print(list(zip(input_files, map(count_lines, input_files))))


def add(a: float, b: float) -> float:
    return a + b


total = reduce(add, map(count_lines, input_files))
print(f"Total: {total}")
