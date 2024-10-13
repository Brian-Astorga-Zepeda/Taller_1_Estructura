//
// Created by MJ on 06-09-2024.
//

#ifndef LIBRO_H
#define LIBRO_H
#include "MaterialBiblioagrafico.h"
// La clase "Libro" hereda de "MaterialBiblioagrafico"
class Libro : public MaterialBiblioagrafico {
private:
    std::string date;
    std::string resumen;
    public:
    // Constructor de la clase "Libro". Aquí se definen los parámetros necesarios para crear un libro.
    // Se le pasan el nombre, ISBN, autor, fecha de publicación y resumen.
    Libro(std::string nombre,std::string isbn,std::string autor,std::string date, std::string resumen);
    // Método para mostrar la información del libro. Sobrescribe un método de la clase base.
    void mostrarInfo() const override;
    // Destructor de la clase "Libro", que se ejecuta cuando se elimina un objeto de tipo "Libro".
    ~Libro();
};



#endif //LIBRO_H
