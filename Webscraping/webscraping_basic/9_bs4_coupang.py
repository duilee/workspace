import requests
import re
from bs4 import BeautifulSoup

url = "https://www.coupang.com/np/search?q=%EB%85%B8%ED%8A%B8%EB%B6%81&channel=user&component=&eventCategory=SRP&trcid=&traid=&sorter=scoreDesc&minPrice=&maxPrice=&priceRange=&filterType=&listSize=36&filter=&isPriceRange=false&brand=&offerCondition=&rating=0&page=1&rocketAll=false&searchIndexingToken=1=4&backgroundColor="
headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.135 Safari/537.36"}
res = requests.get(url, headers = headers)
res.raise_for_status()
soup = BeautifulSoup(res.text, "lxml")

items = soup.find_all("li", attrs ={"class":re.compile("^search-product")})
# print(items[0].find("div", attrs={"class":"name"}).get_text())

for item in items:

    ad_badge = item.find("span", attrs={"class":"ad-badge-text"})
    if ad_badge:
        print("###omit advertised items### \n\n")
        continue

    name = item.find("div", attrs={"class":"name"}).get_text()

    # omit Apple products
    if "Apple" in name:
        print("   <Omit Apple Product>")
        continue

    price = item.find("strong", attrs={"class":"price-value"}).get_text()
    rating = item.find("em", attrs={"class":"rating"})
    
    # get only the items with 100+ reviews and 4.5+ ratings
    if rating:
        rating = rating.get_text()
    else:
        print("No rating item omitted")
        continue
    
    rating_cnt = item.find("span", attrs={"class":"rating-total-count"})

    if rating_cnt:
        rating_cnt = rating_cnt.get_text()
        rating_cnt = rating_cnt[1:-1]
        #print("Rating count:", rating_cnt)
    else:
        print("No rating item omitted")
        continue

    if float(rating) >= 4.5 and int(rating_cnt) >= 100:
        print(name, price, rating, rating_cnt)