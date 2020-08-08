#ifndef BILIOTECA_H
#define BILIOTECA_H
#include "Catalago.hpp"
#include <string>
#include <cstring>
using namespace std;
class Bilioteca
{
private:
    string nombre, ubicacion;
    Catalago ****lista_biblioteca;
    int pisos, estantes, secciones;

public:
    Bilioteca() {}
    Bilioteca(int _pisos, int _estantes, int _secciones, string _nombre, string _ubicacion)
    {
        pisos = _pisos;
        estantes = _estantes;
        secciones = _secciones;
        nombre = _nombre;
        ubicacion = _ubicacion;
        lista_biblioteca = new Catalago ***[_pisos];
        for (int x = 0; x < _pisos; x++)
        {
            lista_biblioteca[x] = new Catalago **[_estantes];
            for (int y = 0; y < _estantes; y++)
            {
                lista_biblioteca[x][y] = new Catalago *[_secciones];
                for (int z = 0; z < _secciones; z++)
                {
                    lista_biblioteca[x][y][z] = new Catalago();
                }
            }
        }
    }
    //getters
    string getnombre() { return nombre; }
    string getubicacion() { return ubicacion; }
    void getlibroportitulo(string _titulo)
    {
        for (int x = 0; x < pisos; x++)
        {

            for (int y = 0; y < estantes; y++)
            {

                for (int z = 0; z < secciones; z++)
                {
                    vector<Libro *> libros = lista_biblioteca[x][y][z]->getlibro();
                    for (int i = 0; i < libros.size(); i++)
                    {
                        if (_titulo == libros[i]->gettitulo())
                        {
                            cout << "Titulo: " << libros[i]->gettitulo() << endl;
                            cout << "Autor: " << libros[i]->getautor() << endl;
                            cout << "Anio: " << libros[i]->getanio() << endl;
                            cout << "Biblioteca: " << nombre << endl
                                 << endl;
                            cout << "Ubicado en el piso " << x << " del estante " << y << " de la seccion: " << z << endl;
                        }
                    }
                }
            }
        }
    }
    void getlibroporautor(string _autor)
    {
        for (int x = 0; x < pisos; x++)
        {

            for (int y = 0; y < estantes; y++)
            {

                for (int z = 0; z < secciones; z++)
                {
                    vector<Libro *> libros = lista_biblioteca[x][y][z]->getlibro();
                    for (int i = 0; i < libros.size(); i++)
                    {
                        if (_autor == libros[i]->getautor())
                        {
                            cout << "Titulo: " << libros[i]->gettitulo() << endl;
                            cout << "Autor: " << libros[i]->getautor() << endl;
                            cout << "Anio: " << libros[i]->getanio() << endl;
                            cout << "Biblioteca: " << nombre << endl;
                            cout << "Ubicado en el piso " << x << " del estante " << y << " de la seccion: " << z << endl;
                        }
                    }
                }
            }
        }
    }
    vector<Libro *> ordenaralfabeticamente(int _pisos, int _estantes, int _secciones)
    {
        vector<Libro *> orden = lista_biblioteca[_pisos][_estantes][_secciones]->getlibro();
        Libro* temporal;
        for (int i = 0; i < orden.size(); i++)
        {
            for (int j = i + 1; j < orden.size(); j++)
            {
                if (orden[i]->gettitulo()>orden[j]->gettitulo())
                {
                    temporal=orden[i];
                    orden[i]=orden[j];
                    orden[j]=temporal;
                }
            }
        }
        return orden;
    }
    //setters
    void agregarlibro1(int _pisos, int _estantes, int _secciones, string _titulo, string _autor, string _anio)
    {
        lista_biblioteca[_pisos][_estantes][_secciones]->agregarlibro(_titulo, _autor, _anio);
    }
    void setnombre(string _nombre)
    {
        nombre = _nombre;
    }
    void setubicacion(string _ubicacion)
    {
        ubicacion = _ubicacion;
    }
    //destructor
    ~Bilioteca()
    {
        for (int x = 0; x < pisos; x++)
        {
            for (int y = 0; y < estantes; y++)
            {
                for (int z = 0; z < secciones; z++)
                {
                    delete lista_biblioteca[x][y][z];
                }
            }
        }
        for (int x = 0; x < pisos; x++)
        {
            for (int y = 0; y < estantes; y++)
            {
                delete[] lista_biblioteca[x][y];
            }
        }
        for (int x = 0; x < pisos; x++)
        {
            delete[] lista_biblioteca[x];
        }
        delete[] lista_biblioteca;
    }
    //Tostring
    string tostring()
    {
        return "Nombre: " + nombre + "Ubicacion: " + ubicacion;
    }
};
#endif