#!/bin/bash

#
#	Name: MTAD_CriarEstrutura.vbs
#	Copyright: DOMOL MTulio ENG
#	Author: Marco T�lio Rodrigues Braga
#	E-mail: admin@mtulio.eti.br
#	Date: 01/11/11 06:39
#	Last Change: 02/11/2011
#	Description: Este script foi desenvolvido para cria��o da estrutura organizacional 
#				implementada no trabalho de Conclus�o de Curso. 
#				Este script pode ser utilizado e distribuido de acordo com a necessidade
#				desde que seja contribuido novamente para o autor.
#
#	Details:
#
#	Sugest�es de melhorias: 
#		- ARQUIVOS LDIF: Criar um analisador Lexico dos arquivos LDIF's gerados para
#			evitar falhas na insercao dos dados na base, podendo tambem 
#			ser criada uma analisador sintatico e semantico, criando um mini-compilador.
#			Com isso eh possivel eviatr dores de cabeca de nao insercao de registros em arquivos LDIF grandes.
#			pode-se adicionar a verificacao das strings validas em cada dn tanto como o tamanho de cada atributo.
#
#	Problemas: Implementar DoWhile(C++) no laco da populacao do diretorio						

# Commands
MOVE=`which mv`
LDAPADD=`which ldapadd`

LDAPADD_ADMIN_AUTH="-x -D cn=administrador,dc=domol,dc=mtulio,dc=eng,dc=br -w 123456"

# Sera registrado o tempo de execucao para analise de performance
HOUR_NOW="date +%d/%m/%Y_%T"

# Files and Directorys
DIR_NAME="/samba/compartilhamentos/GERAL/ldif/`date +%Y%m%d-%H_%M`"
FILE_LOG_TIME="$DIR_NAME/time.log"
FILE_LOG_LDAP_OPE="$DIR_NAME/ldap_oper.log"

# PREREQ

if [ ! -d $DIR_NAME ];then
	mkdir -p $DIR_NAME
fi

# Registrando:  Inicio do Script
echo "###################################" >> $FILE_LOG_TIME
echo "	DOMOL" >> $FILE_LOG_TIME
echo "Iniciando script: `$HOUR_NOW`" >> $FILE_LOG_TIME

# Directory Informations

DOMAINNAME="domol.mtulio.eng.br"
LDAP_BASE="dc=domol,dc=mtulio,dc=eng,dc=br"
LDAP_BASE_OU="ou=DOMOL,dc=domol,dc=mtulio,dc=eng,dc=br"
LDAP_BINDDN="cn=administrador,dc=domol,dc=mtulio,dc=eng,dc=br"

NM_ENTIDADE="DOMOL"
NM_ENTIDADE_DESC="MTulio Dominio OpenLDAP"
NM_UNIDADES_SIGLA="GYN ANA URU FOR SPO"
NM_UNIDADES_OU="USUARIOS GRUPOS COMPUTADORES OBJETOS"

# Sempre colocar um objeto a mais pois o laco de repeticao
# Verifica antes de entrar no Laco

countAllUsers=9
countAllComputers=6
countAllGroups=8
countAllObjects=3

###################################
# 01 - Criando a BASE e a OU Padrao

echo "Inicio - Criar LDIF: `$HOUR_NOW`" >> $FILE_LOG_TIME

FILE_BASE="/tmp/01-$NM_ENTIDADE.ldif"

cat << EOF >> $FILE_BASE
dn: $LDAP_BASE
objectClass: top
objectClass: dcObject
objectClass: organization
dc: ${NM_ENTIDADE}
o: ${NM_ENTIDADE_DESC}

dn: ou=$NM_ENTIDADE,${LDAP_BASE}
ou: ${NM_ENTIDADE}
objectClass: top
objectClass: organizationalUnit
EOF

# Movendo o arquivo gerado para o diretorio
$MOVE $FILE_BASE $DIR_NAME

###################################
# 02 - Criando as OU das Unidades

for iItem in $NM_UNIDADES_SIGLA; do
#echo "For (01).... $iItem"
	UNIDADE=$iItem
	FILE_BASE="/tmp/02-$UNIDADE.ldif"
	DNAtual="ou=$NM_ENTIDADE,${LDAP_BASE}"
	
	echo "dn: ou=$UNIDADE,${DNAtual}
ou: ${UNIDADE}
objectClass: top
objectClass: organizationalUnit" >> $FILE_BASE



	for iItemSubOU in $NM_UNIDADES_OU; do
		#echo "For (02).... $iItemSubOU"
		SUB_OU=$iItemSubOU
		UNI_SUBOU="${iItemSubOU}"
		#DNAtual="ou=${UNIDADE},${DNAtual}"
		DNAtualSub="ou=${iItemSubOU},ou=${UNIDADE},${DNAtual}"
	
		#echo "SUB_OU - ANtes: $SUB_OU"

cat << EOF >> $FILE_BASE

EOF
		
		echo "dn: ${DNAtualSub}
