import os
import shutil
import sys
import json

# 目的路径
file_result_path = 'result'

# json文件的路径


def getJsonFiles(path, endname):
    return [os.path.join(root, file) for root, dirs, files in os.walk(path) for file in files if file.endswith(endname)]


cd = os.getcwd()
name = "entry.json"

path_list = getJsonFiles(cd, name)
# print(path_list)

file_name_tmp = ''


for path in path_list:
    print(path)

    # 打开并读取文件
    f = open(path, 'r', encoding='utf-8')
    content_list = f.readlines()
    content_str = ''.join(content_list)

    # 将读取的文件转化为字典
    json_dict = json.loads(content_str)

    # 保存指定的内容
    title = json_dict['title'].replace('/', ' ')
    part = json_dict['page_data']['part']
    # print(title)
    # print(part)

    # 更改文件名
    old_file_name = str(path).split('\\')
    old_first_file_name = '\\'.join(
        [old_file_name[0], old_file_name[1], file_result_path, old_file_name[2]])
    old_second_file_name = '\\'.join(
        [old_file_name[0], old_file_name[1], file_result_path, old_file_name[2], old_file_name[3]])
    new_first_file_name = '\\'.join(
        [old_file_name[0], old_file_name[1], file_result_path, title])
    new_second_file_name = '\\'.join(
        [old_file_name[0], old_file_name[1], file_result_path, old_file_name[2], part])
    # print(file_name_tmp + '  ' + old_file_name[2])
    if file_name_tmp != old_file_name[2]:
        file_name_tmp = old_file_name[2]
        try:
            if os.path.exists(old_second_file_name):
                # print('11 old second: ' + old_second_file_name +
                #       ' new second: '+new_second_file_name)
                shutil.move(old_second_file_name, new_second_file_name)
            else:
                # print('12 old second: ' + old_second_file_name+'.mp4' +
                #       ' new second: '+new_second_file_name+'.mp4')
                os.rename(old_second_file_name+'.mp4',
                          new_second_file_name+'.mp4')
            # print('112 old first: ' + old_first_file_name +
            #       ' new first: '+new_first_file_name)
            shutil.move(old_first_file_name, new_first_file_name)
        except:
            print('error')
    else:
        old_second_file_name = '\\'.join(
            [old_file_name[0], old_file_name[1], file_result_path, title, old_file_name[3]])
        new_second_file_name = '\\'.join(
            [old_file_name[0], old_file_name[1], file_result_path, title, part])
        try:
            if os.path.exists(old_second_file_name):
                # print('21 old second' + old_second_file_name +
                #       ' new second:'+new_second_file_name)
                shutil.move(old_second_file_name, new_second_file_name)
            else:
                # print('22 old second' + old_second_file_name+'.mp4' +
                #       ' new second:'+new_second_file_name+'.mp4')
                os.rename(old_second_file_name+'.mp4',
                          new_second_file_name+'.mp4')
        except:
            print('error')
