import java.awt.*;
import java.applet.Applet;

public class jantar extends Applet { // detalhes da Interface da Applet

    final int MenuBarHeight = 0;
    public Panel fil0;
    public Panel fil1;
    public Panel fil2;
    public Panel fil3;
    public Panel fil4;
    public Label Label1;
    public Label Label2;
    public Label Label3;
    public Label Label4;
    public Label Label5;
    private filosofo f0, f1, f2, f3, f4; // declaração dos cinco (5) objetos filósofos
    public garfos fork; // declaração do objeto garfos


    public void init( ) {
    setForeground(Color.black);
    setBackground(Color.lightGray);
    setFont(new Font("Dialog",Font.BOLD,12));
    setLayout(null);
    fil0 = new Panel();
    fil0.setLayout(null);
    fil0.setForeground(Color.black);
    fil0.setBackground(Color.yellow);
    fil0.setFont(new Font("Dialog",Font.BOLD,12));
    fil1 = new Panel(); fil1.setLayout(null);
    fil1.setForeground(Color.black);
    fil1.setBackground(Color.yellow);
    fil1.setFont(new Font("Dialog",Font.BOLD,12));
    fil2 = new Panel(); fil2.setLayout(null);
    fil2.setForeground(Color.black);
    fil2.setBackground(Color.yellow);
    fil2.setFont(new Font("Dialog",Font.BOLD,12));
    fil3 = new Panel(); fil3.setLayout(null);
    fil3.setForeground(Color.black);
    fil3.setBackground(Color.yellow);
    fil3.setFont(new Font("Dialog",Font.BOLD,12));
    fil4 = new Panel(); fil4.setLayout(null);
    fil4.setForeground(Color.black);
    fil4.setBackground(Color.yellow);
    fil4.setFont(new Font("Dialog",Font.BOLD,12));
    Label1 = new Label("0 ",Label.LEFT);
    Label1.setFont(new Font("Dialog",Font.BOLD,12));
    Label2 = new Label("1 ",Label.LEFT);
    Label2.setFont(new Font("Dialog",Font.BOLD,12));
    Label3 = new Label("2 ",Label.LEFT);
    Label3.setFont(new Font("Dialog",Font.BOLD,12));
    Label4 = new Label("3 ",Label.LEFT);
    Label4.setFont(new Font("Dialog",Font.BOLD,12));
    Label5 = new Label("4 ",Label.LEFT);
    Label5.setFont(new Font("Dialog",Font.BOLD,12));
    add(Label5); add(Label4); add(Label3);
    add(Label2); add(Label1); add(fil4);
    add(fil3); add(fil2); add(fil1);
    add(fil0);
    InitialPositionSet( );
    fork = new garfos( ); // cria objeto garfos
    f0 = new filosofo(0,this); // cria processos (threads) filósofos
    f1 = new filosofo(1,this);
    f2 = new filosofo(2,this);
    f3 = new filosofo(3,this);
    f4 = new filosofo(4,this);
    f0.start( ); // inicializa cada processo filósofo
    f1.start( );
    f2.start( );
    f3.start( );
    f4.start( );
    }

    public void start( ) { }

    public void stop( ) { }

    public void destroy( ) { }

    public void paint(Graphics g) { }

    public void InitialPositionSet( ) {

    resize(392,305);
    fil0.setBounds(173,43+MenuBarHeight,40,40); fil1.setBounds(250,89+MenuBarHeight,40,40); fil2.setBounds(220,178+MenuBarHeight,40,40); fil3.setBounds(116,177+MenuBarHeight,40,40); fil4.setBounds(88,92+MenuBarHeight,40,40);
    Label1.setBounds(189,15+MenuBarHeight,12,19); Label2.setBounds(299,99+MenuBarHeight,17,19); Label3.setBounds(285,199+MenuBarHeight,13,19); Label4.setBounds(94,192+MenuBarHeight,13,19); Label5.setBounds(67,107+MenuBarHeight,9,19);
    }

    public void jantar_WindowDestroy(Object target) { System.exit(0); }

    public void SetInfo(int key, int status){

    if (key == 0) { if (status ==0) { Repinta(fil0,Color.yellow,Label1,"0 - Pensando"); }
    else if (status ==1) { Repinta(fil0,Color.green,Label1,"0 - Comendo"); }
    else if (status ==2) { Repinta(fil0,Color.red,Label1,"0 - Faminto"); } }
    else if (key == 1) { if (status ==0) { Repinta(fil1,Color.yellow,Label2,"1 - Pensando"); }
    else if (status ==1) { Repinta(fil1,Color.green,Label2,"1 - Comendo"); }
    else if (status ==2) { Repinta(fil1,Color.red,Label2,"1 - Faminto"); } }
    else if (key == 2) { if (status ==0) { Repinta(fil2,Color.yellow,Label3,"2 - Pensando"); }
    else if (status ==1) { Repinta(fil2,Color.green,Label3,"2 - Comendo"); }
    else if (status ==2) { Repinta(fil2,Color.red,Label3,"2 - Faminto"); } }
    else if (key == 3) { if (status ==0) { Repinta(fil3,Color.yellow,Label4,"3 - Pensando"); }
    else if (status ==1) { Repinta(fil3,Color.green,Label4,"3 - Comendo"); }
    else if (status ==2) { Repinta(fil3,Color.red,Label4,"3 - Faminto"); } }
    else if (key == 4) { if (status ==0) { Repinta(fil4,Color.yellow,Label5,"4 - Pensando"); }
    else if (status ==1) { Repinta(fil4,Color.green,Label5,"4 - Comendo"); }
    else if (status ==2) { Repinta(fil4,Color.red,Label5,"4 - Faminto"); }
    }
    }

    public void Repinta(Panel p, Color c, Label l, String s){

    p.setBackground(c);
    l.setText(s);
    }

}
