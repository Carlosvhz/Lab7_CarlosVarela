#include <iostream>
#include <string>
#include "administrador.h"
#include "usuario.h"
#include "cliente.h"
#include "chef.h"
#include "lavaplatos.h"
#include "mesero.h"
#include <typeinfo>
#include <vector>
#include <fstream>

using namespace std;

/* = Prototipos= */

  //Funciones para registrarAdministradores
bool comprobarID(string,vector<usuario*>*); //##PENDIENTE

  //Funciones del menu
usuario* LogIn(usuario*,vector<usuario*>*);
usuario* LogOut(usuario*);
void registrarAdministradores(vector<usuario*>*);
void funcionesUsuario(usuario*,vector<usuario*>*); //#PENDIENTE

  //Funciones de registrarAdministradores
usuario* comprobarUsuario(string,string,vector<usuario*>*);
usuario* comprobarUsuario(string,vector<usuario*>*);
  //Funciones de todos
void guardarUsuario(usuario*);   //##PENDIENTE

  //Funciones de funcionesUsuario
/*De administrador*/
usuario* contratarEmpleado(vector<usuario*>*);
usuario* empleadoMenorSueldo(vector<usuario*>*);
usuario* empleadoMayorSueldo(vector<usuario*>*);
void asignarPlatillo(string,string,vector<usuario*>*);
int promedioTotal(vector<usuario*>*);

/*De chef*/
void gritar(usuario*,vector<usuario*>*);
void agradar(usuario*,vector<usuario*>*);
//_______________________________________________________________



int main(){
  for(int i=0;i<3;i++)cout<<endl;
  int opcion;
  usuario* usuarioActivado = NULL;
  vector<usuario*> usuarios;
  do{
    cout<<"Numero de usuarios en la lista: "<<usuarios.size()<<endl;
    cout<<endl;
    cout<<" ==== Laboratorio#7 ===="<<endl
        <<"1. LogIn"<<endl
        <<"2. Registrar Administradores"<<endl
        <<"3. funciones del usuario" <<endl
        <<"4. LogOut "<<endl
        <<"5. Salir "<<endl
        <<"- Ingrese opcion: ";
    cin>>opcion;
    cout<<endl;
    switch(opcion){
      case 1:
        if(usuarioActivado==NULL){
          usuarioActivado=LogIn(usuarioActivado,&usuarios);
        }else{
          cout<<" ¡¡¡Usuario activado, no puede usar el Login!!! "<<endl;
        }
        break;
      case 2:
        registrarAdministradores(&usuarios);
        break;
      case 3:
        funcionesUsuario(usuarioActivado,&usuarios);
        break;
      case 4:
        usuarioActivado=LogOut(usuarioActivado);
        break;
      default:
        cout<<"Bai :v"<<endl;
        break;
    }
  }while(opcion>0&&opcion<5);
}

