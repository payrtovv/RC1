#include <stdio.h>
#include "lecturas.h"
float leerFlotantePositivo(char*mensaje){
    float valor;
    do{
        printf("%s", mensaje);
        scanf("%f",&valor);
    }while(valor <= 0);
    return valor;
}
float leerFlotante(char*mensaje){
    float valor;
        printf("%s", mensaje);
        scanf("%f",&valor);
    return valor;
}
float leerFlotanteEntre(char*mensaje, float limsup, float liminf){
   float valor;
    do {
        printf("%s", mensaje);
        scanf("%f",&valor);
        if (valor < liminf || valor > limsup) {
        printf("Inténtelo nuevamente.\n");
        }
    } while (valor < liminf || valor > limsup);
    return valor;
}
int leerEnteroPositivo(char*mensaje){
    int valor;
    do{
        printf("%s", mensaje);
        scanf("%d",&valor);
    }while(valor <= 0);
    return valor;
}
int leerEntero(char*mensaje){
    int valor;
     printf("%s", mensaje);
     scanf("%d",&valor);
    return valor;
}
int leerEnteroEntre(char*mensaje, int liminf, int limsup){
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d",&valor);
        if (valor < liminf || valor > limsup) {
        printf("Inténtelo nuevamente.\n");
        }
    } while (valor < liminf || valor > limsup);
    return valor;
}
char leerChar(char*mensaje){
    char valor;
     printf("%s", mensaje);
     scanf("%c",&valor);
    return valor;
}