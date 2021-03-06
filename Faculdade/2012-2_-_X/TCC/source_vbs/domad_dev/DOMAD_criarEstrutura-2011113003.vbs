'
'  Name: DOMAD_CreateEstrutura.vbs
'  Copyright: DOMAD MTulio ENG
'  Author: Marco T�lio Rodrigues Braga
'  E-mail: admin@mtulio.eti.br
'  Date: 29/10/2011 02:40
'  Last Change: 30/11/2011
'  Description: Este script foi criado para cria��o 
'	da estrutura organizacional implementada no trabalho 
'	de Conclus�o de Curso. Este script pode ser utilizado 
'	e distribuido de acordo com a necessidade.
'	Sugest�es e contribui��es podem ser enviadas por e-mail.
'

' -> Impede que voc� use uma vari�vel sem cri�-la
Option Explicit

' -> Declarando variaveis

' Atributos do Objeto
Dim strDescription, userName, userNamePrefix, sAMAccountName

' Variaveis Auxiliares
Dim i, iItem, iTemSubOU
Dim strOU, strPath, strOUBase, strUnitSigla, strNameComp, strSn, strCompany, strPrincipalName, userNamePart, strComputerNamePart
Dim strComputerName, strOS, strSP
Dim strCn, strCnPart, strName, struNCName, struNCNamePart, strDescriptionPart

' Variaveis DN
Dim DNPai, DNPai2, DNUser, DNAtual, DNFilho, DNComp

' Variaveis de Objeto
Dim objDOMAD, objOU,  objOUPai, strOUOrg, objUser

' Quantidade de objetos a serem criados - INFORME
Dim countAllUsers, countAllComputers, countAllGroups, countAllObjects
countAllUsers = 99
countAllComputers = 60
countAllGroups = 80
countAllObjects = 30

' Valores para Testes
'countAllUsers = 9
'countAllComputers = 6
'countAllGroups = 8
'countAllObjects = 3

' Manipulacao de Arquivos
' Log File
Dim myFSO, objFileWrite, myLog
Dim DATE_AAAAMMDDHHmmss, DATE_DDMMAAAAHHmmss, HOUR_DD, HOUR_MM, HOUR_AAAA, HOUR_HH, HOUR_min, HOUR_ss

' Essa funcao deve ser chamada sempre que seja 
' necessario coletar a hora atual
Sub hourNow(HOUR_DD, HOUR_MM, HOUR_AAAA, HOUR_HH, HOUR_min, HOUR_ss)
	HOUR_DD = DatePart("d",Now())
	HOUR_MM = DatePart("m",Now())
	HOUR_AAAA = DatePart("yyyy",Now())
	HOUR_HH = DatePart("h",Now())
	HOUR_min = DatePart("n",Now())
	HOUR_ss = DatePart("s",Now())
End Sub

Sub getDateStr(dateStr)
	hourNow HOUR_DD, HOUR_MM, HOUR_AAAA, HOUR_HH, HOUR_min, HOUR_ss
	dateStr = HOUR_DD & "/" & HOUR_MM & "/" & HOUR_AAAA & "_" & HOUR_HH & ":" & HOUR_min & ":" & HOUR_ss
End Sub

Sub getDateFilenameStr(dateStr)
	hourNow HOUR_DD, HOUR_MM, HOUR_AAAA, HOUR_HH, HOUR_min, HOUR_ss
	DATE_AAAAMMDDHHmmss = HOUR_AAAA & "-" & HOUR_MM & "-" & HOUR_DD & "_" & HOUR_HH & "-" & HOUR_min & "-" & HOUR_ss
End Sub

' Arquivo p/ gravar o tempo de execucao
getDateFilenameStr DATE_AAAAMMDDHHmmss
myLog = "time_" & DATE_AAAAMMDDHHmmss & ".log"

' Criando arquivo
Set myFSO = CreateObject("Scripting.FileSystemObject")
Set objFileWrite = myFSO.OpenTextFile(myLog, 8, True)

' #####################################
' -> Iniciando o Programa

