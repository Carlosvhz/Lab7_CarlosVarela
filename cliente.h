#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "usuario.h"

using namespace std;

class cliente:public usuario{

  private:
    string direccion;
    int rating;

  public:
    //Constructor y desctructor
    cliente();
    cliente(string,string,string,string,int,int,string,int);//Username, password, nombre, ID, Edad, Numero de telefono,direccion,rating
    virtual~cliente();
    //Getters
    string getDireccion();
    int getRating();

};

#endif
