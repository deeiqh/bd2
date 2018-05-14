#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

/*

---------------
             x       y
disco [50][30];
---------------
                     x                    y
variables[[t1][t2]][[t1][t2]];

    t1     t2
x [x1][x2] maneja las variables de las transacciones que van a ser escritas en la misma psicion del disco.
y [y1][y2]
---------------
disco(x,y,50,30);
read(t1,x);
restar(t1,x,n);
read(t2,x);
sumar(t2,x,m);
write(t1,x);
read(t1,y);
write(t2,x);
sumar(t1,y,n);
write(t1,y);

el usuario ingresará los comandos que funcionarán tratando el x[][]

*/

map<char, double> disco(string comando, map<char, double*> &variables)
{
    map<char, double> disco;
    
    //colocar los nombres de las variables en disco y varaibles
    vector<char> arr;
    int i  = 6;
    char c = comando[i];    
    do{
        disco.insert(pair<char, double>(c,0.0));
        arr.push_back(c);
        
        double *ceros = new double[2];
        ceros[0]=0;ceros[1]=0;
        //para que se coloque el  char, x y, en el vector
        variables.insert( pair<char, double*>(c,ceros));
        
        i += 2;
        c = comando[i];  
    }
    while(isalpha(c));
    
   //colocar los valores de las variables en disco
    string numero;
    for(int j=0; j < disco.size();j++){        
        numero = "";
        while(comando[i] != ',' && comando[i] != ')'){
            numero += comando[i];
            i++;
        }
        i--;//deja a i en el ultimo digito
        disco[arr[j]] = stod(numero);
        i += 2;
    }

}

void ejecuta(map<char, double> &disco, map<char, double*> &variables, string comando)
{
    string palabra("");
    int i=0;
    char c;
    while((c = comando[i])!= '('){
        palabra += c;
        i++;
    }
    i += 2;//i en el digito de la transaccion tn
    int transaccion = comando[i];
    i+=2; // i en la variable
    char variable = comando[i];
    if(palabra == "read"){
        variables[variable][transaccion-1] = disco[variable];
    }
    else if(palabra == "restar"){
        i+= 2; //i en 1er digito
        string numero = "";
        while(comando[i] != ')'){
            numero += comando[i];
            i++;
        }
        variables[variable][transaccion-1] -= stod(numero); 
    }
    else if(palabra == "sumar"){
        i+= 2; //i en 1er digito
        string numero = "";
        while(comando[i] != ')'){
            numero += comando[i];
            i++;
        }
        variables[variable][transaccion-1] += stod(numero);   
    }
    else if(palabra == "write"){
        disco[variable] = variables[variable][transaccion-1];
    }
        
    
}

void   imprime(const map<char, double> &disco)
{
    for(auto it = disco.begin(); it != disco.end(); it++){
        cout << it->first << " = "<<it->second << "\n";
    }
}

int main()
{
    fstream arch;
    arch.open("comandos.txt", fstream::in);
    
    string comando;    
    
    arch >> comando;//primera linea contiene valores de variables en disco
    map<char, double*> variables; 
    map<char, double> disco_ =  disco(comando, variables);// disco [x:y];
       
    arch >> comando;
    while(comando != "fin"){
        ejecuta(disco_,variables, comando);
        arch >> comando;
    }
    
    imprime(disco_);
    arch.close();
	return 0;
}



















