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

NM_ENTIADE="DOMOL"
NM_ENTIDADE_DESC="MTulio Dominio OpenLDAP"
NM_UNIDADES_SIGLA="GYN ANA URU FOR SPO"
NM_UNIDADES_OU="USUARIOS GRUPOS COMPUTADORES OBJETOS"


countAllUsers = 99
countAllComputers = 60
countAllGroups = 80
countAllObjects = 30


###################################
# 01 - Criando a BASE e a OU Padrao
FILE_BASE="/tmp/01-$NM_ENTIADE.ldif"

cat << EOF >> $FILE_BASE
dn: $LDAP_BASE
objectClass: top
objectClass: dcObject
objectClass: organization
dc: ${NM_ENTIADE}
o: ${NM_ENTIDADE_DESC}

dn: ou=${NM_ENTIDADE},${LDAP_BASE}
ou: ${NM_ENTIADE}
objectClass: top
objectClass: organizationalUnit

EOF


# Movendo o arquivo gerado para o diretorio
$MOVE $FILE_BASE $DIR_NAME

###################################
# 02 - Criando as OU das Unidades

for iItem in $NM_UNIDADES_SIGLA; do

	UNIDADE=$iItem
	FILE_BASE="/tmp/02-$UNIDADE.ldif"
	DNAtual="ou=${NM_ENTIDADE},${LDAP_BASE}"
	
	echo "dn: ou=${UNIDADE},${DNAtual}
ou: ${UNIDADE}
objectClass: top
objectClass: organizationalUnit" >> $FILE_BASE

	echo " " >> $FILE_BASE

	for iItemSubOU in $NM_UNIDADES_OU; do
	
		SUB_OU="$iTemSubOU"
		UNI_SUBOU="${iItemSubOU}"
		DNAtualSub="ou=${iItemSubOU},${DNAtual}"
		
		echo "dn: ou=${SUB_OU},${DNAtualSub}
ou: ${SUB_OU}
objectClass: top
objectClass: organizationalUnit" >> $FILE_BASE
		echo " " >> $FILE_BASE

		if [ $SUB_OU = "USUARIOS" ]; then
	
			i=1
			for i <= $countAllUsers ; do
				
				USERNAME="${UNIDADE}USER${i}"
				
				echo "dn: cn=${USERNAME},$DNAtualSub
cn: ${USERNAME}
givenName: ${USERNAME}
mail: ${USERNAME}@${DOMAINNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE

				echo " " >> $FILE_BASE
			
				i = `expr 1 + $i`
			# Fim usuarios
			done
		#FIM USUARIOS
		fi
	
		if [ $SUB_OU = "GRUPOS" ]; then
			i=1
			for i <= $countAllUsers ; do			
				GROUPNAME="${UNIDADE}GRUPO${i}"
				echo "dn: cn=${GROUPNAME},$DNAtualSub
cn: ${GROUPNAME}
givenName: ${GROUPNAME}
mail: ${GROUPNAME}@${DOMAINNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE
				
				echo " " >> $FILE_BASE
			
				i = `expr 1 + $i`
			# Fim grupos
			done
		#FIM GRUPOS
		fi
		
		if [ $SUB_OU = "COMPUTADORES" ]; then
			i=1
			for i <= $countAllUsers ; do			
				COMPUTERNAME="${UNIDADE}COMPUTER${i}$"
				echo "dn: cn=${COMPUTERNAME},$DNAtualSub
cn: ${COMPUTERNAME}
givenName: ${COMPUTERNAME}
mail: ${COMPUTERNAME}@${DOMAINNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE
				
				echo " " >> $FILE_BASE
			
				i = `expr 1 + $i`
			# Fim COMPUTADORES
			done
		#FIM COMPUTADORES
		fi
		
		if [ $SUB_OU = "OBJETOS" ]; then
			i=1
			for i <= $countAllUsers ; do			
				OBJECTNAME="${UNIDADE}OBJ${i}$"
				echo "dn: cn=${OBJECTNAME},$DNAtualSub
cn: ${OBJECTNAME}
givenName: ${OBJECTNAME}
mail: ${OBJECTNAME}@${DOMAINNAME}
objectClass: top
objectClass: inetOrgPerson" >> $FILE_BASE
				
				echo " " >> $FILE_BASE
			
				i = `expr 1 + $i`
			# Fim grupos
		
		#FIM OBJETOS
		fi
	# Fim SubOU
	done
	$MOVE $FILE_BASE $DIR_NAME
# Fim Unidades
done