# TAREFA 1 29/01 - Temporizador de Um Disparo (One Shot)

## Descrição

Este projeto tem como objetivo explorar o uso de temporizadores a partir de um projeto que acende leds utilizando a função **add_alarm_in_ms()**. O sistema é acionado por um botão, que quando pressionado, os leds acedem e mudam de estado a cada 3 segundos.

## Componentes Utilizados

Para uso na placa bitDogLab:

- Microcontrolador Raspberry Pi Pico W
- **LED RGB** com pinos conectados às **GPIOs 11, 12 e 13**.
- **Botão A** conectado à **GPIO 5**.

Para uso no simulador Wokwi:

- Microcontrolador Raspberry Pi Pico W.
- 03 LEDs (vermelho, verde, azul);
- 03 resistores de 330 Ω.
- 01 Botão

## Funcionalidades

1. Quando o botao é apertado, os 3 leds acedem.
2. Após 3 segundos, apenas dois leds ficam acesos.
3. Após mais 3 segundos apenas um led permanece aceso.
4. Depois de mais 3 segundos, todos os leds são apagados.
4. O botão deve ser precionado para que o sistema funione novamente.