import requests

res = requests.get("http://google.com")
print("response:", res.status_code) #200 = functioning
res.raise_for_status()

# res = requests.get("http://nadocoding.tistory.com")
# print("response:", res.status_code) #403 = unable to get info

# if res.status_code == requests.codes.ok:
#     print("functioning")
# else:
#     print("problem encountered. [error code", res.status_code, "]")

print(len(res.text))
print(res.text)

with open("mygoogle.html", "w", encoding="utf8") as f:
    f.write(res.text)