#!/usr/bin/python

import RPi.GPIO as Portas
import time

Portas.setmode(Portas.BOARD);
Portas.setup(24,Portas.OUT);

count = 0
while (1):
	print 'The count is:', count
	count = count + 1;
	Portas.output(24,True);
	time.sleep(0.5);
	Portas.output(24,False);
	time.sleep(0.5);

#print "Good bye!"



