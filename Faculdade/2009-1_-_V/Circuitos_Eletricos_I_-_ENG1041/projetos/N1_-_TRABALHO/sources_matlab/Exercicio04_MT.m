clc
clear
R1=2;
R2=4;
R3=6;

t=0:0.001:0.05;
V=10*sin(2*pi*60*t)

plot(t,V)
xlabel('t[s]')
ylabel('V [V]')