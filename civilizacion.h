#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
using namespace std;

class Civilizacion
{
    string nombre;
    string ubicacion_x;
    string ubicacion_y;
    string puntuacion;

public:
    Civilizacion();
    Civilizacion(const string &nombre, const string &ubicacion_x, const string &ubicacion_y, const string &puntuacion);
    void setNombre(const string &v);
    string getNombre();
    void setUbicacion_x(const string &v);
    string getUbicacion_x();
    void setUbicacion_y(const string &v);
    string getUbicacion_y();
    void setPuntuacion(const string &v);
    string getPuntuacion();

    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(10) << c.nombre;
        out << setw(12) << c.ubicacion_x;
        out << setw(12) << c.ubicacion_y;
        out << setw(10) << c.puntuacion;

        return out;
    }
    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        string temp;

        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Ubicacion X: ";
        getline(cin, c.ubicacion_x);

        cout << "Ubicacion Y: ";
        getline (cin, c.ubicacion_y);

        cout << "Puntuacion: ";
        getline(cin, c.puntuacion);

        return in;
    }

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion&c)
    {
        return nombre < c.nombre;
    }

    bool operator<(const Civilizacion&c) const
    {
        return nombre < c.nombre;
    }

};


#endif