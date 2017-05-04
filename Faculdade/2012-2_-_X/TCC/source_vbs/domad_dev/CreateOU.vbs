' http://msdn.microsoft.com/en-us/library/windows/desktop/aa705902(v=vs.85).aspx
' Create AD LDS Organizational Unit.

Option Explicit

Dim objADAM         ' Binding object.
Dim objOU           ' Organizational unit.
Dim strDescription  ' Description of OU.
Dim strOU           ' Organizational unit.
Dim strPath         ' Binding path.

' String de pesquisa.
strPath = "LDAP://localhost:389/dc=domad,dc=mtulio,dc=eng,dc=br"

WScript.Echo "Pesquisando por: " & strPath

' Especificar a Unidade Organizacional.
strOU = "OU=TestOU"
strDescription = "AD LDS Test Organizational Unit"

On Error Resume Next

' Bind to object.
Set objADAM = GetObject(strPath)

' Output error if bind fails.
If Err.Number <> vbEmpty Then
    WScript.Echo "Error:   Bind failed."
    WScript.Quit
End If

WScript.Echo "Create:  " & strOU

' Create Organizational Unit.
Set objOU = objADAM.Create("organizationalUnit", strOU)
objOU.Put "description", strDescription
objOU.SetInfo

' Saida: Sucesso ou Erro.
If Err.Number <> vbEmpty Then
    WScript.Echo "Erro:   Falha na criação."
Else
    WScript.Echo "Sucesso: Organizational Unit criada com sucesso."
End If