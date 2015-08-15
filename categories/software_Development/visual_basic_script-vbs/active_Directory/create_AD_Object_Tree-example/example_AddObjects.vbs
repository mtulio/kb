' Criar objetos do AD

' ================================================================
' ================================================================
' EXAMPLES
' Criação de Usuarios:

' 1 - http://gallery.technet.microsoft.com/scriptcenter/a332ca29-0610-4be4-88f0-63771d04743f
' Demonstration script that creates 1,000 user accounts (named UserNo1, UserNo2, UserNo3, etc.) in the Users container in Active Directory. The script is useful for test scenarios that require multiple user accounts.
Set objRootDSE = GetObject("LDAP://rootDSE") 
 
Set objContainer = GetObject("LDAP://cn=Users," & _ 
    objRootDSE.Get("defaultNamingContext")) 
  
For i = 1 To 1000 
    Set objLeaf = objContainer.Create("User", "cn=UserNo" & i) 
    objLeaf.Put "sAMAccountName", "UserNo" & i 
    objLeaf.SetInfo 
Next 
  
WScript.Echo "1000 Users created." 

' ================================================================
' 2- http://gallery.technet.microsoft.com/scriptcenter/bc330a9b-929d-49fd-8c03-ab69b6fc4fd6
' Creates Active Directory user accounts based on information found in an Excel spreadsheet. 

Dim oRoot  
Dim oDomain 
Dim strName  
Dim strOU  
Dim oOU  
Dim OUFind 
Dim OUName 
Dim count 
Dim s 
count = 0  
OUFind = 0 
strOU = "" 
strName = "" 
OUName = "" 
 
Sub FindOU(ObjOU) 
    For Each FoundObject in ObjOU 
    If StrComp(FoundObject.Name,OUName,vbTextCompare)=0 Then 
        WScript.Echo "The " & FoundObject.Class & " " & FoundObject.Name & " already exists!" 
        WScript.Echo "Press Enter key..." 
        WScript.StdIn.ReadLine 
        OUFind=1 
    End If 
    If FoundObject.class="organizationalUnit" Then 
        FindOU(FoundObject) 
    End If 
    If FoundObject.class="user" Then 
        count=count+1 
    End If 
    Next  
End Sub 
 
'start 
 
Set objArgs = WScript.Arguments  
 
WScript.StdOut.Write "Add User in OU"& vbCrLf 
 
strName =objArgs(0) 
StrOU=left(objArgs(0),len(objArgs(0))-4) 
StrOU=right(StrOU,len(StrOU)-len(GetCurDir)-1) 
Set oRoot   = GetObject("LDAP://rootDSE") 
Set oDomain = GetObject("LDAP://" &oRoot.Get("defaultNamingContext")) 
OUName="OU="&strOU 
 
 
FindOU(oDomain) 
WScript.echo "Total users in AD: " & count 
 
If OUFind=0 Then 
    OUFind=0 
    Set oOU=oDomain.Create("organizationalUnit","ou="&strOU ) 
    oOU.SetInfo 
 
 
    Set objExcel = CreateObject("Excel.Application") 
    Set objWorkbook = objExcel.Workbooks.Open(strName) 
 
    intRow = 2 
    Do Until objExcel.Cells(intRow,1).Value="" 
        OUName="CN=" & objExcel.Cells(intRow,5).Value 
        FindOU(oDomain) 
        If OUFind=0 Then  
            Set objOU = GetObject("LDAP://ou="&strOU&",dc=one,dc=intra,dc=net") 
            Set objUser = objOU.Create("User", "cn=" & objExcel.Cells(intRow,5).Value) 
            objUser.sAMAccountName = objExcel.Cells(intRow, 5).Value 
            objUser.GivenName = objExcel.Cells(intRow, 3).Value 
            objUser.SN = objExcel.Cells(intRow, 2).Value 
            objUser.SetInfo 
            objUser.AccountDisabled = True 
            objUser.SetInfo 
        End If 
        OUFind=0 
    intRow = intRow + 1 
    Loop 
    objExcel.Quit 
    WScript.echo "Ok"  
End If 
 
Function GetCurDir() 
dim Tmp 
dim homeDir 
dim l 
 Tmp=Cstr(WScript.ScriptFullName) 
 l=Len(Tmp) 
 For i=l to 1 Step -1 
 
      If mid(Tmp,i,1)="\" then 
 
         homeDir=Left(Tmp,(i-1)) 
         Exit For 
 
       End if 
 
 Next 
 getCurDir=homeDir 
End Function 

' ================================================================
' ================================================================