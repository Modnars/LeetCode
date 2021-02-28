#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import datetime
import os

'''
Output Example:
// URL    : 
// Author : Modnar
// Date   : 2021/02/27

...

'''

author = 'Modnar'                                   # Set the author's name.
folder = str(os.getcwd())                           # Get the current folder.
date = datetime.datetime.now().strftime("%Y/%m/%d") # Get current time.
folder = folder.split('/')[-1]
print(('// URL    : \n'
       '// Author : ' + author + '\n'
       '// Date   : ' + date + '\n'
       '\n'
       '#include <bits/stdc++.h>\n'
       '\n'
       '/* ************************* */\n'
       '\n\n'
       '/* ************************* */\n'
       '\n'
       'int main(int argc, char *const argv[]) {\n'
       '    return EXIT_SUCCESS;\n'
       '}\n'))

