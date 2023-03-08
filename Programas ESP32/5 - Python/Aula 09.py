# Inserindo dados no banco de dados pelo firebase


import requests
import pyodbc
import time

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns


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
    database = "aulaIOT"
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')

    cursor = cnxn.cursor()
    # cursor.execute("Create table Sensor(Temperatura float, Umidade float, Tempo datetime default(GETDATE())")
    cursor.execute(f"INSERT Sensor(Temperatura, Umidade) VALUES({signal[0]},{signal[1]});")
    cursor.commit()
    print("Inserido com sucesso!")

def ToList():
    server = "CT-C-0018C\SQLEXPRESS"
    database = "aulaIOT"
    driver= '{SQL Server}'
    conn= pyodbc.connect('DRIVER='+driver+';SERVER='+server+';PORT=1433;DATABASE='+database+';Trusted_Connection=yes')
    cursor=conn.cursor()
    cursor.execute("SELECT Temperatura, Tempo FROM dbo.Sensor")
    row = cursor.fetchone()
    lista = []
    tempo = []
    while row:
        lista.append(row[0])
        tempo.append(row[1])
        row = cursor.fetchone()
    return lista, tempo

def ToPlot(ListaDeLista):
    df = pd.DataFrame({"Temperatura":ListaDeLista[0], "Tempo":ListaDeLista[1]})
    df['Tempo'] = pd.to_datetime(df["Tempo"])
    sns.relplot(x="Tempo", y="Temperatura", data=df, kind="line")
    plt.title("Temp por Tempo")
    plt.xticks(rotation=90)
    plt.show()

def apresentar(signal):
    print(f"Temperatura {signal[0]}")
    print(f"Umidade {signal[1]}")


while 1:
    escolha = int(input("Escolha:\n 1 - Inserir dados\n 2 - Ver Grafico\n 0 - Sair\n> "))
    match escolha:
        case 0:
            break
        case 1:
            while 1:
                valores=signal()
                apresentar(valores)
                InserirBD(valores)
                time.sleep(2)
        case 2:
            ToPlot(ToList())
        case _:
            print("Insira um valor válido \n")
            

