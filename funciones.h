#define MAXLIBROS 100
#define MAXLETRAS 30
#define MAXPERSONAS 100
#define MAXLET 25

int CantidadLibros[MAXLETRAS];
char NombresLibros[MAXLIBROS][MAXLETRAS];
float PrecioLibros[MAXLETRAS];

char NombresClientes[MAXLIBROS][MAXLETRAS];
int cedulasClientes[MAXLIBROS];
float ValoresPagados[MAXLIBROS];
int cantidadDeProductosComprados[MAXLIBROS];
char NombresClientesCompras[MAXLIBROS][MAXLETRAS];

void IngresarNuevolibro(int*);
void buscarLibro(char[MAXLETRAS], int);
void EliminarLibro(char[MAXLETRAS], int);
void EditarLibro( char[MAXLETRAS], int);
void aumentarStock(char[MAXLETRAS], int);

void limpiarBufferEntrada();

void facturar(int [MAXLETRAS][2], int [MAXLIBROS], int* , int, int);


void fac(int, int );

void buscarFactura(int [MAXLIBROS][2], int [MAXLETRAS], int);

void fechafun(int [MAXLIBROS][2] , int);

void ListadoFacturas(int, int [MAXLETRAS], int [MAXLIBROS][2]);

void ingresarCliente(int* );

void GuardarArchivoLibros(int);

void CargarArchivoLibros(int);

void GuardarPunteros(int, int, int);

void CargarPunteros(int*, int*, int*);

void GuardarArchivoClientes(int );

void CargarArchivoClientes(int );

void GuardarArchivoCompras(int , int [MAXLIBROS][2], int []);

void CargarArchivoCompras(int , int [MAXLIBROS][2],int []);

void ingresarCliente(int*);
void editarCliente(char[MAXLETRAS],int);
void buscarCliente(char[MAXLETRAS],int);
void mostrarClientes(int);

void mostrarLibros(int );
