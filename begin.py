#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import datetime
import os

'''
Output Example:
// URL    : 
// Author : Modnar
// Date   : 2020/01/25

...

'''

author = 'Modnar'                                   # Set the author's name.
folder = str(os.getcwd())                           # Get the current folder.
date = datetime.datetime.now().strftime("%Y/%m/%d") # Get current time.
folder = folder.split('/')[-1]
print('// URL    : ')
print('// Author : %s' % author)
print('// Date   : %s' % date)
print()
print('#include <cstdlib>')
print('#include <iostream>')
print()
print('/* ************************* */')
print()
print()
print('/* ************************* */')
print()
print('int main(int argc, const char *argv[]) {')
print('    return EXIT_SUCCESS;')
print('}')
