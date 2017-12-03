#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class usuario{

  private:
    string username, password, nombre, ID;
    int edad, numero_telefono;

  public:
    //Constructor y destructor
    usuario();
    usuario(string,string,string,string,int,int);//Username, password, nombre, ID, Edad, Numero de telefono
    virtual ~usuario();
    //Getters
    string getUsername();
    string getPassword();
    string getNombre();
    string getID();
    int getEdad();
    int getNumeroTelefono();

};

#endif
