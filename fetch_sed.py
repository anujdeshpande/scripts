from selenium import webdriver
from selenium.webdriver import ActionChains
from selenium.webdriver.common.keys import Keys
driver=webdriver.Firefox()
action_chains=ActionChains(driver)
url_str="http://www.rosco.com/filters/SED.cfm?titleName=R3410:%20Roscosun%201/8%20CTO&imageName=../images/filters/roscolux/"
w=0
while w < 5000:
 if w < 10:
  k="0"+str(w)    
 else :
  k=str(w)
 new_str=url_str+str(k)+".jpg"  
 driver.get(new_str)
 driver.save_screenshot(str(w)+'.png')
 w=w+1 


