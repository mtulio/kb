clc
clear

%----------------------------------------
% Questao 3 do trabalho
%----------------------------------------

R1=200*10^3; disp(R1)
C=0.000001; disp(C);

t = 0:0.1:1; 
disp(sprintf('t=',t));
aux = t;
vc=5*(1-2*(exp(-2*aux)));

% CALCULO DAS CORRENTES
%calculo do ir
ir=vc/R1;

% calculando ic
vc2 = 20*exp(-2*aux);
ic=C*vc2;

% calculando i
%qir=ir.^2
%qic=ic.^2
%soma=qir+qic
%modulo=sqrt(soma,2)

i = ir+ic

%GRAFICOS

plot(t,ir,'r',t,ic,'k',t,i,'b');
title('Grafico das correntes');
xlabel('tempo[Seg]');
ylabel('Corrente[A]');

%------------------------------------------------------
disp('Tecle algum valot numerico para proximo grafico ');
var=input('Opcao :');
%-------------------------------------------------------
plot(t,vc);
title('Grafico da Tensão');
xlabel('tempo[Seg]');
ylabel('Tensão[V]');
