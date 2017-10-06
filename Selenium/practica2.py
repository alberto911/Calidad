import random
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import Select

driver = webdriver.Firefox()
driver.get("http://micampus.csf.itesm.mx/index.php/division-de-diseno-ingenieria-y-arquitectura/directorio")

personas = {}
elements = driver.find_elements(By.CSS_SELECTOR, "td")

i = 0
while i < len(elements):
	nombre = elements[i].text.split('\n')[0]
	email = elements[i+3].text + 'ca'
	personas[nombre] = email
	i += 4

print(personas)

"""
for nombre, email in personas.items():
	driver.get("http://blazedemo.com/register")
	name_field = driver.find_element(By.ID, "name")
	company_field = driver.find_element(By.ID, "company")
	email_field = driver.find_element(By.ID, "email")
	password_field = driver.find_element(By.ID, "password")
	password_confirm_field = driver.find_element(By.ID, "password-confirm")
	register_button = driver.find_element(By.CLASS_NAME, "btn")

	name_field.send_keys(nombre)
	company_field.send_keys('ITESM')
	email_field.send_keys(email)
	password_field.send_keys('123456')
	password_confirm_field.send_keys('123456')
	register_button.click()

	try:
		WebDriverWait(driver, 10).until(EC.text_to_be_present_in_element((By.CLASS_NAME, "panel-body"), "You are logged in!"))
	finally:
		dropdown_toggle = driver.find_element(By.CLASS_NAME, "dropdown-toggle")
		dropdown_toggle.click()
		logout_link = WebDriverWait(driver, 5).until(EC.element_to_be_clickable((By.LINK_TEXT, "Logout")))
		logout_link.click()"""

nombres = list(personas.keys())

for i in range(7):
	driver.get("http://blazedemo.com/")
	departure_city = Select(driver.find_element(By.NAME, "fromPort"))
	departure_city.select_by_index(i)
	destination_city = Select(driver.find_element(By.NAME, "toPort"))
	destination_city.select_by_index(i)
	driver.find_element(By.CLASS_NAME, "btn-primary").click()

	choose_link = WebDriverWait(driver, 5).until(EC.element_to_be_clickable((By.CLASS_NAME, "btn-small")))
	choose_link.click()

	WebDriverWait(driver, 5).until(EC.title_contains("Purchase"))
	driver.find_element(By.ID, "inputName").send_keys(nombres[i])
	driver.find_element(By.ID, "address").send_keys("Carlos Lazo")
	driver.find_element(By.ID, "city").send_keys("CDMX")
	driver.find_element(By.ID, "state").send_keys("CDMX")
	driver.find_element(By.ID, "zipCode").send_keys("01389")
	driver.find_element(By.ID, "creditCardNumber").send_keys(str(random.randint(1000000000000000,9999999999999999)))
	driver.find_element(By.ID, "creditCardMonth").send_keys(str(random.randint(1,12)))
	driver.find_element(By.ID, "creditCardYear").send_keys(str(random.randint(2018, 2028)))
	driver.find_element(By.ID, "nameOnCard").send_keys(nombres[i])
	driver.find_element(By.CLASS_NAME, "btn-primary").click()

	WebDriverWait(driver, 5).until(EC.title_contains("Confirmation"))

driver.close()   



