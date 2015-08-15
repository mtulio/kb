# Mailman (mailing list manager) scripts

```
* mm_backup_all_lists.sh	: Backup all Mailman lists.
** Get all lists, dump its config files, members and admins and pack its directory
* mm_get_all_members.sh 	: Get all members, from all lists and create a CSV with their members.
** This script is used with Backup Script, but could be changed
```

OBS.:
* All CSV file could be inserted in an DB (or DW) to be used in an BI/Data Mining or wherever you want
