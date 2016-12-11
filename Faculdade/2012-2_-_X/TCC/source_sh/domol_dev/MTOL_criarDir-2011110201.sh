#!/bin/bash

#
#	Name: MTAD_CriarEstrutura.vbs
#	Copyright: DOMOL MTulio ENG
#	Author: Marco Túlio Rodrigues Braga
#	E-mail: admin@mtulio.eti.br
#	Date: 01/11/11 06:39
#	Last Change: 02/11/2011
#	Description: Este script foi desenvolvido para criação da estrutura organizacional 
#				implementada no trabalho de Conclusão de Curso. 
#				Este script pode ser utilizado e distribuido de acordo com a necessidade
#				desde que seja contribuido novamente para o autor.
#
#	Details:
#

MOVE=`which mv`

DOMAINNAME="domol.mtulio.eng.br"
LDAP_BASE="dc=domol,dc=mtulio,dc=eng,dc=br"
LDAP_BASE_OU="ou=DOMOL,dc=domol,dc=mtulio,dc=eng,dc=br"
LDAP_BINDDN="cn=administrador,dc=domol,dc=mtulio,dc=eng,dc=br"
TEMPFILE="/tmp/file1"
DIR_NAME="/samba/compartilhamentos/GERAL/ldif/`date +%Y%m%d-%H_%M`"

if [ ! -d $DIR_NAME ];then
	mkdir -p $DIR_NAME
fi

NM_ENTIDADE="DOMOL"
NM_ENTIDADE_DESC="MTulio Dominio OpenLDAP"
NM_UNIDADES_SIGLA="GYN ANA URU FOR SPO"
NM_UNIDADES_OU="USUARIOS GRUPOS COMPUTADORES OBJETOS"


countAllUsers=90
countAllComputers=60
countAllGroups=80
countAllObjects=30


###################################
# 01 - Criando a BASE e a OU Padrao
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

	echo " " >> $FILE_BASE

	for iItemSubOU in $NM_UNIDADES_OU; do
		#echo "For (02).... $iItemSubOU"
		SUB_OU=$iItemSubOU
		UNI_SUBOU="${iItemSubOU}"
		DNAtualSub="ou=${iItemSubOU},${DNAtual}"
	
		#echo "SUB_OU - ANtes: $SUB_OU"
	
		echo "dn: ou=$SUB_OU,${DNAtualSub}
ou: ${SUB_OU}
objectClass: top
objectClass: organizationalUnit" >> $FILE_BASE
		echo " " >> $FILE_BASE

		#echo "SUB_OU - Depois: $SUB_OU"
		case "$SUB_OU" in
			"USUARIOS") 
			#echo "Case USUARIOS...."
		#if [ $SUB_OU -eq "USUARIOS" ]; then
	
			i=1
			#for i in $countAllUsers ; do
			until [ $i = $countAllUsers ];do
				USERNAME="${UNIDADE}USER${i}"
				#echo "$USERNAME"
				echo "dn: cn=${USERNAME},$DNAtualSub
cn: ${USERNAME}
givenName: ${USERNAME}
mail: ${USERNAME}@${DOMAINNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE

				echo " " >> $FILE_BASE
			
				i=`expr 1 + $i`
			# Fim usuarios
			done
		#FIM USUARIOS
		#fi
		;;
		"GRUPOS")
		#if [ $SUB_OU -eq "GRUPOS" ]; then
			i=1
			#for i in $countAllGroups ; do
			#echo "Chegou no laco GRUPOS... $i"
			#while ( $i=1 <= $countAllGroups ); do
			until [ $i = $countAllGroups ];do
				#echo "Entrou no laco... $i"
				GROUPNAME="${UNIDADE}GRUPO${i}"
				echo "dn: cn=${GROUPNAME},$DNAtualSub
cn: ${GROUPNAME}
givenName: ${GROUPNAME}
mail: ${GROUPNAME}@${DOMAINNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE
				
				echo " " >> $FILE_BASE
			
				i=`expr 1 + $i`
			# Fim grupos
			done
		#FIM GRUPOS
		#fi
		;;
		"COMPUTADORES")
		#if [ $SUB_OU -eq "COMPUTADORES" ]; then
			i=1
			#for i in $countAllComputers ; do			
			until [ $i = $countAllComputers ];do
				COMPUTERNAME="${UNIDADE}COMPUTER${i}$"
				echo "dn: cn=${COMPUTERNAME},$DNAtualSub
cn: ${COMPUTERNAME}
givenName: ${COMPUTERNAME}
mail: ${COMPUTERNAME}@${DOMAINNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE
				
				echo " " >> $FILE_BASE
			
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
			until [ $i = $countAllObjects ];do
				OBJECTNAME="${UNIDADE}OBJ${i}$"
				echo "dn: cn=${OBJECTNAME},$DNAtualSub
cn: ${OBJECTNAME}
givenName: ${OBJECTNAME}
mail: ${OBJECTNAME}@${DOMAINNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE
				
				echo " " >> $FILE_BASE
			
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


echo "Gravado em: $DIR_NAME"
