from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Firefox()
driver.get("http://micampus.csf.itesm.mx/index.php/division-de-diseno-ingenieria-y-arquitectura/directorio")

personas = {}

elements = driver.find_elements(By.CSS_SELECTOR, "td")

i = 0
while i < len(elements):
	nombre = elements[i].text.split('\n')[0]
	email = elements[i+3].text
	personas[nombre] = email
	i += 4

print(personas)

driver.close()
