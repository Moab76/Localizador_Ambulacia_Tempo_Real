# Projeto de Rastreamento com ESP32, Sensor GPS e OpenStreetMap

Este projeto utiliza um **ESP32** junto com um **sensor GPS** para coletar dados de localização em tempo real, além de um **sensor DHT11** para monitorar a temperatura e umidade ambiente. Esses dados são enviados para um servidor **Express** hospedado no **Glitch**, que processa as informações e as exibe em um mapa interativo fornecido pelo **OpenStreetMap**.

## Funcionalidades

- **ESP32**: A placa ESP32 é responsável por ler os dados do sensor GPS e DHT11 e enviá-los via HTTP para o servidor Express.
- **Sensor GPS**: O sensor GPS coleta as coordenadas geográficas (latitude e longitude) e as envia para o servidor.
- **Sensor DHT11**: O DHT11 coleta os dados de temperatura e umidade ambiente e os envia ao servidor.
- **Servidor Express**: O servidor Express, hospedado no Glitch, recebe os dados do ESP32, processa e disponibiliza as informações para visualização em um mapa.
- **OpenStreetMap**: O mapa é renderizado no frontend utilizando a API do OpenStreetMap, permitindo visualizar a localização em tempo real junto com a temperatura e umidade.

## Como Funciona

1. O **ESP32** coleta a posição geográfica do sensor GPS e as condições ambientais (temperatura e umidade) do sensor DHT11.
2. O ESP32 envia os dados via HTTP POST para o servidor **Express**.
3. O servidor Express processa os dados e os disponibiliza em formato JSON.
4. A página frontend carrega o mapa utilizando o **OpenStreetMap** e exibe a localização, temperatura e umidade em tempo real conforme os dados recebidos.

## Tecnologias Utilizadas

- **ESP32**
- **Sensor GPS** (dependendo do modelo utilizado, como o NEO-6M ou outro)
- **Sensor DHT11** para medir temperatura e umidade
- **Node.js** com **Express** para o servidor backend
- **HTTPS** no servidor para garantir a segurança da comunicação
- **OpenStreetMap** para renderização do mapa no frontend
- **Glitch** para hospedagem do servidor Express

## Como Rodar

### 1. Configuração do ESP32

1. Clone o repositório.
2. Conecte o **ESP32** à sua rede Wi-Fi e configure o código do ESP32 para coletar os dados dos sensores GPS e DHT11.
3. No código do ESP32, adicione a URL do servidor Express hospedado no Glitch para enviar os dados via HTTP POST.

### 2. Configuração do Servidor Express

1. Importe o projeto para o **Glitch**.
2. Configure as variáveis necessárias no servidor Express, como as credenciais de rede ou configurações do GPS e DHT11, conforme necessário.
3. O servidor Express irá processar os dados recebidos e fornecer uma API para enviar as coordenadas de localização, temperatura e umidade para o frontend.

### 3. Visualização do Mapa

1. Abra o arquivo `index.html` no navegador para visualizar o mapa com as coordenadas GPS.
2. O mapa será renderizado utilizando o **OpenStreetMap** e mostrará a posição do dispositivo ESP32 em tempo real, junto com os dados de temperatura e umidade.

## Exemplo de Uso

1. Com o sistema em funcionamento, o ESP32 envia dados a cada intervalo de tempo configurado.
2. No frontend, a posição, temperatura e umidade serão atualizadas automaticamente conforme os novos dados GPS e DHT11 são recebidos.

## Contribuindo

Se você deseja contribuir com este projeto, sinta-se à vontade para abrir um **pull request** ou **issue**. Qualquer contribuição é bem-vinda!

---

## Estrutura do Código

### Código do ESP32

O ESP32 coleta os dados de localização e condições ambientais e os envia para o servidor. O código inclui a configuração para os sensores GPS e DHT11, além de enviar os dados via HTTP.

### Código do Servidor Express

O servidor Express recebe os dados do ESP32, processa-os e os disponibiliza para o frontend. Ele também fornece uma API para receber as atualizações de latitude, longitude, temperatura e umidade.

### Frontend (HTML + OpenStreetMap)

O frontend exibe o mapa interativo usando a API do OpenStreetMap, atualizando a posição do dispositivo em tempo real e mostrando a temperatura e a umidade.


