import sys
import re
from functools import reduce
import multiprocessing
from multiprocessing import Pool


def count_words(filename):
    """
    Count the number of times every word in the file `filename`
    is contained in this file.

    Args:
        filename (str): the filename to count the words in

    Returns:
        dict: a mapping of word to count
    """

    all_words = {}

    with open(filename) as f:
        for line in f:
            words = line.split()

            for word in words:
                # lowercase the word and remove all
                # characters that are not [a-z] or hyphen
                word = word.lower()
                match = re.search(r"([a-z\-]+)", word)

                if match:
                    word = match.groups()[0]

                    if word in all_words:
                        all_words[word] += 1
                    else:
                        all_words[word] = 1

    return all_words


def reduce_dicts(dict1, dict2):
    """
    Combine (reduce) the passed two dictionaries to return
    a dictionary that contains the keys of both, where the
    values are equal to the sum of values for each key
    """

    # explicitly copy the dictionary, as otherwise
    # we risk modifying 'dict1'
    combined = {}

    for key in dict1:
        combined[key] = dict1[key]

    for key in dict2:
        if key in combined:
            combined[key] += dict2[key]
        else:
            combined[key] = dict2[key]

    return combined


input_files = sys.argv[1:]

with Pool(multiprocessing.cpu_count()) as pool:
    count_ret = pool.map(count_words, input_files)
    # print(count_ret)

total_ret = reduce(reduce_dicts, count_ret)


# for word, count in total_ret.items():
#     if count >= 2000:
#         print(f"{word}: {count}")

for word in sorted(total_ret.keys()):
    if total_ret[word] > 2000:
        print("%s == %s" % (word, total_ret[word]))
