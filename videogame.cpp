#include "videogame.h"
#include <fstream>
#include <algorithm>

VideoGame::VideoGame()
{

}

VideoGame::VideoGame(const string &nombreV)
{
    this->nombreV = nombreV;
}

void VideoGame::setNombreVideoGame(const string &n)
{
    nombreV = n;
}

string VideoGame::getNombreVideoGame()
{
    return nombreV;
}

void VideoGame::agregarNombreUsuario(const VideoGame &v)
{
    nombreVideoGame.push_back(v);
}

void VideoGame::agregarCivilizacion(const Civilizacion &c)
{
    civilizacion.push_back(c);
}


void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
    civilizacion.insert(civilizacion.begin()+pos, c);
}

size_t VideoGame::size()
{
    return civilizacion.size();
}

void VideoGame::inicializa(const Civilizacion &c, size_t n)
{
    civilizacion = vector<Civilizacion>(n,c);
}

void VideoGame::primeraCivilizacion(const Civilizacion &c)
{
    if (civilizacion.empty()){
        cout << "Vector vacio" << endl;
    }
    else{
        cout << civilizacion.front() << endl;
    }
}

void VideoGame::ultimaCivilizacion(const Civilizacion &c)
{
    if (civilizacion.empty()){
        cout << "Vector vacio" << endl;
    }
    else {
        cout << civilizacion.back() << endl;
    }
}

void VideoGame::ordenarNombre()
{
    sort(civilizacion.begin(), civilizacion.end(),[](Civilizacion n1, Civilizacion n2) 
    {return n1.getNombre() < n2.getNombre();});
}

void VideoGame::ordenarUbicacionX()
{
    sort(civilizacion.begin(), civilizacion.end(), [](Civilizacion x1, Civilizacion x2)
    {return x1.getUbicacion_x() < x2.getUbicacion_x();});
}

void VideoGame::ordenarUbicacionY()
{
    sort(civilizacion.begin(), civilizacion.end(), [](Civilizacion y1, Civilizacion y2)
    {return y1.getUbicacion_y() < y2.getUbicacion_y();});
}

void VideoGame::ordenarPuntuacion()
{
    sort(civilizacion.begin(), civilizacion.end(), [](Civilizacion p1, Civilizacion p2){return p1.getPuntuacion() > p2.getPuntuacion();});
}

void VideoGame::eliminar(const string &nombre)
{
 
    size_t pos = 0;

    for (auto it = civilizacion.begin(); it != civilizacion.end(); it++)
    {
        Civilizacion &c = *it;

        if(nombre == c.getNombre())
        {
            pos = 1;
            civilizacion.erase(it);
            break;
        }
    }
}

Civilizacion* VideoGame::buscar(const Civilizacion &c)
{
    auto it = find(civilizacion.begin(), civilizacion.end(), c);

    if (it == civilizacion.end()){
        return nullptr;
    }
    else {
        return &(*it);
    }
}

void VideoGame::total()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(12) << "Ubicacion X";
    cout << setw(12) << "Ubicacion Y";
    cout << setw(10) << "Puntuacion";
    cout << endl;

    for (size_t i = 0; i < civilizacion.size(); i++){
        Civilizacion &c = civilizacion [i];

        cout << c;
        cout << endl;
    }
}

void VideoGame::modificar(Civilizacion &c)
{
    //Civilizacion c;

    size_t i;
    size_t pos = 0;
    size_t op;
    string  nuevaX, nuevaY,nuevaPuntuacion;
    string nombre;

    for (i = 0; i < civilizacion.size(); i++)
    {
        if (civilizacion[i].getNombre() == c.getNombre())
        {
            pos = 1;
            cout << endl;
            cout << "Datos de la civilizacion: "<< endl;
            cout << "Nombre: " << civilizacion[i].getNombre() << endl;
            cout << "Ubicacion X: " << civilizacion[i].getUbicacion_x() << endl;
            cout << "Ubicacion Y: " << civilizacion[i].getUbicacion_y() << endl;
            cout << "Puntuacion: " << civilizacion[i].getPuntuacion() << endl;
            cout << endl;

            cout << "Que quieres modificar?: "<< endl;
            cout <<"1.- Nombre"<< endl;
            cout <<"2.- Ubicacion X"<< endl;
            cout <<"3.- Ubicacion Y"<< endl;
            cout <<"4.- Puntuacion"<< endl;

            cin >> op;

            switch (op)
            {
                case 1: 
                    cout << "Nuevo nombre: ";
                    cin.ignore();
                    getline (cin, nombre);
                    civilizacion[i].setNombre(nombre);
                    break;
                case 2:
                    cout << "Nueva posicion X: ";
                    cin.ignore();
                    getline(cin, nuevaX);
                    civilizacion[i].setUbicacion_x(nuevaX);
                    break;
                case 3:
                    cout << "Nueva posicion Y: ";
                    cin.ignore();
                    getline(cin, nuevaY);
                    civilizacion[i].setUbicacion_y(nuevaY);
                    break;
                case 4:
                    cout << "Nueva puntuacion: ";
                    cin.ignore();
                    getline(cin, nuevaPuntuacion);
                    civilizacion[i].setPuntuacion(nuevaPuntuacion);
                    break;
            }

            cout << "Modificado con exito! " << endl;
            cout << endl;

        }
    }

}