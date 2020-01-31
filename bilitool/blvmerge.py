import os
import re

cd = os.getcwd()+'\\result'

if os.path.exists(cd) == False :
    exit

for root, dirs, files in os.walk(cd):
    # print(root)
    # print(files)
    if len(files) != 0:
        print(root)
        f = open(root + '\\merge.txt', 'w')
        for file in files:
            if file.endswith('.mp4'):
                f.write('file \'' + os.path.join(root, file) + '\'\n')
        