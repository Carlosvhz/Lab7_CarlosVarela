#ifndef CHEF_H
#define CHEF_H

#include "personal.h"
#include "lavaplatos.h"
#include <string>

class chef:public personal{

  private:
    string platillo_fav;

  public:
    //Constructor y desctructor
    chef();
    chef(string,string,string,string,int,int,int,int,string);
            //Username, password, nombre, ID, Edad, Numero de telefono, año_contratacion, platillo favorito
    virtual~chef();
    //Getters
    string getPlatillo();
};

#endif
