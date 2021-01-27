import os
import re
import ffmpeg

# 用来格式转换——补0防止出现顺序错乱问题
def MCHH_transfer(dir):
    max_length = 0
    num_list = []
    path_list = [os.path.join(root, file)
                 for root, dirs, files in os.walk(dir) for file in files if len(file)<20]
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

# 合并
def MCHH_merge(dir, num_vedio):
    path_list = [os.path.join(root, file)
                 for root, dirs, files in os.walk(dir) for file in files if len(file)<20]
    
    # 将合并顺序写入文件中
    f = open('merge.txt', 'w+')
    for line in path_list:
        f.write('file \'' + line +'\'\n')
    f.close()
    if os.path.exists('result_merge') == False:
        os.mkdir('result_merge')
    
    # 结尾的文件名可以自己做调整
    os.system(r"ffmpeg -f concat -safe 0 -i merge.txt -c copy result_merge\\第" + str(num_vedio) +"集.mp4")
    os.remove('merge.txt')


cd = os.getcwd()
# 从1开始，可以调整
num_vedio = 1

for root, dirs, files in os.walk(cd):
    for dir in dirs: 
        if dir == '__pycache__' or dir == 'result_merge':
            continue
        else:
            MCHH_transfer(dir)
            MCHH_merge(dir, num_vedio)
            num_vedio += 1
