//
// Created by MJ on 06-09-2024.
//

#include "MaterialBiblioagrafico.h"
// Implementación del constructor. Inicializa los atributos del material bibliográfico.
MaterialBiblioagrafico::MaterialBiblioagrafico(std::string nombre, std::string isbn, std::string autor)
    : nombre(nombre), isbn(isbn), autor(autor), prestado(false) {
    // El material comienza sin estar prestado.
}

// Metodo para cambiar el estado de préstamo del material.
void MaterialBiblioagrafico::setPrestado(bool estado) {
    // Actualiza el atributo "prestado" con el nuevo estado.
    prestado = estado;
}

// Metodo que retorna si el material está prestado o no.
bool MaterialBiblioagrafico::getPrestado() const {
    return prestado;
}

// Metodo que devuelve el título del material bibliográfico.
std::string MaterialBiblioagrafico::getTitulo() const {
    return nombre;
}

// Metodo que devuelve el nombre del autor del material bibliográfico.
std::string MaterialBiblioagrafico::getAutor() const {
    return autor;
}