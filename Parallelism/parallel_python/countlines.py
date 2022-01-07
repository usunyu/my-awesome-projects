import sys

input_files = sys.argv
input_files.pop(0)

def count_lines(input_file: str):
    with open(input_file) as f:
        lines = f.readlines()
        return len(lines)

# for input_file in input_files:
#     print(count_lines(input_file))

print(sum(list(map(count_lines, input_files))))