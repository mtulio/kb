//inclui os cabe�alhos
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mysql.h>

int main(int argc, char *argv[])
{
int resquery; //cria uma vari�vel para manter o resultado da consulta
MYSQL con; // cria a vari�vel de conex�o
mysql_init(&con); //inicializa a vari�vel de conex�o
mysql_real_connect(&con, "localhost", "", "", "myteste", 0, NULL, 0);
//efetua a conex�o, n�o esque�a de colocar o nome do seu banco de dados com os dados de usuario, senha e servidor.
printf("Conectado com sucesso n");
resquery = mysql_query (&con, "Insert into cliente(id, nome, end) values (Null, 'Fabio', �endere�o�);");
//insere dados na tabela cliente
printf ("Registro inserido %dn", mysql_affected_rows(&con));
//apresenta o resultado da inser��o na tabela e com a fun��o mysql_affected_rows mostra quantas linhas foram inseridas no banco de dados.
mysql_close(&con);
//fecha a conex�o
system("PAUSE");
getchar();getchar();
return 0;
}
