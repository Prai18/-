"""
beautifulsoup4==4.7.1
lxml==4.3.4
requests==2.22.0
urllib3==1.25.3
"""
import os
import time
import requests
from bs4 import BeautifulSoup

#url
target_url = "http://news.yahoo.co.jp/categories/world"
# target_url = "http://www3.nhk.or.jp/news/cat06.html?utm_int=all_header_menu_news-international"
#get html
r = requests.get(target_url)
#③HTMLパース用のオブジェクトを作成します。
# soup = BeautifulSoup(r.text,"html.parser")
soup = BeautifulSoup(r.text,"lxml")

# print(h2)
# if h2.text=="日本":
tr=[]
for trend in soup.find(class_="topicsList_main"):
	tr.append(trend.getText())

for i in tr:
	time.sleep(5)
	os.system("osascript -e 'display notification\" {}\"'".format(i))
	