//Funciones del menu
usuario* LogIn(usuario* user, vector<usuario*> *usuarios){
  if(usuarios->size()>0){
    if(user==NULL){
      string nombre, password;
      cout<<" =| LogIn |= "<<endl
          <<"Ingrese nombre de usuario: ";
      cin>>nombre;
      cout<<"Ingrese contraseña: ";
      cin>>password;
      user=comprobarUsuario(nombre,password,usuarios);
      while(user==NULL){
        cout<<" ¡¡¡Error en el nombre o contraseña!!! "<<endl
            <<"Ingrese de nuevo el nombre: ";
        cin>>nombre;
        cout<<"Ingrese la contraseña: ";
        cin>>password;
        user=comprobarUsuario(nombre,password,usuarios);
      }
      cout<<" ¡¡¡Usuario logeado, bienvenido "<<user->getNombre()<<"!!!"<<endl;
      return user;
    }
  }else{
    cout<<" ¡¡¡No hay usuarios registrados!!! "<<endl;
    return NULL;
  }
}
usuario* LogOut(usuario* user){
  if(user!=NULL){
    cout<<" =| Sesion cerrada, adios "<<user->getNombre()<<" |= "<<endl;
  }else{
    cout<<" ¡¡¡¡Usuario No Logeado!!!! "<<endl;
  }
  return NULL;
}
void registrarAdministradores(vector<usuario*> *usuarios){
  string nombre,username,ID,password;
  int edad,numeroTelefono,sueldo,anio;
  cout<<" =| Registrar nuevo administrador |= "<<endl
      <<"- Ingrese nombre: ";
  cin>>nombre;
  cout<<"- Ingrese username: ";
  cin>>username;
  cout<<"- Ingrese contraseña: ";
  cin>>password;
  cout<<"- Ingrese edad: ";
  cin>>edad;
  while(edad<18){
    cout<<" ¡¡¡¡No se permiten menores de 18 años!!!! "<<endl
        <<"- Ingrese de nuevo la edad: ";
    cin>>edad;
  }
  cout<<"- Tambien ingrese ID: ";
  cin>>ID;
  while(comprobarID(ID,usuarios)){
    cout<<"- ID ya registrado, Ingrese otro ID: ";
    cin>>ID;
  }
  cout<<"- Ingrese el sueldo: ";
  cin>>sueldo;
  cout<<"- Ingrese el numero de telefono(entero): ";
  cin>>numeroTelefono;
  cout<<"- Ingrese el año de contratacion: ";
  cin>>anio;
  guardarUsuario(new administrador(username,password,nombre,ID,edad,numeroTelefono,anio,sueldo));
  usuarios->push_back(new administrador(username,password,nombre,ID,edad,numeroTelefono,anio,sueldo));
}
void funcionesUsuario(usuario* user, vector<usuario*> *usuarios){
  if(user!=NULL){
    cout<<" =| Funciones extras |= "<<endl;
    int opcion;
    /*_=================================================_*/
    if(dynamic_cast<administrador*>(user)){
      cout<<"1. Contratar empleado"<<endl
          <<"2. Despedir empleado"<<endl
          <<"3. Empleado con menor sueldo"<<endl
          <<"4. Agregar platillo a algun mesero"<<endl
          <<"5. Empleado con mayor sueldo"<<endl
          <<"6. Promedio del sueldo de todos los empleados"<<endl
          <<"Ingrese el numero: ";
      cin>>opcion;
      for(int i=0;i<2;i++){cout<<endl;};
      switch(opcion){
        case 1:{ //Contratar Empleado
          usuario* n = contratarEmpleado(usuarios);
          usuarios->push_back(n);
          guardarUsuario(n);
        }
        break;
        case 2:{  //Despedir empleado
          cout<<" =| Despedir empleado |= "<<endl;
          int numero;
          for(int i=0; i<usuarios->size(); i++){
            cout<<i<<".- Nombre: "<<usuarios->at(i)->getNombre()<<"| ID: "<<usuarios->at(i)->getID()<<endl;
          }
          cout<<"- Ingrese el Numero del usuario que despedira: ";
          cin>>numero;
          while(numero<0||numero>usuarios->size()){
            cout<<" ¡¡ Ingrese un numero correcto!! "<<endl
                <<"Ingrese numero: ";
            cin>>numero;
          }
          usuarios->erase(usuarios->begin()+numero);
          cout<<" ¡¡Usuario despedido!! "<<endl;
        }
        break;
        case 3:{
          usuario* user =  empleadoMenorSueldo(usuarios);
          cout<<" =| Empleado con menor sueldo |= "<<endl
              <<"- Nombre: "<<user->getNombre()<<endl
              <<"- Edad: "<<user->getEdad()<<endl;
          user = NULL;
          delete user;
        }
        break;
        case 4:{
          string platillo;
          string id;
          int cont=0;
          cout<<" =| Agregar platillo a algun mesero |="<<endl
              <<"Lista de meseros disponibles: "<<endl;
          for(int i=0; i<usuarios->size(); i++){
            if(dynamic_cast<mesero*>(usuarios->at(i))){
              cout<<cont<<".- Nombre del mesero: "<<usuarios->at(i)->getNombre()<<"| ID: "<<usuarios->at(i)->getID()<<endl;
              cont++;
            }
          }
          if(cont!=0){
            cout<<"- Ingrese el ID del mesero: ",
            cin>>id;
            while(!comprobarID(id,usuarios)){
              cout<<"¡¡ID incorrecto!! Ingrese de nuevo el ID: ";
              cin>>id;
            }
            cout<<"- Ingrese el platillo: ";
            cin>>platillo;
            asignarPlatillo(platillo,id,usuarios);
          }else{
            cout<<" ¡¡¡ No hay meseros para dar la orden !!! "<<endl;
          }
        }
        break;
        case 5:{
          usuario* user =  empleadoMayorSueldo(usuarios);
          cout<<" =| Empleado con mayor sueldo |= "<<endl
              <<"- Nombre: "<<user->getNombre()<<endl
              <<"- Edad: "<<user->getEdad()<<endl;
          user = NULL;
          delete user;
        }
        break;
        case 6:{
          cout<<" =| Promedio total del sueldo |= "<<endl
              <<"Promedio: "<<promedioTotal(usuarios)<<endl;
        }
        break;
        default:
          cout<<" ¡¡¡ No existe numero de metodo ingresado !!! "<<endl;
      }
    /*_=================================================_*/
    }else if(dynamic_cast<chef*>(user)){ //CHEF
      cout<<"1. Gritarle a un lavaplatos"<<endl
          <<"2. Agradar a un lavaplatos"<<endl
          <<"Ingrese el numero: ";
      cin>>opcion;
      for(int i=0;i<2;i++){cout<<endl;};
      switch(opcion){
        case 1:{
          gritar(user,usuarios);
        }
        break;
        case 2:{
          agradar(user,usuarios);
        }
        break;
      }
    /*_=================================================_*/
    }else if(dynamic_cast<lavaplatos*>(user)){ //LAVAPLATOS
      cout<<"1. Renunciar"<<endl
          <<"2. Pedir aumento"<<endl
          <<"Ingrese el numero: ";
      cin>>opcion;
      for(int i=0;i<2;i++){cout<<endl;};
      switch(opcion){
        case 1:{
          lavaplatos* lava = dynamic_cast<lavaplatos*>(user);
          if(lava->Renunciar()){
            cout<<"¡¡¡ Lavaplatos despedido !!!"<<endl;
          }else{
            cout<<"¡¡¡ Este usuario no puede ser despedido !!! "<<endl;
          }
        }
        break;
        case 2:{
          lavaplatos* lava = dynamic_cast<lavaplatos*>(user);
          if(lava->Aumento()){
            int cantidad;
            cout<<"Ingrese la cantidad de aumento: ";
            cin>>cantidad;
            while(cantidad>=lava->getSueldo()){
              cout<<"NO puede poner tal aumento!... Ingrese otra cantidad: ";
              cin>>cantidad;
            }
            cout<<"¡¡¡ Aumento realiazdo !!!"<<endl;
          }else{
            cout<<"¡¡¡ Este usuario no puede tener un aumento !!! "<<endl;
          }
        }
        break;
      }
    /*_=================================================_*/
    }else if(dynamic_cast<mesero*>(user)){ //MESERO
      mesero* meseron;
      cout<<"1. Entregar platillo"<<endl
          <<"2. Entregar todos los platillos"<<endl
          <<"Ingrese el numero: ";
      cin>>opcion;
      for(int i=0;i<2;i++){cout<<endl;};
      switch(opcion){
        case 1:{
          int numero;
          cout<<" =| Entregar Platillo |="<<endl;
          meseron = dynamic_cast<mesero*>(user);
          if(meseron->getPlatillos().size()!=0){
            cout<<"Lista de platillos: "<<endl;
            for(int i=0; i<meseron->getPlatillos().size(); i++){
              cout<<i<<".- "<<meseron->getPlatillos().at(i)<<endl;
            }
            cout<<"Ingrese el numero de pedido: ";
            cin>>numero;
            while(numero<0||numero>meseron->getPlatillos().size()){
              cout<<"¡¡¡Numero no valido !!! Ingrese un numero correcto: ";
              cin>>numero;
            }
            meseron->eliminarPlatillo(numero);
            cout<<"¡¡¡ Platillo repartido!!! "<<endl;
          }else{
            cout<<" ¡¡¡ Este mesero no tiene platillos a entregar !!!";
          }
        }
        break;
        case 2:{
          cout<<" =| Entregar Platillos |="<<endl;
          meseron = dynamic_cast<mesero*>(user);
          if(meseron->getPlatillos().size()!=0){
            meseron->eliminarPlatillos();
            cout<<"¡¡¡ Platillos repartidos!!! "<<endl;
          }else{
            cout<<" ¡¡¡ Este mesero no tiene platillos a entregar !!!"<<endl;
          }
        }
        break;
      }
    }
  /*_=================================================_*/
  }else if(user==NULL){
    cout<<" ¡¡No hay usuario logeado!! "<<endl;
  }
}


