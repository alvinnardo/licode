from bs4 import BeautifulSoup
from urllib.parse import urlparse
import requests

# 设置UA
headers = {
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36' + 
    '(KHTML, like Gecko) Chrome/88.0.4324.104 Safari/537.36' 
}

# 给定URL路径 (http或https开头)
url = 'http://www.baidu.com'

# 获取域名
host = urlparse(url).netloc 

# 访问页面 
res = requests.get(url, headers = headers)
res.encoding = 'utf-8'
contents = res.text

# 写入文件中
f = open('test.html', 'w', encoding='utf-8')
f.writelines(contents)
f.close()

# 格式化
soup = BeautifulSoup(contents, "html.parser")

