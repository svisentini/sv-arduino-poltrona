# sv-arduino-poltrona
Controle da Poltrona - Arduino

- Versao....: 1.3
- Data......: 13/10/2021
- Autor.....: Sidney Visentini

             _
            | |
           _| |_
          |     |  sensorCimaMotor2
          |     |
          |  2  |
          |     |  sensorBaixoMotor2
          ------- 

             _
            | |
           _| |_
          |     |  sensorCimaMotor1
          |     |
          |  1  |
          |     |  sensorBaixoMotor1
          ------- 

# Pinagem de Entrada
| Descrição | Cor do fio | Pino # |
| --- | --- | --- |
| Botão Sobe | Amarelo | 52 |
| Botão Desce | Verde | 50 |
| Sensor Baixo Motor 1 | Azul | 48 |
| Sensor Cima Motor 1 | Roxo | 46 |
| Sensor Baixo Motor 2 | Branco | 44 |
| Sensor Cima Motor 2 | Cinza | 42 |

# Pinagem de Saída
| Descrição | Pino # |
| --- | --- |
| Saída 1 Motor 1 | 24 |
| Saída 2 Motor 1 | 26 |
| Saída 1 Motor 2 | 28 |
| Saída 2 Motor 2 | 30 |

# Referencia 5v
Utilizado pino 40 (Saída em HIGH)

# Liberar acesso a porta serial (Linux)
sudo chmod a+rw /dev/ttyACM0
