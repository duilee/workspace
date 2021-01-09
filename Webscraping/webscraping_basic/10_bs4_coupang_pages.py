import requests
import re
from bs4 import BeautifulSoup

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.135 Safari/537.36"}

for i in range(1,6):
    print("### page", i, " ###")
    url = "https://www.coupang.com/np/search?q=%EB%85%B8%ED%8A%B8%EB%B6%81&channel=user&component=&eventCategory=SRP&trcid=&traid=&sorter=scoreDesc&minPrice=&maxPrice=&priceRange=&filterType=&listSize=36&filter=&isPriceRange=false&brand=&offerCondition=&rating=0&page={}&rocketAll=false&searchIndexingToken=1=4&backgroundColor=".format(i)

    res = requests.get(url, headers = headers)
    res.raise_for_status()
    soup = BeautifulSoup(res.text, "lxml")

    items = soup.find_all("li", attrs ={"class":re.compile("^search-product")})

    for item in items:

        ad_badge = item.find("span", attrs={"class":"ad-badge-text"})
        if ad_badge:
            print("###omit advertised items### \n\n")
            continue

        name = item.find("div", attrs={"class":"name"}).get_text()

        # omit Apple products
        if "Apple" in name:
            # print("   <Omit Apple Product>")
            continue

        price = item.find("strong", attrs={"class":"price-value"}).get_text()
        rating = item.find("em", attrs={"class":"rating"})
        
        # get only the items with 100+ reviews and 4.5+ ratings
        if rating:
            rating = rating.get_text()
        else:
            # print("No rating item omitted")
            continue
        
        rating_cnt = item.find("span", attrs={"class":"rating-total-count"})

        if rating_cnt:
            rating_cnt = rating_cnt.get_text()[1:-1]
        else:
            # print("No rating item omitted")
            continue
        
        link = item.find("a", attrs={"class":"search-product-link"})["href"]

        if float(rating) >= 4.5 and int(rating_cnt) >= 100:
            # print(name, price, rating, rating_cnt)
            print(f"Product Name : {name}")
            print(f"Price : {price}")
            print(f"Rating : {rating} ({rating_cnt})")
            print("link: {}".format("https://www.coupang.com/"+link))
            print("-"*100)