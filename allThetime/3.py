from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup

# 给定URL路径 (http或https开头)
url = 'http://www.baidu.com'

# 两种方式
# 1.使用模拟器方式
mobile_emulation = {'deviceName': 'Galaxy S5'}
options = webdriver.ChromeOptions()
options.add_experimental_option("mobileEmulation", mobile_emulation)

# 2.使用内置Chrome选项
chrome_options = Options()
chrome_options.add_argument('--headless')

# 填充选项，chrome_options选用两种方式之一
browser = webdriver.Chrome(executable_path='chromedriver.exe', chrome_options=chrome_options)

# 访问网页
browser.get(url)

# 写入文件中
f = open('test.html', 'w', encoding='utf-8')
res = browser.page_source
f.write(res)
f.close()

# 格式化
soup = BeautifulSoup(browser.page_source, 'html.parse')
browser.quit()
