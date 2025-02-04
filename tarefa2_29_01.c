#include <stdio.h>
#include "pico/stdlib.h"


// Definição dos pinos
#define led_red_pin 13
#define led_blue_pin 12
#define led_green_pin 11
#define btn_pin 5

// Variavel para controlar a rotina que está em execução
bool routine = false;
int routineStatus = 0;   // Controla o estado da rotina

// Função pra controlar os leds:
void control_leds(int r, int g, int b){
    gpio_put(led_red_pin, r);
    gpio_put(led_green_pin, g);
    gpio_put(led_blue_pin, b);
}

// Função de callback para controle da rotina dos leds
int64_t turn_off_callback(alarm_id_t id, void *user_data){
    // switch controlado pelo estado da rotina
    switch(routineStatus){
        case 0:
            control_leds(1, 1, 0);  // led vermelho e verde acesos
            routineStatus = 1;
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            break;
        case 1:
            control_leds(0, 1, 0);  // led verde aceso
            routineStatus = 2;
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            break;
        case 2:
            control_leds(0, 0, 0);  // Todos os leds apagados
            routine = false;
            routineStatus = 0;
            break;
    }
    // Caso default retorne 0
    return 0;
}


// Função principal
int main()
{
    stdio_init_all();

    // inicialização dos pinos
    gpio_init(led_red_pin);
    gpio_init(led_green_pin);
    gpio_init(led_blue_pin);
    gpio_init(btn_pin);

    // Definindo os pinos como entrada ou saida
    gpio_set_dir(led_red_pin, GPIO_OUT);
    gpio_set_dir(led_blue_pin, GPIO_OUT);
    gpio_set_dir(led_green_pin, GPIO_OUT);
    gpio_set_dir(btn_pin, GPIO_IN);
    gpio_pull_up(btn_pin);  // resistor pull up no button

    while (true) {
        // verificando se o button foi pressionado
        if(!gpio_get(btn_pin) && !routine){
            sleep_ms(100);  // Debounce
            
            // verificando se o button foi pressionado
            if(!gpio_get(btn_pin)){
                // inicia a rotina e liga todos os leds
                routine = true;
                control_leds(1, 1, 1);
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

        sleep_ms(1);
    }
}
