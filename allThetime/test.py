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

cnt = 0

# 写入excel中
wb = xlwt.Workbook(encoding='utf-8')
ws = wb.add_sheet('S1', cell_overwrite_ok=True)

for i in range(10):
    # 给定URL路径 (http或https开头)
    url = 'https://movie.douban.com/top250?start='+ str(i*25) +'&filter='
    print(url)

    # 获取域名
    # host = urlparse(url).netloc 

    # 访问页面 
    res = requests.get(url, headers = headers)
    res.encoding = 'utf-8'
    contents = res.text

    # 格式化
    soup = BeautifulSoup(contents, "html.parser")

    # 获取每项
    all_li = soup.ol.find_all('li')


    
    for item in all_li:
        # 名称
        name = item.find_all('img')[0]['alt']
        # 评分
        rate = 0
        span = item.find_all('span')
        for sp in span:
            try:
                rate = float(sp.string)
                cnt += 1
            except:
                continue
        print(cnt)
        print(name)
        print(rate)
        ws.write(cnt-1, 0, cnt)
        ws.write(cnt-1, 1, name)
        ws.write(cnt-1, 2, rate)
        
    time.sleep(2)

wb.save('douban250.xls')
