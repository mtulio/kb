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

R1=8;
R2=12;
R3=3;
R4=3;
R5=2;
R6=6;
I1=30;
I2=6;

%> Calculos
Rs56=R5+R6;
Rs34=R3+R4;
RpRs2=(Rs34*R2)/(Rs34+R2);
RpRs1=(Rs56*R1)/(Rs56+R1);
Rpf=(RpRs2*RpRs1)/(RpRs2+RpRs1);
Ir=I1-I2;

Vf=Rpf*Ir;


%divisores de tensoes

Vr5= (R5/Rs56)*Vf;
Ir5= (Vr5/R5);
Pr5=Ir5*Vr5;

Vr6=(R6/Rs56)*Vf;
Ir6=(Vr6/R6);;
Pr6=Ir6*Vr6;

Vr1=Vf; %> por estar em paralelo tensao nao divide
Ir1=(Vr1/R1);;
Pr1=Ir1*Vr1;

Vr2 = Vf; %> por estar em paralelo tensao nao divide
Ir2 = Vr2/R2;
Pr2=Ir2*Vr2;

Vr3 = R3/(R3+R4)*Vf;
Ir3= Vr3/R3;
Pr3=Ir3*Vr3;

Vr4 = R4/(R3+R4)*Vf;
Ir4 = Vr4/R4;
Pr4=Ir4*Vr4;

PI1=Vf*I1;
PI2=Vf*I2;
Po=PI1-PI2

disp('Tens�o em R1 (em volts) ');
disp(Vr1);
disp('Corrente em R1 (em �mperes) ');
disp(Ir1);
disp('Potencia em R1 (em Wats) ');
disp(Pr1);

disp('Tens�o em R2 (em volts) ');
disp(Vr2);
disp('Corrente em R2 (em �mperes) ');
disp(Ir2);
disp('Potencia em R2 (em Wats) ');
disp(Pr2);

disp('Tens�o em R3 (em volts) ');
disp(Vr3);
disp('Corrente em R (em �mperes) ');
disp(Ir3);
disp('Potencia em R3 (em Wats) ');
disp(Pr3);

disp('Tens�o em R4 (em volts) ');
disp(Vr4);
disp('Corrente em R4 (em �mperes) ');
disp(Ir4);
disp('Potencia em R4 (em Wats) ');
disp(Pr4);

disp('Tens�o em R5 (em volts) ');
disp(Vr5);
disp('Corrente em R5 (em �mperes) ');
disp(Ir5);
disp('Potencia em R5 (em Wats) ');
disp(Pr5);

disp('Tens�o em R6 (em volts) ');
disp(Vr6);
disp('Corrente em R6 (em �mperes) ');
disp(Ir6);
disp('Potencia em R6 (em Wats) ');
disp(Pr6);