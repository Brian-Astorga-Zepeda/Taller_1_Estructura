//
// Created by MJ on 06-09-2024.
//

#include "Libro.h"
#include <iostream>
// Implementación del constructor.
Libro::Libro(std::string nombre, std::string isbn, std::string autor, std::string date, std::string resumen)
    : MaterialBiblioagrafico(nombre, isbn, autor), date(date), resumen(resumen) {
    // El constructor inicializa los atributos específicos del libro (fecha de publicación y resumen),
    // y llama al constructor de la clase base para inicializar nombre, ISBN y autor.
}

// Implementación del metodo para mostrar la información del libro.
void Libro::mostrarInfo() const {
    // Se imprime la información básica (nombre, ISBN, autor) junto con los datos específicos del libro (fecha y resumen).
    std::cout << "Libro: " << nombre << "\nISBN: " << isbn << "\nAutor: " << autor
              << "\nFecha de Publicación: " << date << "\nResumen: " << resumen
              << "\nPrestado: " << (prestado ? "Sí" : "No") << std::endl;

}

// Implementación del destructor.
Libro::~Libro() {
    std::cout << "Libro destruido con fecha: " << date << std::endl;
}
