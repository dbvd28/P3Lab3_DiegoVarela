#include <string>
#include <iostream>
#include <vector>
#include "Bilioteca.hpp"
using namespace std;
int main()
{
    vector<Bilioteca *> Bibliotecas;
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
            string nombre = "";
            string ubicacion = "";
            int pisos = 0;
            int estantes = 0;
            int secciones = 0;
            cout << "Escriba el nombre de la biblioteca: " << endl;
            cin >> nombre;
            cout << "Escriba el ubicacion de la biblioteca: " << endl;
            cin >> ubicacion;
            cout << "Introduzca el numero de pisos: " << endl;
            cin >> pisos;
            cout << "Introduzca el numero de estantes: " << endl;
            cin >> estantes;
            cout << "Introduzca el numero de secciones: " << endl;
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
            cout << endl;
            cout << "En que biblioteca lo quiere agregar: " << endl;
            cin >> nombre_bib;
            cout << "Introduzca el titulo del libro: " << endl;
            cin >> titulo;
            cout << "Introduzca el nombre del autor: " << endl;
            cin >> autor;
            cout << "Introduzca el año en que fue publicado: " << endl;
            cin >> anio;
            cout << "Introduzca el numero de pisos: " << endl;
            cin >> pisos;
            cout << "Introduzca el numero de estantes: " << endl;
            cin >> estantes;
            cout << "Introduzca el numero de secciones: " << endl;
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
            cout << "Ingrese el titulo del libro que desea buscar: " << endl;
            getline(cin, titulo);
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
            cout << "Ingrese el autor del libro que desea buscar: " << endl;
            getline(cin, autor);
            getline(cin, autor);
            for (int i = 0; i < Bibliotecas.size(); i++)
            {
                Bibliotecas[i]->getlibroporautor(autor);
            }
        }
        break;
        case 5:
        {
            int pisos, estantes, secciones;
            string nombre_bib = "";
            for (int i = 0; i < Bibliotecas.size(); i++)
            {
                cout << Bibliotecas[i]->tostring();
            }cout<<endl;
            cout << "En que biblioteca desea buscar: " << endl;
            getline(cin, nombre_bib);
            getline(cin, nombre_bib);
            cout << "Introduzca el numero de piso: " << endl;
            cin >> pisos;
            cout << "Introduzca el numero de estante: " << endl;
            cin >> estantes;
            cout << "Introduzca el numero de secciones " << endl;
            cin >> secciones;
            string nombre_temp="";
              vector<Libro *> ordenamiento;
            for (int i = 0; i < Bibliotecas.size(); i++)
            {
                if (nombre_bib == Bibliotecas[i]->getnombre())
                {
                    nombre_temp=Bibliotecas[i]->getnombre();
                  ordenamiento = Bibliotecas[i]->ordenaralfabeticamente(pisos,estantes, secciones);
                }
            }
            for (int i = 0; i < ordenamiento.size(); i++)
            {
                cout << "Titulo: " << ordenamiento[i]->gettitulo() << endl;
                cout << "Autor: " << ordenamiento[i]->getautor() << endl;
                cout << "Anio: " << ordenamiento[i]->getanio() << endl;
                cout << "Biblioteca: " << nombre_temp << endl;
                cout << "Ubicado en el piso " << pisos << " del estante " << estantes << " de la seccion: " << secciones<< endl;
            }
        }
        break;
        case 6:
            dentro_menu = false;
            break;
        }
    }
}
