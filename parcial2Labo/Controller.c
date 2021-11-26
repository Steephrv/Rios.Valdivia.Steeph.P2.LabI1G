#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Parser.h"
#include "movies.h"
#include "controller.h"
#include "miBiblioteca.h"



int controller_loadFromText(char* path , LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	FILE* pFile = NULL;

	if ( path != NULL && pArrayListMovies != NULL )
	{

		pFile = fopen( path, "r");
		if ( pFile == NULL )
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if ( parser_MovieFromText( pFile, pArrayListMovies ) )
			{
				printf( "Carga de archivo de texto exitosa\n" );
				todoOk = 1;
			}
		}
	}
	fclose(pFile);
	return todoOk;
}

int controller_ListMovies(LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	eMovie* auxPelicula;
	if (pArrayListMovies != NULL)
	{

		printf("                                    *** LISTA PELICULAS ***	\n");
		printf("------------------------------------------------------------------------------------------------\n");
		printf(" ID          TITULO                                             GENERO                   RATING\n");
		for (int i = 0; i < ll_len(pArrayListMovies); i++)
		{
			auxPelicula = (eMovie*) ll_get( pArrayListMovies, i );
			mostrarMovie(auxPelicula);
		}
		todoOk = 1;
	}
	else
	{
		 printf("\nLISTA  VACIA!!!!\n");
	}
	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	FILE* pFile;
	int id;
	char titulo[60];
	char genero[60];
	float rating;
	eMovie* auxPelicula;

	if ( path != NULL && pArrayListMovies != NULL )
	{
		pFile = fopen(path, "w");
		if ( pFile == NULL )
		{
			printf("ERROR,No se pudo abrir el archivo\n");

		}

		fprintf( pFile, "id,titulo,genero,rating\n" );

		for (int i = 0; i < ll_len(pArrayListMovies); i++)
		{
			auxPelicula = ll_get(pArrayListMovies, i);
			if ( movie_getId(auxPelicula, &id) &&
					movie_getTitulo(auxPelicula, titulo) &&
					movie_getGenero( auxPelicula, genero) &&
					movie_getRating(auxPelicula, &rating)
			   )
			{
				fprintf(pFile, "%d,%s,%s,%.1f\n", id, titulo, genero, rating);
				todoOk = 1;
			}
		}
		fclose(pFile);
	}

	return todoOk;
}


int controller_asignarAleatorioRatingPeli(LinkedList* pArrayListMovie)
{
	int todoOk =0;

	pArrayListMovie = ll_map(pArrayListMovie, asignarRatingPelicula);

	if(pArrayListMovie != NULL )
	{
		controller_ListMovies(pArrayListMovie);

	}
	return todoOk;
}


int controller_asignarAleatorioGeneroPeli(LinkedList* pArrayListMovie)
{
	int todoOk =0;

	pArrayListMovie = ll_map(pArrayListMovie, asignarGeneroPelicula);

	if(pArrayListMovie != NULL )
	{
		controller_ListMovies(pArrayListMovie);

	}
	return todoOk;
}



int controller_filtrarGeneroDrama(LinkedList* pArrayListMovie)
{
    system("cls");
	int todoOk =0;


	pArrayListMovie = ll_filter(pArrayListMovie, filtrarPeliculasDrama);

	if(pArrayListMovie != NULL )
	{
		controller_ListMovies(pArrayListMovie);
        todoOk = controller_saveAsText("generoDrama.csv",pArrayListMovie);
        if( todoOk == 1)
        {
            printf("\nArchivo creado con exito!!\n");
        }

	}

	return todoOk;
}

int controller_filtrarGeneroComedia(LinkedList* pArrayListMovie)
{
    system("cls");
	int todoOk =0;


	pArrayListMovie = ll_filter(pArrayListMovie, filtrarPeliculasComedia);

	if(pArrayListMovie != NULL )
	{
		controller_ListMovies(pArrayListMovie);
        todoOk = controller_saveAsText("generoComedia.csv",pArrayListMovie);
        if( todoOk == 1)
        {
            printf("\nArchivo creado con exito!!\n");
        }

	}

	return todoOk;
}

int controller_filtrarGeneroAccion(LinkedList* pArrayListMovie)
{
    system("cls");
	int todoOk =0;


	pArrayListMovie = ll_filter(pArrayListMovie, filtrarPeliculasAccion);

	if(pArrayListMovie != NULL )
	{
		controller_ListMovies(pArrayListMovie);
        todoOk = controller_saveAsText("generoAccion.csv",pArrayListMovie);
        if( todoOk == 1)
        {
            printf("\nArchivo creado con exito!!\n");
        }

	}

	return todoOk;
}

int controller_filtrarGeneroTerror(LinkedList* pArrayListMovie)
{
    system("cls");
	int todoOk =0;


	pArrayListMovie = ll_filter(pArrayListMovie, filtrarPeliculasTerror);

	if(pArrayListMovie != NULL )
	{
		controller_ListMovies(pArrayListMovie);
        todoOk = controller_saveAsText("generoTerror.csv",pArrayListMovie);
        if( todoOk == 1)
        {
            printf("\nArchivo creado con exito!!\n");
        }

	}

	return todoOk;
}



int controller_filtrarGeneroPelicula(LinkedList* pArrayListMovie)
{

    char continuar ='s';
    int todoOk = 0;

    if(pArrayListMovie != NULL)
    {
        do
        {
            switch(menuFiltro())
            {
                case 1:
                    if(!controller_filtrarGeneroDrama(pArrayListMovie))
                    {
                        printf("No se pudo filtrar por genero: drama!!\n");
                    }
                    break;

                case 2:
                    if(!controller_filtrarGeneroComedia(pArrayListMovie))
                    {
                        printf("No se pudo filtrar por genero: comedia!!\n");
                    }
                    break;

                case 3:
                    if(!controller_filtrarGeneroAccion(pArrayListMovie))
                    {
                        printf("No se pudo filtrar por genero: accion!!\n");
                    }
                    break;

                case 4:
                    if(!controller_filtrarGeneroTerror(pArrayListMovie))
                    {
                        printf("No se pudo filtrar por genero: terror!!\n");
                    }
                    break;

                case 5:
                    printf("Ha seleccionado salir\n");
                    continuar='n';
                    break;

                default:
                printf("Opcion invalida!!\n");
            }
            system("pause");
            system("cls");


        }while(continuar == 's');

        todoOk=1;
    }

    return todoOk;
}


int controller_sortPeliculas(LinkedList* pArrayListMovie)
{

	int todoOk = 0;

	if ( pArrayListMovie != NULL )
	{

	    ll_sort(pArrayListMovie, compararPeliculasGeneroRating,0);
	    controller_ListMovies(pArrayListMovie);
	    todoOk=1;
	}


	return todoOk;

}




