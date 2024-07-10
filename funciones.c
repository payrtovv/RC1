#include<string.h>
#include<stdio.h>
#include <stdlib.h>

#include "lecturas.h"
#include "funciones.h"

FILE* archivo;
FILE* archivoPunteros;
FILE* archivoClientes;
FILE* archivoCompras;

void GuardarArchivoLibros(int LibrosIngresados){
    archivo = fopen("inventario.txt", "w");    
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo con exito\n");
        return;
    }

    for (int i = 0; i < LibrosIngresados; i++)
    {
        strtok(NombresLibros[i], "\n"); 
        fprintf(archivo, "%s %d %.2f\n", NombresLibros[i], CantidadLibros[i], PrecioLibros[i]);
    }
    fclose(archivo);
}

void CargarArchivoLibros(int LibrosIngresados){
    archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo con exito\n");
        return;
    }  

    char nombreLibro[MAXLETRAS];
    int cantidadLibro=0;
    float precioLibro=0;
    int i = 0;

    while (i < LibrosIngresados && fscanf(archivo, "%s %d %f", nombreLibro, &cantidadLibro, &precioLibro) == 3) {
        strcpy(NombresLibros[i], nombreLibro);
        CantidadLibros[i] = cantidadLibro;
        PrecioLibros[i] = precioLibro;    
        i++;
    }         
                     
    fclose(archivo);
}    

void GuardarArchivoCompras(char NombresClientesCompras[MAXLIBROS][MAXLETRAS], int cantidadDeProductosComprados[MAXLIBROS], float ValoresPagados[MAXLIBROS] ,int NumeroDeCompras, int fechas[MAXLIBROS][2],int CedulasCompras[MAXLIBROS]){
    archivoCompras = fopen("compras.txt", "w");    
    if (archivoCompras == NULL) {
        printf("No se pudo abrir el archivo con exito\n");
        return;
    }

    for (int i = 0; i < NumeroDeCompras; i++)
    {
        fprintf(archivoCompras, "%d %d %d %d %s %d %.2f\n", fechas[i][0],fechas[i][1] ,fechas[i][2], CedulasCompras[i], NombresClientesCompras[i],cantidadDeProductosComprados[i], ValoresPagados[i]);
    }
    fclose(archivoCompras);
}


void CargarArchivoCompras(char NombresClientesCompras[MAXLIBROS][MAXLETRAS], int cantidadDeProductosComprados[MAXLIBROS] ,float ValoresPagados[MAXLIBROS], int NumeroDeCompras, int fechas[MAXLIBROS][2],int CedulasCompras[MAXLIBROS]){
    archivoCompras = fopen("compras.txt", "r");
    if (archivoCompras == NULL) {
        printf("No se pudo abrir el archivo con exito\n");
        return;
    }  

    
    int i = 0;

    while (i < NumeroDeCompras && fscanf(archivoCompras, "%d %d %d %d %s %d %.2f", &fechas[i][0],&fechas[i][1] ,&fechas[i][2], &CedulasCompras[i], NombresClientesCompras[i],&cantidadDeProductosComprados[i] ,&ValoresPagados[i]) == 7) {
        i++;
    }         
                     
    fclose(archivoCompras);
}    



void GuardarArchivoClientes(char NombresClientes[MAXLIBROS][MAXLETRAS], int ClientesIngresados, int cedulasClientes[MAXLIBROS]){
    archivoClientes = fopen("clientes.txt", "w");    
    if (archivoClientes == NULL) {
        printf("No se pudo abrir el archivo con exito\n");
        return;
    }

    for (int i = 0; i < ClientesIngresados; i++)
    {
        strtok(NombresClientes[i], "\n"); 
        fprintf(archivoClientes, "%s %d\n", NombresClientes[i], cedulasClientes[i]);
    }
    fclose(archivoClientes);
}



