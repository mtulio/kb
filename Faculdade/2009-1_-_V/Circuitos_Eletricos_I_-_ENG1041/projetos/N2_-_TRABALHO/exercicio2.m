clc
clear

%----------------------------------------
% Questao 2 do trabalho
%----------------------------------------

%resistores
R1 = 10;
R2 = 10;
R3 = 15;

%fonte tensao
V1 = 40;

%fonte tensao
I1 = 3;

%--------------------------------------------------------------
%LETRA A 
%--------------------------------------------------------------
% encontrar RC de forma a extrair a maxima potencia
% RC = RTH;

Rp = (R1*R2)/(R1+R2);
Rs = Rp + R3;

Rc = Rs;  % RC = RTH

%---------------------------------------------------------------
%LETRA B
%---------------------------------------------------------------
%encontrar VTH e IN

Itrans = V1 / R2; %tansformaçao de fonte

Rp = (R1 * R2)/(R1+R2); %resistencia paralelo

It = Itrans + I1; %achando a corrente total 
%achando RTH
RTH = R3 + Rp;

%achando VTH
Va = Rp * It; 
Vb = R3 * I1;
VTH = Va + Vb;

%achando IN
IN = VTH / RTH;

disp('QUESTAO 2 Do TRABALHO.');

disp(sprintf('Letra A -  Rc = %d[Ohms]',Rc));
disp(sprintf('Letra B -  VTH = %d[Volts]  IN =  %d[Ampere]',VTH,IN));

%---------------------------------------------------------------
%LETRA C
%---------------------------------------------------------------

RC=0:0.01:50;
%Pmax=(IN^2)*RC;
%Pmax=(VTH^2)./(4*RC); disp(sprintf('RC = ',RC)); disp(sprintf('Pmax = ',Pmax));
aux = RC;
soma = RTH+RC;
div = VTH./soma;
quad = div.*div;
Pmax = quad.*aux;
plot(RC,Pmax);
title('Grafico da potencia');
xlabel('Resistor');
ylabel('Potencia');
