//
// Created by MJ on 06-09-2024.
//

#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>

Sistema::Sistema() : numMateriales(0),numUsuarios(0){

}


void Sistema::cargarMaterialesDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    int i=0;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre, isbn, autor, extra;



        std::getline(ss, nombre, ',');
        std::getline(ss, isbn, ',');
        std::getline(ss, autor, ',');


        std::getline(ss, extra, ',');


        if (!extra.empty() && std::isdigit(extra[0])) {
            std::string mes;
            int numeroEdicion;
            numeroEdicion = std::stoi(extra);
            std::getline(ss,mes);
            agregarMaterial(nombre,isbn,autor,numeroEdicion,mes);


        } else {
            std::string fechaPublicacion, resumen;
            std::getline(ss, fechaPublicacion, ',');
            std::getline(ss, resumen);
            agregarMaterial(nombre,isbn,autor,fechaPublicacion,resumen);



        }
    }
    archivo.close();
}
void Sistema::cargarUsuariosDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre,idS;

        std::getline(ss, nombre, ',');
        std::getline(ss, idS);
        int id=std::stoi(idS);
        agregarUsuario(nombre,id);




    }
}
void Sistema::agregarMaterial(const std::string& nombre, const std::string& isbn, const std::string& autor, const std::string& fechaPublicacion, const std::string& resumen) {
    if(numMateriales<100){
        biblioteca[numMateriales] = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
        ++numMateriales;
    } else {
        std::cerr << "Límite de Materiales alcanzado." << std::endl;
    }
}

void Sistema::agregarMaterial(const std::string& nombre, const std::string& isbn, const std::string& autor, int numeroEdicion, const std::string& mesPublicacion) {
    if(numMateriales<100){
        biblioteca[numMateriales] = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);
        ++numMateriales;
    } else {
        std::cerr << "Límite de Materiales alcanzado." << std::endl;
    }
}

void Sistema::agregarUsuario(std::string nombre, int id) {
    if (numUsuarios < 100) {
        usuarios[numUsuarios] = new Usuario(nombre, id);
        ++numUsuarios;
    } else {
        std::cerr << "Límite de usuarios alcanzado." << std::endl;

    }
}
void Sistema::agregarNuevoUsuario(std::string nombre, int id) {
    if (numUsuarios < 100) {
        std::ofstream archivo("Usuarios.txt", std::ios::app);
        if(archivo.is_open()) {
            archivo << nombre << ", "<< id <<"\n";
        }
        usuarios[numUsuarios] = new Usuario(nombre, id);
        ++numUsuarios;
    } else {
        std::cerr << "Límite de usuarios alcanzado." << std::endl;

    }
}

    Sistema::~Sistema(){
        for (int i = 0; i < numMateriales; ++i) {
            delete biblioteca[i];
        }
        for (int i = 0; i < numUsuarios; ++i) {
            delete usuarios[i];
        }
    }
void Sistema::mostrarBiblioteca() const {
    for (int i = 0; i < numMateriales; ++i) {
        biblioteca[i]->mostrarInfo();
    }
}
void Sistema::mostrarUsuarios() const {
    for (int i = 0; i < numUsuarios; ++i) {
        std::cout << "Usuario " << usuarios[i]->getNombre() << " con ID " << usuarios[i]->getId() << " \n";
    }
}
#include "Sistema.h"
#include <iostream>

// Método para buscar materiales por título o autor
void Sistema::buscarMaterial(const std::string &nombre) {
    bool encontrado = false;

    for (int i = 0; i < numMateriales; ++i) {
        if (nombre == biblioteca[i]->getAutor() || nombre == biblioteca[i]->getTitulo()) {
            if (!encontrado) {
                std::cout << "Materiales encontrados:\n";
                encontrado = true;
            }
            biblioteca[i]->mostrarInfo();
        }
    }

    if (!encontrado) {
        std::cerr << "No se encontró el material con el nombre o autor dado.\n";
    }
}
void Sistema::borrarUsuario(std::string nombre) {
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i]->getNombre() == nombre) {
            usuarios[i]=nullptr;
            std::cout << "Usuarios "<<nombre <<"eliminado correctamenet"<<std::endl;
        }
    }
}
void Sistema::buscarUsuario(std::string nombre) {
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i]->getNombre() == nombre) {
            std::cout << "Usuario " << nombre << " con ID " << usuarios[i]->getId() << " encontrado con éxito.\n";
            std::cout << usuarios[i]->mostrarMaterialesPrestados() << std::endl;
            return;
        }
    }
    std::cout << "Usuario " << nombre << " no encontrado.\n";
}

void Sistema::prestarMaterial(std::string nombre, std::string nombreUsuario) {
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i]->getNombre() == nombreUsuario) {
            for (int j = 0; j < numMateriales; ++j) {
                if (biblioteca[j]->getTitulo() == nombre) {
                    if (biblioteca[j]->getPrestado() == false) {
                        if (usuarios[i]->prestarMaterial(biblioteca[j])) {
                            biblioteca[j]->setPrestado(true);
                            std::cout << "Material prestado con éxito.\n";
                        } else {
                            std::cout << "El usuario ya tiene el máximo de materiales prestados.\n";
                        }
                        return;
                    }
                    std::cout << "El material ya está prestado.\n";
                    return;
                }
            }
            std::cout << "Material " << nombre << " no encontrado.\n";
            return;
        }
    }
    std::cout << "Usuario " << nombreUsuario << " no encontrado.\n";
}

void Sistema::devolverMaterial(std::string nombre,std::string nombreUsuario) {
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i]->getNombre() == nombreUsuario) {
            for (int j = 0; j < numMateriales; ++j) {
                if (biblioteca[j]->getTitulo() == nombre) {
                    usuarios[i]->devolverMaterial(biblioteca[j]);
                }std::cout << "Material " << nombre << " no encontrado.\n";
            }
        }std::cout << "Usuario " << nombreUsuario << " no encontrado.\n";
    }
}










