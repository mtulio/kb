%**** UNIVERSIDADE CATOLICA DE GOIAS
%**** ENG1041 - CIRCUITOS ELETRICOS
%**** TRABALHO PRATICO N1
%**** DR. MARCOS ANTONIO DE SOUSA
%**** ALUNO:    MARCO TULIO RODRIGUES BRAGA
%****           MILLYS FABRIELLE   
%****           WALTER

% Exercicio 1

%> Limpando a tela
clc
clear

%> inicializando variaveis
R1 = 1;
R2 = 2;
R3 = 3;
x= 0:0.00001:0.020;
If = (24 * sin((120 * pi) * x));
disp(If);
%>Calculando Rs
Rs = R1 + R2 + R3;

%> Calculando Vf
Vf= Rs * If;

%> Calculando Vr1 e Ir1

Vr1 = (R1/Rs)*Vf;
Ir1 = Vr1 / R1;

%> Calculando Vr2 e Ir2

Vr2 = (R2/Rs)*Vf;
Ir2 = Vr2 / R2;


%> Calculando Vr3 e Ir3

Vr3 = (R3/Rs)*Vf;
Ir3 = Vr3 / R3;

%> imprimindo valores
disp('Tens�o em R1 (em volts) ');
disp(Vr1);
disp('Corrente em R1 (em �mperes) ');
disp(Ir1);

disp('Tens�o em R2 (em volts) ');
disp(Vr2);
disp('Corrente em R2 (em �mperes) ');
disp(Ir2);

disp('Tens�o em R3 (em volts) ');
disp(Vr3);
disp('Corrente em R3 (em �mperes) ');
disp(Ir3);

%> GRAFICOS

%>calculo da variaveis
vr1= (R1/Rs)*(Rs*(24*sin((120*pi)*x)));
vr2= (R2/Rs)*(Rs*(24*sin((120*3.1416)*x)));
vr3= (R3/Rs)*(Rs*(24*sin((120*3.1416)*x)));


plot(x,vr1,'k',x,vr2,'r',x,vr3,'b');
title('Grafico das Tens�o');
xlabel( 'Tempo [s]' );
ylabel('Tens�o [V]');

disp('Tecle algum valot numerico para proximo grafico ');
var=input('Opcao :');
plot(x,If,'b');
title('Grafico das Correntes');
xlabel( 'Tempo [s]' );
ylabel('Corrente [V]');
