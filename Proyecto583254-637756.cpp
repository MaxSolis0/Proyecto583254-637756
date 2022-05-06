#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

string Ticker[50] = {"USD","EUR","GBP", "JPY", "MXN"};
int opcion, monedaIn, monedaOut, Transacciones = 0;
double Cantidad, CantidadNueva, TotalUSD = 0;
double Total[5][2] = {0,0,0,0,0,0,0,0,0,0};

void Menu()
{
    const string linea_blanco_100 = "                                                                                                    ";
    const string linea_blanco_65 = "                                                                 ";   

    system("cls");
    cout << "          "<<char(201);
    for (int i=1; i<=100;i++) 
    {
        cout << char(205); 
    }
    cout << char(187)<<endl;
    for (int i=1; i<=3;i++)
    {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
     }
    cout << "          " << char(186) << "                                      MENU DIVISAS                                                  "<< char(186) << endl;
    for (int i=1; i<=3;i++)
    {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
    }
    cout << "          " << char(186) << "      01 Nueva divisa              " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      02 Total y cargos            " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      03 Finalizar                 " << linea_blanco_65 << char(186) << endl;
    for (int i=1; i<=5;i++)
    {
        cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
    }
    cout << "          "<<char(200);
    for (int i=1; i<=100;i++) 
    {
        cout << char(205); 
    }
    cout << char(188)<<endl;
    cout << "                                  Opcion ";

}

void divisa() 
{
    double cambios[5][5] = {{1,	0.9381,	0.7926,	127.35,	20.4378}, {1.0660,	1,	0.8450,	135.77,	21.7878}, {1.2616,	1.1835,	1,	160.69,	25.7843}, {0.785200,	0.73655,	0.006222,	1,	0.1605}, {0.04895,	0.04588,	0.03876,	6.2314,	1}};
    const string linea_blanco_100 = "                                                                                                    ";
    const string linea_blanco_65 = "                                                                 ";   

    system("cls");
    cout << "          "<<char(201);
    for (int i=1; i<=100;i++) 
    {
        cout << char(205); 
    }
    cout << char(187)<<endl;
    for (int i=1; i<=3;i++)
    {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
     }
    cout << "          " << char(186) << "                                         DIVISAS                                                    "<< char(186) << endl;
    for (int i=1; i<=3;i++)
    {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
    }
    cout << "          " << char(186) << "      1 USD                        " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      2 EUR                        " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      3 GBP                        " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      4 JPY                        " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      5 MXN                        " << linea_blanco_65 << char(186) << endl;
    for (int i=1; i<=5;i++)
    {
        cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
    }
    cout << "          "<<char(200);
    for (int i=1; i<=100;i++) 
    {
        cout << char(205); 
    }
    cout << char(188)<<endl;
    
    cout << "Ingrese el numero de moneda inicial: (1, 2, 3, 4 o 5)" << "\n";
    cin >> monedaIn;
    while (monedaIn<1 && monedaIn>5){
        cout << "Porfavor da una opcion valida (1, 2, 3, 4 o 5)"<<endl;
        cin >> monedaIn;        
    }
    cout << "Ingrese la cantidad a cambiar: " << "\n";
    cin >> Cantidad;
    if (monedaIn == 4){
        Cantidad = ceilf(Cantidad);
    } else {
        Cantidad = ceilf(Cantidad * 100) / 100;
    }
    Total[monedaIn-1][1] = Total[monedaIn-1][1] + Cantidad;

    cout << "Ingrese el numero de moneda final: " << "\n";
    cin >> monedaOut;
    while (monedaOut<1 && monedaOut>5) {
        cout << "Porfavor da una opcion valida (1, 2, 3, 4 o 5)"<<endl;
        cin >> monedaOut;        
    }
    CantidadNueva = cambios[monedaIn-1][monedaOut-1]*Cantidad;
    if (monedaOut == 4){
        CantidadNueva = ceilf(CantidadNueva);
    } else {
        CantidadNueva = ceilf(CantidadNueva * 100) / 100;
    }
    Total[monedaOut-1][2]=Total[monedaOut-1][2] + CantidadNueva;
    Transacciones = Transacciones + 1;
    TotalUSD = TotalUSD + Cantidad*cambios[monedaIn-1][1];
    cout << Cantidad << " " << Ticker[monedaIn-1] <<" son: " << CantidadNueva << " " << Ticker[monedaOut-1]<<endl;
}

void TotalScreen()
{
    int ancho = 11;
    float cargoPorc, cargo;
    cout << "Total de entrada" << endl;
    for (int i=0; i<5; i++)
    {
        cout.width(ancho);
        cout << Total[i][1] <<" " << Ticker[i] << "\n";
    }
    cout << "\n" << "Total de salida" << endl;
    for (int i=0; i<5; i++)
    {
        cout.width(ancho);
        cout << Total[i][2] <<" " << Ticker[i] << "\n";
    }
    if(Transacciones < 20){
        cargoPorc = 0.01;
    } else if (Transacciones < 50) {
        cargoPorc = 0.025;
    } else if (Transacciones < 100) {
        cargoPorc = 0.05;
    } else {
        cargoPorc = 0.06;
    }
    cargo = TotalUSD*cargoPorc;
    cout << "\n" << "Se realizaron " << Transacciones << " transacciones, el cargo es de: " << cargo << "USD." << endl;
}

int main() 
{
    string opcion_str;
    int opcion;
    do {
        Menu();
        cin >> opcion_str;
        opcion = atoi(opcion_str.c_str());
        switch (opcion)
        {
        case 1:
            divisa();
            system("pause");
            break;
        case 2:
            TotalScreen();
            system("pause");
            break;
        case 3:
            cout << "¡Gracias por su preferencia!"<<endl;
            break;
        default:
            cout << "Por favor da una opcion valida (1, 2, o 3)"<<endl;
            system("pause");
            break;
        }
    } while (opcion != 3);
    return(0);
}