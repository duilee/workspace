from selenium import webdriver
import time

browser = webdriver.Chrome() # "./chromedriver.exe"

# move to naver.com
browser.get("http://naver.com")

# click log in
elem = browser.find_element_by_class_name("link_login")
elem.click()

browser.find_element_by_id("id").send_keys("naver_id")
browser.find_element_by_id("pw").send_keys("naver_pw")

browser.find_element_by_id("log.login").click()

time.sleep(3)

# type in new id
#browser.find_element_by_id("id").send_keys("my_id")
browser.find_element_by_id("id").clear()
browser.find_element_by_id("id").send_keys("my_id")

# get html info
print(browser.page_source)

# close browser
browser.close() # only the current tab
browser.quit() # all browser

