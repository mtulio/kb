#!/bin/bash

# Sync from GMAIL to GMAIL accounts

USER1_LOGIN='FROM ACCOUNT'
USER1_PASS='FROM ACCOUNT PASS'
USER2_LOGIN='TO ACCOUNT'
USER2_PASS='TO ACCOUNT PASS'
test -f ./sync-gmail2gmail.env && source ./sync-gmail2gmail.env

imapsync \
           --host1 imap.gmail.com \
           --ssl1 \
           --user1 "${USER1_LOGIN}" \
           --password1 "${USER1_PASS}" \
           --host2 imap.gmail.com \
           --ssl2 \
           --user2 "${USER2_LOGIN}" \
           --password2 "${USER2_PASS}" \
           --automap


