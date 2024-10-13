//
// Created by MJ on 06-09-2024.
//

#include "Usuario.h"

#include <iostream>
#include <ostream>

// Implementación del constructor. Inicializa el nombre, el ID y los materiales prestados.
Usuario::Usuario(std::string nombre, int id) : nombre(nombre), id(id) {
    // Inicializa todos los espacios de "materialesprestados" como nullptr (sin materiales prestados).
    for (int i = 0; i < 5; ++i) {
        materialesprestados[i] = nullptr;
    }
}

// Implementación del destructor. No hay recursos dinámicos que liberar en este caso.
Usuario::~Usuario() { }

// Método que muestra los materiales prestados. Si el usuario no tiene materiales, se indica.
std::string Usuario::mostrarMaterialesPrestados() const {
    std::string resultado;
    resultado += "Usuario: " + nombre + "\nID: " + std::to_string(id) + "\n";
    resultado += "Materiales prestados:\n";
    bool tieneMateriales = false;

    // Recorre el arreglo de materiales prestados.
    for (int i = 0; i < 5; ++i) {
        if (materialesprestados[i] != nullptr) {
            tieneMateriales = true;
            resultado += "- " + materialesprestados[i]->getTitulo() + "\n"; // Asume que MaterialBiblioagrafico tiene el método getTitulo().
        }
    }

    // Si no tiene materiales prestados, se indica en el resultado.
    if (!tieneMateriales) {
        resultado += "No tiene materiales prestados.\n";
    }

    return resultado;
}

// Devuelve el nombre del usuario.
std::string Usuario::getNombre() const {
    return nombre;
}

// Devuelve el ID del usuario.
int Usuario::getId() const {
    return id;
}

// Implementación del método para devolver un material prestado.
bool Usuario::devolverMaterial(MaterialBiblioagrafico* material) {
    // Busca el material en el arreglo.
    for (int i = 0; i < 5; ++i) {
        if (materialesprestados[i] == material) {
            // Si se encuentra, lo elimina (lo establece en nullptr).
            materialesprestados[i] = nullptr;
            return true;
        }
    }
    // Si no se encuentra el material, devuelve false.
    return false;
}

// Implementación del método para prestar material.
bool Usuario::prestarMaterial(MaterialBiblioagrafico* material) {
    // Busca un espacio libre en el arreglo de materiales prestados.
    for (int i = 0; i < 5; ++i) {
        if (materialesprestados[i] == nullptr) {
            // Si hay un espacio libre, se añade el material y se devuelve true.
            materialesprestados[i] = material;
            return true;
        }
    }
    // Si no hay espacio, devuelve false.
    return false;
}
