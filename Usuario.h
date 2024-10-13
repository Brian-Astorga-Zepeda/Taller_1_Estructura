//
// Created by MJ on 06-09-2024.
//

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "MaterialBiblioagrafico.h"
// La clase "Usuario" representa a una persona que puede pedir prestado materiales bibliográficos.
class Usuario {
private:
    // Variables privadas que almacenan el nombre del usuario, su ID y los materiales prestados.
    std::string nombre;
    int id;
    // Un arreglo de punteros a "MaterialBiblioagrafico" que representa los materiales que el usuario ha prestado.
    // Solo se pueden prestar un máximo de 5 materiales.
    MaterialBiblioagrafico* materialesprestados[5];

    public:
    // Constructor de la clase "Usuario". Inicializa el nombre y el ID del usuario.
    // Además, inicializa el arreglo de materiales prestados con punteros nulos (nullptr),
    // indicando que el usuario no tiene materiales prestados inicialmente.
    Usuario(std::string nombre, int id);
    // Metodo para prestar material al usuario. Recibe un puntero a "MaterialBiblioagrafico".
    // Si el usuario tiene espacio disponible (menos de 5 materiales prestados), el material se añade.
    // Retorna `true` si el préstamo fue exitoso y `false` si ya se alcanzó el límite.
    bool prestarMaterial(MaterialBiblioagrafico* material);
    // Metodo para devolver un material prestado. Busca el material en el arreglo de prestados y lo elimina.
    // Retorna `true` si la devolución fue exitosa y `false` si el material no se encuentra en los prestados.
    bool devolverMaterial(MaterialBiblioagrafico* material);
    // Metodo que muestra todos los materiales que el usuario tiene actualmente prestados.
    // Devuelve una cadena con el nombre del usuario, su ID y los títulos de los materiales prestados.
    std::string mostrarMaterialesPrestados() const;
    // Metodo que devuelve el nombre del usuario.
    std::string getNombre() const;
    // Metodo que devuelve el id del usuario.
    int getId() const;
    // Destructor de la clase "Usuario". Se ejecuta cuando un objeto de tipo "Usuario" es eliminado.
    ~Usuario();
};



#endif //USUARIO_H
