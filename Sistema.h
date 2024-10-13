//
// Created by MJ on 06-09-2024.
//

#ifndef SISTEMA_H
#define SISTEMA_H
#include "MaterialBiblioagrafico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

// La clase Sistema maneja la gestión de materiales bibliográficos y usuarios de la biblioteca.
// Permite agregar, buscar, prestar y devolver materiales, así como cargar datos desde archivos.

class Sistema {
private:
    // Arreglo estático que almacena punteros a materiales bibliográficos (libros, revistas, etc.).
    MaterialBiblioagrafico* biblioteca[100]{};

    // Número actual de materiales cargados en la biblioteca.
    int numMateriales{};

    // Arreglo estático que almacena punteros a usuarios.
    Usuario* usuarios[100]{};

    // Número actual de usuarios en el sistema.
    int numUsuarios{};

public:
    // Constructor de la clase Sistema, inicializa los contadores de materiales y usuarios en 0.
    Sistema();

    // Carga materiales desde un archivo de texto, identificando si son libros o revistas.
    void cargarMaterialesDesdeArchivo(const std::string& nombreArchivo);

    // Carga usuarios desde un archivo de texto.
    void cargarUsuariosDesdeArchivo(const std::string& nombreArchivo);

    // Agrega un libro a la biblioteca.
    void agregarMaterial(const std::string& nombre, const std::string& isbn, const std::string& autor,
                         const std::string& fechaPublicacion, const std::string& resumen);

    // Agrega una revista a la biblioteca.
    void agregarMaterial(const std::string& nombre, const std::string& isbn, const std::string& autor,
                         int numeroEdicion, const std::string& mesPublicacion);

    // Agrega un usuario al sistema.
    void agregarUsuario(std::string nombre, int id);

    // Agrega un usuario al sistema que no estaba en el txt inicial.
    void agregarNuevoUsuario(std::string nombre, int id);

    // Busca un usuario por nombre y muestra su información.
    void buscarUsuario(std::string nombre);

    // Elimina un usuario por nombre.
    void borrarUsuario(std::string nombre);

    // Muestra la información de todos los materiales en la biblioteca.
    void mostrarBiblioteca() const;

    // Muestra la información de todos los usuarios en el sistema.
    void mostrarUsuarios() const;

    // Busca un material por su título o autor.
    void buscarMaterial(const std::string& nombre);

    // Presta un material a un usuario, si está disponible.
    void prestarMaterial(std::string nombre, std::string nombreUsuario);

    // Devuelve un material prestado por un usuario.
    void devolverMaterial(std::string nombre, std::string nombreUsuario);

    // Destructor de la clase Sistema. Libera la memoria asignada a los materiales y usuarios.
    ~Sistema();
};


#endif //SISTEMA_H
