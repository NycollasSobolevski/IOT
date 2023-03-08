import requests
import pyodbc
import time

import matplotlib.pyplot as plt
import pyodbc
import numpy as np
# grafico
import pandas as pd
import seaborn as sns

# proxies = {"https": "https://disrct:etsds10243110@rb-proxy-de.bosch.com:8080"}
# url_temp  = "https://esp32-proj-a91fe-default-rtdb.firebaseio.com/Nycollas/Sensor/temperatura.json"
# url_humid = "https://esp32-proj-a91fe-default-rtdb.firebaseio.com/Nycollas/Sensor/umidade.json"
# temperature = float(requests.get(url_temp, proxies=proxies).content)
# humidity = float(requests.get(url_humid, proxies=proxies).content)

server = "CT-C-0018C\SQLEXPRESS"
database = "aulaIOT"
driver= '{SQL Server}'
conn= pyodbc.connect('DRIVER='+driver+';SERVER='+server+';PORT=1433;DATABASE='+database+';Trusted_Connection=yes')
cursor=conn.cursor()
cursor.execute("SELECT Temperatura, Tempo FROM dbo.Sensor")
row = cursor.fetchone()

lista=[]
listatempo=[]

while row:
    print(row)
    lista.append(row[0])
    listatempo.append(str(row[1]))
    row = cursor.fetchone()

df=pd.DataFrame({"Temperatura":lista, "Tempo":listatempo})

df['Tempo'] = pd.to_datetime(df["Tempo"])
sns.relplot(x="Tempo", y="Temperatura", data=df, kind="line")
plt.title("Temperatura por Tempo")
plt.xticks(rotation=90)
plt.show()

print(*listatempo)
print(*lista)
print("Processo Concluido")
