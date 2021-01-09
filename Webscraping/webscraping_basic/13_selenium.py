from selenium import webdriver

# if Chrome .exe in other directory must add within brackets
browser = webdriver.Chrome("./chromedriver.exe")
browser.get("http://naver.com")

# elem = browser.find_element_by_class_name("link_login")
# >>> elem.click()
# >>> browser.back()
# >>> browser.forward()
# >>> browser.back() 
# >>> elem = browser.find_element_by_id("query")
# >>> from selenium.webdriver.common.keys import Keys 
# >>> elem.send_keys("나도코딩")
# >>> elem.send_keys(Keys.ENTER)

# >>> elem = browser.find_element_by_name("q")
# >>> elem.send_keys("나도코딩")
# >>> elem = browser.find_element_by_xpath("//*[@id='daumSearch']/fieldset/div/div/button[2]")
# >>> elem
# <selenium.webdriver.remote.webelement.WebElement (session="c11fa6c4ae0f6548e73459bc1b42bb98", element="501b6727-fcdb-4c74-9d99-c6399c60b772")>
# >>> elem.click()
# >>> broswer.quit()