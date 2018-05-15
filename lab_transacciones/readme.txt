El orden de los comandos de las transacciones serán ingresados por un archivo de
textos, donde:

    La primera línea simulará el disco, de tal forma que genere las futuras 
    variables de las transacciones.
    
    La última línea indica el fin de la inserción de comandos.
    
    A partir de la segunda se indica el comando a usar, la transacción sobre la que
    actúa y las variables y valores que involucra. Es decir:
        read(t1,x) indica que en la transacción 1 se lee de disco a la variable x.
        sumar(t2,x,2) indica que en la transacción 2 se suma 2 a la variable x.
        
    Se simularán las operaciones en el orden que hayan sido scritas en el archivo
    de texto.
    
    Se da como output los valores que quedan de las variables en el disco.
    
    Otro ejemplo de input podría ser:
    
        disco(x,y,50,30)
        read(t1,x)
        restar(t1,x,10)
        read(t2,x)
        sumar(t2,x,20)
        write(t1,x)
        read(t1,y)
        write(t2,x)
        sumar(t1,y,10)
        write(t1,y)
        fin
    
    
