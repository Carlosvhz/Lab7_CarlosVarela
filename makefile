run:	main.o usuario.o cliente.o personal.o administrador.o chef.o lavaplatos.o mesero.o
	g++ main.o usuario.o cliente.o personal.o administrador.o chef.o lavaplatos.o mesero.o -o run

main.o:	usuario.h cliente.h personal.h administrador.h chef.h lavaplatos.h mesero.h main.cpp
	g++ -c main.cpp

usuario.o:	usuario.h usuario.cpp
	g++ -c usuario.cpp

personal.o:	personal.h personal.cpp
	g++ -c personal.cpp

cliente.o:	cliente.h cliente.cpp
	g++ -c cliente.cpp

administrador.o:	administrador.h administrador.cpp
	g++ -c administrador.cpp

chef.o:	chef.h chef.cpp
	g++ -c chef.cpp

lavaplatos.o:	lavaplatos.h lavaplatos.cpp
	g++ -c lavaplatos.cpp

mesero.o:	mesero.h mesero.cpp
	g++ -c mesero.cpp

clear:
	rm *.o run
