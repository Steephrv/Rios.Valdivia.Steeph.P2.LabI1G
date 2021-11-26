#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct{
	int id_peli;
	char tituloPeli[128];
	char generoPeli[128];
	float rating;
}eMovie;

#endif // MOVIES_H_INCLUDED

eMovie* movie_new();
eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr);
void movie_delete(eMovie* pMovie);
int movie_setId(eMovie* this,int id);
int movie_getId(eMovie* this,int* id);
int movie_setTitulo(eMovie* this,char* titulo);
int movie_getTitulo(eMovie* this,char* titulo);
int movie_setGenero(eMovie* this,char* genero);
int movie_getGenero(eMovie* this,char* genero);
int movie_setRating(eMovie* this,float rating);
int movie_getRating(eMovie* this,float* rating);


int menu();

int mostrarMovie(eMovie* movie);

void* asignarRatingPelicula(void* ratingPelicula);
void* asignarGeneroPelicula(void* generoPelicula);


int menuFiltro();

int filtrarPeliculasDrama(void* genero);
int filtrarPeliculasComedia(void* genero);
int filtrarPeliculasAccion(void* genero);
int filtrarPeliculasTerror(void* genero);


int compararPeliculasGeneroRating(void* pPeliculaA,void* pPeliculaB);
