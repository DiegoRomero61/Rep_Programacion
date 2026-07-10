#include <stdio.h>

int main()
{
    int opcion;
    float temperatura, resultado;

    do
    {
        printf("\n===================================\n");
        printf("   CONVERSOR DE TEMPERATURAS\n");
        printf("===================================\n");

        printf("1. Celsius a Fahrenheit\n");
        printf("2. Fahrenheit a Celsius\n");
        printf("3. Celsius a Kelvin\n");
        printf("4. Kelvin a Celsius\n");
        printf("5. Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese grados Celsius: ");
                scanf("%f", &temperatura);

                resultado = (temperatura * 9.0 / 5.0) + 32;

                printf("Resultado: %.2f °F\n", resultado);
                break;

            case 2:
                printf("Ingrese grados Fahrenheit: ");
                scanf("%f", &temperatura);

                resultado = (temperatura - 32) * 5.0 / 9.0;

                printf("Resultado: %.2f °C\n", resultado);
                break;

            case 3:
                printf("Ingrese grados Celsius: ");
                scanf("%f", &temperatura);

                resultado = temperatura + 273.15;

                printf("Resultado: %.2f K\n", resultado);
                break;

            case 4:
                printf("Ingrese grados Kelvin: ");
                scanf("%f", &temperatura);

                resultado = temperatura - 273.15;

                printf("Resultado: %.2f °C\n", resultado);
                break;

            case 5:
                printf("\nPrograma finalizado.\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
        }

    }while(opcion != 5);

    return 0;
}
