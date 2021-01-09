import csv
import requests
from bs4 import BeautifulSoup

headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.135 Safari/537.36"}
url = "https://finance.naver.com/sise/sise_market_sum.nhn?sosok=0&page="

filename = "enterprisevalue1-200.csv"
# without newline gives extra line spacing, so add newline = ""
# for excel use encoding = "utf-8-sig"
f = open(filename, "w", encoding="utf-8-sig", newline="")
writer = csv.writer(f)

title = "N	종목명	현재가	전일비	등락률	액면가	시가총액	상장주식수	외국인비율	거래량	PER	ROE	토론실".split("\t")
print(type(title))
writer.writerow(title)

for page in range(1,5):
    res = requests.get(url + str(page), headers = headers)
    res.raise_for_status()
    soup = BeautifulSoup(res.text, "lxml")

    data_rows = soup.find("table", attrs={'class': 'type_2'}).find("tbody").find_all ("tr")
    for row in data_rows:
        columns = row.find_all("td")
        # take only data with meaningful numbers
        if len(columns) <=1:
            continue
        # .strip() gets rid of unnecessary values \n, \t and such
        data = [column.get_text().strip() for column in columns]
        #print(data)
        #write csv data with writerow
        writer.writerow(data)