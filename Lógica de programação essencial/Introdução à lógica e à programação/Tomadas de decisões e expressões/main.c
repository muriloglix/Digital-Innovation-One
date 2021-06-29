/*
 * Copyright (C) 2021 Murilo Morais Marques <muriloglix@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   main.c
 * Author: Murilo Morais Marques <muriloglix@gmail.com>
 *
 * Created on June 28, 2021, 8:46 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
void limpar_buffer() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);

}

int main(int argc, char** argv) {
    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril"};
    float valores_meses[4];
    float total, media = 0;
    char nome[256] = {'\0'};

    // Se a média for maior ou igual a 5000 ganha abono de 10%, se não abono de 3%.
    printf("Olá vendedor, por favor, insira o seu nome: ");
    scanf("%255s", nome);
    limpar_buffer();
    printf("Olá %s, abaixo vamos te perguntar quanto você vendeu em casa mês.\n", nome);
    for (int i = 0; i < 4; i++) {
        printf("Insira quanto vendeu no mês de %s: ", meses[i]);
        scanf("%f", &valores_meses[i]);
        limpar_buffer();
        total += valores_meses[i];
    }
    media = total / 4;

    if (total >= 5000) {
        printf("%s, parabéns, você vai ganhar 10%% de abono em cima da quantidade vendida!!!!! \n"
                "Ela equivale a: R$ %2.2f", nome, total * (10.0 / 100.0));
        return (EXIT_SUCCESS);
    }

    printf("%s, infelizmente você vai ganhar apenas 3%% de abono em cima da quantidade vendida.\n"
            "Ela equivale a: R$ %2.2f", nome, total * (3.0 / 100.0));
    return (EXIT_SUCCESS);
}

