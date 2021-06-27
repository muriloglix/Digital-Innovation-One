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
 * Created on June 27, 2021, 2:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Crie um mapa mental para resolver um determinado problema, por exemplo,
 * calcular a média aritmética de 4 notas, sabendo que as notas são as
 * seguintes:
 * Nota 1: 5
 * Nota 2: 7
 * Nota 3: 10
 * Nota 4: 3
 */

//float notas[5] = {0.0};

void limpar_buffer() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);

}

int main() {
    int i;
    float media = 0.0;

    printf("Olá, seja bem-vindo ao calculador de notas.\n\n");

    for (i = 1; i <= 4; i++) {
        float nota;
        printf("Insira a nota %d: ", i);
        scanf("%f", &nota);
        limpar_buffer();
        media = media + nota;
    }

    if (media != 0.0)
        media = media / 4.0;

    printf("Sua média é: %2.2f\n", media);

    return (EXIT_SUCCESS);
}