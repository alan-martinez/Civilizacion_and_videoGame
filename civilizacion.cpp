#include "civilizacion.h"

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre, const string &ubicacion_x, const string &ubicacion_y, const string &puntuacion)
{
    this->nombre = nombre;
    this->ubicacion_x = ubicacion_x;
    this->ubicacion_y = ubicacion_y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}

string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setUbicacion_x(const string &v)
{
    ubicacion_x = v;
}

string Civilizacion::getUbicacion_x()
{
    return ubicacion_x;
}

void Civilizacion::setUbicacion_y(const string &v)
{
    ubicacion_y = v;
}

string Civilizacion::getUbicacion_y()
{
    return ubicacion_y;
}

void Civilizacion::setPuntuacion(const string &v)
{
    puntuacion = v;
}

string Civilizacion::getPuntuacion()
{
    return puntuacion;
}


