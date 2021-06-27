from selenium import webdriver
from selenium.webdriver.common.by import By
import time

options = webdriver.ChromeOptions()
options.headless = False
options.add_argument("window-size=1920x1080")
options.add_argument("user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36")

browser = webdriver.Chrome(options=options)

browser.get('https://www.w3schools.com/tags/tryit.asp?filename=tryhtml5_input_type_radio')

browser.switch_to.frame('iframeResult')

time.sleep(1)

elem = browser.find_element_by_xpath('//*[@id="male"]')
# elem = browser.find_element(By.XPATH, '//*[@id="male"]')
# elem = browser.find_element(By.ID, 'idname')

# 선택 안되어 잇으면 선택
if elem.is_selected() == False: 
    print("not selected, so select")
    elem.click()
else:
    print("already selected")

time.sleep(5)

# 선택 안되어 잇으면 선택
if elem.is_selected() == False: 
    print("not selected, so select")
    elem.click()
else:
    print("already selected")

time.sleep(5)

browser.quit()