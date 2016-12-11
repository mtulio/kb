public class filosofo extends Thread{//cada filósofo é visto como um processo

    private int key; // identifica o filósofo
    private int status; // 0 = pensa , 1 = come , 2 = faminto
    private jantar j; // objeto jantar

    public filosofo(int key,jantar j) {
    this.key = key;
    this.j = j;
    }

    public int getKey(){ // pega identificador do filósofo
    return key;
    }

    public void setStatus(int i){ // seta status do filósofo
    status = i;
    switch ( i ){
    case 0 : j.SetInfo(key, 0); break;
    case 1 : j.SetInfo(key, 1); break;
    case 2 : j.SetInfo(key, 2); break; }
    }

    private void pensando(){ // no estado pensando bloqueia por um certo tempo 2000ms)
    try{Thread.sleep(2000);}
    catch(Exception e){}
    }

    private void comendo(){ // no estado comendo bloqueia por um certo tempo (2500 ms)
    try{Thread.sleep(2500);}
    catch(Exception e){}
    }

    public void run(){
    while(true){ // roda indefinidamente
    setStatus(0); // filósofo pensando
    pensando(); // pensa - bloqueia por certo tempo
    j.fork.pick2(this); // filósofo pega os garfos
    comendo(); // come - bloqueia por certo tempo
    j.fork.put2(this); // libera os garfos }
    }

}
