import requests
from bs4 import BeautifulSoup

url = "https://comic.naver.com/webtoon/weekday.nhn"
res = requests.get(url)
res.raise_for_status()

soup = BeautifulSoup(res.text, "lxml")

# get all list from naver webtoon
cartoons = soup.find_all("a", attrs={"class":"title"})
# all element with class = 'title' and 'a' element
for cartoon in cartoons:
    print(cartoon.get_text())