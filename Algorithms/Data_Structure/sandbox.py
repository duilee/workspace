import re
s = "para, gr, def."

print(re.sub(r'[^\w]', ' ', s).lower().split())

t = ['e', 'a', 't']
t.sort(key=lambda x: x[0])
print(t)
