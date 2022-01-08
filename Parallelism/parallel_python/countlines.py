import sys
from functools import reduce
import multiprocessing
from multiprocessing import Pool

input_files = sys.argv[1:]


def count_lines(input_file: str):
    with open(input_file) as f:
        lines = f.readlines()
        return len(lines)

# for input_file in input_files:
#     print(count_lines(input_file))

# print(list(zip(input_files, map(count_lines, input_files))))


with Pool(multiprocessing.cpu_count()) as pool:
    count_ret = pool.map(count_lines, input_files)
    print(list(zip(input_files, count_ret)))


def add(a: float, b: float) -> float:
    return a + b


total = reduce(add, count_ret)
print(f"Total: {total}")
