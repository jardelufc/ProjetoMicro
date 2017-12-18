# ProjetoMicro
#EstradaInteligente - Contador de Trafego, Status dos Postes de Rua e Status do Transito

Utilizamos a placa STM32F103, e os programas Attolic TrueSTUDIO e STM32CubeMX. 

Instruções para compilar o codigo na bluepill:

 1 - Baixe os arquivos em sw, o arquivo Estrada Inteligente será o codigo da placa.
 2 - Baixe os programas Attolic TrueSTUDIO e STM32CubeMX no seu computador para manipular o codigo. 
 3 - Utilizamos um programador St-link V2 para colocar o codigo na placa. 

Obs: Para alimentar o modulo HC-05 (bluetooth) se pode conectar na porta 5V da bluepill, mas para isso a placa deve estar conectada via USB no computador
para ter essa tensão completa. 

Instruçoes para o Aplicativo Android:
  1 - Acesse a pasta Android\app\build\outputs\apk\debug .
  2 - Baixe o arquivo .apk.
  3 - Instale ele no seu celular android e estará pronto para usar. 

Caso voce deseje modificar os codigos do aplicativo :
  1 - Baixe o Android Studio. 
  2 - Importe o projeto para o Android Studio e faça as alterações desejadas.
  3 - Compile o projeto e passe para o dispositivo.
