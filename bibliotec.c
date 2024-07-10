#include"funciones.h"
#include <stdio.h>
#include "lecturas.h"

int main(){
    char buscar[MAXLETRAS], NombresClientesCompras[MAXLIBROS][MAXLETRAS], NombresClientes[MAXLIBROS][MAXLETRAS];
    int LibrosIngresados=0,NumeroDeCompras=0,ClientesIngresados=0, respuesta=0, fechas[MAXLIBROS][2], CedulasCompras[MAXLIBROS], cantidadDeProductosComprados[MAXLIBROS];
    int cedulasClientes[MAXLIBROS];
    float ValoresPagados[MAXLIBROS];
    CargarPunteros(&LibrosIngresados, &NumeroDeCompras, &ClientesIngresados);
    CargarArchivoLibros(LibrosIngresados);
    CargarArchivoCompras(NombresClientesCompras, cantidadDeProductosComprados , ValoresPagados,NumeroDeCompras, fechas,CedulasCompras);
    CargarArchivoClientes(NombresClientes, ClientesIngresados, cedulasClientes);
    while (respuesta <= 12)
    {   
        printf("/// Inventario Biblioteca del saber \\\\\\ \n");
        printf("Opciones de Inventario: \n");
        printf("1.- Ingresar un libro. \n");
        printf("2.- Buscar un libro. \n");
        printf("3.- Editar un libro. \n");
        printf("4.- Eliminar un libro. \n");
        printf("5.- Mostrar inventario. \n");
        printf("6.- Aumentar stock. \n");
        printf("7.- Agregar cliente. \n");
        printf("8.- Editar cliente. \n");
        printf("9.- Buscar cliente. \n");
        printf("10.- Listado de clientes. \n");
        printf("11.- Facturar. \n");
        printf("12.- Buscar factura. \n");
        printf("13.- Ver listado de factura. \n");
        printf("14.- Salir del programa. \n");
        respuesta = leerEnteroEntre("Ingrese la opcion a elegir: ",1,14);
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
            aumentarStock( buscar, LibrosIngresados);
            break;
        case 7:
            ingresarCliente(NombresClientes, cedulasClientes, &ClientesIngresados);
            break;
        case 8:
            editarCliente(NombresClientes, cedulasClientes, buscar, ClientesIngresados);
            break;
        case 9:
            buscarCliente(NombresClientes, cedulasClientes, buscar, ClientesIngresados);
            break;
        case 10:
            mostrarClientes(NombresClientes, cedulasClientes, ClientesIngresados);
            break;
        case 11:
            facturar(NombresClientes, cedulasClientes, NombresClientesCompras, cantidadDeProductosComprados, ValoresPagados ,fechas, CedulasCompras, &NumeroDeCompras, ClientesIngresados, LibrosIngresados);
            break;
        case 12:
            buscarFactura(cedulasClientes, NombresClientesCompras, cantidadDeProductosComprados, ValoresPagados ,fechas, CedulasCompras, NumeroDeCompras);
            break;
        case 13:
            ListadoFacturas(NombresClientesCompras, cantidadDeProductosComprados, ValoresPagados ,NumeroDeCompras, CedulasCompras, fechas);
            break;
        default:
        printf("Saliendo...");
        }
    } 
    GuardarArchivoLibros(LibrosIngresados);
    GuardarPunteros(LibrosIngresados, NumeroDeCompras , ClientesIngresados);
    GuardarArchivoCompras(NombresClientesCompras, cantidadDeProductosComprados , ValoresPagados,NumeroDeCompras, fechas, CedulasCompras);
    GuardarArchivoClientes(NombresClientes, ClientesIngresados, cedulasClientes);      
}