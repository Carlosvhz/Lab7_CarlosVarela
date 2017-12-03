#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H

#include "personal.h"
#include "chef.h"

class lavaplatos:public personal{

  private:
    int motivacion;

  public:
    //Constructor y desctructor
    lavaplatos();
    lavaplatos(string,string,string,string,int,int,int,int);
            //Username, password, nombre, ID, Edad, Numero de telefono, año_contratacion
    virtual~lavaplatos();
    //Getters
    bool Renunciar();
    bool Aumento();

    int getMotivacion();
    void setMotivacion(int);

    void desmotivar(int);
    void motivar(int);

};

#endif
