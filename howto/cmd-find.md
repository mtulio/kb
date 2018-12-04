# *nix command: Find

## mtime

* Find files older than 2 days:

`find /path/to/files* -mtime +5`

* Find and remove files older than 2 days:

`find /path/to/files* -mtime +5 -exec rm -rf {}\;`
