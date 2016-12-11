    Option Explicit
    Dim objRootLDAP, objContainer, objUser, objShell
    Dim objExcel, objSpread, intRow
    Dim strUser, strOU, strSheet
    Dim strCN, strSam, strFirst, strLast, strPWD, strdepartment, strprincipalname, strTitulo, strMensagem, strcompany, strdescription, strMail, strTel, strFunc

	' OU para criação dos novos usuarios
    strOU = "OU=TEMP-CREATE ,"
    ' Arquivo aonde contem os dados dos usuarios
	'	Sintaxe: <1-username>|<2-nome_completo>|<3-primeiro_nome>|<4-sobrenome>|<5-senha>|<6-descricao>|<8-Depto>|<7-Comp>|<9-Mail>|<10-Tel>|<11-Func>
	strSheet = "\\10.5.22.200\scripts$\zz-01.Usuarios\METROPOLITANA.xls"

    ' Bind to Active Directory, Users container.
    Set objRootLDAP = GetObject("LDAP://rootDSE")
    Set objContainer = GetObject("LDAP://" & strOU & objRootLDAP.Get("defaultNamingContext"))

    ' Open the Excel spreadsheet
	Set objExcel = CreateObject("Excel.Application")
    Set objSpread = objExcel.Workbooks.Open(strSheet)
    intRow = 3 'Row 1 often contains headings

    ' Here is the ‘DO…Loop’ that cycles through the cells
    ' Note intRow, x must correspond to the column in strSheet
    Do Until objExcel.Cells(intRow,1).Value = ""
    strSam = Trim(objExcel.Cells(intRow, 1).Value)
    strCN = Trim(objExcel.Cells(intRow, 2).Value)
    strFirst = Trim(objExcel.Cells(intRow, 3).Value)
    strLast = Trim(objExcel.Cells(intRow, 4).Value)
    strPWD = Trim(objExcel.Cells(intRow, 5).Value)
    strprincipalname = strSam & "@palacio.go.gov.br"
    strdescription = Trim(objExcel.Cells(intRow, 6).Value)
	strdepartment = Trim(objExcel.Cells(intRow, 8).Value)
    strcompany = Trim(objExcel.Cells(intRow, 7).Value)
	strMail = Trim(objExcel.Cells(intRow, 9).Value)
	strTel = Trim(objExcel.Cells(intRow, 10).Value)
	strFunc = Trim(objExcel.Cells(intRow, 11).Value)
	
    ' Build the actual User from data in strSheet.
    Set objUser = objContainer.Create("User", "cn=" & strCN)
    objUser.sAMAccountName = strSam
    objUser.givenName = strFirst
    objUser.sn = strLast
    objUser.SetInfo
	
    objUser.userPrincipalName= strprincipalname
    objUser.displayName = strCN
    objUser.department = strdepartment
    objUser.company = strcompany
    objUser.description = strdescription
	objUser.mail = strMail
	objUser.telephoneNumber = strTel
	objUser.title = strFunc
	
    ' Separate section to enable account with its password
    objUser.userAccountControl = 512
    objUser.pwdLastSet = 0
    'objUser.setPassword("rp@pal")
	objUser.setPassword("" & strPWD & "")
    objUser.SetInfo

    intRow = intRow + 1
    Loop
    objExcel.Quit

    strTitulo = "COMANDO CONCLUIDO!!"
    strMensagem = _
    "USUARIO(S) CRIADO(S) COM SUCESSO!" & vbcrlf & vbcrlf & _
    " Mova para OU correta." & vbcrlf & _
    "" & vbcrlf & _
    ""
    'BtnCode = WshShell.Popup(strMensagem, 5, "Informação:", 64 + 0)
    msgbox strMensagem, 0 + 64, strTitulo

    WScript.Quit