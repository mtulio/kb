public class garfos {
private boolean[] catched = new boolean[5]; //vetor de garfos - True(em uso) False(liberado)
public garfos( ) { }

public synchronized void pick2(filosofo f){ //método para pegar os 2 garfos (sincronizado)

    int key;
    key = f.getKey( ); //identifica qual é o filósofo que quer pegar os garfos
    while (catched[key] | | catched[((key +1)%5)]){
    //enquanto o seu garfo ou o do seu vizinho à direita estiver em uso espera até o(s) garfo(s) ser(em) liberado(s).
    f.setStatus(2); //passa para o estado FAMINTO
    try{wait( );} //espera
    catch(Exception e){}
    }
    catched[key] = true;
    catched[((key +1)%5)] = true;
    f.setStatus(1); //passa para o estado COMENDO

}

public synchronized void put2(filosofo f){ //método para liberar os 2 garfos pegos (sincronizado)

    int key; key = f.getKey( ); //identifica qual é o filósofo que vai liberar os garfos
    catched[key] = false; //libera o seu garfo e o de seu vizinho à direita
    int aux = (key+1)%5;
    catched[aux] = false;
    try{notifyAll( );} //notifica que liberou os garfos
    catch(Exception e){}

}

}
