import requests
import json



# r = requests.get('https://www.github.com')
# proxie = {'https':"https://disrct:etsds10243110@10.224.200.26:8080"}

# url = 'https://random.dog/woof.json'
# img_data = requests.get(url, proxies=proxie).content

# new_url = json.loads(img_data)['url']
# img = requests.get(new_url,proxies=proxie).content

# with open('dog.jpg','wb') as dog_file:
#     dog_file.write(img)

# url_temp = 'https://esp32-proj-a91fe-default-rtdb.firebaseio.com/Nycollas/Sensor/temperatura.json'
# url_umid = 'https://esp32-proj-a91fe-default-rtdb.firebaseio.com/Nycollas/Sensor/umidade.json'

# temperature = float(requests.get(url_temp, proxies=proxie).content)
# humidity = float(requests.get(url_umid, proxies=proxie).content)
 
# print(temperature)
# print(humidity)

# ___________________________________________________________________________________________________
#DESAFIOOO
#Faça um programa utilizando a API https://agify.io/, faça um GET request enviando como
# parâmetro o nome de uma pessoa, o dado retornado deve ser a previsão de idade para a
# pessoa de acordo com seu nome.

url_api  = "https://api.agify.io?name=nycollas"
classe_url = requests.get(url_api, proxies=proxie).content
age = json.loads(classe_url)['age']
print(age)
# ___________________________________________________________________________________________________