ou: ${SUB_OU}
objectClass: top
objectClass: organizationalUnit" >> $FILE_BASE


		#echo "SUB_OU - Depois: $SUB_OU"
		case "$SUB_OU" in
			"USUARIOS") 
			#echo "Case USUARIOS...."
		#if [ $SUB_OU -eq "USUARIOS" ]; then
	
			i=0
			#for i in $countAllUsers ; do
			until [ $i = $countAllUsers ];do
				USERNAME="${UNIDADE}USER${i}"
				#echo "$USERNAME"

				cat << EOF >> $FILE_BASE

EOF
				
				echo "dn: cn=${USERNAME},$DNAtualSub
cn: ${USERNAME}
givenName: ${USERNAME}
mail: ${USERNAME}@${DOMAINNAME}
sn: $UNIDADE User
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE

			i=`expr 1 + $i`
			# Fim usuarios
			done
		#FIM USUARIOS
		#fi
		;;
		"GRUPOS")
		#if [ $SUB_OU -eq "GRUPOS" ]; then
			i=0
			#for i in $countAllGroups ; do
			#echo "Chegou no laco GRUPOS... $i"
			#while ( $i=1 <= $countAllGroups ); do
			until [ $i = $countAllGroups ];do
				#echo "Entrou no laco... $i"
				GROUPNAME="${UNIDADE}GRUPO${i}"
				MEMBERSGROUP="cn=${UNIDADE}USER${i},ou=USUARIOS,ou=${UNIDADE},$LDAP_BASE_OU"
				
				cat << EOF >> $FILE_BASE

EOF
				
				echo "dn: cn=${GROUPNAME},$DNAtualSub
cn: ${GROUPNAME}
description: Group - ${GROUPNAME}
member: ${MEMBERSGROUP}
objectClass: groupofnames" >> $FILE_BASE
				
			
				i=`expr 1 + $i`
			# Fim grupos
			done
		#FIM GRUPOS
		#fi
		;;
		"COMPUTADORES")
		#if [ $SUB_OU -eq "COMPUTADORES" ]; then
			i=0
			#for i in $countAllComputers ; do			
			until [ $i = $countAllComputers ];do
				COMPUTERNAME="${UNIDADE}COMPUTER${i}$"
				
				cat << EOF >> $FILE_BASE

EOF

				echo "dn: cn=${COMPUTERNAME},$DNAtualSub
cn: ${COMPUTERNAME}
sn: Hostname: ${COMPUTERNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE
				
				#echo "" >> $FILE_BASE
				
			
				i=`expr 1 + $i`
			# Fim COMPUTADORES
			done
		#FIM COMPUTADORES
		#fi
		;;
		"OBJETOS")
		#if [ "$SUB_OU" -eq "OBJETOS" ]; then
			i=1
			#for i in $countAllObjects; do			
			until [ $i = `expr $countAllObjects + 1` ];do
				OBJECTNAME="${UNIDADE}OBJ-SHARE${i}"
				#SERVERNAME="${UNIDADE}SERVER${i}"
				SHARENAME="\\\SERVER${UNIDADE}${i}\SHARED${i}"
				cat << EOF >> $FILE_BASE

EOF
				
				echo "dn: cn=${OBJECTNAME},$DNAtualSub
description: ${OBJECTNAME}
sn: \\servidor${i}\share${i}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE

				i=`expr 1 + $i`
			# Fim grupos
			done	
		#FIM OBJETOS
		#fi
		;;
		*);;
	esac
	# Fim SubOU
	done
	$MOVE $FILE_BASE $DIR_NAME
# Fim Unidades
done

echo "Fim - Criar LDIF: `$HOUR_NOW`" >> $FILE_LOG_TIME

echo "Start Add to dir: `$HOUR_NOW`" >> $FILE_LOG_TIME

$LDAPADD -f $DIR_NAME/01-* $LDAPADD_ADMIN_AUTH >> $FILE_LOG_LDAP_OPE

for LDIF_LIST in $(ls -l $DIR_NAME/02-*.ldif | awk -F " " '{print$9}');do
	$LDAPADD -f $LDIF_LIST $LDAPADD_ADMIN_AUTH >> $FILE_LOG_LDAP_OPE
done

#$LDAPADD -f $DIR_NAME/02-ANA.ldif $LDAPADD_ADMIN_AUTH
#$LDAPADD -f $DIR_NAME/02-FOR.ldif $LDAPADD_ADMIN_AUTH
#$LDAPADD -f $DIR_NAME/02-GYN.ldif $LDAPADD_ADMIN_AUTH
#$LDAPADD -f $DIR_NAME/02-SPO.ldif $LDAPADD_ADMIN_AUTH
#$LDAPADD -f $DIR_NAME/02-URU.ldif $LDAPADD_ADMIN_AUTH


echo "Finish Add to dir: `$HOUR_NOW`" >> $FILE_LOG_TIME
echo "###################################" >> $FILE_LOG_TIME

cat $FILE_LOG_TIME

echo "LDIF's criados em: $DIR_NAME"
