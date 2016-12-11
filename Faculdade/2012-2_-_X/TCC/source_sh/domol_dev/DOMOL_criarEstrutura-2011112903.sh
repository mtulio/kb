#!/bin/bash
#
#	Name: DOMOL_criarEstrutura.sh
#	Copyright: DOMOL MTulio ENG
#	Author: Marco Tulio Rodrigues Braga
#	E-mail: admin@mtulio.eti.br
#	Date: 01/11/11 06:39
#	Last Change: 29/11/2011
#	Description: Este script foi desenvolvido para criacao 
#		da estrutura organizacional implementada no 
#		trabalho de Conclusao de Curso. 
#		Este script pode ser utilizado e distribuido 
#		de acordo com a necessidade desde que seja 
#		contribuido novamente para o autor.
#
#	Details:
#
#	Sugestões de melhorias: 
#		- ARQUIVOS LDIF: Criar um analisador Lexico dos 
#		arquivos LDIF's gerados para evitar falhas na 
#		insercao dos dados na base, podendo tambem 
#		ser criada uma analisador sintatico e semantico, 
#		criando um mini-compilador. Com isso eh possivel 
#		evitar erros na insercao de registros 
#		em arquivos LDIF grandes.
#		- Pode-se adicionar a verificacao das strings 
#		validas em cada dn tanto como o tamanho de cada 
#		atributo.
#
#	Problems: Implementar DoWhile(C++) no laco da populacao 
#		do diretorio						

###################################
# 0 - Definindo variaveis
# Comandos
MOVE=`which mv`
LDAPADD=`which ldapadd`

LDAPADD_ADMIN_AUTH="-x -D cn=administrador,dc=domol,dc=mtulio,dc=eng,dc=br -w 123456"

# Sera registrado o tempo de execucao para analise 
# de performance
HOUR_NOW="date +%d/%m/%Y_%T"

# Definicao: Arquivos e Diretorios
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

# Informacoes sobre a estrutura de Diretorio

DOMAINNAME="domol.mtulio.eng.br"
LDAP_BASE="dc=domol,dc=mtulio,dc=eng,dc=br"
LDAP_BASE_OU="ou=DOMOL,dc=domol,dc=mtulio,dc=eng,dc=br"
LDAP_BINDDN="cn=administrador,dc=domol,dc=mtulio,dc=eng,dc=br"

# OU Generica para usuarios de sistemas (LAM, phpldapadmin)
LDAP_BASE_SYSTEM="ou=SYSTEM,dc=domol,dc=mtulio,dc=eng,dc=br"

NM_ENTIDADE="DOMOL"
NM_ENTIDADE_DESC="MTulio Dominio OpenLDAP"
NM_UNIDADES_SIGLA="GYN ANA URU FOR SPO"
NM_UNIDADES_OU="USUARIOS GRUPOS COMPUTADORES OBJETOS"

# Sempre definir um objeto a mais, pois o laco 
# verifica antes de sua execucao

countAllUsers=9
countAllComputers=6
countAllGroups=8
countAllObjects=3

###################################
# Definicoes de Funcoes para melhor 
# "visualizacao" do codigo

fc_createOuUsuarios() {
	i=0
        until [ $i = $countAllUsers ];do
        	USERNAME="${UNIDADE}USER${i}"
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
# Fim funcao criar OU Usuarios
}

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
EOF

# Movendo o arquivo gerado para o diretorio correto
$MOVE $FILE_BASE $DIR_NAME

# 02 - Criando as OU da Entidade
FILE_BASE="/tmp/02-$NM_ENTIDADE.ldif"

cat << EOF >> $FILE_BASE
dn: ou=$NM_ENTIDADE,${LDAP_BASE}
ou: ${NM_ENTIDADE}
objectClass: top
objectClass: organizationalUnit
EOF

# Movendo o arquivo gerado para o diretorio correto
$MOVE $FILE_BASE $DIR_NAME

# 02 - Criando as OU para Sistemas
FILE_BASE="/tmp/02-SYSTEM.ldif"

cat << EOF >> $FILE_BASE
dn: ou=SYSTEM,${LDAP_BASE}
ou: SYSTEM
description: OU for Systems Objects
objectClass: top
objectClass: organizationalUnit

dn: ou=USERS,${LDAP_BASE_SYSTEM}
ou: USERS
description: OU for Systems Users
objectClass: top
objectClass: organizationalUnit

dn: ou=COMPUTERS,${LDAP_BASE_SYSTEM}
ou: COMPUTERS
description: OU for Systems Computers
objectClass: top
objectClass: organizationalUnit

dn: ou=GROUPS,${LDAP_BASE_SYSTEM}
ou: GROUPS
description: OU for Systems Groups
objectClass: top
objectClass: organizationalUnit

dn: ou=OTHERS,${LDAP_BASE_SYSTEM}
ou: OTHERS
description: OU for Others Systems Objects
objectClass: top
objectClass: organizationalUnit
EOF

# Movendo o arquivo gerado para o diretorio correto
$MOVE $FILE_BASE $DIR_NAME

# 02 - Criando a estrutura da SAMBA
FILE_BASE="/tmp/02-SAMBA.ldif"

