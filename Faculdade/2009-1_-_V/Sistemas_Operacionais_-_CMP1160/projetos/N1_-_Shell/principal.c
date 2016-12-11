#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
char local[50], arg0[40], arg1[40], arg2[40], arg3[30];
FILE *pwd;

void criaprocesso(char caminho[40],char cmd[10],char parametro[30],char parametro1[30],char prm[30])
{
	pid_t pid;
	pid=fork();
	if(pid<0){
		fprintf(stderr, "FALHA NO EXECUCAO DO FORK()");
	    return;
	}
	else if(pid==0){
		execlp(caminho,cmd,parametro,parametro1,prm,NULL);
	}
	else{
	    wait(NULL);
	    printf("\n");
	    return;
	}
}

int tratacomando(char const cmd[30])
{
	int x;
	for(x=0;x<40;x++){
		arg0[x]='\0';
		arg1[x]='\0';
		arg2[x]='\0';
		arg3[x]='\0';
	}
	int qPosicao=strlen(cmd), i, j=0, k; //j eh a quantidade de espacos do prog
	if(qPosicao==0) return 50;
	for(i=0;cmd[i]!='\0';i++) if(cmd[i]==' ') j++;
	if(j==0){
		for(i=0;cmd[i]!='\0';i++) arg0[i]=cmd[i];
		if(!(strcmp(cmd,"ls"))) return 1;
		else{
			if(!(strcmp(cmd,"pwd"))) return 2;
			else{
				if(!(strcmp(cmd,"free"))) return 3;
				else{
					if(!(strcmp(cmd,"clear"))) return 4;
					else{
						if(!(strcmp(cmd,"date"))) return 5;
						else{
							if(!(strcmp(cmd,"ps"))) return 8;
							else{
								if(!(strcmp(cmd,"route"))) return 10;
								else{
									if(!(strcmp(cmd,"lspci"))) return 13;
									else{
										if(!(strcmp(cmd,"--help"))) return 50;
										else{
											if(!(strcmp(cmd,"top"))) return 14;
											else{
												if(!(strcmp(cmd,"ifconfig"))) return 15;
												else{
													if(!(strcmp(cmd,"fdisk"))) return 16;
													else{
														if(!(strcmp(cmd,"gcc"))||!(strcmp(cmd,"g++"))) return 19;
														else{
															if((arg0[0]=='.')&&(arg0[1]=='/')) return 20;
															else{
																if(!(strcmp(cmd,"lsusb"))) return 27;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return 0;
	}
	else{
		if(j==1){
			for(i=0;cmd[i]!=' ';i++) arg0[i]=cmd[i];
			for(i++, k=0;cmd[i]!='\0';i++,k++) arg1[k]=cmd[i];
			if((!(strcmp(arg0,"ls")))) return 6;
			//if(!(strcmp(arg0,"cd"))) return 7;
			if(!(strcmp(arg0,"ps"))) return 9;
			//if(!(strcmp(arg0,"cp"))) return 10;
			if(!(strcmp(arg0,"route"))) return 11;
			if(!(strcmp(arg0,"fdisk"))) return 12;
			if(!(strcmp(arg0,"gcc"))&&!(strcmp(arg1,"--help"))) return 17;
			if(!(strcmp(arg0,"g++"))&&!(strcmp(arg1,"--help"))) return 18;
			return 0;
		}
		else{
			if(j==2){
				for(i=0;cmd[i]!=' ';i++) arg0[i]=cmd[i];
				for(i++,k=0;cmd[i]!=' ';i++,k++) arg1[k]=cmd[i];
				for(i++,k=0;cmd[i]!='\0';i++,k++) arg2[k]=cmd[i];
				return 22;
			}
			else{
				if(j==3){

					for(i=0;cmd[i]!=' ';i++) arg0[i]=cmd[i];
					for(i++,k=0;cmd[i]!=' ';i++,k++) arg1[k]=cmd[i];
					for(i++,k=0;cmd[i]!=' ';i++,k++) arg2[k]=cmd[i];
					for(i++,k=0;cmd[i]!='\0';i++,k++) arg3[k]=cmd[i];
					if((strcmp(arg0,"g++"))&&(strcmp(arg0,"gcc"))) return 0;
					return 23;
				}
			}
		}
	}
	printf("CONTROLEPROG___ %s ___ %s ___ %s ___",arg0,arg1,arg2);
	return 0;
}

int main(void)
{
	int o=0, i=0;
	char comando[50], z;
	system("pwd >> pwd.txt");
	pwd=fopen("pwd.txt","r");
	for(i=0;(fscanf(pwd,"%c",&z)!=EOF)&&z!=10;i++){
		local[i]=z;
	}
	fclose(pwd);
	system("rm -rf pwd.txt");
	printf("\n\n\tBem Vindo, para duvidas digite o comando --help\n\n\n");
	printf("kbca@hifi:%s#",local);
	fflush(stdin);
	gets(comando);
	while(strcmp(comando,"exit")){
		if(!strcmp(comando,"--help")){
			system("clear");
			printf("\n\n\n\t _____________________________________________________\n"
						"\t|                                                      |\n"
						"\t|         BEM VINDO AO SHELL KBCA@HIFI                 |\n"
						"\t|                                                      |\n"
						"\t| bin.: ls* | free | pwd | clear | date                |\n"
						"\t|                                                      |\n"
						"\t| sbin.: route | fdisk* | lspci | ifconfig | lsusb     |\n"
						"\t|                                                      |\n"
						"\t| Gerenciar.: ps* | kill | top | ps -aux               |\n"
						"\t|                                                      |\n"
						"\t| Obs.: para compilar utilize o gcc* ou o g++*         |\n"
						"\t|                                                      |\n"
						"\t| * - Aceita parametros [comando --help]               |\n"
						"\t|______________________________________________________|\n\n",arg0,arg1,arg2);
		}
		switch(tratacomando(comando)){
		case 1:{
			criaprocesso("/bin/ls","ls",NULL,NULL,NULL);
			break;
		}
		case 3:{
			criaprocesso("/usr/bin/free","free",NULL,NULL,NULL);
			break;
		}
		case 2:{
			criaprocesso("/bin/pwd","pwd",NULL,NULL,NULL);
			break;
		}
		case 4:{
			criaprocesso("/usr/bin/clear","clear",NULL,NULL,NULL);
			printf("\tPara duvidas digite o comando --help\n\n");
			break;
		}
		case 5:{
			criaprocesso("/bin/date","date",NULL,NULL,NULL);
			break;
		}
		case 6:{
			criaprocesso("/bin/ls","ls",arg1,NULL,NULL);
			break;
		}
		case 7:{
			criaprocesso(arg0,arg1,NULL,NULL,NULL);
			break;
		}
		case 8:{
			criaprocesso("/bin/ps","ps",NULL,NULL,NULL);
			break;
		}
		case 9:{
			criaprocesso("/bin/ps","ps",arg1,NULL,NULL);
			break;
		}
		case 10:{
			criaprocesso("/sbin/route","route",NULL,NULL,NULL);
			break;
		}
		case 11:{
			criaprocesso("/sbin/route","route",arg1,NULL,NULL);
			break;
		}
		case 12:{
			criaprocesso("/sbin/fdisk","fdisk",arg1,NULL,NULL);
			break;
		}
		case 13:{
			criaprocesso("/sbin/lspci","lspci",NULL,NULL,NULL);
			break;
		}
		case 14:{
			criaprocesso("/usr/bin/top","top",NULL,NULL,NULL);
			break;
		}
		case 15:{
			criaprocesso("/sbin/ifconfig","ifconfig",NULL,NULL,NULL);
			break;
		}
		case 16:{
			criaprocesso("/sbin/fdisk","fdisk","-l",NULL,NULL);
			break;
		}
		case 17:{
			criaprocesso(arg0,arg0,arg1,NULL,NULL);
			break;
		}
		case 18:{
			criaprocesso(arg0,arg0,arg1,NULL,NULL);
			break;
		}
		case 19:{
			printf("Erro - Falta parametros (g** caminhoCmONomeDoArquivo -o nomeDoArquivo)\n\n");
			break;
		}
		case 20:{
			criaprocesso(arg0,arg0,NULL,NULL,NULL);
			break;
		}
		case 21:{
			criaprocesso(arg0,arg0,arg1,NULL,NULL);
			break;
		}
		case 22:{
			criaprocesso(arg0,arg0,arg1,arg2,NULL);
			break;
		}
		case 23:{
			criaprocesso(arg0,arg0,arg1,arg2,arg3);
			break;
		}
		case 27:{
			criaprocesso("/sbin/lsusb","lsusb",NULL,NULL,NULL);
			break;
		}
		case 50:
			break;
		default:
			printf("hifi - Comando inexistente\n");
			break;
		}
	printf("kbca@hifi:%s#",local);
	fflush(stdin);
	gets(comando);
	}
}
