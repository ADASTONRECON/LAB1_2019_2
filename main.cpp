/*
 * NOMBRE: GIOVANNI GIUSSEPPE MIRANDA MALPARTIDA
 * CODIGO: 20151864
 */

#include <iomanip>
#include <iostream>
#include "herramientas.h"

using namespace std;


int main(int argc, char** argv){

    int i, numcaracteres, codigo, dia, mes ,anio;
    float tipocambio_dolar, tipocambio_euro, saldo;
    float monto;
    double totaldeposito, totalretiro;
    int cantdeposito, cantretiro;
    char car, car2, tipomoneda;
    bool primeraletra = true;

    imprimirTitulo();
    //LECTURA DE LOS TIPOS DE CAMBIO            
    cin >> tipocambio_dolar >> tipocambio_euro >> ws;

    //FORMATO DE LECTURA
    cout.precision(2);
    cout << fixed;


    while (1) {
        while (1) {
            cin.clear();
            numcaracteres = 0;

            //LECTURA E IMPRESIÓN DEL NOMBRE, CODIGO, MONEDA Y SALDO INICIAL DEL USUARIO
            imprimirEncabezado_1();
            while (1) {
                car = cin.get();
                if(cin.eof())
                    return 0;
                if (car == ' ') {
                    primeraletra = true;
                    cout.put(' ');
                    car2 = cin.peek();
                    if (car2 == ' ') {
                        break;
                    }
                } else if (primeraletra) {
                    //car = car2;                    
                    primeraletra = false;                               
                    cout << car;
                } else {
                    car = car - 'A' + 'a';
                    cout << car;
                }    
                numcaracteres++;
            }
            imprimirEspacios(numcaracteres);
            cin >> codigo >> ws >> tipomoneda >> saldo;
            cout << "    " << setw(18) << codigo << left;
            switch (tipomoneda) {
                case '$':
                {
                    cout<< setw(20) << "Dólar";
                    break;
                }
                case 'S':
                {
                    cout<< setw(20) << "Soles";
                    break;
                }
                case '&':
                {
                    cout<< setw(20) << "Euros";
                    break;
                }
            }
            cout << tipomoneda << "  " << saldo << endl;



            //LECTURA E IMPRESION DE LOS MOVIMIENTOS HECHOS POR EL USUARIO
            imprimirEncabezado_2();
            cin >> ws;
            while (1) {
                //LECTURA E IMPRESION DE LA FECHA
                if(!(cin >> dia >> car >> mes >> car >> anio))
                    break;

                cout << right <<setw(2) << setfill('0') <<  dia << '/' << setw(2) << mes << '/' << anio << left << setfill(' ');

                cantdeposito = 0;
                cantretiro = 0;
                totaldeposito = 0.0;
                totalretiro = 0.0;

                //LECTURA DE LOS DEPOSITOS Y RETIROS POR DIA
                while (1) {
                    car2 = car;
                    cin >> ws >> car;
                    /*if ((car != 'D') || (car != 'R')) {
                        cin.unget();
                        car = car2;
                    }*/
                    if ((car == 'S') || (car == '$') || (car == '&')) {
                        cin.unget();
                        car = car2;
                    }
                    cin >> ws >> car2 >> monto;

                    switch (car2) {
                        case 'S':
                        {
                            if (tipomoneda == '$') {
                                monto /= tipocambio_dolar;

                            } else if (tipomoneda == '&') {
                                monto /= tipocambio_euro;

                            }
                            break;
                        }
                        case '$':
                        {
                            if (tipomoneda == 'S') {
                                monto *= tipocambio_dolar;
                            } else if (tipomoneda == '&') {
                                monto *= tipocambio_dolar;
                                monto /= tipocambio_euro;
                            }
                            break;
                        }
                        case '&':
                        {
                            if (tipomoneda == 'S') {
                                monto *= tipocambio_euro;
                            } else if (tipomoneda == '$') {
                                monto *= tipocambio_euro;
                                monto /= tipocambio_dolar;
                            }
                        }
                    }
                    if (car == 'D') {
                        cantdeposito++;
                        totaldeposito += monto;
                        saldo += monto;
                    }
                    if (car == 'R') {
                        cantretiro++;
                        totalretiro += monto;
                        saldo -= monto;
                    }


                    //CAMBIO DE LINEA EN LINUX ES \r Y PARA WINDOWS \n
                    if (cin.get() == '\r') {
                        cout << right << setw(10) << tipomoneda << " " << setw (9) <<totalretiro;
                        cout << right << setw(13) << tipomoneda << " " << setw (9) << totaldeposito;
                        cout << right << setw(15) << tipomoneda << " " << setw (9) << saldo << endl;

                        cin >> ws;
                        break;
                    } else {
                        cin.unget();
                    } 
                }
            }
        }
    }
    return 0;
}