//Funciones de funcionesUsuario
  /*Administrador*/
usuario* contratarEmpleado(vector<usuario*> *usuarios){
  usuario* user;
  int opcion;
  string username, nombre, password, ID;
  int edad, numTelefono,anio, sueldo;
  cout<<" =| Registrar nuevo usuario |= "<<endl
      <<"1. Registrar nuevo Cliente"<<endl
      <<"2. Registrar nuevo Chef"<<endl
      <<"3. Registrar nuevo lavaplatos"<<endl
      <<"4. Registrar nuevo mesero"<<endl
      <<"Ingrese opcion: ";
  while( (cin>>opcion)<0||opcion>4){
    cout<<" ¡¡¡¡Numero no valido!!!! "<<endl
        <<"Ingrese de nuevo la opcion: ";
  }
  cout<<"- Ingrese nombre: ";
  cin>>nombre;
  cout<<"- Ingrese nombre de usuario: ";
  cin>>username;
  cout<<"- Ingrese edad: ";
  cin>>edad;
  cout<<"- Ingrese contraseña: ";
  cin>>password;
  cout<<"- Ingrese ID: ";
  cin>>ID;
  while(comprobarID(ID,usuarios)){
    cout<<"- ID ya registrado, Ingrese otro ID: ";
    cin>>ID;
  }
  cout<<"- Ingrese numero de Telefono(entero): ";
  cin>>numTelefono;
  switch(opcion){
    case 1:{
      string direccion;
      int rating;
      cout<<"- Ingrese direccion: ";
      cin>>direccion;
      cout<<"- Ingrese numero de Rating: ";
      cin>>rating;
      user = new cliente(username,password,nombre,ID,edad,numTelefono,direccion,rating);
    }
    break;

    case 2:{
      string platillo;
      cout<<"- Ingrese el platillo favorito: ";
      cin>>platillo;
      cout<<"- Ingrese año de contratacion: ";
      cin>>anio;
      cout<<"- Ingrese sueldo: ";
      cin>>sueldo;
      user = new chef(username,password,nombre,ID,edad,numTelefono,anio,sueldo,platillo);
    }
    break;

    case 3:{
      cout<<"- Ingrese año de contratacion: ";
      cin>>anio;
      cout<<"- Ingrese sueldo: ";
      cin>>sueldo;
      user = new lavaplatos(username,password,nombre,ID,edad,numTelefono,anio,sueldo);
    }
    break;

    case 4:{
      cout<<"- Ingrese año de contratacion: ";
      cin>>anio;
      cout<<"- Ingrese sueldo: ";
      cin>>sueldo;
      user = new mesero(username,password,nombre,ID,edad,numTelefono,anio,sueldo);
    }
    break;
    guardarUsuario(user);
  }
  cout<<"¡¡Usuario registrado!!"<<endl;
  return user;
}
usuario* empleadoMenorSueldo(vector<usuario*> *usuarios){
  int cont;
  int numero=10000;
  personal* retornar;
  personal* persona;
  for(int i=0; i<usuarios->size(); i++){
    if(dynamic_cast<personal*>(usuarios->at(i))){
      persona = dynamic_cast<personal*>(usuarios->at(i));
      if(persona->getSueldo()<numero){
        retornar = dynamic_cast<personal*>(usuarios->at(i));
        numero = persona->getSueldo();
      }
    }
  }
  return retornar;
}
usuario* empleadoMayorSueldo(vector<usuario*> *usuarios){
  int cont;
  int numero=0;
  personal* retornar;
  personal* persona;
  for(int i=0; i<usuarios->size(); i++){
    if(dynamic_cast<personal*>(usuarios->at(i))){
      persona = dynamic_cast<personal*>(usuarios->at(i));
      if(persona->getSueldo()>numero){
        retornar = dynamic_cast<personal*>(usuarios->at(i));
        numero = persona->getSueldo();
      }
    }
  }
  return retornar;
}
void asignarPlatillo(string platillo, string id, vector<usuario*> *usuarios){
  mesero* meserito;
  for(int i=0; i<usuarios->size(); i++){
    if(usuarios->at(i)->getID()==id){
      meserito = dynamic_cast<mesero*>(usuarios->at(i));
      meserito->setPlatillo(platillo);
      break;
    }
  }
  cout<<"¡¡ Platillo asignado !!"<<endl;
}
int promedioTotal(vector<usuario*> *usuarios){
  int contSueldo=0, contPromedio=0;
  personal* p;
  for(int i=0; i<usuarios->size(); i++){
    if(dynamic_cast<personal*>(usuarios->at(i))){
      p = dynamic_cast<personal*>(usuarios->at(i));
      contPromedio++;
      contSueldo+=p->getSueldo();
    }
  }
  return contSueldo/contPromedio;
}
  /*Chef*/
