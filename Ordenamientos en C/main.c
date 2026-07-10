#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>
#include <string.h>

void merge(int arreglo[], int izquierda, int medio, int derecha)
{
    int i, j, k;

    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++)
        L[i] = arreglo[izquierda + i];

    for(j = 0; j < n2; j++)
        R[j] = arreglo[medio + 1 + j];

    i = 0;
    j = 0;
    k = izquierda;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arreglo[k] = L[i];
            i++;
        }
        else
        {
            arreglo[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        arreglo[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arreglo[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arreglo[], int izquierda, int derecha)
{
    if(izquierda < derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(arreglo, izquierda, medio);
        mergeSort(arreglo, medio + 1, derecha);

        merge(arreglo, izquierda, medio, derecha);
    }
}

int particion(int arreglo[], int bajo, int alto)
{
    int pivote = arreglo[alto];
    int i = bajo - 1;
    int j;
    int aux;

    for(j = bajo; j < alto; j++)
    {
        if(arreglo[j] < pivote)
        {
            i++;

            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
        }
    }

    aux = arreglo[i + 1];
    arreglo[i + 1] = arreglo[alto];
    arreglo[alto] = aux;

    return i + 1;
}

void quickSort(int arreglo[], int bajo, int alto)
{
    if(bajo < alto)
    {
        int pi = particion(arreglo, bajo, alto);

        quickSort(arreglo, bajo, pi - 1);
        quickSort(arreglo, pi + 1, alto);
    }
}

int main()
{
    setlocale(LC_ALL, "");

    unsigned int tam = 65000;
    int *arreglo;
    char *cadena;
    int opcion;
    unsigned int i, j;
    int aux;
    clock_t inicio, fin;
    double tiempo;
    int opcionb;

    double burbuja[2][10];
    double seleccion[2][10];

    double mezcla[2][10];
    double rapido[2][10];

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 10; j++)
        {
            burbuja[i][j] = 0;
            seleccion[i][j] = 0;
            mezcla[i][j] = 0;
            rapido[i][j] = 0;
        }
    }

    arreglo = (int *)malloc(tam * sizeof(int));
    cadena = (char *)malloc(tam * sizeof(char));

   for(i = 0; i < tam; i++)
    {
        arreglo[i] = 0;
        cadena[i] = '\0';
    }

    srand(time(NULL));
    char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    do
    {
        system("cls");

        printf("Programa de pruebas");
        printf("\n\n1.- Arreglo en ceros");
        printf("\n2.- Llenar arreglo (Random)");
        printf("\n3.- Mostrar arreglo");
        printf("\n4.- Ordenar por Burbuja");
        printf("\n5.- Ordenar por Selección Directa");
        printf("\n6.- Ordenar por Mezcla");
        printf("\n7.- Ordenamiento rápido");
        printf("\n8.- Tamaño del arreglo");
        printf("\n9.- Mostrar historial");
        printf("\n10.- Búsqueda de cadenas");
        printf("\n\n11.- Salir");

        printf("\n\nIngrese una opción: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                for(i = 0; i < tam; i++)
                {
                    arreglo[i] = 0;
                    cadena[i] = '\0';
                }

                printf("Arreglo inicializado en ceros.\n");

                sleep(2);
                printf("\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 2:
                system("cls");

                for(i = 0; i < tam; i++)
                {
                    arreglo[i] = rand() % 100;
                    cadena[i] = caracteres[rand() % 36];
                }

                printf("Arreglo llenado con números aleatorios.\n");

                sleep(2);
                printf("\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 3:
                system("cls");

                printf("ARREGLO DE ENTEROS\n\n");

                for(i=0;i<tam;i++)
                {
                    printf("%d ", arreglo[i]);

                    if((i+1)%20==0)
                        printf("\n");
                }

                printf("\n\n");

                printf("ARREGLO DE CARACTERES\n\n");

                for(i=0;i<tam;i++)
                {
                    printf("%c ", cadena[i]);

                    if((i+1)%40==0)
                        printf("\n");
                }

                sleep(2);
                printf("\n\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 4:
                int opcionb;
                system("cls");
                printf("Ordenamiento por Burbuja");
                printf("\n\nElija la forma en la que quiere ordenarlo");
                printf("\n\n\n1.- Ascendente");
                printf("\n\n2.- Descendente");
                printf("\n\n\nIngrese una opción: ");
                scanf("%d", &opcionb);

                inicio = clock();

                if(opcionb == 1)
                {
                    system("cls");
                    for(i = 0; i < tam - 1; i++)
                    {
                        for(j = 0; j < tam - 1 - i; j++)
                        {
                            if(arreglo[j] > arreglo[j + 1])
                            {
                                aux = arreglo[j];
                                arreglo[j] = arreglo[j + 1];
                                arreglo[j + 1] = aux;
                            }
                        }
                    }
                    printf("Arreglo ordenado en forma ascendente.\n");
                }

                else if(opcionb == 2)
                {
                    system("cls");
                    for(i = 0; i < tam - 1; i++)
                    {
                        for(j = 0; j < tam - 1 - i; j++)
                        {
                            if(arreglo[j] < arreglo[j + 1])
                            {
                                aux = arreglo[j];
                                arreglo[j] = arreglo[j + 1];
                                arreglo[j + 1] = aux;
                            }
                        }
                    }
                    printf("Arreglo ordenado en forma descendente.\n");
                }

                else
                {
                    system("cls");
                    sleep(2);
                    printf("\nOpción no válida.\n");
                    sleep(2);
                    printf("\nPresione cualquier tecla para volver al menú...");
                    getch();
                    break;
                }

                fin = clock();

                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

                for(i = 9; i > 0; i--)
                {
                    burbuja[0][i] = burbuja[0][i - 1];
                    burbuja[1][i] = burbuja[1][i - 1];
                }

                burbuja[0][0] = tam;
                burbuja[1][0] = tiempo;

                printf("\n\n\nEl tiempo de ejecución fue de: %f segundos\n", tiempo);

                sleep(2);
                printf("\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 5:
                system("cls");

                int opcionc;
                system("cls");
                printf("Ordenamiento por Selección Directa");
                printf("\n\nElija la forma en la que quiere ordenarlo");
                printf("\n\n\n1.- Ascendente");
                printf("\n\n2.- Descendente");
                printf("\n\n\nIngrese una opción: ");
                scanf("%d", &opcionc);

                inicio = clock();

                if(opcionc == 1)
                {
                    system("cls");
                    int menor, pos;

                    for(i = 0; i < tam - 1; i++)
                    {
                        menor = arreglo[i];
                        pos = i;

                        for(j = i + 1; j < tam; j++)
                        {
                            if(arreglo[j] < menor)
                            {
                                menor = arreglo[j];
                                pos = j;
                            }
                        }

                        aux = arreglo[i];
                        arreglo[i] = arreglo[pos];
                        arreglo[pos] = aux;
                    }

                    printf("Arreglo ordenado en forma ascendente.\n");
                }

                else if(opcionc == 2)
                {
                    system("cls");
                    int mayor, pos;

                    for(i = 0; i < tam - 1; i++)
                    {
                        mayor = arreglo[i];
                        pos = i;

                        for(j = i + 1; j < tam; j++)
                        {
                            if(arreglo[j] > mayor)
                            {
                                mayor = arreglo[j];
                                pos = j;
                            }
                        }

                        aux = arreglo[i];
                        arreglo[i] = arreglo[pos];
                        arreglo[pos] = aux;
                    }

                    printf("Arreglo ordenado en forma descendente.\n");
                }

                else
                {
                    system("cls");
                    sleep(2);
                    printf("\nOpción no válida.\n");
                    sleep(2);
                    printf("\nPresione cualquier tecla para volver al menú...");
                    getch();
                    break;
                }

                fin = clock();

                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

                for(i = 9; i > 0; i--)
                {
                    seleccion[0][i] = seleccion[0][i - 1];
                    seleccion[1][i] = seleccion[1][i - 1];
                }

                seleccion[0][0] = tam;
                seleccion[1][0] = tiempo;

                printf("\n\n\nEl tiempo de ejecución fue de: %f segundos\n", tiempo);


                sleep(2);
                printf("\n\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 6:
                system("cls");

                printf("Ordenamiento por Mezcla (Merge Sort)\n");

                inicio = clock();

                mergeSort(arreglo, 0, tam - 1);

                fin = clock();

                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

                for(i = 9; i > 0; i--)
                {
                    mezcla[0][i] = mezcla[0][i - 1];
                    mezcla[1][i] = mezcla[1][i - 1];
                }

                mezcla[0][0] = tam;
                mezcla[1][0] = tiempo;

                printf("\nArreglo ordenado correctamente.\n");
                printf("\nTiempo: %f segundos\n", tiempo);


                sleep(2);
                printf("\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 7:
                system("cls");

                printf("Ordenamiento Rapido (Quick Sort)\n");

                inicio = clock();

                quickSort(arreglo, 0, tam - 1);

                fin = clock();

                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

                for(i = 9; i > 0; i--)
                {
                    rapido[0][i] = rapido[0][i - 1];
                    rapido[1][i] = rapido[1][i - 1];
                }

                rapido[0][0] = tam;
                rapido[1][0] = tiempo;

                printf("\nArreglo ordenado correctamente.\n");
                printf("\nTiempo: %f segundos\n", tiempo);

                sleep(2);
                printf("\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 8:
                system("cls");

                unsigned int nuevoTam;

                printf("Tamaño actual: %u\n", tam);
                printf("\n\nIngrese el nuevo tamaño (máximo 65000): ");
                scanf("%u", &nuevoTam);

                if(nuevoTam >= 1 && nuevoTam <= 65000)
                {
                    tam = nuevoTam;

                    free(arreglo);
                    free(cadena);

                    arreglo = (int *)malloc(tam * sizeof(int));
                    cadena = (char *)malloc(tam * sizeof(char));

                    for(i = 0; i < tam; i++)
                    {
                        arreglo[i] = 0;
                        cadena[i] = '\0';
                    }

                    system("cls");
                    sleep(2);
                    printf("\nNuevo tamaño establecido correctamente.\n");
                }

                else
                {
                    system("cls");
                    sleep(2);
                    printf("\nTamaño inválido.\n");
                }

                sleep(2);
                printf("\n\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 9:
                system("cls");
                printf("BURBUJA\n\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("| n     ");

                for(j = 0; j < 10; j++)
                    printf("| %-10.0f ", burbuja[0][j]);

                printf("|\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("| T(n)  ");

                for(j = 0; j < 10; j++)
                    printf("| %-10.4f ", burbuja[1][j]);

                printf("|\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");


                printf("\n\nSELECCION DIRECTA\n\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("| n     ");

                for(j = 0; j < 10; j++)
                    printf("| %-10.0f ", seleccion[0][j]);

                printf("|\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("| T(n)  ");

                for(j = 0; j < 10; j++)
                    printf("| %-10.4f ", seleccion[1][j]);

                printf("|\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("\n\nMEZCLA (MERGE SORT)\n\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("| n     ");

                for(j = 0; j < 10; j++)
                    printf("| %-10.0f ", mezcla[0][j]);

                printf("|\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("| T(n)  ");

                for(j = 0; j < 10; j++)
                    printf("| %-10.4f ", mezcla[1][j]);

                printf("|\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");


                printf("\n\nQUICK SORT\n\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("| n     ");

                for(j = 0; j < 10; j++)
                    printf("| %-10.0f ", rapido[0][j]);

                printf("|\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                printf("| T(n)  ");

                for(j = 0; j < 10; j++)
                    printf("| %-10.4f ", rapido[1][j]);

                printf("|\n");

                for(i = 0; i < 11; i++)
                    printf("+------------");
                printf("+\n");

                sleep(2);
                printf("\n\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 10:
                system("cls");

                char buscar[100];
                int longitud;
                int encontrada = 0;
                int k;

                printf("BUSQUEDA DE CADENAS\n\n");
                printf("Contenido del arreglo:\n\n");

                for(i = 0; i < tam; i++)
                {
                    printf("%c ", cadena[i]);

                    if((i + 1) % 25 == 0)
                        printf("\n");
                }

                inicio = clock();

                printf("\n\nIngrese el caracter o cadena a buscar: ");
                scanf("%s", buscar);

                longitud = strlen(buscar);

                printf("\n\nCoincidencias encontradas:\n\n");

                for(i = 0; i <= tam - longitud; i++)
                {
                    int coincide = 1;

                    for(k = 0; k < longitud; k++)
                    {
                        if(cadena[i + k] != buscar[k])
                        {
                            coincide = 0;
                            break;
                        }
                    }

                    if(coincide)
                    {
                        printf("Offset (Indice): %u\n", i);
                        encontrada = 1;
                    }
                }

                if(!encontrada)
                {
                    printf("No se encontraron coincidencias.\n");
                }

                fin = clock();

                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("\nTiempo de busqueda: %.6f segundos\n", tiempo);

                sleep(2);
                printf("\n\nPresione cualquier tecla para volver al menú...");
                getch();
                break;

            case 11:
                system("cls");
                printf("Fin del programa.\n");
                break;

            default:
                system("cls");
                printf("Opción no válida.\n");
                sleep(2);
        }

    } while(opcion != 11);

    free(arreglo);
    free(cadena);

    return 0;
}
