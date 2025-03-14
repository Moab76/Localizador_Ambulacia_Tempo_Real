# Projeto de Rastreamento com ESP32, Sensor GPS e OpenStreetMap

Este projeto utiliza um **ESP32** junto com um **sensor GPS** para coletar dados de localização em tempo real e enviá-los para um servidor **Express** hospedado no **Glitch**. O servidor processa as informações de localização e as exibe em um mapa interativo fornecido pelo **OpenStreetMap**.

## Funcionalidades

- **ESP32**: A placa ESP32 é responsável por ler os dados do sensor GPS e enviá-los via HTTP para o servidor Express.
- **Sensor GPS**: O sensor GPS coleta as coordenadas geográficas (latitude e longitude) e as envia para o servidor.
- **Servidor Express**: Um servidor Express hospedado no Glitch recebe os dados do ESP32, processa e disponibiliza as informações para visualização em um mapa.
- **OpenStreetMap**: O mapa é renderizado no frontend utilizando a API do OpenStreetMap, permitindo visualizar a localização em tempo real.

## Como Funciona

1. O **ESP32** coleta a posição geográfica do sensor GPS.
2. O ESP32 envia os dados via HTTP POST para o servidor **Express**.
3. O servidor Express processa os dados e os disponibiliza em formato JSON.
4. A página frontend carrega o mapa utilizando o **OpenStreetMap** e exibe a localização em tempo real conforme os dados recebidos.

## Tecnologias Utilizadas

- **ESP32**
- **Sensor GPS** (dependendo do modelo utilizado, como o NEO-6M ou outro)
- **Node.js** com **Express** para o servidor backend
- **HTTPS** no servidor para garantir a segurança da comunicação
- **OpenStreetMap** para renderização do mapa no frontend
- **Glitch** para hospedagem do servidor Express

## Como Rodar

### 1. Configuração do ESP32

1. Clone o repositório.
2. Conecte o **ESP32** à sua rede Wi-Fi e configure o código do ESP32 para coletar os dados do sensor GPS.
3. No código do ESP32, adicione a URL do servidor Express hospedado no Glitch para enviar os dados via HTTP POST.

### 2. Configuração do Servidor Express

1. Importe o projeto para o **Glitch**.
2. Configure as variáveis necessárias no servidor Express, como as credenciais de rede ou configurações do GPS, conforme necessário.
3. O servidor Express irá processar os dados recebidos e fornecer uma API para enviar as coordenadas para o frontend.

### 3. Visualização do Mapa

1. Abra o arquivo `index.html` no navegador para visualizar o mapa com as coordenadas GPS.
2. O mapa será renderizado utilizando o **OpenStreetMap** e mostrará a posição do dispositivo ESP32 em tempo real.

## Exemplo de Uso

1. Com o sistema em funcionamento, o ESP32 envia dados a cada intervalo de tempo configurado.
2. No frontend, a posição será atualizada automaticamente conforme os novos dados GPS são recebidos.

## Contribuindo

Se você deseja contribuir com este projeto, sinta-se à vontade para abrir um **pull request** ou **issue**. Qualquer contribuição é bem-vinda!