void gritar(usuario* user, vector<usuario*> *usuarios){
  int cont=0;
  cout<<" =| Gritarle a un lavaplatos |= "<<endl
      <<"Lista de lavaplatos: "<<endl;
  for(int i=0; i<usuarios->size(); i++){
    if(dynamic_cast<lavaplatos*>(usuarios->at(i))){
        cout<<cont<<".- Nombre: "<<usuarios->at(i)->getNombre()<<" | ID: "<<usuarios->at(i)->getID()<<endl;
        cont++;
    }
  }
  if(cont!=0){
    string id;
    int num;
    lavaplatos* platos;
    cout<<"Ingrese el ID del lavaplatos: ";
    cin>>id;
    while(!comprobarID(id,usuarios)){
      cout<<"¡¡¡ ID incorrecto!!! ingrese de nuevo: ";
      cin>>id;
    }
    cout<<"Ingrese la cantidad de motivacion que le bajara: ";
    cin>>num;
    for(int i=0; i<usuarios->size(); i++){
      if(dynamic_cast<lavaplatos*>(usuarios->at(i)) && usuarios->at(i)->getID()==id){
        platos = dynamic_cast<lavaplatos*>(usuarios->at(i));
        platos->desmotivar(num);
        cout<<"¡¡¡ Lavaplatos regañado :v !!! "<<endl;
      }
    }
  }else{
    cout<<"¡¡¡ No hay lavaplatos para regañarlo !!! "<<endl;
  }
}
void agradar(usuario* user, vector<usuario*> *usuarios){
  int cont=0;
  cout<<" =| Gritarle a un lavaplatos |= "<<endl
      <<"Lista de lavaplatos: "<<endl;
  for(int i=0; i<usuarios->size(); i++){
    if(dynamic_cast<lavaplatos*>(usuarios->at(i))){
        cout<<cont<<".- Nombre: "<<usuarios->at(i)->getNombre()<<" | ID: "<<usuarios->at(i)->getID()<<endl;
        cont++;
    }
  }
  if(cont!=0){
    string id;
    int num;
    lavaplatos* platos;
    cout<<"Ingrese el ID del lavaplatos: ";
    cin>>id;
    while(!comprobarID(id,usuarios)){
      cout<<"¡¡¡ ID incorrecto!!! ingrese de nuevo: ";
      cin>>id;
    }
    cout<<"Ingrese la cantidad de motivacion que le aumentara: ";
    cin>>num;
    for(int i=0; i<usuarios->size(); i++){
      if(dynamic_cast<lavaplatos*>(usuarios->at(i)) && usuarios->at(i)->getID()==id){
        platos = dynamic_cast<lavaplatos*>(usuarios->at(i));
        platos->motivar(num);
        cout<<"¡¡¡ Lavaplatos regañado :v !!! "<<endl;
      }
    }
  }else{
    cout<<"¡¡¡ No hay lavaplatos para regañarlo !!! "<<endl;
  }
}