void CargarArchivoClientes(char NombresClientes[MAXLIBROS][MAXLETRAS], int ClientesIngresados, int cedulasClientes[MAXLIBROS]){
    archivoClientes = fopen("clientes.txt", "r");
    if (archivoClientes == NULL) {
        printf("No se pudo abrir el archivo con exito\n");
        return;
    }  
    int i = 0;

    while (i < ClientesIngresados && fscanf(archivoClientes, "%s %d", NombresClientes[i], &cedulasClientes[i]) == 2) {
        i++;
    }         
                     
    fclose(archivoClientes);
}    

void GuardarPunteros(int LibrosIngresados, int NumeroDeCompras , int ClientesIngresados){
    archivoPunteros = fopen("punteros.txt", "w");
    if (archivoPunteros == NULL) {
        printf("No se pudo abrir el archivo con exito\n");
        return;
    }  
    fprintf(archivoPunteros, "%i %i %i", LibrosIngresados, NumeroDeCompras, ClientesIngresados);
    fclose(archivoPunteros);
}



void CargarPunteros(int* LibrosIngresados, int* NumeroDeCompras, int* ClientesIngresados){
    int Libros=0, numero=0, Clientes=0;
    archivoPunteros = fopen("punteros.txt", "r");
    if (archivoPunteros == NULL) {
        printf("No se pudo abrir el archivo con exito\n");
        return;
    }  
    fscanf(archivoPunteros, "%d %d %d", &Libros, &numero, &Clientes);           
    printf("%i", Clientes);
    *LibrosIngresados = Libros;
    *NumeroDeCompras = numero;
    *ClientesIngresados = Clientes;
    fclose(archivoPunteros);
}

    


void IngresarNuevolibro(int* LibrosIngresados){
    char buscar[MAXLETRAS];
    if (*LibrosIngresados >= MAXLIBROS) {
        printf("No hay almacenamiento suficiente.\n");
        printf("<-------------------------->\n");
        return;
    }   
    printf("Ingrese el nombre del libro a registrar: ");
    fgets(buscar, MAXLETRAS, stdin);
    strtok(buscar, "\n");
    for (int i = 0; i < *LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Libro ya existente.\n");
            printf("<-------------------------->\n");
            return;
        }
    }
    strcpy(NombresLibros[*LibrosIngresados], buscar);
    CantidadLibros[*LibrosIngresados] = leerEnteroPositivo("Ingrese la cantidad de libros: ");
    PrecioLibros[*LibrosIngresados] = leerFlotantePositivo("Ingrese el precio del libro: ");
    printf("Producto agregado con exito.\n");
    printf("<-------------------------->\n");
    (*LibrosIngresados)++;
}

void limpiarBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void buscarLibro(char buscar[MAXLETRAS], int LibrosIngresados ){
    printf("Ingrese el libro a buscar: ");
    fgets(buscar,MAXLETRAS, stdin);
    strtok(buscar, "\n");
    for (int i = 0; i < LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Encontrado\n");
            printf("Nombre:   %s\n", NombresLibros[i]);
            printf("Cantidad: %i\n", CantidadLibros[i]);
            printf("Precio:   %.2f\n", PrecioLibros[i]);
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Libro no encontrado\n");
    printf("<-------------------------->\n");
}

void EliminarLibro(char buscar[MAXLETRAS], int LibrosIngresados){
    printf("Ingrese el libro a ser eliminado: ");
    fgets(buscar,MAXLETRAS, stdin);
    strtok(buscar, "\n");
    for (int i = 0; i < LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Encontrado y eliminado exitosamente. \n");
            for (int j = 0; j < MAXLETRAS; j++) {
            NombresLibros[i][j] = 0; 
            }
            CantidadLibros[i]=0;
            PrecioLibros[i]=0;
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
    printf("<-------------------------->\n");
}

void EditarLibro(char buscar[MAXLETRAS], int LibrosIngresados ){
    printf("Ingrese el libro a editar: ");
    fgets(buscar,MAXLETRAS, stdin);
    strtok(buscar, "\n");
    for (int i = 0; i < LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Encontrado\n");
            printf("Nombre:   %s\n", NombresLibros[i]);
            printf("Cantidad: %i\n", CantidadLibros[i]);
            printf("Precio:   %.2f\n", PrecioLibros[i]);
            CantidadLibros[i] = leerEnteroPositivo("\nIngrese la nueva cantidad de libros: ");
            PrecioLibros[i] = leerFlotantePositivo("Ingrese el nuevo precio de el libro: ");
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
    printf("<---------------------------->\n");
}

void aumentarStock(char buscar[MAXLETRAS], int LibrosIngresados){
    int valor;
    printf("Ingrese el nombre libro al que se quiere aumentar el stock: ");
    fgets(buscar,MAXLETRAS, stdin);
    strtok(buscar, "\n");
    for (int i = 0; i < LibrosIngresados; i++)
    {
        if ((strcmp(buscar,NombresLibros[i]))==0)
        {
            printf("Encontrado\n");
            printf("Nombre:   %s\n", NombresLibros[i]);
            printf("Cantidad: %i\n", CantidadLibros[i]);
            valor = leerEnteroPositivo("\nIngrese cuanto se va a aumentar: ");
            CantidadLibros[i] = CantidadLibros[i] + valor;
            printf("Agregado correctamente\n");
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
    printf("<---------------------------->\n");
}

void facturar(char NombresClientes[MAXLIBROS][MAXLETRAS], int cedulasClientes[MAXLIBROS], char NombresClientesCompras[MAXLIBROS][MAXLETRAS], int cantidadDeProductosComprados[MAXLIBROS], float ValoresPagados[MAXLIBROS] ,int fechas[MAXLIBROS][2], int CedulasCompras[MAXLIBROS],int* NumeroDeCompras, int ClientesIngresados, int LibrosIngresados){
    int buscarcedula=0;
    buscarcedula = leerCedula("Ingrese el numero de cedula: \n");
    for (int i = 0; i < ClientesIngresados; i++)
    {
        if (buscarcedula==cedulasClientes[i])
        {
            printf("Cedula encontrada\n");
            fechafun(fechas, *NumeroDeCompras);
            CedulasCompras[*NumeroDeCompras] = buscarcedula;
            strcpy(NombresClientesCompras[*NumeroDeCompras], NombresClientes[i]);
            fac(cantidadDeProductosComprados,ValoresPagados, LibrosIngresados, *NumeroDeCompras);
            (*NumeroDeCompras)++;
            return;
        }

    }

    printf("Cedula no encontrada");
}


void fac(int cantidadDeProductosComprados[MAXLIBROS], float ValoresPagados[MAXLIBROS]  ,int LibrosIngresados, int NumeroDeCompras){
    char buscar[MAXLETRAS];
    int respuesta = 1;
    float valor = 0;
    float valorTotal =0;
    cantidadDeProductosComprados[NumeroDeCompras] = 0;
    limpiarBufferEntrada();
    while(respuesta == 1){
        printf("Ingrese el nombre del libro a vender: \n");
        fgets(buscar,MAXLETRAS, stdin);
        strtok(buscar, "\n");
        valor = 0; 
        for (int i = 0; i < LibrosIngresados; i++)
        {
            if ((strcmp(buscar,NombresLibros[i]))==0)
            {
                int cantidad=0;
                printf("Encontrado\n");
                cantidad = leerEnteroPositivo("Ingresar la cantidad de libros a vender: \n");
                if((CantidadLibros[i]- cantidad) <= 0){
                    printf("No hay sufiscientes\n");
                    return;
                }
                valor = cantidad * PrecioLibros[i];
                cantidadDeProductosComprados[NumeroDeCompras] += cantidad;
                CantidadLibros[i] = CantidadLibros[i] - cantidad;
                valorTotal += valor;
                break;
            }
            
        }
        printf("Desea seguir comprando? 1=si/2=no\n");
        scanf("%i", &respuesta);
        limpiarBufferEntrada();
    }
    printf("Cantidad a pagar: %.2f\n", valorTotal);
    ValoresPagados[NumeroDeCompras]=valorTotal;
    printf("<-------------------------->\n");
}

void buscarFactura(int cedulasClientes[MAXLIBROS], char NombresClientesCompras[MAXLIBROS][MAXLETRAS], int cantidadDeProductosComprados[MAXLIBROS], float ValoresPagados[MAXLIBROS] ,int fechas[MAXLIBROS][2], int CedulasCompras[], int NumeroDeCompras){
    int buscarcedula=0;

    buscarcedula = leerCedula("Ingresar la cedula del cliente: ");
    for (int i = 0; i < NumeroDeCompras; i++)
    {
        if (buscarcedula==cedulasClientes[i])
        {
            printf("Encontrado\n");
            printf("fecha: ");
            printf("%i/ %i/ %i\n", fechas[i][0], fechas[i][1], fechas[i][2]);
            printf("cedula: ");
            printf("%i\n", CedulasCompras[i]);
            printf("Nombre: ");
            printf("%s\n", NombresClientesCompras[i]);
            printf("Valor pagado: ");
            printf("%.2f\n", ValoresPagados[i]);
            printf("cantidad de productos: ");
            printf("%i\n", cantidadDeProductosComprados[i]);
            printf("<-------------------------->\n");
        }
    }
}

void ListadoFacturas(char NombresClientesCompras[MAXLIBROS][MAXLETRAS], int cantidadDeProductosComprados[MAXLIBROS], float ValoresPagados[MAXLIBROS]  ,int NumeroDeCompras, int CedulasCompras[], int fechas[MAXLIBROS][2]){
    for (int i = 0; i < NumeroDeCompras; i++)
    {
            printf("fecha: ");
            printf("%i/ %i/ %i\n", fechas[i][0], fechas[i][1], fechas[i][2]);
            printf("cedula: ");
            printf("%i\n", CedulasCompras[i]);
            printf("Nombre: ");
            printf("%s\n", NombresClientesCompras[i]);
            printf("Valor pagado: ");
            printf("%.2f\n", ValoresPagados[i]);
            printf("cantidad de productos: ");
            printf("%i\n", cantidadDeProductosComprados[i]);
            printf("<-------------------------->\n");
    }
    
}

void fechafun(int fechas[MAXLIBROS][2], int NumeroDeCompras){
    int mes, dia, anio;
    mes = leerEnteroEntre("Ingrese el numero del mes: ", 1,12);
    switch(mes){
        case 1:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,31);
            break;
        case 2:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,28);
            break;
        case 3:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,31);
            break; 
        case 4:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,30);
            break;
        case 5:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,31);
            break;
        case 6:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,30);
            break;      
        case 7:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,31);
            break;
        case 8:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,31);
            break;
        case 9:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,30);
            break; 
        case 10:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,31);
            break;
        case 11:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,30);
            break;
        case 12:
            dia = leerEnteroEntre("Ingrese el dia: ", 1,31);
            break;     
        }    
    printf("ingrese el anio: ");   
    scanf("%i", &anio);   
    fechas[NumeroDeCompras][0] = mes;
    fechas[NumeroDeCompras][1] = dia;
    fechas[NumeroDeCompras][2] = anio;
    }

