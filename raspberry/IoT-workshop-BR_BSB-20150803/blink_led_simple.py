#!/usr/bin/python

import RPi.GPIO as Portas

Portas.setmode(Portas.BOARD);
Portas.setup(24,Portas.OUT);

#Portas.output(24,True);
Portas.output(24,False);



