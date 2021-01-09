# i.e. Korean ssn
# 901201-111111
# abcdef-111111 # not valid

# email address
# duilee@gmail.com
# duilee@gmail@gmail.com # not valid

# car licence
# 11B 1234
# 123B 1234

# IP Address
# 192.168.0.1
# 1000.2000.3000.4000 # not valid

import re
#ca?e
#care, cafe, case, cave ... 
#caae, caabe, cace, cade...

p = re.compile("ca.e") # .: one letter string > care, cafe, case... | not caffe
# ^: start of a string (i.e. ^de = desk, destination ... not fade)
# $ : end of string(i.e. se$, case, base... not face )

def print_match(m):
    if m:
        print("m.group():", m.group()) # returns string that matches
        print("m.string:", m.string) # returns input string
        print("m.start():", m.start()) # starting index of matching string
        print("m.end():", m.end()) # end index of matching string
        print("m.span():", m.span()) # start and end index of matching string
    else:
        print("no match")
# match : see if string matches from the beginning
m = p.match("careless")
print_match(m)
print(m)

# m = p.search("good care") #search: see if anything matches within the string
# print_match(m)

# lst = p.findall("good care cafe") #findall: return string that matches
# print(lst)

# 1. p = re.compile("desired form")
# 2. m = p.match("string to compare") : see if matches from the beginning
# 3. m = p.search("string to compare") : see if there is a match within the string
# 4. lst = p.findall("string to compare") : returns list of all matches

# desired form: re (. ^ $)
# W3school for further study
