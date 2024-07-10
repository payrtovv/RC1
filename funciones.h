#define MAXLIBROS 100
#define MAXLETRAS 30
#define MAXPERSONAS 100
#define MAXLET 25

int CantidadLibros[MAXLETRAS];
char NombresLibros[MAXLIBROS][MAXLETRAS];
float PrecioLibros[MAXLETRAS];

void IngresarNuevolibro(int*);
void buscarLibro(char[MAXLETRAS], int);
void EliminarLibro(char[MAXLETRAS], int);
void EditarLibro( char[MAXLETRAS], int);
void aumentarStock(char[MAXLETRAS], int);
void mostrarLibros(int );

void limpiarBufferEntrada();

void facturar(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS],char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS], float [MAXLIBROS] ,int [MAXLETRAS][2], int [MAXLIBROS], int* , int, int);
void fac(int [MAXLIBROS], float [MAXLIBROS]  ,int, int );
void buscarFactura(int [MAXLIBROS], char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS], float [MAXLIBROS] ,int [MAXLIBROS][2], int [MAXLETRAS], int);
void fechafun(int [MAXLIBROS][2] , int);
void ListadoFacturas(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS], float [MAXLIBROS]  ,int, int [MAXLETRAS], int [MAXLIBROS][2]);

void ingresarCliente(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS], int* );
void editarCliente(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS], char[MAXLETRAS],int);
void buscarCliente(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS], char[MAXLETRAS],int);
void mostrarClientes(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS], int);

void GuardarArchivoLibros(int);

void CargarArchivoLibros(int);

void GuardarPunteros(int, int, int);

void CargarPunteros(int*, int*, int*);

void GuardarArchivoClientes(char [MAXLIBROS][MAXLETRAS], int, int [MAXLIBROS]);

void CargarArchivoClientes(char [MAXLIBROS][MAXLETRAS], int, int [MAXLIBROS] );

void GuardarArchivoCompras(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS] , float [MAXLIBROS], int , int [MAXLIBROS][2], int []);

void CargarArchivoCompras(char [MAXLIBROS][MAXLETRAS], int [MAXLIBROS] ,float [MAXLIBROS],int , int [MAXLIBROS][2],int []);

int leerCedula(char* ); 

