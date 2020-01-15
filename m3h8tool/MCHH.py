import os
import re
import ffmpeg

def MCHH_transfer(dir):
    max_length = 0
    num_list = []
    path_list = [os.path.join(root, file)
                 for root, dirs, files in os.walk(dir) for file in files]
    for file in path_list:
        num = re.findall('\d+$', file)
        if len(num) != 0:
            num_list.append(num[0])
            if len(num[0]) > max_length:
                max_length = len(num[0])

    if max_length != 0:
        for i in range(len(path_list)):
            # print(path_list[i])
            # print(prefix_list[i]+'0'*(max_length-len(num_list[i]))+num_list[i])
            if os.path.exists(path_list[i]):
                os.rename(path_list[i], path_list[i].rstrip(
                    num_list[i])+'0'*(max_length-len(num_list[i]))+num_list[i])


def MCHH_merge(dir, num_vedio):
    path_list = [os.path.join(root, file)
                 for root, dirs, files in os.walk(dir) for file in files]
    f = open('merge.txt', 'w+')
    for line in path_list:
        f.write('file \'' + line +'\'\n')
    f.close()
    if os.path.exists('result_merge') == False:
        os.mkdir('result_merge')
    os.system(r"ffmpeg -f concat -safe 0 -i merge.txt -c copy result_merge\\video" + str(num_vedio) +".mp4")
    os.remove('merge.txt')


cd = os.getcwd()
num_vedio = 0

for root, dirs, files in os.walk(cd):
    for dir in dirs: 
        if dir != '__pycache__' or dir != 'result_merge':
            MCHH_transfer(dir)
            MCHH_merge(dir, num_vedio)
            num_vedio += 1
