#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "movies.h"

int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListMovies)
{
	int todoOk = 0;
	int cant;
	char id_Peli[60];
	char nombrePeli[60];
	char generoPeli[60];
	char duracionPeli[60];
	eMovie* auxPelicula;

	if (pFile != NULL && pArrayListMovies != NULL  )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id_Peli, nombrePeli, generoPeli, duracionPeli);
		do
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id_Peli,nombrePeli,generoPeli, duracionPeli);
			if (cant < 4)
			{
				break;
			}

			auxPelicula = movie_newParametros( id_Peli, nombrePeli, generoPeli, duracionPeli  );
			if (auxPelicula != NULL)
			{
				ll_add( pArrayListMovies, auxPelicula );
				todoOk = 1;
				auxPelicula = NULL;
			}
		}
		while (!feof(pFile));
	}
	return todoOk;
}
