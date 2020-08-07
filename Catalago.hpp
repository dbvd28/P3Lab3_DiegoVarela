#ifndef CATALAGO_H
#define CATALAGO_H
#include <vector>
#include "Libro.hpp"
#include <string>
using namespace std;
class Catalago
{
private:
    vector<Libro*> lista_libros;

public:
    Catalago() {}
    //getters
    vector<Libro*> getlibro () { return lista_libros; }
    //setters
    void agregarlibro(string _titulo, string _autor, string _anio){lista_libros.push_back(new Libro( _titulo, _autor, _anio));}
    //Destructor
    ~Catalago()
    {
    }
};
#endif