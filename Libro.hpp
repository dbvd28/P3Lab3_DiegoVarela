#ifndef LIBRO_H
#define LIBRO_H
#include <string>
using namespace std;
class Libro
{
private:
    string titulo, autor, anio;

public:
    Libro() {}
    Libro(string _titulo, string _autor, string _anio){
        titulo= _titulo;
        autor = _autor;
        anio   = _anio;
    }
    //getters
    string getanio() { return anio; }
    string getautor() { return autor; }
    string gettitulo() { return titulo; }
    //setter
    void setanio(string _anio) { anio = _anio; }
    void setautor(string _autor) { autor = _autor; }
    void settitulo(string _titulo) { titulo = _titulo; }
    //destructor
    ~Libro()
    {
    }
    //tostring
    string tostring()
    {
        return "Autor: "+autor+"Titulo: "+titulo+"Año: "+anio;
    }
};
#endif