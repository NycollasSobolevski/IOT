import requests
import pyodbc
import time

# server name: CT-C-0018C\SQLEXPRESS
def signal():
    proxies = {"https": "https://disrct:etsds10243110@rb-proxy-de.bosch.com:8080"}
    url_temp  = "https://esp32-proj-a91fe-default-rtdb.firebaseio.com/Nycollas/Sensor/temperatura.json"
    url_humid = "https://esp32-proj-a91fe-default-rtdb.firebaseio.com/Nycollas/Sensor/umidade.json"
    temperature = float(requests.get(url_temp, proxies=proxies).content)
    humidity = float(requests.get(url_humid, proxies=proxies).content)
    return temperature, humidity

# Configurando DB
def InserirBD(signal):
    server = "CT-C-0018C\SQLEXPRESS"
    database = "tempdb"
    cnxn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')

    cursor = cnxn.cursor()
    cursor.execute(f"INSERT dbo.Sensor(Temperatura, Umidade) VALUES({signal[0]},{signal[1]});")
    cursor.commit()
    print("Inserido com sucesso!")

def apresentar(signal):
    print(f"Temperatura {signal[0]}")
    print(f"Umidade {signal[1]}")

while 1:
    valores=signal()
    apresentar(valores)
    InserirBD(valores)
    time.sleep(120)
