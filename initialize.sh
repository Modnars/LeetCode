#!/bin/sh

if [[ $# -lt 1 ]]; then
    echo "usage: $(basename $0) ProblemNumber [SourceFileExtension]"
    exit 1
fi

filename="main"
author="modnarshen"
root_dir=`pwd`
src_dir="src"

problem_number=$1
file_extension=${2:-"cc"}

if [[ ! -d $src_dir ]]; then
    mkdir -p $src_dir
fi
cd $src_dir

mkdir -p $problem_number && cd $problem_number
if [[ -f "$filename.$file_extension" ]]; then
    echo "file already exists"
else
    new_file="$filename.$file_extension"
    file_date=`date +%Y.%m.%d`
if [[ ${file_extension} == "cc" ]]; then  # For C++ file
cat > $new_file <<END_OF_FILE
// File:   ${problem_number}/${new_file}
// Author: ${author}
// Date:   ${file_date}

#include <bits/stdc++.h>

int main(int argc, const char *argv[]) {
    return 0;
}
END_OF_FILE
echo -e "all:\n\tg++ -std=c++11 -Wall -Werror ${new_file}" > Makefile
elif [[ ${file_extension} == "py" ]]; then  # For Python3 file
cat > $new_file <<END_OF_FILE
#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

def main():
    pass

if __name__ == '__main__':
    main()
END_OF_FILE
fi
fi

cd $root_dir && python3 update_readme.py $problem_number
