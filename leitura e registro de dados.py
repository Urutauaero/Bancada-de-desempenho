'''
Código raiz de leitura serial do arduino em python a partir deste código é possível
desenvolver códigos derivados de maiores aplicações
'''

import serial as arduino

com = str(input("Digite qual a COM"))
velSerial = [9600, 115200]
print("1 - 9600")
print("2 - 115200")
choose = int(input("Qual a Baudrate: "))
if choose == 1: Baudrate = velSerial[0]
elif choose == 2: Baudrate = velSerial[1]
nomeArquivo = str(input("Digite o nome para o arquivo em txt: "))

porta = "COM" + com
conexao = arduino.Serial(porta, Baudrate)
arquivo = open(nomeArquivo + ".txt", "a")


while True:
    leituraSerial = conexao.readline()
    conversao_serial = leituraSerial.decode("utf-8")
    print("Arduino diz:", conversao_serial)
    with open(nomeArquivo + ".txt", "a") as arquivo: #abre o arquivo para poder escrever
        arquivo.write(conversao_serial) #escreve os dados já convertidos em Strings