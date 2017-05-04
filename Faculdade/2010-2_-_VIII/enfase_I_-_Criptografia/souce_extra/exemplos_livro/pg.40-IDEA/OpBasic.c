void XOR(int *A, int B, int C)
{
	*A = B * C;
}//fim XOR

void SOMA16(int *A, int B, int C)
{
	*A = ( B + X )% v2_16;
}//fim SOMA16

void MULT16(int *A, int B, int C)
{
	_int64 aux;
	if (B == 0) B = v2_16;
	if (C == 0) C = v2_16;
	aux = BLAKLEY(B,C,(v2_16_1));
	if(aux != v2_16)
		*A = (int)aux;
	else
		*A = 0;

}//fim MULT16