from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import requests
import re
from bs4 import BeautifulSoup
import time
browser = webdriver.Chrome()
browser.maximize_window()

# move to page
url = "https://www.instagram.com/"
browser.get(url)

time.sleep(2)

browser.find_element_by_name("username").send_keys("") # Your username
browser.find_element_by_name("password").send_keys("") # Your password

time.sleep(2)

browser.find_element_by_xpath("//*[@id='loginForm']/div/div[3]/button").click()

#click on my profile pic, and click profile
time.sleep(2)
browser.find_element_by_xpath("//*[@id='react-root']/section/nav/div[2]/div/div/div[3]/div/div[5]/span/img").click()
time.sleep(1)
browser.find_element_by_xpath("//*[@id='react-root']/section/nav/div[2]/div/div/div[3]/div/div[5]/div[2]/div/div[2]/div[2]/a[1]/div").click()

#click on followers
elem = WebDriverWait(browser, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='react-root']/section/main/div/header/section/ul/li[2]/a")))
elem.click()
time.sleep(2)

# scroll down the element
dialog = browser.find_element_by_xpath("/html/body/div[4]/div/div/div[2]")

prev_height = browser.execute_script("return arguments[0].scrollHeight", dialog)

while True:
    # scroll to the bottom

    browser.execute_script('arguments[0].scrollTop = arguments[0].scrollHeight', dialog)

    time.sleep(2)
    
    #get current height of the document
    curr_height = browser.execute_script("return arguments[0].scrollHeight", dialog)

    if curr_height == prev_height:
        break

    prev_height = curr_height

print("scroll complete")

soup = BeautifulSoup(browser.page_source, "lxml")

followers = soup.find_all('a', attrs={'class':re.compile("^FPmhX")})
follower_lst = []
for follower in followers:
    follower_lst += [follower.get_text()]


#exit and click on following
browser.find_element_by_xpath("/html/body/div[4]/div/div/div[1]/div/div[2]/button").click()

elem = WebDriverWait(browser, 10).until(EC.presence_of_element_located((By.XPATH, "//*[@id='react-root']/section/main/div/header/section/ul/li[3]/a")))
elem.click()
time.sleep(2)

dialog = browser.find_element_by_xpath("/html/body/div[4]/div/div/div[2]")
prev_height = browser.execute_script("return arguments[0].scrollHeight", dialog)

while True:
    # scroll to the bottom

    browser.execute_script('arguments[0].scrollTop = arguments[0].scrollHeight', dialog)

    time.sleep(2)
    
    #get current height of the document
    curr_height = browser.execute_script("return arguments[0].scrollHeight", dialog)

    if curr_height == prev_height:
        break

    prev_height = curr_height

soup = BeautifulSoup(browser.page_source, "lxml")

followings = soup.find_all('a', attrs={'class':re.compile("^FPmhX")})
not_following_back_lst = []

for following in followings:
    person = following.get_text()
    if person not in follower_lst:
        not_following_back_lst += [person]

print(not_following_back_lst)





