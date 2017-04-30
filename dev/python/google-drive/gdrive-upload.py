from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive

gauth = GoogleAuth()

drive = GoogleDrive(gauth)

file1 = drive.CreateFile({'title': 'Hello.txt'})

file1.SetContentString('Hello')

file1.Upload() # Files.insert()

