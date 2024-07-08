#include"funciones.h"
#include <stdio.h>
#include "lecturas.h"

int main(){
    char buscar[MAXLETRAS];
    int LibrosIngresados=0,NumeroDeCompras=0,ClientesIngresados=0, respuesta=0, fechas[MAXLIBROS][2], CedulasCompras[MAXLIBROS];
    float PrecioLibros[MAXLIBROS];
    CargarPunteros(&LibrosIngresados, &NumeroDeCompras, &ClientesIngresados);
    CargarArchivoLibros(LibrosIngresados);
    CargarArchivoCompras(NumeroDeCompras, fechas,CedulasCompras);
    CargarArchivoClientes(ClientesIngresados);
    while (respuesta <= 12)
    {   
        printf("/// Inventario Biblioteca del saber \\\\\\ \n");
        printf("Opciones de Inventario: \n");
        printf("1.- Ingresar un libro. \n");
        printf("2.- Buscar un libro. \n");
        printf("3.- Editar un libro. \n");
        printf("4.- Eliminar un libro. \n");
        printf("5.- Mostrar inventario. \n");
        printf("6.- Agregar cliente. \n");
        printf("7.- Editar cliente. \n");
        printf("8.- Buscar cliente. \n");
        printf("9.- Listado de clientes. \n");
        printf("10.- Facturar. \n");
        printf("11.- Buscar factura. \n");
        printf("12.- Ver listado de factura. \n");
        printf("13.- Salir del programa. \n");
        respuesta = leerEnteroEntre("Ingrese la opcion a elegir: ",1,13);
        limpiarBufferEntrada(); 
        switch (respuesta)
        {
        case 1:
            IngresarNuevolibro(&LibrosIngresados);
            break;
        case 2:
            buscarLibro(buscar, LibrosIngresados);
            break;
        case 3:
            EditarLibro(buscar, LibrosIngresados);
            break;
        case 4:
            EliminarLibro(buscar, LibrosIngresados);
            break;
        case 5:
            mostrarLibros(LibrosIngresados);
            break;
        case 6:
            ingresarCliente(&ClientesIngresados);
            break;
        case 7:
            editarCliente(buscar, ClientesIngresados);
            break;
        case 8:
            buscarCliente(buscar, ClientesIngresados);
            break;
        case 9:
            mostrarClientes(ClientesIngresados);
            break;
        case 10:
            facturar(fechas, CedulasCompras, &NumeroDeCompras, ClientesIngresados, LibrosIngresados);
            break;
        case 11:
            buscarFactura(fechas, CedulasCompras, NumeroDeCompras);
            break;
        case 12:
            ListadoFacturas(NumeroDeCompras, CedulasCompras, fechas);
            break;
        default:
        printf("Saliendo...");
        }
    } 
    GuardarArchivoLibros(LibrosIngresados);
    GuardarPunteros(LibrosIngresados, NumeroDeCompras , ClientesIngresados);
    GuardarArchivoCompras(NumeroDeCompras, fechas, CedulasCompras);
    GuardarArchivoClientes(ClientesIngresados);      
}