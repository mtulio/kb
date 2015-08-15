# Zimbra Collaboration Suite scripts for Sys Admins

## Data Transformation and Integration using PDI - Pentaho Data Integration (Kettle)

I'm developing a way to consolidate and centralize data from Zimbra Report scripts, now are    
decentralized (LDAP base, logs, reports). That data will be stored at an relational database.
These amount of DATA could be transformed - using ETL, to an INFORMATION and stored in 
an Data Warehouse then generate reports to make decision of such as: scalability,  topology upgrades,  
security policies revision/update/upgrade, update systems, etc

The reports could be done with Dimensional cubes using Mondrian (Pentaho Suite).

Kinds of Data that will be extracted from reports created by scripts:
* MTA report / amount of send and receive messages
* LDAP Users Information:
-  '> Daily blocked users
-  '> Users' configuration
-  '> Users' quota
-  '> Users' audit
* Backup Information
-  '> General backup - all domains and users
-  '> Specific backup - per users


