#ifndef MESERO_H
#define MESERO_H

#include "personal.h"
#include <vector>

class mesero:public personal{

  private:
    vector<string> platillos;

  public:
    //Constructor y desctructor
    mesero();
    mesero(string,string,string,string,int,int,int,int);
            //Username, password, nombre, ID, Edad, Numero de telefono, año_contratacion
    virtual~mesero();
    //Getters
    string getPlatillo(int);
    vector<string> getPlatillos();
    void eliminarPlatillo(int);
    void eliminarPlatillos();
    void setPlatillo(string);
};

#endif
