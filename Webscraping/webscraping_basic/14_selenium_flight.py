
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

browser = webdriver.Chrome()
browser.maximize_window() # browser maximize

url = "https://flight.naver.com/flights/"
browser.get(url) # move to url

browser.find_element_by_link_text("가는날 선택").click()

# choose current month's 27th and 28th
# browser.find_elements_by_link_text("27")[0].click()
# browser.find_elements_by_link_text("28")[0].click()

# next month's 27th and 28th
browser.find_elements_by_link_text("27")[1].click()
browser.find_elements_by_link_text("28")[1].click()

browser.find_element_by_xpath("//*[@id='recommendationList']/ul/li[1]").click()

browser.find_element_by_link_text("항공권 검색").click()

try:
    elem = WebDriverWait(browser, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='content']/div[2]/div/div[4]/ul/li[1]")))
    print(elem.text)
finally:
    browser.quit()

# first search result
# elem = browser.find_element_by_xpath("//*[@id='content']/div[2]/div/div[4]/ul/li[1]")
# print(elem.text)