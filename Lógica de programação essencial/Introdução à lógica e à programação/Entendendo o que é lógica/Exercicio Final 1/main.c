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

float notas[5] = {0.0};

void limpar_buffer() {
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);

}

void menu_2() {
    int i;
    printf("\n\n");
    for (i = 1; i <= 4; i++) {
        printf("Nota %d: %2.2f\n", i, notas[i - 1]);
    }
    printf("Média das notas: %.2f\n", notas[4]);
}

void menu_1() {
    int i;
    char entrada_do_usuario[11] = {'\0'};
    float nota;

    notas[4] = 0.0;

    for (i = 1; i <= 4; i++) {
        nota = 0.0;
entrada_incorreta_1:
        printf("Insira a nota %d: ", i);
        scanf("%10s", entrada_do_usuario);
        limpar_buffer();

        if (!isdigit(entrada_do_usuario[0])) {
entrada_incorreta_2:
            printf("\n\nPor favor, insira um número igual ou maior a zero e menor ou igual a 10.\n\n");
            goto entrada_incorreta_1;
        }

        sscanf(entrada_do_usuario, "%f", &nota);

        if (!(nota >= 0.0 && nota <= 10.0))
            goto entrada_incorreta_2;

        notas[i - 1] = nota;
        notas[4] += nota;
    }

    if (notas[4] != 0)
        notas[4] = notas[4] / 4.0;

    menu_2();
}

int main() {

    int menu_selecao = -1;
menu_start: // Ponto onde inicia a execução do menu
    printf("Olá, seja bem-vindo ao calculador de notas, abaixo você "
            "encontrará os menus necessários para navegação:\n"
            "\t1. Definir notas.\n"
            "\t2. Visualizar notas.\n"
            "\t9. Sair.\n"
            "Selecione: ");

    menu_selecao = getchar();
    limpar_buffer();
    switch (menu_selecao) {
        case '1':
            menu_1();
            break;
        case '2':
            menu_2();
            break;
        case '9':
            goto sair;
        default:
            printf("\n\nSeleção inválida.\n\n");
            goto menu_start;
    }
    printf("\n\n");
    goto menu_start;

sair:
    return (EXIT_SUCCESS);
}