int leerCedula(char* mensaje) {
    char numCedula[11]; 
    int respuesta = 0, cedula = 0;
    do {
        printf("%s", mensaje);
        scanf("%s", numCedula);
        
        if (strlen(numCedula) != 10) {
            printf("La cedula debe contener 10 digitos.\n");
        } else {
            int numRegion = (numCedula[0] - '0') * 10 + (numCedula[1] - '0');
            int ultimoNum = numCedula[9] - '0';
            int numPares = (numCedula[1] - '0') + (numCedula[3] - '0') + (numCedula[5] - '0') + (numCedula[7] - '0');

            if (numRegion < 1 || numRegion > 24) {
                printf("Cedula incorrecta.\n");
            } else {
                int vector[5];
                for (int i = 0; i < 5; i++) {
                    vector[i] = (numCedula[i * 2] - '0') * 2;
                    if (vector[i] > 9) {
                        vector[i] -= 9;
                    }
                }

                int numImpares = vector[0] + vector[1] + vector[2] + vector[3] + vector[4];
                int suma = numPares + numImpares;
                int primerNum = suma / 10;
                int deceneaInmediata = (primerNum + 1) * 10;
                int numValidador = deceneaInmediata - suma;
                if (numValidador == 10) {
                    numValidador = 0;
                }
                if (numValidador == ultimoNum) {
                    respuesta = 1;
                    cedula = atoi(numCedula); 
                } else {
                    printf("Cedula incorrecta, intentelo nuevamente.\n");
                }
            }
        }
    } while (respuesta != 1);
    return cedula;
}
void ingresarCliente(char NombresClientes[MAXLIBROS][MAXLETRAS], int cedulasClientes[MAXLIBROS], int* ClientesIngresados){
    char nombre[MAXLETRAS];
    if (*ClientesIngresados >= MAXPERSONAS) {
        printf("Numero maximo de clientes alcanzado. \n");
        printf("<-------------------------->\n");
        return;
    }   
    printf("Ingrese el nombre del cliente: ");
    fgets(nombre, MAXLET, stdin);
    strtok(nombre, "\n");
    for (int i = 0; i < *ClientesIngresados; i++){
        if ((strcmp(nombre,NombresClientes[i]))==0){
            printf("Cliente ya registrado.\n");
            printf("<-------------------------->\n");
            return;
        }
    }
    strcpy(NombresClientes[*ClientesIngresados], nombre);
    cedulasClientes[*ClientesIngresados] = leerCedula("Ingrese la cedula del cliente: ");
    printf("Cliente registrado con exito.\n");
    printf("<-------------------------->\n");
    (*ClientesIngresados)++;
}

