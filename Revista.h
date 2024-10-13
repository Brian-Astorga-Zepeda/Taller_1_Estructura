//
// Created by MJ on 06-09-2024.
//

#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialBiblioagrafico.h"

// Clase "Revista", que hereda de "MaterialBiblioagrafico"
class Revista : public MaterialBiblioagrafico {
private:
    int edicion;
    std::string mes;
    public:
    // Constructor de la clase "Revista". Recibe parámetros como el nombre de la revista, el ISBN, el autor ,el número de edición y el mes de publicación.
    Revista(std::string nombre,std::string isbn,std::string autor,int edicion, std::string mes);
    // Metodo que sobrescribe el de la clase padre, usado para mostrar la información de la revista.
    void mostrarInfo() const override;
    // Destructor de la clase "Revista". Se ejecuta cuando un objeto de tipo "Revista" es eliminado.
    ~Revista();
};

#endif //REVISTA_H
