# Studing node.js - Installing

To install node.js see that article: https://class.coursera.org/startup-001/lecture/119


* Check information of packages: nodejs and npm (nodejs package manager):
```
[root@mtnote ~]# dnf info npm nodejs
Last metadata expiration check performed 1:53:21 ago on Wed Oct 14 20:32:00 2015.
Pacotes disponíveis

Name        : nodejs
Arq.        : x86_64
Epoch       : 0
Versão      : 0.10.36
Release     : 4.fc22
Tam.        : 389 k
Repo        : fedora
Summary     : JavaScript runtime
URL         : http://nodejs.org/
License     : MIT and ASL 2.0 and ISC and BSD
Description : Node.js is a platform built on Chrome's JavaScript runtime
            : for easily building fast, scalable network applications.
            : Node.js uses an event-driven, non-blocking I/O model that
            : makes it lightweight and efficient, perfect for data-intensive
            : real-time applications that run across distributed devices.

Name        : npm
Arq.        : noarch
Epoch       : 0
Versão      : 1.3.6
Release     : 6.fc21
Tam.        : 334 k
Repo        : fedora
Summary     : Node.js Package Manager
URL         : http://npmjs.org/
License     : Artistic 2.0
Description : npm is a package manager for node.js. You can use it to install and publish your
            : node programs. It manages dependencies and does other cool stuff.
 
```

* Install package: nodejs :
```
[root@mtnote ~]# dnf install nodejs
Last metadata expiration check performed 1:55:58 ago on Wed Oct 14 20:32:00 2015.
Dependencies resolved.
============================================================================================================================================
 Package                             Arq.                       Versão                                    Repo                         Tam.
============================================================================================================================================
Instalando:
 compat-libuv010                     x86_64                     1:0.10.34-1.fc22                          fedora                       65 k
 nodejs                              x86_64                     0.10.36-4.fc22                            fedora                      389 k
 v8                                  x86_64                     1:3.14.5.10-21.fc22                       updates                     3.0 M

Resumo da transação
============================================================================================================================================
Instalar  3 Packages

Tamanho total do download: 3.4 M
Tamanho depois de instalado: 11 M
Correto? [s/N]:s

Baixando pacotes:
(1/3): compat-libuv010-0.10.34-1.fc22.x86_64.rpm                                                             34 kB/s |  65 kB     00:01    
(2/3): nodejs-0.10.36-4.fc22.x86_64.rpm                                                                     118 kB/s | 389 kB     00:03    
(3/3): v8-3.14.5.10-21.fc22.x86_64.rpm                                                                      386 kB/s | 3.0 MB     00:07    
--------------------------------------------------------------------------------------------------------------------------------------------
Total                                                                                                       314 kB/s | 3.4 MB     00:11     
Executando verificação da transação
Verificação de transação completa.
Executando teste de transação
Teste de transação completo
Executando a transação
  Instalando    : v8-1:3.14.5.10-21.fc22.x86_64                                                                                         1/3 
  Instalando    : compat-libuv010-1:0.10.34-1.fc22.x86_64                                                                               2/3 
  Instalando    : nodejs-0.10.36-4.fc22.x86_64                                                                                          3/3 
  Verifying     : nodejs-0.10.36-4.fc22.x86_64                                                                                          1/3 
  Verifying     : compat-libuv010-1:0.10.34-1.fc22.x86_64                                                                               2/3 
  Verifying     : v8-1:3.14.5.10-21.fc22.x86_64                                                                                         3/3 

Instalados:
  compat-libuv010.x86_64 1:0.10.34-1.fc22              nodejs.x86_64 0.10.36-4.fc22              v8.x86_64 1:3.14.5.10-21.fc22             

Concluído!

```

