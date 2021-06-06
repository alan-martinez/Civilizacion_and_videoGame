#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class VideoGame
{
    //string nombreVideoGame;
    vector <VideoGame> nombreVideoGame;
    vector <Civilizacion> civilizacion;
    string nombreV;

public: 

    VideoGame();
    VideoGame(const string &nombreV);
    void setNombreVideoGame(const string &n);
    string getNombreVideoGame();
    void agregarNombreUsuario(const VideoGame &v);


    void agregarCivilizacion (const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    void inicializa(const Civilizacion &c, size_t n);
    
    void primeraCivilizacion(const Civilizacion &c);
    void ultimaCivilizacion(const Civilizacion &c);
    void ordenarNombre();
    void ordenarUbicacionX();
    void ordenarUbicacionY();
    void ordenarPuntuacion();
    void eliminar(const string &nombre);
    Civilizacion* buscar(const Civilizacion &c);
    void total();

    void modificar(Civilizacion &c);

    friend VideoGame& operator<<(VideoGame &v, const Civilizacion &c)
    {
        v.agregarCivilizacion(c);
        return v;
    }

    friend istream& operator>>(istream &in, VideoGame &v)
    {
        string temp;

        cout << "Nombre Usuario: ";
        getline(cin, v.nombreV);

        return in;
    }

    friend ostream& operator<<(ostream &out, const VideoGame &v)
    {
        out << left;
        out << setw(10) << v.nombreV;

        return out;
    }
};

#endif