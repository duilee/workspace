from selenium import webdriver
from selenium.webdriver.common.by import By
import time

options = webdriver.ChromeOptions()
options.headless = False
options.add_argument("window-size=1920x1080")
options.add_argument("user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36")

browser = webdriver.Chrome(options=options)

browser.get('https://www.w3schools.com/tags/tryit.asp?filename=tryhtml_option')

browser.switch_to.frame('iframeResult')

"""
# cars 에 해당하는 element find 후 4번째 select
elem = browser.find_element_by_xpath('//*[@id="cars"]/option[4]')

elem.click()
"""

"""
# 텍스트값을 이용해서 선택
# 텍스트가 아우디인 항목 선택
elem = browser.find_element_by_xpath('//*[@id="cars"]/option[text()="Audi"]')
elem.click()
"""

# 텍스트값 부분 일치
elem = browser.find_element_by_xpath('//*[@id="cars"]/option[contains(text(), "Au")]')
elem.click()

time.sleep(5)
browser.quit()

#//*[@id="cars"]/option[4]