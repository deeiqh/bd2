#include <iostream>

using namespace std;

int main()
{
	return 0;
}
/*

  t1  t2
x [x1][x2] maneja las variables de las transacciones que van a ser escritas en la misma psicion del disco.
y [y1][y2]

      x y
disco [][];

read(t1,x);
restar(t1,x,n);
read(t2,x);
restar(t2,x,m);
write(t1,x);
read(t1,y);
write(t2,x);
sumar(t1,y,n);
write(t1,y);

el usuario ingresará los comandos que funcionarán tratando el x[][]

*/
