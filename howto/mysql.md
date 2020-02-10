# mysql

MySQL tips.

## Connect

`mysql -u root --host myserver.com -p`

## CRUD

### Create

### Retrieve

### Update

`UPDATE glpi_users SET password=MD5('new_pass') WHERE name='admin';`

### Delete



## Permissions

* Show grants for current user

```
SHOW GRANTS;
SHOW GRANTS FOR CURRENT_USER;
SHOW GRANTS FOR CURRENT_USER();
```

* Show all user privileges from information_schema


```
use information_schema;
select * from USER_PRIVILEGES;
```

## Admin

* Show table sizes

## Metrics

* Show main metrics

```
select name,status,count,avg_count,max_count,subsystem from INNODB_METRICS;
```

* show System metrics

```
select name,status,count,avg_count,max_count,subsystem from INNODB_METRICS where subsystem="os" or subsystem='file_system';
```

* Open files


```
select * from global_status where VARIABLE_NAME='OPENED_FILES';

```

* Table sizes

```
SELECT  table_schema as `Database`, table_name AS `Table`, round(((data_length + index_length) / 1024 / 1024), 2) `Size in MB` FROM information_schema.TABLES ORDER BY (data_length + index_length) DESC;
```
