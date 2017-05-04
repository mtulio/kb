'Open up the path to save the information into a text file
Dim myFSO, objFileWrite

'Dim NOW
'DIA = DatePart("m",Now())

'HOUR_DD = DatePart("d",Now())
'HOUR_MM = DatePart("m",Now())
'HOUR_AAAA = DatePart("yyyy",Now())
'HOUR_HH = DatePart("h",Now())
'HOUR_min = DatePart("n",Now())
'HOUR_ss = DatePart("s",Now())

'Dim HOUR_DD, HOUR_MM, HOUR_AAAA, HOUR_HH, HOUR_min, HOUR_ss

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

' Formatando data para criacao do arquivo
hourNow HOUR_DD, HOUR_MM, HOUR_AAAA, HOUR_HH, HOUR_min, HOUR_ss
'DATE_DDMMAAAAHHmmss = HOUR_DD & "/" & HOUR_MM & "/" & HOUR_AAAA & "_" & HOUR_HH & ":" & HOUR_min & ":" & HOUR_ss 
DATE_AAAAMMDDHHmmss = HOUR_AAAA & "-" & HOUR_MM & "-" & HOUR_DD & "_" & HOUR_HH & "-" & HOUR_min & "-" & HOUR_ss


Set myFSO = CreateObject("Scripting.FileSystemObject")
Set objFileWrite = myFSO.OpenTextFile("time-"& DATE_AAAAMMDDHHmmss & ".log", 8, True)

objFileWrite.WriteLine("###################################")
objFileWrite.WriteLine("		DOMAD")


' Definindo a hora atual e gravando no arquivo:
'hourNow HOUR_DD, HOUR_MM, HOUR_AAAA, HOUR_HH, HOUR_min, HOUR_ss
'DATE_DDMMAAAAHHmmss = HOUR_DD & "/" & HOUR_MM & "/" & HOUR_AAAA & "_" & HOUR_HH & ":" & HOUR_min & ":" & HOUR_ss 
getDateStr DATE_DDMMAAAAHHmmss
objFileWrite.WriteLine("Start Add to dir: " & DATE_DDMMAAAAHHmmss)
'objFileWrite.WriteLine("Adicionando Estrutura no AD!")

' PROGRAMA
WScript.Echo "Certifique-se que as OU configuradas neste script não existam, caso contrario este script falhará!"
WScript.Sleep 10000

' Definindo a hora atual e gravando no arquivo:
getDateStr DATE_DDMMAAAAHHmmss
'objFileWrite.WriteLine("Estrutura adicionada com sucesso!")
objFileWrite.WriteLine("Finish Add to dir: " & DATE_DDMMAAAAHHmmss)
objFileWrite.WriteLine("###################################")

objFileWrite.Close
SET objFileWrite = NOTHING
SET myFSO = NOTHING

WScript.Echo "FIM!"