SAMBA_DOMAIN="DOMOL"
# O SID da maquina pode ser obtido pelo comando:
# $ net getlocalsid
# A variavel pode ser utilizada:
# SAMBA_SID="`net getlocalsid |awk -F "is: " '{print$2}'`"
SAMBA_SID="S-1-5-21-3420771710-2698102504-902350248"

cat << EOF >> $FILE_BASE
dn: sambaDomainName=${SAMBA_DOMAIN},${LDAP_BASE}
sambaDomainName: ${SAMBA_DOMAIN}
sambaSID: ${SAMBA_SID}
sambaAlgorithmicRidBase: 1000
objectClass: sambaDomain
sambaMinPwdLength: 5
sambaPwdHistoryLength: 0
sambaLogonToChgPwd: 0
sambaMaxPwdAge: -1
sambaMinPwdAge: 0
sambaLockoutDuration: 30
sambaLockoutObservationWindow: 30
sambaLockoutThreshold: 0
sambaForceLogoff: -1
sambaRefuseMachinePwdChange: 0
EOF

# Movendo o arquivo gerado para o diretorio correto
$MOVE $FILE_BASE $DIR_NAME

###################################
# 03 - Criando as OU das Unidades

for iItem in $NM_UNIDADES_SIGLA; do
	UNIDADE=$iItem
	FILE_BASE="/tmp/03-$UNIDADE.ldif"
	DNAtual="ou=$NM_ENTIDADE,${LDAP_BASE}"
	
	echo "dn: ou=$UNIDADE,${DNAtual}
ou: ${UNIDADE}
objectClass: top
objectClass: organizationalUnit" >> $FILE_BASE

	for iItemSubOU in $NM_UNIDADES_OU; do
		SUB_OU=$iItemSubOU
		UNI_SUBOU="${iItemSubOU}"
		DNAtualSub="ou=${iItemSubOU},ou=${UNIDADE},${DNAtual}"
		cat << EOF >> $FILE_BASE

EOF
		echo "dn: ${DNAtualSub}
ou: ${SUB_OU}
objectClass: top
objectClass: organizationalUnit" >> $FILE_BASE

		case "$SUB_OU" in
		"USUARIOS") fc_createOuUsuarios;;
#			i=0
#			until [ $i = $countAllUsers ];do
#				USERNAME="${UNIDADE}USER${i}"
#				cat << EOF >> $FILE_BASE
#
#EOF
#				echo "dn: cn=${USERNAME},$DNAtualSub
#cn: ${USERNAME}
#givenName: ${USERNAME}
#mail: ${USERNAME}@${DOMAINNAME}
#sn: $UNIDADE User
#objectClass: top
#objectClass: inetOrgPerson" >> $FILE_BASE
#
#			i=`expr 1 + $i`
#			# Fim usuarios
#			done
#		#FIM USUARIOS
#		#fi
#		;;
		"GRUPOS")
			i=0
			until [ $i = $countAllGroups ];do
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
			i=0
			until [ $i = $countAllComputers ];do
				COMPUTERNAME="${UNIDADE}COMPUTER${i}$"
				cat << EOF >> $FILE_BASE

EOF
				echo "dn: cn=${COMPUTERNAME},$DNAtualSub
cn: ${COMPUTERNAME}
sn: Hostname: ${COMPUTERNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE
				i=`expr 1 + $i`
			# Fim COMPUTADORES
			done
		#FIM COMPUTADORES
		#fi
		;;
		"OBJETOS")
			i=1
			until [ $i = `expr $countAllObjects + 1` ];do
				OBJECTNAME="${UNIDADE}OBJ-SHARE${i}"
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
		*)echo "Erro desconhecido na criacao das OU's por unidade";;
	esac
	# Fim SubOU
	done
	$MOVE $FILE_BASE $DIR_NAME
# Fim Unidades
done

echo "Fim - Criar LDIF: `$HOUR_NOW`" >> $FILE_LOG_TIME
echo "Start Add to dir: `$HOUR_NOW`" >> $FILE_LOG_TIME

# Executando os scripts na ordem de que o "Pai" seja criado primeiro que o "Filho"

for LDIF_LIST in $(ls -l $DIR_NAME/01-*.ldif | awk -F " " '{print$9}');do
	$LDAPADD -f $LDIF_LIST $LDAPADD_ADMIN_AUTH >> $FILE_LOG_LDAP_OPE
done

for LDIF_LIST in $(ls -l $DIR_NAME/02-*.ldif | awk -F " " '{print$9}');do
	$LDAPADD -f $LDIF_LIST $LDAPADD_ADMIN_AUTH >> $FILE_LOG_LDAP_OPE
done

for LDIF_LIST in $(ls -l $DIR_NAME/03-*.ldif | awk -F " " '{print$9}');do
	$LDAPADD -f $LDIF_LIST $LDAPADD_ADMIN_AUTH >> $FILE_LOG_LDAP_OPE
done


echo "Finish Add to dir: `$HOUR_NOW`" >> $FILE_LOG_TIME
echo "###################################" >> $FILE_LOG_TIME

#cat $FILE_LOG_TIME

echo "LDIF's criados em: $DIR_NAME" |tee -a $FILE_LOG_TIME
