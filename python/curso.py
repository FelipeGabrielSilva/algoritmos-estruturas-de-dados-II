import pandas as pd
import win32com.client

from datetime import datetime
import os
import time
import re

from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.by import By

class Automacao_Moedas():

    def __init__(self):
        print('Inicial')

    def Configuracao_Driver(self):
        #Configuracao do Driver do Navegador
        configuracao_driver = Options()
        configuracao_driver.add_experimental_option('detach', True)
        #configuracao_driver.add_argument('--headless')

        driver_chrome = Service(
            ChromeDriverManager().install()
        )

        driver_path = ChromeDriverManager().install()
        print("Caminho do Driver -", driver_path)

        return configuracao_driver, driver_chrome

    def Receber_Dados_Moedas(self, configuracao_chrome, driver):
        navegador = webdriver.Chrome(service=driver, options=configuracao_chrome)
        navegador.maximize_window()
        navegador.get('https://cuex.com/pt/usd-brl')
        time.sleep(5)

        #Conversao Dolar
        texto_conversao = navegador.find_element(
            By.XPATH, '//*[@id="section-content"]/cx-converter/cx-calculator/div[2]/div[2]/div[1]/div/cx-calculator-exchange-result/div/div[2]/div/button'
        )
        texto_conversao = texto_conversao.text
        dolar = texto_conversao.replace('BRL','').replace(',', '.')
        dolar = float(dolar)
        dolar = f'{dolar: ,.2f}'
        print(f'Dolar - {dolar}')

        #Euro
        navegador.find_element(
            By.XPATH, '//*[@id="section-content"]/cx-converter/cx-calculator/div[1]/div/cx-calculator-form/form/div/div[2]/div/cx-picker/div/div'
        ).click()

        navegador.find_element(
            By.XPATH, '//*[@id="panelOptions"]/div[2]/div[1]/div[2]/div/div[2]'
        ).click()

        texto_conversao = navegador.find_element(
            By.XPATH, '//*[@id="section-content"]/cx-converter/cx-calculator/div[2]/div[2]/div[1]/div/cx-calculator-exchange-result/div/div[2]/div/button'
        )
        texto_conversao = texto_conversao.text
        euro = texto_conversao.replace('BRL','').replace(',', '.')
        euro = float(euro)
        euro = f'{euro: ,.2f}'
        print(f'Euro - {euro}')


        #navegador.close()


obj_automacao = Automacao_Moedas()
configuracao, driver = obj_automacao.Configuracao_Driver()
obj_automacao.Receber_Dados_Moedas(configuracao, driver)
