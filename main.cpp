/*
    Autor: Alan Jahir Martinez Sepulveda
    Fecha: 02/06/2021
*/

#include <iostream>
#include "videogame.h"

using namespace std;

int main()
{
    VideoGame vg;
    string op;

    while(true)
    {
        cout << "1.- Nombre de usuario: " << endl;
        cout << "2.- Agregar civilizacion" << endl;
        cout << "3.- Insertar" << endl;
        cout << "4.- Inicializar" << endl;
        cout << "5.- Primera civilizacion" << endl;
        cout << "6.- Ultima civilizacion" << endl;
        cout << "7.- Ordenamiento (4tipos)" << endl;
        cout << "8.- Eliminar por nombre" << endl;
        cout << "9.- Buscar" << endl;
        cout << "10.- Modificar" << endl;
        cout << "11.- Resumen" << endl;
        cout << "12.- Salir" << endl;

        getline(cin, op);

        if (op == "1"){
            VideoGame usuario;
            cin>> usuario;

            vg.agregarNombreUsuario(usuario);
        }

        if (op == "2"){
            Civilizacion c;

            cin >> c;

            vg.agregarCivilizacion(c);
            cin.ignore();
        }
    
        else if (op  == "3"){
            Civilizacion c;
            cin >> c;

            size_t pos;
            cout << "Posicion: ";
            cin >> pos; cin.ignore();
            if (pos >= vg.size()){
                cout << "Posicion no valida!" << endl;
            }
            else{
                vg.insertar(c, pos);
            }
        }

        else if(op == "4"){
            Civilizacion c;

            cin >> c;

            size_t n;
            cout <<"n: ";
            cin >> n; cin.ignore();

            vg.inicializa(c, n);
        }

        else if(op == "5"){
            Civilizacion c;

            vg.primeraCivilizacion(c);
        }

        else if(op == "6"){
            Civilizacion c;

            vg.ultimaCivilizacion(c);
        }
        
        else if(op == "7"){
            Civilizacion c;

            size_t opcion;
            cout << "¿Como quieres ordenar?" << endl;

            cout << "1.- Ordenar por nombre" << endl;
            cout << "2.- Ordenar por ubicacion X" << endl;
            cout << "3.- Ordenar por ubicacion Y" << endl;
            cout << "4.- Ordenar (des) puntuacion" << endl;
            cin >> opcion; cin.ignore();

            switch (opcion)
            {
                
                case 1:
                    vg.ordenarNombre();
                    cout << endl;
                    break;
                case 2: 
                    vg.ordenarUbicacionX();
                    cout << endl;
                    break;
                case 3:
                    vg.ordenarUbicacionY();
                    cout << endl;
                    break;
                case 4:
                    vg.ordenarPuntuacion();
                    cout << endl;
                    break;
            }

            cout << "Ordenamiento hecho correctamente!";
            cout << endl << endl;
        }
        else if (op == "8"){

            string nombre;
            cout << "Nombre: ";
            cin >> nombre; cin.ignore();

            vg.eliminar(nombre);

        }

        else if (op == "9"){
            Civilizacion c;
            cin >> c; cin.ignore();

            Civilizacion *civilizacion = vg.buscar(c);

            if (civilizacion == nullptr){
                cout << "No encontrado" << endl;
            }
            else{
                cout << *civilizacion << endl;
            }
        }

        else if(op == "10"){
            Civilizacion c;
            cin>> c;
            vg.modificar(c);
        }

        else if (op == "11"){
            vg.total();
        }

        else if (op == "12"){
            break;
        }
    }


    return 0;
}