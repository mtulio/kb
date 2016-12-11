int BLAKLEY(int a, int b, int n)
//entrada: a,b,n
//saida: R = (a*b)MOD n
{
	unsigned int aux;
	int R; R= 0;
	for (aux = 0x80000000; aux > 0; aux >>=1)
	{
		R = (R <<1);
		if((a & aux) != 0) R += b;
		if(R > n) R -= n;
		if(R > n) R -= n;
	}//fim for
	return R;
}//fim BLAKLEY