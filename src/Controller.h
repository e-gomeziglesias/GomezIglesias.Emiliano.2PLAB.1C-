int controller_loadLibroFromText(char* path , LinkedList* pArrayListLibro);
int controller_loadEditorialFromText(char* path , LinkedList* pArrayListEditorial);
int controller_loadLibroFromBinary(char* path , LinkedList* pArrayListLibro);
int controller_loadEditorialFromBinary(char* path , LinkedList* pArrayListEditorial);
int controller_getLibro(LinkedList* pArrayListLibro, int index, int* pId, char* titulo, char* autor, float* pPrecio, int* pIdEditorial);
int controller_getEditorial(LinkedList* pArrayListEditorial, int index, int* pId, char* nombre);
int controller_MostrarUnaEditorialCompleta(LinkedList* pArrayListEditorial, int index);
int controller_MostrarDescripcionUnaEditorial(LinkedList* pArrayListEditorial, int index);
int controller_MostrarUnLibroCompleto(LinkedList* pArrayListLibro, int indexLibro, LinkedList* pArrayListEditorial);
int controller_getIndexEditorialById(LinkedList* pArrayListEditorial, int id);
int controller_getIndexLibroById(LinkedList* pArrayListLibro, int id);
int controller_ListLibros(LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial);
int controller_ListEditoriales(LinkedList* pArrayListEditorial);
int controller_saveLibroAsText(char* path , LinkedList* pArrayListLibro);
int controller_saveEditorialAsText(char* path , LinkedList* pArrayListEditorial);
int controller_sortLibros(LinkedList* pArrayListEmployee);
int controller_ListarLibrosDeMinotauro(LinkedList* pArrayListaLibro, char* pathArchivoMinotauro, LinkedList* pArrayListEditorial);
int controller_mapeo(LinkedList* pArrayListaLibro, LinkedList* pArrayListEditorial, char* pathArchivoMapeo);

/*
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
*/
