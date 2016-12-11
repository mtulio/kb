#include<stdio.h>
main () {
	int nc, opcao;
	float consumo, tp;
	printf ("\nDigite o numero da conta do cliente: ");
	scanf ("%i", &nc);
	printf ("Tipos de conta:\n\t(1)-Residencial\n\t(2)-Comercial\n\t(3)-Industrial\nDigite a opção desejada: ");
	scanf ("%i", &opcao);
	printf ("Informe o consumo de Água, em m³: ");
	scanf ("%f", &consumo);
	switch (opcao) {
		case 1 :
			tp = 5.0 + (0.05*consumo);
		break;
		case 2 :
			if (consumo <= 80.0) {
				tp = 500.0;
			}
			else tp = 500.0 + (0.25*consumo);
		break;
		case 3 :
			if (consumo <=500.0) {
				tp = 800.0;
			}
			else tp = 800.0 + (0.04*consumo);
		break;
		default:
			printf ("\n\t\tOpção INVALIDA, tente novamente!\n\n");
	}
	printf ("\nNumero da Conta: %.0i\nTipo de Conta: %.0i\nConsumo: %.0f m³\nValor à pagar: R$ %.2f\n\n",nc, opcao, 	consumo,tp);
	getchar();
	getchar();
}
