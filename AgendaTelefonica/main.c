#include <stdio.h>
#include <string.h>

#define MAX_CONTACTOS 100

struct Contacto
{
    char nombre[50];
    char telefono[20];
};

int main()
{
    struct Contacto agenda[MAX_CONTACTOS];

    int cantidad = 0;
    int opcion;
    int i;
    char nombreBuscar[50];
    int encontrado;

    do
    {
        printf("\n===============================\n");
        printf("      AGENDA TELEFONICA\n");
        printf("===============================\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar contactos\n");
        printf("3. Buscar contacto\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                if(cantidad < MAX_CONTACTOS)
                {
                    printf("\nNombre: ");
                    scanf(" %[^\n]", agenda[cantidad].nombre);

                    printf("Telefono: ");
                    scanf("%s", agenda[cantidad].telefono);

                    cantidad++;

                    printf("\nContacto agregado correctamente.\n");
                }
                else
                {
                    printf("\nLa agenda esta llena.\n");
                }

                break;

            case 2:

                if(cantidad == 0)
                {
                    printf("\nNo hay contactos registrados.\n");
                }
                else
                {
                    printf("\n----- LISTA DE CONTACTOS -----\n");

                    for(i = 0; i < cantidad; i++)
                    {
                        printf("\nContacto %d\n", i + 1);
                        printf("Nombre: %s\n", agenda[i].nombre);
                        printf("Telefono: %s\n", agenda[i].telefono);
                    }
                }

                break;

            case 3:

                if(cantidad == 0)
                {
                    printf("\nNo hay contactos registrados.\n");
                    break;
                }

                printf("\nIngrese el nombre a buscar: ");
                scanf(" %[^\n]", nombreBuscar);

                encontrado = 0;

                for(i = 0; i < cantidad; i++)
                {
                    if(strcmp(nombreBuscar, agenda[i].nombre) == 0)
                    {
                        printf("\nContacto encontrado.\n");
                        printf("Nombre: %s\n", agenda[i].nombre);
                        printf("Telefono: %s\n", agenda[i].telefono);

                        encontrado = 1;
                        break;
                    }
                }

                if(encontrado == 0)
                {
                    printf("\nContacto no encontrado.\n");
                }

                break;

            case 4:

                printf("\nHasta luego.\n");
                break;

            default:

                printf("\nOpcion no valida.\n");
        }

    }
    while(opcion != 4);

    return 0;
}
