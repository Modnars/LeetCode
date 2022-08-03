#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sys
import regex

def main():
    if len(sys.argv) < 1:
        sys.stderr.write('usage: %s ProblemNumber', sys.argv[0])
        return 1
    re_pattern = r'\|\[(.*)\]\((.*)\)\|'
    items = []
    found = False
    key = sys.argv[1]
    with open('README.md', 'r', encoding='utf-8') as f:
        for line in f:
            match_obj = regex.match(re_pattern, line)
            if match_obj:
                items.append((match_obj.group(1), line))
                found |= match_obj.group(1) == key
    if not found:
        key_tuple = (key, "|[%s](./src/%s/main.cc)|\n" % (key, key))
        i = 0
        while i < len(items) and items[i][0] <= key: i += 1
        if i < len(items): items.insert(i, key_tuple)
        else: items.append(key_tuple)

    with open('README.md', 'w', encoding='utf-8') as f:
        f.write('# LeetCode 2022\n\n')
        f.write('## C++\n')
        f.write('|Problem|\n|:-:|\n')
        for t in items:
            f.write(t[1])


if __name__ == '__main__':
    main()
