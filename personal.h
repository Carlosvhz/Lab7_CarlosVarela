#ifndef PERSONAL_H
#define PERSONAL_H

#include "usuario.h"

class personal:public usuario{

  private:
    int anio_contratacion, sueldo;

  public:
    //Constructor y desctructor
    personal();
    personal(string,string,string,string,int,int,int,int);//Username, password, nombre, ID, Edad, Numero de telefono, año_contratacion, sueldo
    virtual ~personal();
    //Getters
    int getContratacion();
    int getSueldo();

};

#endif
