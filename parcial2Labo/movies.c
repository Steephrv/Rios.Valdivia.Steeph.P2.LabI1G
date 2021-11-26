#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "movies.h"
#include "LinkedList.h"

eMovie* movie_new()
{
	eMovie* nuevaPelicula = (eMovie*) malloc(sizeof(eMovie));
	if(nuevaPelicula != NULL)
	{
		nuevaPelicula->id_peli = 0;
		strcpy(nuevaPelicula->tituloPeli, "");
		strcpy(nuevaPelicula->generoPeli, "");
		nuevaPelicula->rating = 0;
	}
	return nuevaPelicula;
}

eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr)
{
	eMovie* nuevaPelicula = movie_new();
	if(nuevaPelicula != NULL)
	{
		if(!(movie_setId(nuevaPelicula, atoi(idStr)) &&
			movie_setTitulo(nuevaPelicula,tituloStr) &&
			movie_setGenero(nuevaPelicula,generoStr) &&
			movie_setRating(nuevaPelicula,atof(ratingStr) ) ))
		{
			free(nuevaPelicula);
			nuevaPelicula = NULL;
		}
	}

	return nuevaPelicula;
}

void movie_delete(eMovie* pMovie)
{

	if(pMovie != NULL)
	{
		free(pMovie);

	}
}


int movie_setId(eMovie* this,int id)
{
	int todoOk =0;

	if(this != NULL && id >= 0 )
	{
		this->id_peli = id;
		todoOk =1;
	}

	return todoOk;
}

int movie_getId(eMovie* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL )
	{
		*id = this->id_peli;
		todoOk = 1;
	}

	return todoOk;
}

int movie_setTitulo(eMovie* this,char* titulo)
{
	int todoOk =0;
	char auxCadena[128];

	if(this != NULL && titulo != NULL && strlen(titulo) >= 3 && strlen(titulo) < 128 )
	{
		strcpy(auxCadena, titulo);
		strlwr(auxCadena);
		auxCadena[0]= toupper(auxCadena[0]);
		strcpy(this->tituloPeli,auxCadena);
		todoOk =1;
	}

	return todoOk;
}


int movie_getTitulo(eMovie* this,char* titulo)
{
	int todoOk = 0;
	if(this != NULL && titulo != NULL )
	{
		strcpy(titulo,this->tituloPeli);
		todoOk = 1;
	}

	return todoOk;
}

int movie_setGenero(eMovie* this,char* genero)
{
	int todoOk =0;
	char auxCadena[128];

	if(this != NULL && genero != NULL && strlen(genero) >= 3 && strlen(genero) < 128 )
	{
		strcpy(auxCadena, genero);
		strlwr(auxCadena);
		auxCadena[0]= toupper(auxCadena[0]);
		strcpy(this->generoPeli,auxCadena);
		todoOk =1;
	}

	return todoOk;
}


int movie_getGenero(eMovie* this,char* genero)
{
	int todoOk = 0;
	if(this != NULL && genero != NULL )
	{
		strcpy(genero,this->generoPeli);
		todoOk = 1;
	}

	return todoOk;
}


int movie_setRating(eMovie* this,float rating)
{
	int todoOk =0;

	if(this != NULL &&  rating >= 0)
	{
		this->rating = rating;
		todoOk =1;
	}

	return todoOk;
}

int movie_getRating(eMovie* this,float* rating)
{
	int todoOk = 0;
	if(this != NULL && rating != NULL )
	{
		*rating = this->rating;
		todoOk = 1;
	}

	return todoOk;
}