void mostrarClientes(char NombresClientes[MAXLIBROS][MAXLETRAS], int cedulasClientes[MAXLIBROS], int ClientesIngresados){
    printf("Lista de clientes Biblioteca Del Saber \n");
    for (int i = 0; i < ClientesIngresados; i++)
    {
        printf("Nombre: %s\n", NombresClientes[i]);
        printf("Cedula: %i \n", cedulasClientes[i]);
        printf("<-------------------------->\n");
    }
}
void buscarCliente(char NombresClientes[MAXLIBROS][MAXLETRAS], int cedulasClientes[MAXLIBROS], char buscar[MAXLETRAS], int ClientesIngresados){
    printf("Ingrese el cliente a buscar: ");
    fgets(buscar,MAXLETRAS, stdin);
    strtok(buscar, "\n");
    for (int i = 0; i < ClientesIngresados; i++)
    {
        if ((strcmp(buscar,NombresClientes[i]))==0)
        {
            printf("Encontrado\n");
            printf("Nombre: %s\n", NombresClientes[i]);
            printf("Cedula: %i\n", cedulasClientes[i]);
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Cliente no encontrado\n");
    printf("<-------------------------->\n");
}
void editarCliente(char NombresClientes[MAXLIBROS][MAXLETRAS], int cedulasClientes[MAXLIBROS], char buscar[MAXLETRAS], int ClientesIngresados){

    printf("Ingrese el cliente a editar: ");
    fgets(buscar,MAXLETRAS, stdin);
    strtok(buscar, "\n");
    for (int i = 0; i < ClientesIngresados; i++)
    {
        if ((strcmp(buscar,NombresClientes[i]))==0)
        {
            printf("Encontrado\n");
            printf("Nombre:   %s\n", NombresClientes[i]);
            printf("Cedula: %i\n", cedulasClientes[i]);
            cedulasClientes[i]=leerCedula("Ingrese el numero de cedula: ");
            printf("<-------------------------->\n");
            return;
        }
    }
    printf("Cliente no encontrado.\n");
    printf("<---------------------------->\n");
}

void mostrarLibros(int LibrosIngresados){
    printf("Inventario Biblioteca Del Saber \n");
    for (int i = 0; i < LibrosIngresados; i++)
    {
        printf("Nombre:   %s\n", NombresLibros[i]);
        printf("Cantidad: %i\n", CantidadLibros[i]);
        printf("Precio:   %.2f\n", PrecioLibros[i]);
        printf("<-------------------------->\n");
    }
    
}