WScript.Echo "Certifique-se que as OU configuradas neste script n�o existam, caso contrario este script falhar�!"

objFileWrite.WriteLine("###################################")
objFileWrite.WriteLine("		DOMAD")

' Definindo a hora atual e gravando no arquivo:
getDateStr DATE_DDMMAAAAHHmmss
objFileWrite.WriteLine("Start Add to dir: " & DATE_DDMMAAAAHHmmss)
objFileWrite.WriteLine("Adicionando Estrutura no AD!")

' String de pesquisa.
' Bind to object.
strPath = "LDAP://dc=domad,dc=mtulio,dc=eng,dc=br"
Set objOUPai = GetObject(strPath)

' ===	OU=DOMAD
' Criando a OU Base

DNPai = "dc=DOMAD,dc=mtulio,dc=eng,dc=br"
Set objOUPai = GetObject("LDAP://" & DNPai)

strOU = "ou=DOMAD"
strDescription = "MTulio ENG - Dominio AD (DOMAD)"

' Criando a estrutura da Unidade
Set objOU = objOUPai.Create("organizationalUnit", strOU)
objOU.Put "description", strDescription
objOU.SetInfo

' Saida: Sucesso ou Erro.
If Err.Number <> vbEmpty Then
	WScript.Echo "Erro:   Falha na cria��o.\n" & Err.Number
End If

' ===	OU=UNIDADES,OU=DOMAD
' Quatro Unidades Organizacionais para 5 Filiais
' Matriz 2 X 5
Dim vetorOU(1,4)

vetorOU(0,0) = Array("ou=GYN", "Unidade Goiania-GO")
vetorOU(1,0) = Array("ou=USUARIOS","ou=GRUPOS","ou=COMPUTADORES","ou=OBJETOS","ou=Departamentos" )

vetorOU(0,1) = Array("ou=ANA", "Unidade Anapolis-GO")
vetorOU(1,1) = Array("ou=USUARIOS","ou=GRUPOS","ou=COMPUTADORES","ou=OBJETOS" )

vetorOU(0,2) = Array("ou=URU", "Unidade Uruacu-GO")
vetorOU(1,2) = Array("ou=USUARIOS","ou=GRUPOS","ou=COMPUTADORES","ou=OBJETOS" )

vetorOU(0,3) = Array("ou=FOR", "Unidade Fortaleza-CE")
vetorOU(1,3) = Array("ou=USUARIOS","ou=GRUPOS","ou=COMPUTADORES","ou=OBJETOS" )

vetorOU(0,4) = Array("ou=SPO", "Unidade Sao Paulo-SP")
vetorOU(1,4) = Array("ou=USUARIOS","ou=GRUPOS","ou=COMPUTADORES","ou=OBJETOS" )

