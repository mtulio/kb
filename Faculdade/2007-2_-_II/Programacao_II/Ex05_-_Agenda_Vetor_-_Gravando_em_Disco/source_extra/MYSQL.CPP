//inclui os cabeçalhos
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mysql.h>

int main(int argc, char *argv[])
{
int resquery; //cria uma variável para manter o resultado da consulta
MYSQL con; // cria a variável de conexão
mysql_init(&con); //inicializa a variável de conexão
mysql_real_connect(&con, "localhost", "", "", "myteste", 0, NULL, 0);
//efetua a conexão, não esqueça de colocar o nome do seu banco de dados com os dados de usuario, senha e servidor.
printf("Conectado com sucesso n");
resquery = mysql_query (&con, "Insert into cliente(id, nome, end) values (Null, 'Fabio', ‘endereço’);");
//insere dados na tabela cliente
printf ("Registro inserido %dn", mysql_affected_rows(&con));
//apresenta o resultado da inserção na tabela e com a função mysql_affected_rows mostra quantas linhas foram inseridas no banco de dados.
mysql_close(&con);
//fecha a conexão
system("PAUSE");
getchar();getchar();
return 0;
}
