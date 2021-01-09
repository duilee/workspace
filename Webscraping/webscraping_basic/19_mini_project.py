from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys 
import csv
import requests
from bs4 import BeautifulSoup

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.135 Safari/537.36"}
options = webdriver.ChromeOptions()
options.headless = True
options.add_argument("window-size=1920x1080")
options.add_argument("user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36")

browser = webdriver.Chrome(options=options)
browser.maximize_window() # browser maximize

url = "https://daum.net"
browser.get(url) # move to url

browser.find_element_by_name("q").send_keys("송파 헬리오시티")
browser.find_element_by_xpath("//*[@id='daumSearch']/fieldset/div/div/button[2]").click()

soup = BeautifulSoup(browser.page_source, "lxml")

items = soup.find_all("tr")

for i in range(1, len(items)):
    print("============매물{0}===========".format(i))
    infos = items[i].find_all('td')
    indexes = ['거래', '면적', '가격', '동', '층']
    for j, info in enumerate(infos):
        text = info.get_text().strip()
        if j == 1:
            print("{0} : {1} (공급/전용)".format(indexes[j], text))
        elif j == 2:
            print("{0} : {1} (만원)".format(indexes[j], text))
        else:
            print("{0} : {1}".format(indexes[j], text))