' === 	Criando as unidades: ou=Unidade,ou=DOMAD
strPath = "LDAP://ou=DOMAD,dc=DOMAD,dc=mtulio,dc=eng,dc=br"

	For iItem=0 To UBound(vetorOU,2) 
		DNPai = "ou=DOMAD,dc=DOMAD,dc=mtulio,dc=eng,dc=br"
		DNAtual = vetorOU(0,iItem)(0)
		
		Set objOUPai = GetObject("LDAP://" & DNPai)
		
		' Buscando a Unidade Organizacional no Vetor
		strOU = DNAtual
		strDescription = vetorOU(0,iItem)(1)
		
		strOUOrg = strOU
		
		'WScript.Echo "Criando:  " & strOU & "," & DNPai
		
		' Criando a estrutura da Unidade
		Set objOU = objOUPai.Create("organizationalUnit", strOU)
		objOU.Put "description", strDescription
		objOU.SetInfo
		
		' Saida: Sucesso ou Erro.
		If Err.Number <> vbEmpty Then
			WScript.Echo "Erro:   Falha na cria��o."
		End If
		
		DNPai = DNAtual & "," & DNPai
		' Criando a estrutura Basica
		For iTemSubOU=0 To UBound(vetorOU(1,iItem))
			DNFilho = lcase(vetorOU(1,iItem)(iTemSubOU))
			Set objOUPai = GetObject("LDAP://" & DNPai)
			strOU = lcase(vetorOU(1,iItem)(iTemSubOU))
			
			' Criando a estrutura da Unidade
			Set objOU = objOUPai.Create("organizationalUnit", strOU)
			objOU.SetInfo
		
			' Saida: Sucesso ou Erro.
			If Err.Number <> vbEmpty Then
				WScript.Echo "Erro:   Falha na cria��o."
			End If
			
			strCompany = "MTulio ENG"
			DNPai2 = DNFilho & "," & DNPai
				
			Set objOUPai = GetObject("LDAP://" & DNPai2)
			
			' Populando a base com Usuarios
			If strOU = "ou=usuarios" Then			
				For i = 1 To countAllUsers
					If (i < 10) Then 
						strSn = " User 0" & i
						userNamePart = "USER0" & i
					Else
						strSn = " User " & i
						userNamePart = "USER" & i
					End if
					If strOUOrg = "ou=GYN" Then
						strUnitSigla = "GYN"
						strNameComp = strUnitSigla & strSn
						DNUser = "cn=" & strNameComp
						userName = strUnitSigla & userNamePart
						strPrincipalName = userName & "@domad.mtulio.eng.br"
						Set objUser = objOUPai.Create("User", DNUser) 
						objUser.sAMAccountName = userName
						objUser.givenName = strUnitSigla
						objUser.sn = strSn
						objUser.SetInfo
						objUser.userPrincipalName= strprincipalname
						objUser.displayName = strNameComp
						objUser.company = strCompany
						objUser.description = strNameComp
						objUser.userAccountControl = 512			' Ativando a conta
						objUser.pwdLastSet = 0						' Ativando a conta
						objUser.setPassword("" & "123@qwe" & "")	' Definindo senha
						objUser.SetInfo
					End if
					
					If strOUOrg = "ou=ANA" Then
						strUnitSigla = "ANA"
						strNameComp = strUnitSigla & strSn
						DNUser = "cn=" & strNameComp
						userName = strUnitSigla & userNamePart
						strPrincipalName = userName & "@domad.mtulio.eng.br"
						Set objUser = objOUPai.Create("User", DNUser) 
						objUser.sAMAccountName = userName
						objUser.givenName = strUnitSigla
						objUser.sn = strSn
						objUser.SetInfo
						objUser.userPrincipalName= strprincipalname
						objUser.displayName = strNameComp
						objUser.company = strCompany
						objUser.description = strNameComp
						objUser.userAccountControl = 512
						objUser.pwdLastSet = 0
						objUser.setPassword("" & "123@qwe" & "")
						objUser.SetInfo
					End if
					
					If strOUOrg = "ou=URU" Then
						strUnitSigla = "URU"
						strNameComp = strUnitSigla & strSn
						DNUser = "cn=" & strNameComp
						userName = strUnitSigla & userNamePart
						strPrincipalName = userName & "@domad.mtulio.eng.br"
						Set objUser = objOUPai.Create("User", DNUser) 
						objUser.sAMAccountName = userName
						objUser.givenName = strUnitSigla
						objUser.sn = strSn
						objUser.SetInfo
						objUser.userPrincipalName= strprincipalname
						objUser.displayName = strNameComp
						objUser.company = strCompany
						objUser.description = strNameComp
						objUser.userAccountControl = 512
						objUser.pwdLastSet = 0
						objUser.setPassword("" & "123@qwe" & "")
						objUser.SetInfo
					End if
					
					If strOUOrg = "ou=FOR" Then
						strUnitSigla = "FOR"
						strNameComp = strUnitSigla & strSn
						DNUser = "cn=" & strNameComp
						userName = strUnitSigla & userNamePart
						strPrincipalName = userName & "@domad.mtulio.eng.br"
						Set objUser = objOUPai.Create("User", DNUser) 
						objUser.sAMAccountName = userName
						objUser.givenName = strUnitSigla
						objUser.sn = strSn
						objUser.SetInfo
						objUser.userPrincipalName= strprincipalname
						objUser.displayName = strNameComp
						objUser.company = strCompany
						objUser.description = strNameComp
						objUser.userAccountControl = 512
						objUser.pwdLastSet = 0
						objUser.setPassword("" & "123@qwe" & "")
						objUser.SetInfo
					End if
					
					If strOUOrg = "ou=SPO" Then
						strUnitSigla = "SPO"
						strNameComp = strUnitSigla & strSn
						DNUser = "cn=" & strNameComp
						userName = strUnitSigla & userNamePart
						strPrincipalName = userName & "@domad.mtulio.eng.br"
						Set objUser = objOUPai.Create("User", DNUser) 
						objUser.sAMAccountName = userName
						objUser.givenName = strUnitSigla
						objUser.sn = strSn
						objUser.SetInfo
						objUser.userPrincipalName= strprincipalname
						objUser.displayName = strNameComp
						objUser.company = strCompany
						objUser.description = strNameComp
						objUser.userAccountControl = 512
						objUser.pwdLastSet = 0
						objUser.setPassword("" & "123@qwe" & "")
						objUser.SetInfo
					End if
				Next
			' Fim ou=usuarios
			End if
			' Populando a OU Grupos
			If strOU = "ou=grupos" Then
				strDescription = "Grupos - " & strDescription
				For i = 1 To countAllGroups
					If (i < 10) Then 
						strCnPart = "GRUPO0" & i
					Else
						strCnPart = "GRUPO" & i
					End if
					If strOUOrg = "ou=GYN" Then
						strUnitSigla = "GYN"
						sAMAccountName = strUnitSigla & strCnPart
						strCn = strUnitSigla & strCnPart
						Set objUser = objOUPai.Create("Group", "cn=" & strCn)
						objUser.cn = strCn
						objUser.sAMAccountName = sAMAccountName
						objUser.description = strDescription
						objUser.SetInfo
					' End GYN
					End If
					
					If strOUOrg = "ou=ANA" Then
						strUnitSigla = "ANA"
						sAMAccountName = strUnitSigla & strCnPart
						strCn = strUnitSigla & strCnPart
						Set objUser = objOUPai.Create("Group", "cn=" & strCn)
						objUser.cn = strCn
						objUser.sAMAccountName = sAMAccountName
						objUser.description = strDescription
						objUser.SetInfo
					' End ANA
					End If
					
					If strOUOrg = "ou=URU" Then
						strUnitSigla = "URU"
						sAMAccountName = strUnitSigla & strCnPart
						strCn = strUnitSigla & strCnPart
						Set objUser = objOUPai.Create("Group", "cn=" & strCn)
						objUser.cn = strCn
						objUser.sAMAccountName = sAMAccountName
						objUser.description = strDescription
						objUser.SetInfo
					' End URU
					End If
					
					If strOUOrg = "ou=FOR" Then
						strUnitSigla = "FOR"
						sAMAccountName = strUnitSigla & strCnPart
						strCn = strUnitSigla & strCnPart
						Set objUser = objOUPai.Create("Group", "cn=" & strCn)
						objUser.cn = strCn
						objUser.sAMAccountName = sAMAccountName
						objUser.description = strDescription
						objUser.SetInfo
					' End FOR
					End If
					
					If strOUOrg = "ou=SPO" Then
						strUnitSigla = "SPO"
						sAMAccountName = strUnitSigla & strCnPart
						strCn = strUnitSigla & strCnPart
						Set objUser = objOUPai.Create("Group", "cn=" & strCn)
						objUser.cn = strCn
						objUser.sAMAccountName = sAMAccountName
						objUser.description = strDescription
						objUser.SetInfo
					' End SPO
					End If
				Next
			' Fim ou=grupos
			End if

			' Populando a base com Computadores
			If strOU = "ou=computadores" Then
				strOS = "Microsoft Windows 7 Professinal"
				strSP = "Service Pack 20"
				For i = 1 To countAllComputers
					If (i < 10) Then 
						strComputerNamePart = "COMP0" & i
					Else
						strComputerNamePart = "COMP" & i
					End if
					If strOUOrg = "ou=GYN" Then
						strUnitSigla = "GYN"
						strComputerName = strUnitSigla & strComputerNamePart
						DNComp = "cn=" & strComputerName
						Set objUser = objOUPai.Create("Computer", DNComp) 		' Criando objeto
						objUser.cn = strComputerName							' Atributo Obrigatorio
						objUser.Description = strComputerName					' Atributo Obrigatorio
						objUser.distinguishedName = DNComp & DNPai				' Atributo Obrigatorio
						objUser.OperatingSystem = strOS							' Atributo Opcional
						objUser.OperatingSystemServicePack = strSP				' Atributo Opcional
						objUser.sAMAccountName = strComputerName & "$"			' Definindo senha
						objUser.userAccountControl = 4096						' Ativando a conta 
						objUser.SetInfo
					End If					

					If strOUOrg = "ou=ANA" Then
						strUnitSigla = "ANA"
						strComputerName = strUnitSigla & strComputerNamePart
						DNComp = "cn=" & strComputerName
						Set objUser = objOUPai.Create("Computer", DNComp) 		' Criando objeto
						objUser.cn = strComputerName							' Atributo Obrigatorio
						objUser.Description = strComputerName					' Atributo Obrigatorio
						objUser.distinguishedName = DNComp & DNPai				' Atributo Obrigatorio
						objUser.OperatingSystem = strOS							' Atributo Opcional
						objUser.OperatingSystemServicePack = strSP				' Atributo Opcional
						objUser.sAMAccountName = strComputerName & "$"			' Definindo senha
						objUser.userAccountControl = 4096						' Ativando a conta 
						objUser.SetInfo
					End If
					
					If strOUOrg = "ou=URU" Then
						strUnitSigla = "URU"
						strComputerName = strUnitSigla & strComputerNamePart
						DNComp = "cn=" & strComputerName
						Set objUser = objOUPai.Create("Computer", DNComp) 		' Criando objeto
						objUser.cn = strComputerName							' Atributo Obrigatorio
						objUser.Description = strComputerName					' Atributo Obrigatorio
						objUser.distinguishedName = DNComp & DNPai				' Atributo Obrigatorio
						objUser.OperatingSystem = strOS							' Atributo Opcional
						objUser.OperatingSystemServicePack = strSP				' Atributo Opcional
						objUser.sAMAccountName = strComputerName & "$"			' Definindo senha
						objUser.userAccountControl = 4096						' Ativando a conta 
						objUser.SetInfo
					End If
					
					If strOUOrg = "ou=FOR" Then
						strUnitSigla = "FOR"
						strComputerName = strUnitSigla & strComputerNamePart
						DNComp = "cn=" & strComputerName
						Set objUser = objOUPai.Create("Computer", DNComp) 		' Criando objeto
						objUser.cn = strComputerName							' Atributo Obrigatorio
						objUser.Description = strComputerName					' Atributo Obrigatorio
						objUser.distinguishedName = DNComp & DNPai				' Atributo Obrigatorio
						objUser.OperatingSystem = strOS							' Atributo Opcional
						objUser.OperatingSystemServicePack = strSP				' Atributo Opcional
						objUser.sAMAccountName = strComputerName & "$"			' Definindo senha
						objUser.userAccountControl = 4096						' Ativando a conta 
						objUser.SetInfo
					End If
					
					If strOUOrg = "ou=SPO" Then
						strUnitSigla = "SPO"
						strComputerName = strUnitSigla & strComputerNamePart
						DNComp = "cn=" & strComputerName
						Set objUser = objOUPai.Create("Computer", DNComp) 		' Criando objeto
						objUser.cn = strComputerName							' Atributo Obrigatorio
						objUser.Description = strComputerName					' Atributo Obrigatorio
						objUser.distinguishedName = DNComp & DNPai				' Atributo Obrigatorio
						objUser.OperatingSystem = strOS							' Atributo Opcional
						objUser.OperatingSystemServicePack = strSP				' Atributo Opcional
						objUser.sAMAccountName = strComputerName & "$"			' Definindo senha
						objUser.userAccountControl = 4096						' Ativando a conta 
						objUser.SetInfo
					End If	
				Next
			' Fim ou=computadores
			End if
			
			' Populando a base com Mapeamentos de Compartilhamentos
			If strOU = "ou=objetos" Then
				strDescription = "Compartilhamentos - " & strDescription
				For i = 1 To countAllObjects
					If (i < 10) Then 
						strCnPart = "SHARE0" & i
						struNCNamePart = "001\share0" & i
						strDescriptionPart = " - Compartilhamento 0" & i
					Else
						strCnPart = "SHARE" & i
						struNCNamePart = "001\share" & i
						strDescriptionPart = " - Compartilhamento " & i
					End if
					If strOUOrg = "ou=GYN" Then
						strUnitSigla = "GYN"
						strCn = strUnitSigla & strCnPart
						struNCName = "\\srv" & strUnitSigla & struNCNamePart
						strDescription = strUnitSigla & strDescriptionPart
						Set objUser = objOUPai.Create("Volume", "cn=" & strCn) 
						objUser.cn = strCn
						objUser.uNCName = struNCName
						objUser.uNCName = strDescription
						objUser.SetInfo
					' End GYN
					End If
					
					If strOUOrg = "ou=ANA" Then
						strUnitSigla = "ANA"
						strCn = strUnitSigla & strCnPart
						struNCName = "\\srv" & strUnitSigla & struNCNamePart
						strDescription = strUnitSigla & strDescriptionPart
						Set objUser = objOUPai.Create("Volume", "cn=" & strCn) 
						objUser.cn = strCn
						objUser.uNCName = struNCName
						objUser.uNCName = strDescription
						objUser.SetInfo
					' End ANA
					End If
					
					If strOUOrg = "ou=URU" Then
						strUnitSigla = "URU"
						strCn = strUnitSigla & strCnPart
						struNCName = "\\srv" & strUnitSigla & struNCNamePart
						strDescription = strUnitSigla & strDescriptionPart
						Set objUser = objOUPai.Create("Volume", "cn=" & strCn) 
						objUser.cn = strCn
						objUser.uNCName = struNCName
						objUser.uNCName = strDescription
						objUser.SetInfo
					' End URU
					End If
					
					If strOUOrg = "ou=FOR" Then
						strUnitSigla = "FOR"
						strCn = strUnitSigla & strCnPart
						struNCName = "\\srv" & strUnitSigla & struNCNamePart
						strDescription = strUnitSigla & strDescriptionPart
						Set objUser = objOUPai.Create("Volume", "cn=" & strCn) 
						objUser.cn = strCn
						objUser.uNCName = struNCName
						objUser.uNCName = strDescription
						objUser.SetInfo
					' End FOR
					End If
					
					If strOUOrg = "ou=SPO" Then
						strUnitSigla = "SPO"
						strCn = strUnitSigla & strCnPart
						struNCName = "\\srv" & strUnitSigla & struNCNamePart
						strDescription = strUnitSigla & strDescriptionPart
						Set objUser = objOUPai.Create("Volume", "cn=" & strCn) 
						objUser.cn = strCn
						objUser.uNCName = struNCName
						objUser.uNCName = strDescription
						objUser.SetInfo
					' End SPO
					End If
				Next
			' Fim ou=objetos
			End if
		Next
	Next

' Definindo a hora atual e gravando no arquivo:
getDateStr DATE_DDMMAAAAHHmmss
objFileWrite.WriteLine("Finish Add to dir: " & DATE_DDMMAAAAHHmmss)
objFileWrite.WriteLine("Estrutura adicionada com sucesso!")
objFileWrite.WriteLine("###################################")
	
WScript.Echo "Script executado com sucesso."

' Sugest�es para melhoria deste script
' 1) Adicionar tratamento de excess�es. Exemplo: Verificar se uma determinada OU existe e n�o tentar cri�-la
' 2) Criar fun��es e  separar melhor o codigo para maior organiza��o