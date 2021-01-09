

from selenium import webdriver
browser = webdriver.Chrome()
browser.maximize_window()

# move to page
url = "https://play.google.com/store/movies/top"
browser.get(url)

# scroll down
# browser.execute_script("window.scrollTo(0, 1080)")
# browser.execute_script("window.scrollTo(0, 2080)")

# move to the bottom of the page
# browser.execute_script("window.scrollTo(0, document.body.scrollHeight)")

import time
interval = 5

# current document height
prev_height = browser.execute_script("return document.body.scrollHeight")


while True:
    # scroll to the bottom

    browser.execute_script("window.scrollTo(0, document.body.scrollHeight)")

    time.sleep(2)
    
    #get current height of the document
    curr_height = browser.execute_script("return document.body.scrollHeight")

    if curr_height == prev_height:
        break

    prev_height = curr_height

print("scroll complete")

# for pages that requires movement i.e. scrolling

import requests
from bs4 import BeautifulSoup

soup = BeautifulSoup(browser.page_source, "lxml")

# movies = soup.find_all("div", attrs={"class":["ImZGtf mpg5gc", "Vpfmgd"]})
movies = soup.find_all("div", attrs={"class":"Vpfmgd"})
print(len(movies))

for movie in movies:
    title = movie.find("div", attrs={'class':'WsMG1c nnK0zc'}).get_text()
    
    original_price = movie.find("span", attrs={"class" : "SUZt4c djCuy"})
    if original_price:
        original_price = original_price.get_text()
    else:
        #print(title, "movie not discounted")
        continue

    # discounted price    
    price = movie.find("span", attrs={"class":"VfPpfd ZdBevf i5DZme"}).get_text()

    link = movie.find("a", attrs={"class" : "JC71ub"})["href"]

    # actual link : https://play.google.com + link
    print(f"title:{title}")
    print(f"price before discount: {original_price}")
    print(f"price after discount: {price}")
    print("link:", "https://play.google.com" + link)
    print("-"*120)

browser.quit()
