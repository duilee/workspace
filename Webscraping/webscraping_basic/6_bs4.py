import requests
from bs4 import BeautifulSoup

url = "https://comic.naver.com/webtoon/weekday.nhn"
res = requests.get(url)
res.raise_for_status()

soup = BeautifulSoup(res.text, "lxml")
# print(soup.title.get_text())
# print(soup.a) # first 'a' detected
# print(soup.a.attrs) # 'a' element's attributes
# print(soup.a["href"]) # 'a' element's attribute value

# print(soup.find("a", attrs={"class" : "Nbtn_upload"})) # first element that satisfy the criteria 
# print(soup.find( attrs={"class" : "Nbtn_upload"}))

# print(soup.find("li", attrs={"class":"rank01"}))
rank1 = soup.find("li", attrs={"class":"rank01"})
# print(rank1.a.get_text())
# print(rank1.next_sibling.next_sibling)
# rank2 = rank1.next_sibling.next_sibling
# rank3 = rank2.next_sibling.next_sibling
# print(rank3.a.get_text())

# rank2 = rank3.previous_sibling.previous_sibling
# print(rank2.a.get_text())
# print(rank1.parent)
# rank2 = rank1.find_next_sibling("li")
# print(rank2.a.get_text())
# rank3 = rank2.find_next_sibling("li")
# print(rank3.a.get_text())
# rank2 = rank3.find_previous_sibling("li")
# print(rank2.a.get_text())

# print(rank1.find_next_sibling("li"))

webtoon = soup.find("a", text="독립일기-24화 쓰레기 줄이기")
print(webtoon)