* [if you want] Install package: npm (nodejs package manager) [check dependencies, if you need]:
```
[root@mtnote ~]# dnf install npm
Last metadata expiration check performed 1:58:34 ago on Wed Oct 14 20:32:00 2015.
Dependencies resolved.
============================================================================================================================================
 Package                                     Arq.                 Versão                                        Repo                   Tam.
============================================================================================================================================
Instalando:
 c-ares-devel                                x86_64               1.10.0-4.fc22                                 fedora                 76 k
 compat-libuv010-devel                       x86_64               1:0.10.34-1.fc22                              fedora                 40 k
 dwz                                         x86_64               0.11-4.fc22                                   fedora                103 k
 ghc-srpm-macros                             noarch               1.4.2-1.fc22                                  fedora                8.1 k
 gnat-srpm-macros                            noarch               1-1.fc22                                      fedora                8.5 k
 go-srpm-macros                              noarch               1-2.fc22                                      updates               7.9 k
 gyp                                         noarch               0.1-0.17.0bb6747git.fc22                      fedora                507 k
 http-parser-devel                           x86_64               2.0-7.20121128gitcd01361.fc22                 fedora                 14 k
 keyutils-libs-devel                         x86_64               1.5.9-4.fc22                                  fedora                 45 k
 krb5-devel                                  x86_64               1.13.2-7.fc22                                 updates               648 k
 libcom_err-devel                            x86_64               1.42.12-4.fc22                                fedora                 35 k
 libselinux-devel                            x86_64               2.3-10.fc22                                   updates               181 k
 libsepol-devel                              x86_64               2.3-4.fc22                                    fedora                 76 k
 libuv                                       x86_64               1:1.4.0-1.fc22                                fedora                 75 k
 libuv-devel                                 x86_64               1:1.4.0-1.fc22                                fedora                 35 k
 libverto-devel                              x86_64               0.2.6-4.fc22                                  fedora                 16 k
 node-gyp                                    noarch               0.10.6-4.fc22                                 fedora                 30 k
 nodejs-abbrev                               noarch               1.0.4-8.fc21                                  fedora                7.8 k
 nodejs-ansi                                 noarch               0.2.1-2.fc21                                  fedora                 13 k
 nodejs-archy                                noarch               0.0.2-10.fc21                                 fedora                6.8 k
 nodejs-asn1                                 noarch               0.1.11-5.fc21                                 fedora                 11 k
 nodejs-assert-plus                          noarch               0.1.4-2.fc21                                  fedora                7.5 k
 nodejs-async                                noarch               0.2.10-2.fc21                                 fedora                 21 k
 nodejs-aws-sign                             noarch               0.3.0-3.fc21                                  fedora                5.8 k
 nodejs-block-stream                         noarch               0.0.7-2.fc21                                  fedora                8.9 k
 nodejs-boom                                 noarch               0.4.2-4.fc21                                  fedora                 37 k
 nodejs-child-process-close                  noarch               0.1.1-4.fc21                                  fedora                6.2 k
 nodejs-chmodr                               noarch               0.1.0-6.fc21                                  fedora                6.1 k
 nodejs-chownr                               noarch               0.0.1-11.fc21                                 fedora                6.7 k
 nodejs-cmd-shim                             noarch               1.1.0-5.fc21                                  fedora                8.0 k
 nodejs-combined-stream                      noarch               0.0.4-5.fc21                                  fedora                8.2 k
 nodejs-config-chain                         noarch               1.1.7-3.fc21                                  fedora                 10 k
 nodejs-cookie-jar                           noarch               1:0.3.0-3.fc21                                fedora                6.4 k
 nodejs-cryptiles                            noarch               0.2.2-2.fc21                                  fedora                7.1 k
 nodejs-ctype                                noarch               0.5.3-5.fc21                                  fedora                 31 k
 nodejs-delayed-stream                       noarch               0.0.5-7.fc21                                  fedora                8.1 k
 nodejs-devel                                x86_64               0.10.36-4.fc22                                fedora                328 k
 nodejs-editor                               noarch               0.0.4-4.fc21                                  fedora                6.7 k
 nodejs-forever-agent                        noarch               0.5.0-3.fc21                                  fedora                5.7 k
 nodejs-form-data                            noarch               0.1.1-2.fc21                                  fedora                 11 k
 nodejs-fstream                              noarch               0.1.24-2.fc21                                 fedora                 25 k
 nodejs-fstream-ignore                       noarch               0.0.7-3.fc21                                  fedora                9.0 k
 nodejs-fstream-npm                          noarch               0.1.5-3.fc21                                  fedora                 11 k
 nodejs-github-url-from-git                  noarch               1.1.1-4.fc21                                  fedora                6.1 k
 nodejs-glob                                 noarch               3.2.6-2.fc21                                  fedora                 16 k
 nodejs-graceful-fs                          noarch               2.0.0-4.fc21                                  fedora                 11 k
 nodejs-hawk                                 noarch               1.0.0-2.fc21                                  fedora                105 k
 nodejs-hoek                                 noarch               0.9.1-3.fc21                                  fedora                 52 k
 nodejs-http-signature                       noarch               0.10.0-5.fc21                                 fedora                 17 k
 nodejs-inherits                             noarch               2.0.1-5.fc22                                  fedora                 13 k
 nodejs-ini                                  noarch               1.1.0-5.fc21                                  fedora                8.5 k
 nodejs-init-package-json                    noarch               0.0.10-3.fc21                                 fedora                9.6 k
 nodejs-json-stringify-safe                  noarch               5.0.0-3.fc21                                  fedora                6.9 k
 nodejs-lockfile                             noarch               0.4.2-2.fc21                                  fedora                 11 k
 nodejs-lru-cache                            noarch               2.3.0-5.fc21                                  fedora                9.8 k
 nodejs-mime                                 noarch               1.2.11-2.fc21                                 fedora                 22 k
 nodejs-minimatch                            noarch               0.2.12-4.fc21                                 fedora                 18 k
 nodejs-mkdirp                               noarch               0.3.5-5.fc21                                  fedora                7.8 k
 nodejs-mute-stream                          noarch               0.0.4-2.fc21                                  fedora                7.6 k
 nodejs-node-uuid                            noarch               1.4.1-2.fc21                                  fedora                 10 k
 nodejs-nopt                                 noarch               2.1.2-2.fc21                                  fedora                 16 k
 nodejs-normalize-package-data               noarch               0.2.1-2.fc21                                  fedora                 13 k
 nodejs-npm-registry-client                  noarch               0.2.28-3.fc22                                 updates                25 k
 nodejs-npm-user-validate                    noarch               0.0.3-3.fc21                                  fedora                6.4 k
 nodejs-npmconf                              noarch               0.1.3-2.fc21                                  fedora                 17 k
 nodejs-npmlog                               noarch               0.0.4-3.fc21                                  fedora                9.6 k
 nodejs-oauth-sign                           noarch               0.3.0-3.fc21                                  fedora                5.2 k
 nodejs-once                                 noarch               1.1.1-7.fc21                                  fedora                6.3 k
 nodejs-opener                               noarch               1.3.0-9.fc21                                  fedora                7.1 k
 nodejs-osenv                                noarch               0.0.3-7.fc21                                  fedora                7.4 k
 nodejs-packaging                            noarch               7-2.fc21                                      fedora                 11 k
 nodejs-promzard                             noarch               0.2.0-8.fc21                                  fedora                 12 k
 nodejs-proto-list                           noarch               1.2.2-7.fc21                                  fedora                7.0 k
 nodejs-qs                                   noarch               0.6.6-3.fc22                                  fedora                 13 k
 nodejs-read                                 noarch               1.0.5-2.fc21                                  fedora                8.9 k
 nodejs-read-installed                       noarch               0.2.4-3.fc21                                  fedora                9.6 k
 nodejs-read-package-json                    noarch               1.1.3-2.fc21                                  fedora                 12 k
 nodejs-request                              noarch               2.25.0-2.fc21                                 fedora                 27 k
 nodejs-retry                                noarch               0.6.0-7.fc21                                  fedora                 11 k
 nodejs-rimraf                               noarch               2.2.2-2.fc21                                  fedora                8.2 k
 nodejs-semver                               noarch               2.1.0-3.fc21                                  fedora                 16 k
 nodejs-sha                                  noarch               1.2.1-2.fc21                                  fedora                7.7 k
 nodejs-sigmund                              noarch               1.0.0-7.fc21                                  fedora                8.6 k
 nodejs-slide                                noarch               1.1.5-2.fc21                                  fedora                 10 k
 nodejs-sntp                                 noarch               0.2.4-3.fc21                                  fedora                 10 k
 nodejs-tar                                  noarch               0.1.18-2.fc21                                 fedora                 23 k
 nodejs-tunnel-agent                         noarch               0.3.0-3.fc21                                  fedora                6.6 k
 nodejs-uid-number                           noarch               0.0.3-9.fc21                                  fedora                7.5 k
 nodejs-which                                noarch               1.0.5-10.fc21                                 fedora                8.3 k
 npm                                         noarch               1.3.6-6.fc21                                  fedora                334 k
 ocaml-srpm-macros                           noarch               2-2.fc22                                      fedora                7.9 k
 openssl-devel                               x86_64               1:1.0.1k-12.fc22                              updates               1.3 M
 pcre-devel                                  x86_64               8.37-4.fc22                                   updates               539 k
 perl-srpm-macros                            noarch               1-14.fc22                                     fedora                9.3 k
 redhat-rpm-config                           noarch               29-1.fc22                                     updates                58 k
 v8-devel                                    x86_64               1:3.14.5.10-21.fc22                           updates                64 k
Upgrading:
 krb5-libs                                   x86_64               1.13.2-7.fc22                                 updates               837 k
 openssl                                     x86_64               1:1.0.1k-12.fc22                              updates               496 k
 openssl-libs                                x86_64               1:1.0.1k-12.fc22                              updates               941 k
 pcre                                        x86_64               8.37-4.fc22                                   updates               486 k

Resumo da transação
============================================================================================================================================
Instalar  96 Packages
Upgrade    4 Packages

Tamanho total do download: 8.1 M
Correto? [s/N]:

```

