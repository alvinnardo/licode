from bs4 import BeautifulSoup
from urllib.parse import urlparse
import requests
import openpyxl
import xlwt
import os
import sys
import time

# 设置UA
headers = {
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36' +
    '(KHTML, like Gecko) Chrome/88.0.4324.104 Safari/537.36'
}

html = open('nk.html', 'w', encoding='utf-8')

for i in range(292):

    print(i)

    # 给定URL路径 (http或https开头)
    url = 'https://www.nowcoder.com/ta/review-c/review?page=' + str(i)

    # 获取域名
    # host = urlparse(url).netloc

    # 访问页面
    res = requests.get(url, headers=headers)
    res.encoding = 'utf-8'
    contents = res.text

    # 写入txt中
    # f = open('test.html', 'w', encoding='utf-8')
    # f.writelines(contents)
    # f.close()

    # 格式化
    soup = BeautifulSoup(contents, "html.parser")

    # 获取题目
    re = soup.find_all(name='div', attrs={"class": "final-question"})
    html.writelines(str(i))
    html.writelines(str(re[0]))

    time.sleep(1)

html.close()
