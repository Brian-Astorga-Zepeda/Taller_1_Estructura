//
// Created by MJ on 06-09-2024.
//

#ifndef MATERIALBIBLIOAGRAFICO_H
#define MATERIALBIBLIOAGRAFICO_H

#include <string>
// Clase padre para representar materiales.
class MaterialBiblioagrafico {
protected:
    // Atributos protegidos que podran ser accecibles para las clases "Libro" y "Revista".
    std::string nombre;
    std::string isbn;
    std::string autor;
    bool prestado=false;
    public:
    // Constructor que inicializa los atributos nombre, isbn y autor del material bibliográfico.
    MaterialBiblioagrafico(std::string nombre, std::string isbn, std::string autor);
    // Metodo virtual que podra ser sobrescrito por las clases hijas,"Libro" y "Revista".
    virtual void mostrarInfo() const=0;
    //Metodo para poder marcar un libro como Prestado o no Prestado.
    void setPrestado(bool estado);
    //Metodo para objetener el titulo de un material.
    std::string getTitulo() const;
    //Metodo para objetener el autor de un material.
    std::string getAutor() const;
    //Metodo para objetener el estado de un material(Prestado o no Prestado).
    bool getPrestado() const;

};



#endif //MATERIALBIBLIOAGRAFICO_H
