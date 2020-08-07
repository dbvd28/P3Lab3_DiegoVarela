#include <string>
#include <iostream>
#include <vector>
#include "Bilioteca.hpp"
using namespace std;
int main()
{
    vector<Bilioteca*> Bibliotecas;
    bool dentro_menu = true;
    while (dentro_menu)
    {
        int opcion = 0;
        cout << "1) Crear Biblioteca" << endl
             << "2) Agregar Libro" << endl
             << "3) Buscar por titulo" << endl
             << "4) Buscar por autor" << endl
             << "5) Explorar Biblioteca" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            string nombre, ubicacion;
            int pisos, estantes, secciones;
            cout << "Escriba el nombre de la biblioteca;";
            getline(cin, nombre);
            cout << "Escriba el ubicacion de la biblioteca;";
            getline(cin, ubicacion);
            cout << "Introduzca el numero de pisos: ";
            cin >> pisos;
            cout << "Introduzca el numero de estantes: ";
            cin >> estantes;
            cout << "Introduzca el numero de secciones: ";
            cin >> secciones;
            Bibliotecas.push_back(new Bilioteca(pisos, estantes, secciones, nombre, ubicacion));
        }

        break;
        case 2:
        {
            string nombre_bib = "";
            string titulo = "";
            string autor = "";
            string anio = "";
            for (int i = 0; i < Bibliotecas.size(); i++)
            {
                cout << Bibliotecas[i]->tostring();
            }
            int pisos, estantes, secciones;
            cout << "En que biblioteca lo quiere agregar: ";
            getline(cin, nombre_bib);
            cout << "Introduzca el titulo del libro: ";
            cin >> titulo;
            cout << "Introduzca el nombre del autor: ";
            cin >> autor;
            cout << "Introduzca el año en que fue publicado: ";
            cin >> anio;
            cout << "Introduzca el numero de pisos: ";
            cin >> pisos;
            cout << "Introduzca el numero de estantes: ";
            cin >> estantes;
            cout << "Introduzca el numero de secciones: ";
            cin >> secciones;
            for (int i = 0; i < Bibliotecas.size(); i++)
            {
                if (nombre_bib == Bibliotecas[i]->getnombre())
                {
                    Bibliotecas[i]->agregarlibro1(pisos, estantes, secciones, titulo, autor, anio);
                }
            }
        }

        break;
        case 3:
        {
            string titulo = "";
            cout << "Ingrese el titulo del libro que desea buscar: ";
            getline(cin, titulo);
            for (int i = 0; i < Bibliotecas.size(); i++)
            {
                Bibliotecas[i]->getlibroportitulo(titulo);
            }
        }
        break;
        case 4:
        {
            string autor = "";
            cout << "Ingrese el autor del libro que desea buscar: ";
            getline(cin, autor);
            for (int i = 0; i < Bibliotecas.size(); i++)
            {
                Bibliotecas[i]->getlibroporautor(autor);
            }
        }
        break;
        }
    }
}
