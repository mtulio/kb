# Mail scripts

## sync-gmail2gmail.sh

Sync from G/gmail account to another.

Pre reqs:
- Install util `imapsync`
- Enable IMAP proto should be enabled in both accounts [1]
- Enble loging with less-secure apps in your account [2]
- Test login in IMAP server [3]

Refs:
 1. [Enable IMAP in GMAIL Account](https://support.google.com/mail/answer/7126229?visit_id=1-636285916825620980-2983546906&hl=pt-BR&rd=1)
 2. [How to allow less secure apps](https://support.google.com/accounts/answer/6010255) and [Allowing less secure apps](https://myaccount.google.com/u/4/lesssecureapps?pageId=none&pli=1)
 3. Testing login in GMAIL IMAP server:

```
$  ncat --ssl -C  imap.gmail.com 993
* OK Gimap ready for requests from 2804:14d:baa6:2999::7 y7mb52459270vsd
a LOGIN "ACCOUNT@G_APP_DOMAIN" "MY_G_ACCOUNT_PASSWORD"
* CAPABILITY IMAP4rev1 UNSELECT IDLE NAMESPACE QUOTA ID XLIST CHILDREN X-GM-EXT-1 UIDPLUS COMPRESS=DEFLATE ENABLE MOVE CONDSTORE ESEARCH UTF8=ACCEPT LIST-EXTENDED LIST-STATUS LITERAL- SPECIAL-USE APPENDLIMIT=35651584
a OK ACCOUNT@G_APP_DOMAIN authenticated (Success)

```
