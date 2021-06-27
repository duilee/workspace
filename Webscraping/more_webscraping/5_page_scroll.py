from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

options = webdriver.ChromeOptions()
options.headless = False
options.add_argument("window-size=1920x1080")
options.add_argument("user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36")

browser = webdriver.Chrome(options=options)

browser.get('https://shopping.naver.com/home/p/index.nhn')

# 무선마우스 입력
browser.find_element_by_xpath('//*[@id="autocompleteWrapper"]/input[1]').send_keys('무선마우스')

# 검색 클릭
browser.find_element_by_xpath('//*[@id="autocompleteWrapper"]/a[2]').click()

# 스크롤

# 지정한 위치로 스크롤
#browser.execute_script('window.scrollTo(0, 1080)')
#browser.execute_script('window.scrollTo(0, 2080)')

# 가장 아래로
#browser.execute_script('window.scrollTo(0, document.body.scrollHeight)')

# 동적 페이지에 대해 마지막까지 스크롤
interval = 2

# 현재 문서 높이 가져오기
prev_height = browser.execute_script('return document.body.scrollHeight')

# 반복 수행
while True:
    # 스크롤 내림
    browser.execute_script('window.scrollTo(0, document.body.scrollHeight)')

    # 페이지 로딩 대기
    time.sleep(interval)

    # 현재 문서 높이 
    curr_height = browser.execute_script('return document.body.scrollHeight')
    if curr_height == prev_height: # 높이 변화가 없으면
        break
    
    prev_height = curr_height

# 맨위로 올리기
browser.execute_script('window.scrollTo(0, 0)')

time.sleep(5)
browser.quit()