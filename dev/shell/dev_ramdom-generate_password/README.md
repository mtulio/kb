# Generate random password

Generating random password using Linux Shell Script


Use script 'linux_gen_random_passwd.sh' to generate password:

* Help
```
$ ./linux_gen_random_passwd.sh -h
 Usage          : ./linux_gen_random_passwd.sh [simple|medium|complex|default|all] [lenght] ]
 '-> simple	: Generate simple password
 '-> medium	: Generate a medium password
 '-> complex	: Generate a complex password
 '-> medium	: Generate a default (medium) password
 '-> all	: Generate all level of password
 '-> lenght	: Lenght of password. Minimal is 6. Default is 8

```

* Generate password with complexity level: simple
```
$ ./linux_gen_random_passwd.sh
 # Level: [SIMPLE] , Lenght: [10] , Password: jvqJSJ1o9x
```

* Generate password with complexity level: medium
```
$ ./linux_gen_random_passwd.sh --medium 10
 # Level: [MEDIUM] , Lenght: [10] , Password: #@B!gfvD3D
```

* Generate password with complexity level: complex
```
$ ./linux_gen_random_passwd.sh --complex 10
 # Level: [COMPLEX] , Lenght: [10] , Password: T3vkK#gLwy
```

* Generate three levels:
```
$ ./linux_gen_random_passwd.sh --all 10
 # Level: [SIMPLE] , Lenght: [10] , Password: XiG8FsuSXl
 # Level: [MEDIUM] , Lenght: [10] , Password: dE4c$gCxx2
 # Level: [COMPLEX] , Lenght: [10] , Password: Dl$1BMWicY
```