int menu()
{
    int opcion;

    printf("     *** ABM PELICULAS ***\n");
    printf("  1- CARGAR ARCHIVO\n");
    printf("  2- IMPRIMIR LISTA\n");
    printf("  3- ASIGNAR RATING\n");
    printf("  4- ASIGNAR GENERO\n");
    printf("  5- FILTRAR POR GENERO\n");
    printf("  6- ORDENAR PELICULAS\n");
    printf("  7- GUARDAR PELICULAS\n");
    printf("  8- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int mostrarMovie(eMovie* movie)
{
    int todoOk = 0;
    int id;
    char titulo[60];
    char genero[60];
    float rating;

    if (movie != NULL)
    {
        if ( movie_getId( movie, &id ) &&
             movie_getTitulo( movie, titulo ) &&
             movie_getGenero( movie, genero) &&
             movie_getRating(movie, &rating)
           )
        {
            printf ("  %-3d     %-30s                      %-15s             %-4.1f\n", id, titulo, genero, rating);
            todoOk = 1;
        }
    }
    return todoOk;
}


void* asignarRatingPelicula(void* ratingPelicula)
{

    int max = 100;
    int min = 10;
    float rating;
    eMovie* auxPelicula = NULL;


    if( ratingPelicula != NULL)
    {
        auxPelicula = (eMovie*)ratingPelicula;
        rating = (float)(rand() % (max - min + 1) + min )/10;
        movie_setRating(auxPelicula,rating);
    }
    return auxPelicula;
}

void* asignarGeneroPelicula(void* generoPelicula)
{

    int max = 4;
    int min = 1;
    int genero;
    eMovie* auxPelicula = NULL;


    if( generoPelicula != NULL)
    {
        auxPelicula = (eMovie*)generoPelicula;
        genero = rand() % (max - min + 1) + min;

        switch(genero)
        {
            case 1:
                {
                    movie_setGenero(auxPelicula,"Drama");
                }
                break;

            case 2:
                {
                    movie_setGenero(auxPelicula,"Comedia");
                }
                break;

            case 3:
                {
                    movie_setGenero(auxPelicula,"Accion");
                }
                break;

            case 4:
                {
                    movie_setGenero(auxPelicula,"Terror");
                }
        }

    }
    return auxPelicula;
}


int menuFiltro()
{
    int opcion;

    printf("\n     *** FILTRO POR GENERO DE PELICULA ***\n");
    printf("  1- GENERO DRAMA\n");
    printf("  2- GENERO COMEDIA\n");
    printf("  3- GENERO ACCION\n");
    printf("  4- GENERO TERROR\n");
    printf("  5- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int filtrarPeliculasDrama(void* genero)
{
    int todoOk=0;
    eMovie* auxPelicula = NULL;

    if( genero != NULL)
    {
        auxPelicula = (eMovie*)genero;
        if( !strcmp(auxPelicula->generoPeli,"Drama") )
        {
            todoOk =1;
        }
    }
    return todoOk;
}

int filtrarPeliculasComedia(void* genero)
{
    int todoOk=0;
    eMovie* auxPelicula = NULL;

    if( genero != NULL)
    {
        auxPelicula = (eMovie*)genero;
        if( !strcmp(auxPelicula->generoPeli,"Comedia") )
        {
            todoOk =1;
        }
    }
    return todoOk;
}

int filtrarPeliculasAccion(void* genero)
{
    int todoOk=0;
    eMovie* auxPelicula = NULL;

    if( genero != NULL)
    {
        auxPelicula = (eMovie*)genero;
        if( !strcmp(auxPelicula->generoPeli,"Accion") )
        {
            todoOk =1;
        }
    }
    return todoOk;
}

int filtrarPeliculasTerror(void* genero)
{
    int todoOk=0;
    eMovie* auxPelicula = NULL;

    if( genero != NULL)
    {
        auxPelicula = (eMovie*)genero;
        if( !strcmp(auxPelicula->generoPeli,"Terror") )
        {
            todoOk =1;
        }
    }
    return todoOk;
}


int compararPeliculasGeneroRating(void* pPeliculaA,void* pPeliculaB)
{
    int todoOk= 0;

    if((strcmp(((eMovie*)pPeliculaA)->generoPeli ,((eMovie*)pPeliculaB)->generoPeli) > 0 )|| (strcmp(((eMovie*)pPeliculaA)->generoPeli ,((eMovie*)pPeliculaB)->generoPeli) == 0 && ((eMovie*)pPeliculaA)->rating > ((eMovie*)pPeliculaB)->rating))
    {
        todoOk= 1;
    }
    if((strcmp(((eMovie*)pPeliculaA)->generoPeli ,((eMovie*)pPeliculaB)->generoPeli) < 0 )|| (strcmp(((eMovie*)pPeliculaA)->generoPeli ,((eMovie*)pPeliculaB)->generoPeli) == 0 && ((eMovie*)pPeliculaA)->rating < ((eMovie*)pPeliculaB)->rating))
    {
        todoOk = -1;
    }

    return todoOk;
}



