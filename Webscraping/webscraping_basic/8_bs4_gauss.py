import requests
from bs4 import BeautifulSoup

url = "https://comic.naver.com/webtoon/list.nhn?titleId=675554"

res = requests.get(url)
res.raise_for_status()

soup = BeautifulSoup(res.text, "lxml")

# title = cartoons[0].a.get_text()
# link = cartoons[0].a["href"]
# print(title)
# print("https://comic.naver.com" + link)

# for cartoon in cartoons:
#     title = cartoon.a.get_text()
#     link = "https://comic.naver.com" + cartoon.a["href"]
#     print(title, link)

# get ratings
total_rate = 0
cartoons = soup.find_all("div", attrs={"class":"rating_type"})
for cartoon in cartoons:
    rate = cartoon.find("strong").get_text()
    #print(cartoon.strong.get_text())
    print(rate)
    total_rate += float(rate)

print("total score:", total_rate)
print("average score:", total_rate / len(cartoons))

# further story = BeautifulSoup documentation 
