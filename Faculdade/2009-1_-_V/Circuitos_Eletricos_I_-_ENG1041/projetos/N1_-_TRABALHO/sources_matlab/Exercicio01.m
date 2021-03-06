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

%> Inicializa�ao das variaveis
R1 = 8;
R2 = 2;
R3 = 6;
R4 = 4;
R5 = 4;
R6 = 8;
R7 = 8;
Vf = 32;

%> Formulas para Calculo das resistencias em serie e paralela
R23eq = R2+R3;
R45eq = R4+R5;
R67eq = (R6*R7)/(R6+R7);
ReqP = (R23eq*R45eq)/(R23eq+R45eq);
Rtt = R1+ReqP+R67eq;

%> Calculando a Corrente, Tens�o e potencia para o R1
V1=(R1/Rtt)*Vf;
I1=V1/R1;
P1=V1*I1;

%> Calculando a Corrente, Tens�o e Potencia em R2
I2 = I1/2;
V2 = R2*I2;
P2 = V2*I2;

%> Calculando a Corrente, Tensao e Potencia em R3
I3=I2;
V3 = R3*I3;
P3 = V3*I3;

%> Calculando a Corrente, Tensao e Potencia em R4
I4=I1/2;
V4 = R4*I4;
P4 = V4*I4;

%> Calculando a Corrente, Tensao e Potencia em R5
I5=I4;
V5 = R5*I5;
P5 = V5*I5;

%> Calculando a Corrente, Tensao e Potencia em R6
I6=I3;
V6 = R6*I6;
P6 = V6*I6;

%> Calculando a Corrente, Tensao e Potencia em R7
I7=I4;
V7 = R7*I7;
P7 = V7*I7;

%> Imprimindo os valores de R1
disp('Tens�o em R1 (em Volts):');
disp(V1);
disp('Corrente em R1 (em Amperes):');
disp(I1);
disp('Potencia Dissipada em R1 (em Wats):');
disp(P1);

%> Imprimindo os valores em R2
disp('Tens�o em R2 (em Volts):');
disp(V2);
disp('Corrente em R2 (em Amperes):');
disp(I2);
disp('Potencia Dissipada em R2 (em Wats):');
disp(P2);

%> Imprimindo os valores em R3
disp('Tens�o em R3 (em Volts):');
disp(V3);
disp('Corrente em R3 (em Amperes):');
disp(I3);
disp('Potencia Dissipada em R3 (em Wats):');
disp(P3);

%> Imprimindo os valores em R4
disp('Tens�o em R4 (em Volts):');
disp(V4);
disp('Corrente em R4 (em Amperes):');
disp(I4);
disp('Potencia Dissipada em R4 (em Wats):');
disp(P4);

%> Imprimindo os valores em R5
disp('Tens�o em R5 (em Volts):');
disp(V5);
disp('Corrente em R5 (em Amperes):');
disp(I5);
disp('Potencia Dissipada em R5 (em Wats):');
disp(P5);

%> Imprimindo os valores em R6
disp('Tens�o em R6 (em Volts):');
disp(V6);
disp('Corrente em R6 (em Amperes):');
disp(I6);
disp('Potencia Dissipada em R6 (em Wats):');
disp(P6);

%> Imprimindo os valores em R7
disp('Tens�o em R7 (em Volts):');
disp(V7);
disp('Corrente em R7 (em Amperes):');
disp(I7);
disp('Potencia Dissipada em R7 (em Wats):');
disp(P7);

