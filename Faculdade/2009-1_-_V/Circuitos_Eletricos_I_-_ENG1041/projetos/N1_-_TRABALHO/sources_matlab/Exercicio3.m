clc
clear

%***********************************************
%	Inicialização
%***********************************************

R1=2;
R2=5;
R3=1;
R4=4;
R5=3;

I1=10;
I2=20;
I3=5;

G1=1/R1;
G2=1/R2;
G3=1/R3;
G4=1/R4;
G5=1/R5;


%***********************************************
% Calculo da Matriz de Condutancia
%***********************************************

% PRECISA IMPRIMIR A MATRIZ? NAO

G=[(G1+G2) -G2 -G1;-G2 (G2+G3+G5) 0;-G1 0 (G1+G4)];

%***********************************************
%	Calculo da Matriz de Correntes
%***********************************************

% PRECISA IMPRIMIR A MATRIZ DE CORRENTES? NAO

I=[(I1+I3);(I2-I3);-I1];

%***********************************************
%	Calculo da Matriz de Tensoes
%***********************************************

% IMPRIMIR A MATRIZ DE TENSÕES?
% PODE SER ESSA FORMULA OU USAR A FUNCAO inv()? NAO
V=(G^-1)*I
V=inv(G)*I

%***********************************************
%	Obtendo as Tensoes
%***********************************************

V1=V(1);
V2=V(2);
V3=V(3);

%***********************************************
%   Obtendo a Tensoes nos Resistores
%***********************************************

VR1=V1-V3;
VR2=V1-V2;
VR3=V2;
VR4=V3;
VR5=V2;

%***********************************************
%   Obtendo a Correntes nos Resistores
%***********************************************

IR1=VR1/R1;
IR2=VR2/R2;
IR3=VR3/R3;
IR4=VR4/R4;
IR5=VR5/R5;

%***********************************************
%   Obetendos a Potencia Dicipada nos Resistores
%***********************************************

PR1=VR1*IR1;
PR2=VR2*IR2;
PR3=VR3*IR3;
PR4=VR4*IR4;
PR5=VR5*IR5;

%***********************************************
%   Resultados
%***********************************************

disp ('O valor das Tensoes em Volts (V)');
disp ('A tensao no Resistor R1');
disp (VR1)

disp ('A tensao no Resistor R2');
disp (VR2)

disp ('A tensao no Resistor R3');
disp (VR3)

disp ('A tensao no Resistor R4');
disp (VR4)

disp ('A tensao no Resistor R5');
disp (VR5)


disp ('O valor das Correntes em Amperes (A)');
disp ('A corrente no Resistor R1');
disp (IR1)

disp ('A corrente no Resistor R2');
disp (IR2)

disp ('A corrente no Resistor R3');
disp (IR3)

disp ('A corrente no Resistor R4');
disp (IR4)

disp ('A corrente no Resistor R5');
disp (IR5)


disp ('O valor das Potencias em Wats (W)');
disp ('A potencia no Resistor R1');
disp (PR1)

disp ('A potencia no Resistor R2');
disp (PR2)

disp ('A potencia no Resistor R3');
disp (PR3)

disp ('A potencia no Resistor R4');
disp (PR4)

disp ('A potencia no Resistor R5');
disp (PR5)

%***********************************************
%                   Fim
%***********************************************