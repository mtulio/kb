' http://gallery.technet.microsoft.com/scriptcenter/
' ====================================================================
' Verificar se a Unidade Organizacional Existe
' ====================================================================
'> IMPLEMENTAR

' Criando uma Unidade Organizacional

' 01 - http://gallery.technet.microsoft.com/scriptcenter/84bcc147-917c-4097-afe5-6438857c8990
'Set objDomain = GetObject("LDAP://dc=fabrikam,dc=com") 
'Set objOU = objDomain.Create("organizationalUnit", "ou=Management"o 


' 02 - http://gallery.technet.microsoft.com/scriptcenter/62435baa-8b67-4576-a46e-d68d7ad12958

'Set objOU1 = GetObject("LDAP://ou=OU1,dc=na,dc=fabrikam,dc=com") 
'Set objOU2 = objOU1.Create("organizationalUnit", "ou=OU2"o 

' ====================================================================
On Error Resume Next 
' Criando estrutura Basica - Entidade

Set objDC = GetObject("LDAP://dc=DOMAD,dc=mtulio,dc=eng,dc=br") 
Set objOUEntidade = objDC.Create("organizationalUnit", "ou=DOMAD", o)

' Criando as Organizacoes

'Set ObjOUEntidade = GetObject("LDAP://ou=DOMAD,dc=DOMAD,dc=mtulio,dc=eng,dc=br")

' Unidade Goianiar
'Set ObjUnidade = ObjOUEntidade.Create("organizationalUnit", "ou=GYN"o

'Set objUniDN = GetObject("LDAP://ou=GYN,ou=DOMAD,dc=DOMAD,dc=mtulio,dc=eng,dc=br")
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=USUARIOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=GRUPOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=COMPUTADORES"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=OBJETOS"o

' Unidade Anapolis
'Set ObjUnidade = ObjOUEntidade.Create("organizationalUnit", "ou=ANA"o

'Set objUniDN = GetObject("LDAP://ou=ANA,ou=DOMAD,dc=DOMAD,dc=mtulio,dc=eng,dc=br")
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=USUARIOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=GRUPOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=COMPUTADORES"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=OBJETOS"o

' Unidade Uruacu
'Set ObjUnidade = ObjOUEntidade.Create("organizationalUnit", "ou=URU"o

'Set objUniDN = GetObject("LDAP://ou=URU,ou=DOMAD,dc=DOMAD,dc=mtulio,dc=eng,dc=br")
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=USUARIOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=GRUPOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=COMPUTADORES"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=OBJETOS"o

' Unidade Fortaleza
'Set ObjUnidade = ObjOUEntidade.Create("organizationalUnit", "ou=FOR"o

'Set objUniDN = GetObject("LDAP://ou=FOR,ou=DOMAD,dc=DOMAD,dc=mtulio,dc=eng,dc=br")
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=USUARIOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=GRUPOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=COMPUTADORES"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=OBJETOS"o

' Unidade Sao Paulo
'Set ObjUnidade = ObjOUEntidade.Create("organizationalUnit", "ou=SPO"o

'Set objUniDN = GetObject("LDAP://ou=SPO,ou=DOMAD,dc=DOMAD,dc=mtulio,dc=eng,dc=br")
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=USUARIOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=GRUPOS"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=COMPUTADORES"o
'Set objUniOU = objUniDN.Create("organizationalUnit", "ou=OBJETOS"o
