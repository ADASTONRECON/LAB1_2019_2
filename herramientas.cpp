/*
 * NOMBRE: GIOVANNI GIUSSEPPE MIRANDA MALPARTIDA
 * CODIGO: 20151864
 */

#include <iomanip>
#include <iostream>
#include "herramientas.h"

using namespace std;

#define MAX_ANCHO 100
#define MAX_CAR 36

void imprimirLineas(char car){
    int i;
    for(i = 0; i < MAX_ANCHO; i++){
        cout << car;
    }
    cout << endl;
}

void imprimirTitulo(){
    cout << "ESTADO DE CUENTAS DEL BANCO ABCD" << endl;
}

void imprimirEncabezado_1(){
    imprimirLineas('=');
    cout << left << setw(36) << "CLIENTE" << setw(23) << "CODIGO DE CUENTA" << setw(19) << "MONEDA" << "SALDO INICIAL" << endl;
}


void imprimirEncabezado_2(){
    imprimirLineas('=');
    cout << left << setw(18) << "FECHA" << setw(24) << "RETIRO DOLARES" << setw(24) << "DEPOSITOS DOLARES" << setw(20) << "SALDO DOLARES" << "OBSERVACION" << endl;
    imprimirLineas('-');
}


void imprimirMovimientos(){
    
}

void imprimirEspacios(int num){
    int i;
    for(i = 0; i < num; i++){
        cout.put(' ');
    }
}

void imprimirResumen();