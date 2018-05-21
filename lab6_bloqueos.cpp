//IDEA GENERAL PARA TOMAR EN CUENTA EN EL TRABAJO GRUPAL
#include <iostream>
#include <list>
#include <map>

using namespace std;

int main()
{
	class Transaccion{
		string id;
		string modo; //exclusivo, compartido
		bool realizado = false;
		bool borrada = false;
	};
	
	class Registro{
		string instruccion_id;
		list<Transaccion> lista_transacciones;
	};
	
	//colocando datos iniciales
	map<string, lista<Registro>> tabla_de_bloqueos;		
	Transaccion tr1;
	tr1.id = "tr231";
	tr1.modo = "exclusivo";
	
	Registro reg1;
	reg1.instruccion_id = "I8";
	reg1.lista_transacciones.push_back(tr1);
	
	lista<Registro> lista1;
	lista1.push_back(reg1);
	
	tabla_de_bloqueos["x"] = lista1;
	
	//SOLICITUD
	
	//operación agrega un registro de solicitud para la lista del dato
		//instruccion_id es I23, por ejemplo, no se "usa"
	//operacion(transaccion, tabla_de_bloqueos, dato, instruccion_id, modo)
	//en este caso se añadirá un modo exclusivo sobre uno ya compartido
		
	//colocando nuevo registro que busca poner modo exclusivo sobre uno compartido
	Transaccion tr2;
	tr2.id = "tr2";
	tr2.modo = "exclusivo";
	
	Registro reg2;
	reg2.instruccion_id = "I24";
	
	bool grant = false;
	if(tabla_de_bloqueos["x"]!= NULL){ //vemos la última transacción
		Transaccion t = tabla_de_bloqueos["x"].back().lista_transacciones.back();
		if(t.realizado == true && t.modo == "compartido")
			grant = true;
	}	
	tr2.realizado = grant;//concede o no solicitud	
	reg2.lista_transacciones.push_back(tr2); // agregamos con los valores adecuados
	
	//DESBLOQUEO
	Registro reg3 = tabla_de_bloqueos["x"].back(); // el último registro del datos
	//dado que las transacciones están al final de la lista no sería necesario volver a las anteriores
	if(reg3.lista_transacciones.back().realizado == false){
		reg3.lista_transacciones.back().realizado == true;
		reg3.lista_transacciones.back().borrada == true;
	}
	
	//INTERRUPCIÓN de transaccion tr2
	//recorre toda la estructura map
	for(auto it=lista_transacciones.begin(); it != tabla_de_bloqueos.end(); it++){
		if((it->second).back().lista_transacciones.back().id == "tr2" &&	(it->second).back().lista_transacciones.back().realizado == true)
			(it->second).back().lista_transacciones.pop_back();
				
	}

	return 0;
}



























