/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:42:30 by mhiguera          #+#    #+#             */
/*   Updated: 2023/09/30 18:09:22 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Definición del tamaño del mapa
#define row 10
#define col 20

#   define wall '1'
#   define floor '0'
#   define E 'E'
#   define P 'P'
#   define C  'C'

// Función para imprimir el mapa
void printMap(char map[row][col])
{
    int i;
    int j;
    
    i = 0;
    while (i < row) 
    {
        j = 0;
        while (j < col) 
            printf("%c ", map[i][j++]);
        printf("\n");
        i++;
    }
}

int main() {
    char map[row][col] = {
        "11111111111111111111",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "10000000000000000001",
        "11111111111111111111"
    };

    int playerX = 1; // Posición inicial del jugador (fila)
    int playerY = 1; // Posición inicial del jugador (columna)

    while (1) {
        system("clear"); // Limpiar la pantalla (solo en sistemas Unix/Linux)

        // Coloca al jugador en su posición actual en el mapa
        map[playerX][playerY] = P;

        // Imprime el mapa
        printMap(map);

        // Verifica si el jugador llegó a la salida
        if (map[playerX][playerY] == E) {
            printf("¡Has ganado!\n");
            break;
        }

        // Pide al jugador que ingrese una dirección (w/a/s/d)
        char movimiento;
        printf("Ingrese una dirección (w/a/s/d): ");
        scanf(" %c", &movimiento);

        // Borra la posición actual del jugador
        map[playerX][playerY] = floor;

        // Actualiza la posición del jugador en función de la dirección ingresada
        switch (movimiento) {
            case 'w':
                if (map[playerX - 1][playerY] != wall)
                    playerX--;
                break;
            case 'a':
                if (map[playerX][playerY - 1] != wall)
                    playerY--;
                break;
            case 's':
                if (map[playerX + 1][playerY] != wall)
                    playerX++;
                break;
            case 'd':
                if (map[playerX][playerY + 1] != wall)
                    playerY++;
                break;
            default:
                printf("Movimiento no válido\n");
        }
    }

    return 0;
}
