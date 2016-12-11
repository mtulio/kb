//Iteração 1
void Iterac1(int Ka, int Kb, int Kc, int Kd, int *Xa, int *Xb, int *Xc, int *Xd, )
{
	int Xa1=*Xa, Xb1=*Xb, Xc1=*Xc, Xd1=*Xd;
	MULT16(Xa,Xa1,Ka);
	MULT16(Xd,Xd1,Kd);
	SOMA16(Xb,Xc1,Kc);
	SOMA16(Xc,Xb1,Kb);
}//fim iteracao 1

//iteracao 2
void Iterac2(int Ke, int Kf, int *Xa, int *Xb, int *Xc, int *Xd)
{
	int Xa1=*Xa, Xb1=*Xb, Xc1=*Xc, Xd1=*Xd;
	itn Y1,Z1,Y2,Z2; int aux1, aux2;
	XOR(&Y1,Xa1,Xb1);
	XOR(&Z1,Xc1,Xd1);

	//CAlcula de Y2
	MULT16(&aux1, Ke, Y1);
	SOMA16(&aux2, aux1, Z1);
	MULT16(&Y2, aux2, Kf);
	
	//Calculo de Z2
	SOMA16(&Z2,aux1,Y2);
	XOR(Xa,Xa1,Y2);
	XOR(Xb,Xb1,Y2);
	XOR(Xc,Xc1,Z2);
	XOR(Xd,Xd1,Z2);
}//fim Iteracao 2

void Iteracao(int Ka, int Kb, int Kc, int Kd, int Ke, int Kf, int *Xa, int *Xb, int *Xc, int *Xd)
{
	Iterac1(Ka,Kb,Kc,Kd,Xa,Xb,Xc,Xd);
	Iterac2(Ke,Kf,Xa,Xb,Xc,Xd);
}//fim Iteracao

void TransformacaoT(int K49, int K50, int K51, int K52, *Xa, *Xb, *Xc, *Xd)
{
	int Xa1=*Xa, Xb1=*Xb, Xc1=*Xc, Xd1=*Xd;
	MULT16(Xa,Xa1,K49);
	MULT16(Xd,Xd1,K52);
	SOMA16(Xb,Xc1,K50);
	SOMA16(Xc,Xb1,K51);
}//fim Transformacao