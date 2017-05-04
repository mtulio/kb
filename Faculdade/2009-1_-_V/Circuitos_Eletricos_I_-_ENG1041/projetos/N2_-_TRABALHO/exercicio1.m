%**** UNIVERSIDADE CATOLICA DE GOIAS
%**** ENG1041 - CIRCUITOS ELETRICOS
%**** TRABALHO PRATICO N2
%**** DR. MARCOS ANTONIO DE SOUSA
%**** ALUNO:    MARCO TULIO RODRIGUES BRAGA
%****           MILLYS FABRIELLE   
%****           WALTER

% Exercicio 01

clc
clear
% Declarando as Resistencias
R1=8;
R2=6;
R3=4;
R4=2;
R5=3;
R6=10;
R7=5;
R8=7;
R9=1;

% Criando a matriz [V]=[R]*[I] > [i]=[v]/[I]

R=[(R1+R5+R6) -R5 -R6 0;-R5 (R2+R3+R4+R5) 0 -R4;-R6 0 (R6+R7+R8) -R8;0 -R4 -R8 (R4+R8+R9)];
X=inv(R);
V=[10;20;-10;0];
I=X*V;

% Pegando os valores da corrente no vetor
I1=I(1);
I2=I(2);
I3=I(3);
I4=I(4);

% Calculando a corrent em cada Resistor
IR1=I1;
IR2=I2
IR3=I2;
IR4=I2-I4;
IR5=I1-I2;
IR6=I1-I3;
IR7=I3;
IR8=I3-I4;
IR9=I4;

% Calculando a tensao em cada resistor
VR1=R1*I1
VR2=R2*I2
VR3=R3*I2
VR4=R4*(I2-I4)
VR5=R5*(I1-I2)
VR6=R6*(I1-I3)
VR7=R7*I3
VR8=R8*(I3-I4)
VR9=R9*I4

% Calculando a potencia em cada resistor
PR1=(VR1^2)/R1;
PR2=(VR2^2)/R2;
PR3=(VR3^2)/R3;
PR4=(VR4^2)/R4;
PR5=(VR5^2)/R5;
PR6=(VR6^2)/R6;
PR7=(VR7^2)/R7;
PR8=(VR8^2)/R8;
PR9=(VR9^2)/R9;

% Imprimindo os resultados

% P/ R1
disp('Corrente em R1 (em ámperes) ');
disp(IR1);
disp('Tensão em R1 (em volts) ');
disp(VR1);
disp('Potencia em R1 (em Wats) ');
disp(PR1);

% P/ R2
disp('Corrente em R2 (em ámperes) ');
disp(IR2);
disp('Tensão em R2 (em volts) ');
disp(VR2);
disp('Potencia em R2 (em Wats) ');
disp(PR2);

% P/ R3
disp('Corrente em R3 (em ámperes) ');
disp(IR3);
disp('Tensão em R3 (em volts) ');
disp(VR3);
disp('Potencia em R3 (em Wats) ');
disp(PR3);

% P/ R4
disp('Corrente em R4 (em ámperes) ');
disp(IR4);
disp('Tensão em R4 (em volts) ');
disp(VR4);
disp('Potencia em R4 (em Wats) ');
disp(PR4);

% P/ R5
disp('Corrente em R5 (em ámperes) ');
disp(IR5);
disp('Tensão em R5 (em volts) ');
disp(VR5);
disp('Potencia em R5 (em Wats) ');
disp(PR5);

% P/ R6
disp('Corrente em R6 (em ámperes) ');
disp(IR6);
disp('Tensão em R6 (em volts) ');
disp(VR6);
disp('Potencia em R6 (em Wats) ');
disp(PR6);

% P/ R7
disp('Corrente em R7 (em ámperes) ');
disp(IR7);
disp('Tensão em R7 (em volts) ');
disp(VR7);
disp('Potencia em R7 (em Wats) ');
disp(PR7);

% P/ R7
disp('Corrente em R7 (em ámperes) ');
disp(IR7);
disp('Tensão em R7 (em volts) ');
disp(VR7);
disp('Potencia em R7 (em Wats) ');
disp(PR7);

% P/ R8
disp('Corrente em R8 (em ámperes) ');
disp(IR8);
disp('Tensão em R8 (em volts) ');
disp(VR8);
disp('Potencia em R8 (em Wats) ');
disp(PR8);

% P/ R9
disp('Corrente em R9 (em ámperes) ');
disp(IR9);
disp('Tensão em R9 (em volts) ');
disp(VR9);
disp('Potencia em R9 (em Wats): ');
disp(PR9);

