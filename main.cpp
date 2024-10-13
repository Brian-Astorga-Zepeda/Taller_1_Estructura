#include <iostream>

#include "Libro.h"
#include "Revista.h"
#include "Sistema.h"
#include "Usuario.h"
#include <string>

// main.cpp

#include <iostream>
#include <string>
#include "Sistema.h"

int main() {
    // Crea una instancia del sistema de biblioteca.
    Sistema sistema;
    Sistema* ptrsistema = &sistema;
    // Carga los materiales y usuarios desde archivos de texto.
    sistema.cargarMaterialesDesdeArchivo("Biblioteca.txt");
    sistema.cargarUsuariosDesdeArchivo("Usuarios.txt");

    int opcion; // Variable para almacenar la opción seleccionada en el menú.

    // Ciclo para mostrar el menú y procesar las opciones del usuario.
    do {
        // Muestra el menú de opciones.
        std::cout << "Menú de Biblioteca:\n";
        std::cout << "1. Agregar material (libro o revista)\n";
        std::cout << "2. Mostrar materiales\n";
        std::cout << "3. Prestar material\n";
        std::cout << "4. Devolver material\n";
        std::cout << "5. Buscar material\n";
        std::cout << "6. Agregar usuario\n";
        std::cout << "7. Mostrar usuarios\n";
        std::cout << "8. Buscar usuario\n";
        std::cout << "9. Borrar usuario\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el salto de línea después de la entrada.

        // Procesa la opción seleccionada.
        switch (opcion) {
            case 1: {
                // Variables para agregar material.
                std::string nombre, isbn, autor, fechaPublicacion, resumen;
                int numeroEdicion;
                std::string mesPublicacion;

                // Solicita la información del material.
                std::cout << "Ingrese el título del material: ";
                std::getline(std::cin, nombre);
                std::cout << "Ingrese el ISBN: ";
                std::getline(std::cin, isbn);
                std::cout << "Ingrese el autor: ";
                std::getline(std::cin, autor);

                // Solicita información específica para libros.
                std::cout << "Si es un **LIBRO**, ingrese la siguiente información:\n";
                std::cout << "Fecha de publicación: ";
                std::getline(std::cin, fechaPublicacion);
                std::cout << "Resumen: ";
                std::getline(std::cin, resumen);
                sistema.agregarMaterial(nombre, isbn, autor, fechaPublicacion, resumen);

                // Solicita información específica para revistas.
                std::cout << "\nSi es una **REVISTA**, ingrese la siguiente información:\n";
                std::cout << "Número de edición: ";
                std::cin >> numeroEdicion;
                std::cin.ignore();  // Ignorar el salto de línea.
                std::cout << "Mes de publicación: ";
                std::getline(std::cin, mesPublicacion);
                sistema.agregarMaterial(nombre, isbn, autor, numeroEdicion, mesPublicacion);

                break;
            }

            case 2: {
                // Muestra todos los materiales en la biblioteca.
                std::cout << "Materiales en la biblioteca:\n";
                sistema.mostrarBiblioteca();
                break;
            }

            case 3: {
                std::string nombreMaterial, nombreUsuario;
                // Solicita la información para prestar un material.
                std::cout << "Ingrese el título del material a prestar: ";
                std::getline(std::cin, nombreMaterial);
                std::cout << "Ingrese el nombre del usuario: ";
                std::getline(std::cin, nombreUsuario);
                sistema.prestarMaterial(nombreMaterial, nombreUsuario);
                break;
            }

            case 4: {
                std::string nombreMaterial, nombreUsuario;
                // Solicita la información para devolver un material.
                std::cout << "Ingrese el título del material a devolver: ";
                std::getline(std::cin, nombreMaterial);
                std::cout << "Ingrese el nombre del usuario: ";
                std::getline(std::cin, nombreUsuario);
                sistema.devolverMaterial(nombreMaterial, nombreUsuario);
                break;
            }

            case 5: {
                std::string nombre;
                // Solicita el título o autor del material a buscar.
                std::cout << "Ingrese el título o autor del material a buscar: ";
                std::getline(std::cin, nombre);
                sistema.buscarMaterial(nombre);
                break;
            }

            case 6: {
                std::string nombre;
                int id;
                // Solicita la información para agregar un nuevo usuario.
                std::cout << "Ingrese el nombre del usuario: ";
                std::getline(std::cin, nombre);
                std::cout << "Ingrese el ID del usuario: ";
                std::cin >> id;
                std::cin.ignore();  // Ignorar el salto de línea.
                sistema.agregarNuevoUsuario(nombre, id);
                break;
            }

            case 7: {
                // Muestra todos los usuarios en el sistema.
                std::cout << "Usuarios en el sistema:\n";
                sistema.mostrarUsuarios();
                break;
            }

            case 8: {
                std::string nombre;
                // Solicita el nombre del usuario a buscar.
                std::cout << "Ingrese el nombre del usuario a buscar: ";
                std::getline(std::cin, nombre);
                sistema.buscarUsuario(nombre);
                break;
            }

            case 9: {
                std::string nombre;
                // Solicita el nombre del usuario a eliminar.
                std::cout << "Ingrese el nombre del usuario a eliminar: ";
                std::getline(std::cin, nombre);
                sistema.borrarUsuario(nombre);
                break;
            }

            case 0: {
                // Mensaje de salida del sistema.
                std::cout << "Saliendo del sistema...\n";
                break;
            }

            default: {
                // Mensaje para opción no válida.
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
            }
        }

        std::cout << std::endl;  // Espacio entre cada iteración del menú.
    } while (opcion != 0);  // Continúa mostrando el menú hasta que se elija la opción 0.

    delete ptrsistema; // Se llama a la destrucción del sistema.
    return 0;  // Finaliza el programa.
}
