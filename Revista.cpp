//
// Created by MJ on 06-09-2024.
//
#include <iostream>
#include "Revista.h"
// Implementación del constructor.
Revista::Revista(std::string nombre, std::string isbn, std::string autor, int edicion, std::string mes)
    : MaterialBiblioagrafico(nombre, isbn, autor), edicion(edicion), mes(mes) {
    // El constructor inicializa los atributos específicos de la revista (edición y mes),
    // y llama al constructor de la clase base para inicializar nombre, ISBN y autor.
}

// Implementación del metodo para mostrar la información de la revista.
void Revista::mostrarInfo() const {
    // Se imprime la información básica (nombre, ISBN, autor) junto con los datos específicos de la revista.
    std::cout << "Revista: " << nombre << "\nISBN: " << isbn << "\nAutor: " << autor
              << "\nEdicion: " << edicion << "\nMes de publicacion: " << mes
              << "\nPrestado: " << (prestado ? "Sí" : "No") << std::endl;

}

// Implementación del destructor.
Revista::~Revista() {
    // Se imprime un mensaje indicando que la revista ha sido destruida, mostrando su edición.
    std::cout << "Revista destruida con edicion: " << edicion << std::endl;
}