//Otras funciones
      /*Guarda el usuario en los archivos de texto*/
void guardarUsuario(usuario* user){
  ofstream fichero("datos.txt",ios::out);
  if(dynamic_cast<cliente*>(user)){           //Cliente
    cliente* cl = dynamic_cast<cliente*>(user);
    fichero<<cl->getNombre()<<","<<cl->getUsername()<<","<<cl->getPassword()<<","<<cl->getID()
          <<","<<cl->getEdad()<<","<<cl->getNumeroTelefono()<<","<<cl->getDireccion()<<","<<cl->getRating()<<"C";
  }else if(dynamic_cast<personal*>(user)){           //personal
    personal* ps = dynamic_cast<personal*>(user);
    fichero<<ps->getNombre()<<","<<ps->getUsername()<<","<<ps->getPassword()<<","<<ps->getID()
          <<","<<ps->getEdad()<<","<<ps->getNumeroTelefono()<<","<<ps->getContratacion()<<","<<ps->getSueldo()<<"P";
  }else if(dynamic_cast<administrador*>(user)){           //administrador
    administrador* adm = dynamic_cast<administrador*>(user);
    fichero<<adm->getNombre()<<","<<adm->getUsername()<<","<<adm->getPassword()<<","<<adm->getID()
          <<","<<adm->getEdad()<<","<<adm->getNumeroTelefono()<<","<<adm->getEmpleadosContratados()<<","<<adm->getEmpleadosDespedidos()<<"A";
  }else if(dynamic_cast<chef*>(user)){           //chef
    chef* ch = dynamic_cast<chef*>(user);
    fichero<<ch->getNombre()<<","<<ch->getUsername()<<","<<ch->getPassword()<<","<<ch->getID()
          <<","<<ch->getEdad()<<","<<ch->getNumeroTelefono()<<","<<ch->getPlatillo()<<"H";
  }else if(dynamic_cast<lavaplatos*>(user)){           //Llavaplatos
    lavaplatos* lv = dynamic_cast<lavaplatos*>(user);
    fichero<<lv->getNombre()<<","<<lv->getUsername()<<","<<lv->getPassword()<<","<<lv->getID()
          <<","<<lv->getEdad()<<","<<lv->getNumeroTelefono()<<","<<lv->getMotivacion()<<"L";
  }else if(dynamic_cast<mesero*>(user)){           //mesero
    mesero* ms = dynamic_cast<mesero*>(user);
    fichero<<ms->getNombre()<<","<<ms->getUsername()<<","<<ms->getPassword()<<","<<ms->getID()
          <<","<<ms->getEdad()<<","<<ms->getNumeroTelefono()<<"M";
  }
  fichero.close();
}

      /*Comprueba si el ID no se repite*/
bool comprobarID(string id, vector<usuario*> *usuarios){
  for(int i=0; i<usuarios->size(); i++){
    if(usuarios->at(i)->getID()==id){
      return true;
    }
  }
  return false;
}

      /*Comprueba si el usuario existe y lo retorna, por medio de nombre y contraseña*/
usuario* comprobarUsuario(string nombre, string password, vector<usuario*> *usuarios){
  for(int i=0; i<usuarios->size(); i++){
    if(usuarios->at(i)->getUsername()==nombre && usuarios->at(i)->getPassword()==password){
      return usuarios->at(i);
    }
  }
  return NULL;
}

      /*Comprueba si el usuario existe y lo retorna, por medio del ID*/
usuario* comprobarUsuario(string ID, vector<usuario*> *usuarios){
  for(int i=0; i<usuarios->size(); i++){
    if(usuarios->at(i)->getID()==ID){
      return usuarios->at(i);
    }
  }
  return 0;
}
