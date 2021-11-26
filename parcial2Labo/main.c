
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "movies.h"
#include "time.h"

int main()
{
    srand(time(NULL));
    char seguir = 's';
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;




	LinkedList* listaPeliculas = ll_newLinkedList();
	if (listaPeliculas == NULL)
	{
		printf("No se pudo crear el linkedList\n");
		exit(1);
	}

	do
	{
		switch (menu())
		{
		case 1:
			if ( !controller_loadFromText("movies.csv", listaPeliculas) )
			{
				printf("ERROR al cargar archivo texto\n");
			}
			flag1=1;
			break;
		case 2:
		    if(flag1 == 1)
            {
                if ( !controller_ListMovies(listaPeliculas) )
                {
                    printf("ERROR al listar pelicula/s !!!\n");
                }
            }
            else
            {
                printf("Para listar las peliculas 1er tiene que cargar el archivo (opc 1) \n");
            }

			break;
		case 3:

           if ( controller_asignarAleatorioRatingPeli(listaPeliculas) )
            {
                printf("Error al querer asignar rating aleatoria!!\n");
            }
            flag2=1;

			break;
		case 4:

            if(controller_asignarAleatorioGeneroPeli(listaPeliculas))
            {
                printf("ERROR al querer asignar  genero a las peliculas!!\n");
            }
            flag3=1;

            break;


		case 5:
		    if(flag1 == 1 && flag2 == 1 && flag3 ==1)
            {
                if ( !controller_filtrarGeneroPelicula(listaPeliculas) )
                {
                    printf("ERROR al querer filtrar los generos de las  peliculas!!\n");
                }
            }
            else
            {
                printf("Para filtrar los generos primero tiene que cargar el archivo , luego asignar el rating (opc 3) y luego asignar los generos (opc 4) !!\n");
            }

			break;

        case 6:
            if(flag1 == 1 && flag2 == 1 && flag3 ==1)
            {
                if( !controller_sortPeliculas(listaPeliculas))
                {
                    printf("No se pudo ordenar las peliculas de forma descendente!!\n");
                }
                flag4=1;
            }
            else
            {
                printf("Para ordenar los generos primero tiene que cargar el archivo , luego asignar el rating (opc 3) y luego asignar los generos (opc 4) !!\n");
            }

            break;

		case 7:
		    if(flag4 ==1)
            {
                if ( !controller_saveAsText("ordenamientoPeliculas.csv",listaPeliculas) )
                {
                    printf("ERROR no se pudo guardar en el archivo!!!\n");
                }
                else
                {
                    printf("Lista ordenada guardada con exito en el archivo: ordenamientoPeliculas.csv \n");
                }
            }
            else
            {
                printf("Para guardar en un archivo primero tiene que ordenar (opc 5)");
            }
			break;

		case 8:
			printf("Ha seleccionado salir\n");
			seguir='n';
			break;

		default:
			printf("Opcion invalida!!\n");
		}
		system("pause");
        system("cls");

	}
	while(seguir == 's');

	free(listaPeliculas);

    return 0;
}
