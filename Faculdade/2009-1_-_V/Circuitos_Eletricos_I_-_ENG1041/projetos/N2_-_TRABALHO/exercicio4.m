clc
clear
%----------------------------------------
% Questao 4 do trabalho
%----------------------------------------

R1 = 4;
I1 = 6;
H=1/5;

il0=6;
il01=6;
il02=0;

%para letra a
Rtha = R1;
Ta = H/Rtha;

%para letra b
Rb = 2;
Rthb = Rb;
Tb = H/Rthb;

%para letra c
Rc = 6;
Rthc = Rc;
Tc = H/Rthc;

t = 0:0.01:1; 
ita = il02 + (il01 - il02)*exp(-t/Ta);
itb = il02 + (il01 - il02)*exp(-t/Tb);
itc = il02 + (il01 - il02)*exp(-t/Tc);

plot(t,ita,'r',t,itb,'k',t,itc,'b');
title('Grafico das correntes');
xlabel('tempo[Seg]');
ylabel('Corrente[A]');


%------------------------------------------------------
disp('Aperte algum numero para plotar grafico das tensões ');
var=input('');
%-------------------------------------------------------

v0= 0; %indutor é um curto
v01=I1*R1;  % a chave abriu e a corente que passa no resistor é a que esta no indutor
v02=0; % o capacitor ja descaregou;


va = v02 + (v01 - v02)*exp(-t/Ta);
vb = v02 + (v01 - v02)*exp(-t/Tb);
vc = v02 + (v01 - v02)*exp(-t/Tc);
plot(t,va,'r',t,vb,'k',t,vc,'b');
title('Grafico das Tensões');
xlabel('tempo[Seg]');
ylabel('Tensão[V]');
