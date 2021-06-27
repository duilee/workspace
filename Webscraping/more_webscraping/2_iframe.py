"""
<html>
    <body>
    <iframe id="1">
        <html>
            <body>
            </body>
        <html>
    </iframe>

    <iframe id="1">
        <html>
            <body>
            </body>
        <html>
    </iframe>

    </body>
</html>

# iframe contains seperate html, hence access separately
"""
# frame 전환
from selenium import webdriver
import time

options = webdriver.ChromeOptions()
options.headless = False
options.add_argument("window-size=1920x1080")
options.add_argument("user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.102 Safari/537.36")

browser = webdriver.Chrome(options=options)

browser.get('https://www.w3schools.com/tags/tryit.asp?filename=tryhtml5_input_type_radio')

time.sleep(2)

browser.switch_to.frame('iframeResult')

time.sleep(2)

elem = browser.find_element_by_xpath('//*[@id="male"]')

elem.click()

time.sleep(5)

browser.switch_to.default_content() # 상위

browser.quit()