# sv-arduino-poltrona
Controle da Poltrona - Arduino

- Versao....: 1.4
- Data......: 28/11/2021
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
| Descrição |  Pino # |
| --- | --- |
| Botão Sobe | 52 |
| Botão Desce |  50 |
| Sensor Baixo Motor 1 |  46 |
| Sensor Cima Motor 1 |  48 |
| Sensor Baixo Motor 2 |  42 |
| Sensor Cima Motor 2 |  44 |

# Pinagem de Saída
| Descrição | Pino # |
| --- | --- |
| Saída 1 Motor 1 | 24 |
| Saída 2 Motor 1 | 26 |
| Saída 1 Motor 2 | 28 |
| Saída 2 Motor 2 | 30 |

# Referencia 5v
Utilizado pino 40 (Saída em HIGH)

# Listar as portas
ls /dev/tty*

# Liberar acesso a porta serial (Linux)
sudo chmod a+rw /dev/ttyACM0
