#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/** \brief carga el archivo
 *
 * \param path char*
 * \param pArrayListMovies LinkedList*
 * \return int retorna 1 si cargo correctamente o 0 si hubo algun error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListMovies);

/** \brief muestra la lista
 *
 * \param pArrayListMovies LinkedList*
 * \return int retorna 1 si esta todoOk o 0 si hubo algun error
 *
 */
int controller_ListMovies(LinkedList* pArrayListMovies);

/** \brief guarda la lista en un archivo
 *
 * \param path char*
 * \param pArrayListMovies LinkedList*
 * \return int retorna 1 si salio todoOk o 0 si hubo algun error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListMovies);
int controller_asignarAleatorioRatingPeli(LinkedList* pArrayListMovie);
int controller_asignarAleatorioGeneroPeli(LinkedList* pArrayListMovie);


int controller_filtrarGeneroDrama(LinkedList* pArrayListMovie);
int controller_filtrarGeneroComedia(LinkedList* pArrayListMovie);
int controller_filtrarGeneroAccion(LinkedList* pArrayListMovie);
int controller_filtrarGeneroTerror(LinkedList* pArrayListMovie);
int controller_filtrarGeneroPelicula(LinkedList* pArrayListMovie);


int controller_sortPeliculas(LinkedList* pArrayListMovie);

#endif // CONTROLLER_H_INCLUDED
