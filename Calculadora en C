#include <stdio.h>

int main()
{
    int opcion;
    float num1, num2, resultado;

    do
    {
        printf("\n==============================\n");
        printf("      CALCULADORA EN C\n");
        printf("==============================\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if(opcion >= 1 && opcion <= 4)
        {
            printf("\nIngrese el primer numero: ");
            scanf("%f", &num1);

            printf("Ingrese el segundo numero: ");
            scanf("%f", &num2);
        }

        switch(opcion)
        {
            case 1:
                resultado = num1 + num2;
                printf("\nResultado: %.2f\n", resultado);
                break;

            case 2:
                resultado = num1 - num2;
                printf("\nResultado: %.2f\n", resultado);
                break;

            case 3:
                resultado = num1 * num2;
                printf("\nResultado: %.2f\n", resultado);
                break;

            case 4:
                if(num2 != 0)
                {
                    resultado = num1 / num2;
                    printf("\nResultado: %.2f\n", resultado);
                }
                else
                {
                    printf("\nError: No se puede dividir entre cero.\n");
                }
                break;

            case 5:
                printf("\nGracias por utilizar la calculadora.\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
        }

    }while(opcion != 5);

    return 0;
}
