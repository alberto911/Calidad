from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

driver = webdriver.Firefox()
driver.get("http://localhost:4000")
driver.find_element(By.XPATH, "/html/body/div/div/div[1]/form/div[2]/div/input").click()
driver.find_element(By.XPATH, "/html/body/div/div/div[1]/form/div/div[2]/input").click()
db_hostname = driver.find_element(By.ID, "input-db-hostname")
db_hostname.clear()
db_hostname.send_keys("db")
db_username = driver.find_element(By.ID, "input-db-username")
db_username.clear()
db_username.send_keys("admin")
driver.find_element(By.ID, "input-db-password").send_keys("admin")
driver.find_element(By.ID, "input-db-database").send_keys("opencart")
driver.find_element(By.ID, "input-db-prefix").clear()
driver.find_element(By.ID, "input-password").send_keys("admin")
driver.find_element(By.ID, "input-email").send_keys("admin@example.com")
driver.find_element(By.XPATH, "/html/body/div/div/div[1]/form/div/div[2]/input").click()

driver.get("http://localhost:4000/admin")
driver.find_element(By.ID, "input-username").send_keys("admin")
password = driver.find_element(By.ID, "input-password")
password.send_keys("admin")
password.send_keys(Keys.RETURN)
WebDriverWait(driver, 5).until(EC.title_contains("Dashboard"))

driver.find_element(By.XPATH, "/html/body/div[1]/div/div[3]/div/div/div[1]/button").click()
driver.find_element(By.XPATH, "/html/body/div[1]/nav/ul/li[2]/a").click()
driver.find_element(By.XPATH, "/html/body/div[1]/nav/ul/li[2]/ul/li[2]/a").click()
driver.find_element(By.XPATH, "/html/body/div[1]/nav/ul/li[2]/ul/li[2]/ul/li[1]/a").click()
driver.find_element(By.XPATH, "/html/body/div/div/div[1]/div/div/a").click()

driver.find_element(By.ID, "input-name1").send_keys("Botella de agua 600 ml")
driver.find_element(By.ID, "input-meta-title1").send_keys("Agua 600")
driver.find_element(By.XPATH, "/html/body/div[1]/div/div[2]/div/div[2]/form/ul/li[2]/a").click()
driver.find_element(By.ID, "input-model").send_keys("A600")
driver.find_element(By.ID, "input-price").send_keys("10")
driver.find_element(By.XPATH, "/html/body/div[1]/div/div[1]/div/div/button").click()
driver.find_element(By.XPATH, "/html/body/div/div/div[1]/div/div/a").click()

driver.find_element(By.ID, "input-name1").send_keys("Botella de agua 1 litro")
driver.find_element(By.ID, "input-meta-title1").send_keys("Agua 1000")
driver.find_element(By.XPATH, "/html/body/div[1]/div/div[2]/div/div[2]/form/ul/li[2]/a").click()
driver.find_element(By.ID, "input-model").send_keys("A1000")
driver.find_element(By.ID, "input-price").send_keys("15")
driver.find_element(By.XPATH, "/html/body/div[1]/div/div[1]/div/div/button").click()

driver.get("http://localhost:4000")
driver.find_element(By.XPATH, "/html/body/header/div/div/div[2]/div/input").send_keys("agua")
driver.find_element(By.XPATH, "/html/body/header/div/div/div[2]/div/div/button").click()
driver.find_element(By.XPATH, "/html/body/div[2]/div/div/div[3]/div[1]/div/div[2]/div[2]/button[1]").click()
driver.find_element(By.XPATH, "/html/body/div[2]/div/div/div[3]/div[2]/div/div[2]/div[2]/button[1]").click()

