#!/bin/bash
#####################################################################
## Regras MATRIZ: 
#	0) O firewall deve ter uma conexao VPN para as Filiais liberando as portas 1194(OpenVPN)
#	1) M_LAN1 PODE ACESSAR REDE DOS SERVIDORES(M_LAN3)
#	2) M_LAN2 PODE ACESSAR REDE DOS SERVIDORES(M_LAN3)
#	3) M_LAN1 PODE ACESSAR M_LAN2
#	4) M_LAN2 PODE ACESSAR M_LAN1
#	5) M_LAN2 PODE ACESSAR O SERVIDOR DE ARQUIVOS DAS DUAS FILIAIS(F1_LAN1 & F2_LAN1): ports: netbios-ns(137),netbios-dgm(138),netbios-ssn(139),microsoft-ds(445)
#	6) Servidores Matriz
#		a.1) O Servidor SMTP pode acessar a internet pela porta 25(SMTP) e 465(SMTPs) por tcp.
#		a.2) A internet pode acesar o Servidor SMTP pelas portas 25(SMTP) e 465(SMTPs) por tcp.
#		a.3) As redes das Filiais podem acessar o Servidor SMTP da matriz pelas portas: 25(SMTP), 465(SMTPs), 110(POP3), 995(POP3s), 143(IMAP) e 993(IMAPs) 
#		b.1) O Servidor DNS pode acessar a internet pela porta 53(DNS) por tcp/udp.
#		b.2) A internet pode acessar o servidor DNS pela porta 53(DNS) por tcp/udp.
#		c) A internet pode acessar o servidor WEB pelas portas 80(HTTP) e 443(HTTPS) tcp.
#		d) "SGBD Matriz pode consultar SGBD filiais": SGBD acessar servidores SGBD Filiais F1 e F2. SGBD MYSQL: 3306 tcp/udp
#		e) Servidor Proxy pode acessar a Internet pelas portas 80(HTTP), 8080(HTTP), 81(HTTP), 443(HTTPS), 20(FTP), 21(FTP) tcp/udp.
#
#		
## Regras FILIAL
#	0) O Firewall dever ter uma conexao VPN com a Matriz
#	1) Servidor Proxy pode acessar a Internet pelas portas 80(HTTP), 8080(HTTP), 81(HTTP), 443(HTTPS), 20(FTP), 21(FTP) tcp/udp.
#	2) A LAN da Filial poderá acessar as Portas 25(SMTP), 465(SMTPs), 110(POP3), 995(POP3s), 143(IMAP) e 993(IMAPs) do Servidor SMTP da Matriz pelas portas
#	3) A LAN da Filial poderá acessar o servidor DNS da Matriz através 53(DNS) tcp/udp.
#	4) O servidor SGBD da Matriz(ORIGEM) pode acessar o servidor SGBD da Filial(destino) pelas portas do SGBD MYSQL: 3306 tcp/udp ou (SQL Data(1433), SQL Monitor(1434)).
#	5) A M_LAN2 poderá acessar os arquivos do servidor Samba

#####################################################################

echo "### Localizando o binario do IPTABLES"
ipt=`which iptables`

echo "# Limpando as regras"
$ipt -F
$ipt -X
$ipt -t nat -F
$ipt -t nat -X
$ipt -t mangle -F
$ipt -t mangle -X
$ipt -P INPUT DROP
$ipt -P FORWARD DROP
$ipt -P OUTPUT ACCEPT

echo "## VALIDANDO OS PACOTES"
$ipt -A INPUT -j DROP -m state --state INVALID
$ipt -A INPUT -j ACCEPT -m state --state ESTABLISHED,RELATED

$ipt -A FORWARD -j DROP -m state --state INVALID
$ipt -A FORWARD -j ACCEPT -m state --state ESTABLISHED,RELATED 


echo "### Definicao de Hosts, Redes, IPs"

M_LAN1="192.168.0.0/24"
M_LAN2="192.168.1.0/24"
M_LAN3="192.168.2.0/24"
F2_LAN1="192.168.20.0/24"
F1_LAN1="192.168.10.0/24"

M_FW1="200.200.1.2/32"
F1_FW1="200.200.1.2/32"
F2_FW1="200.200.1.3/32"

INTERNET="0.0.0.0/0"

M_SERVER_VPN="192.168.2.10"
M_SRV_SMTP="192.168.3.11"
M_SRV_DMS="192.168.3.12"
M_SRV_WEB="192.168.3.13"
M_SRV_MYSQL="192.168.3.14"
M_SRV_PROXY="192.168.3.15"

F1_SRV_MYSQL="192.168.10.10"
F2_SRV_PROXY="192.168.10.11"
F2_SRV_SAMBA="192.168.10.12"

F2_SRV_MYSQL="192.168.20.10"
F2_SRV_PROXY="192.168.20.11"
F2_SRV_SAMBA="192.168.20.12"

####################################################################
echo "## Regras MATRIZ: "

echo "#	0) O firewall deve ter uma conexao VPN para as Filiais liberando as portas 1194(OpenVPN)"

$ipt -t filter -A INPUT -s $F1_FW1 -d $M_FW1 -p tcp --dport 1194 -j ACCEPT
$ipt -t filter -A INPUT -s $F2_FW1 -d $M_FW1 -p udp --dport 1194 -j ACCEPT

echo "#	1) M_LAN1 PODE ACESSAR REDE DOS SERVIDORES(M_LAN3)"

$ipt -t filter -A FORWARD -s $M_LAN1 -d $M_LAN3 -j ACCEPT

echo "#	2) M_LAN2 PODE ACESSAR REDE DOS SERVIDORES(M_LAN3)"

$ipt -t filter -A FORWARD -s $M_LAN2 -d $M_LAN3 -j ACCEPT

echo "#	3) M_LAN1 PODE ACESSAR M_LAN2"

$ipt -t filter -A FORWARD -s $M_LAN1 -d $M_LAN2 -j ACCEPT

echo "#	4) M_LAN2 PODE ACESSAR M_LAN1"

$ipt -t filter -A FORWARD -s $M_LAN2 -d $M_LAN1 -j ACCEPT

echo "#	5) M_LAN2 PODE ACESSAR O SERVIDOR DE ARQUIVOS DAS DUAS FILIAIS(F1_LAN1 & F2_LAN1): ports: netbios-ns(137),netbios-dgm(138),netbios-ssn(139),microsoft-ds(445)"

$ipt -t filter -A FORWARD -s $M_LAN2 -d $F1_SRV_SAMBA -j ACCEPT
$ipt -t filter -A FORWARD -s $M_LAN2 -d $F2_SRV_SAMBA -j ACCEPT

echo "#	6) Servidores Matriz"

echo "#		a.1) O Servidor SMTP pode acessar a internet pela porta 25(SMTP) e 465(SMTPs) por tcp."

$ipt -t filter -A FORWARD -s $M_SRV_SMTP -d $INTERNET -p tcp --match multiport --dports 25,465 -j ACCEPT
$ipt -t nat -A POSTROUTING -s $M_SRV_SMTP -d $INTERNET -j SNAT --to-destination $M_FW1

echo "#		a.2) A internet pode acesar o Servidor SMTP pelas portas 25(SMTP) e 465(SMTPs) por tcp."

$ipt -t filter -A FORWARD -s $INTERNET -d $M_SRV_SMTP -p tcp --match multiport --dports 25,465 -j ACCEPT
$ipt -t nat -A PREROUTING -s $INTERNET -d $M_FW1 -p tcp --dport 25 -j DNAT --to-destination $M_SRV_SMTP
$ipt -t nat -A PREROUTING -s $INTERNET -d $M_FW1 -p tcp --dport 465 -j DNAT --to-destination $M_SRV_SMTP

echo "#		a.3) As redes das Filiais podem acessar o Servidor SMTP da matriz pelas portas: 25(SMTP), 465(SMTPs), 110(POP3), 995(POP3s), 143(IMAP) e 993(IMAPs) "

$ipt -t filter -A FORWARD -s $F1_LAN1 -d $M_SRV_SMTP -p tcp --match multiport --dports 25,465,110,995,143,993 -j ACCEPT
$ipt -t filter -A FORWARD -s $F2_LAN1 -d $M_SRV_SMTP -p tcp --match multiport --dports 25,465,110,995,143,993 -j ACCEPT
		
		
echo "#		b.1) O Servidor DNS pode acessar a internet pela porta 53(DNS) por tcp/udp."

$ipt -t filter -A FORWARD -s $M_SRV_DNS -d $INTERNET -p tcp --dport 53 -j ACCEPT
$ipt -t nat -A POSTROUTING -s $M_SRV_DNS -d $INTERNET -j SNAT --to-destination $M_FW1

echo "#		b.2) A internet pode acessar o servidor DNS pela porta 53(DNS) por tcp/udp."

$ipt -t filter -A FORWARD -s $INTERNET -d $M_SRV_DNS -p tcp --dport 53 -j ACCEPT
$ipt -t nat -A PREROUTING -s $INTERNET -d $M_FW1 -p tcp --dport 53 -j DNAT --to-destination $M_SRV_DNS

$ipt -t filter -A FORWARD -s $INTERNET -d $M_SRV_DNS -p udp --dport 53 -j ACCEPT
$ipt -t nat -A PREROUTING -s $INTERNET -d $M_FW1 -p udp --dport 53 -j DNAT --to-destination $M_SRV_DNS

echo "#		c) A internet pode acessar o servidor WEB pelas portas 80(HTTP) e 443(HTTPS) tcp."

$ipt -t filter -A FORWARD -s $INTERNET -d $M_SRV_WEB -p tcp --match multiport --dports 80,443 -j ACCEPT
$ipt -t nat -A PREROUTING -s $INTERNET -d $M_FW1 -p tcp --dport 80 -j DNAT --to-destination $M_SRV_WEB
$ipt -t nat -A PREROUTING -s $INTERNET -d $M_FW1 -p tcp --dport 443 -j DNAT --to-destination $M_SRV_WEB

echo "#		d) \"SGBD Matriz pode consultar SGBD filiais\": SGBD acessar servidores SGBD Filiais F1 e F2. SGBD MYSQL: 3306 tcp/udp"

$ipt -t filter -A FORWARD -s $M_SRV_MYSQL -d $F1_SRV_MYSQL -p tcp --dport 3306 -j ACCEPT
$ipt -t filter -A FORWARD -s $M_SRV_MYSQL -d $F2_SRV_MYSQL -p tcp --dport 3306 -j ACCEPT

$ipt -t filter -A FORWARD -s $F1_SRV_MYSQL -d $M_SRV_MYSQL -p tcp --dport 3306 -j ACCEPT
$ipt -t filter -A FORWARD -s $F2_SRV_MYSQL -d $M_SRV_MYSQL -p tcp --dport 3306 -j ACCEPT

echo "#		e) Servidor Proxy pode acessar a Internet pelas portas 80(HTTP), 8080(HTTP), 81(HTTP), 443(HTTPS), 20(FTP), 21(FTP) tcp/udp."

$ipt -t filter -A FORWARD -s $M_SRV_PROXY -d $INTERNET -p tcp --match multiport --dports 80,8080,81,443,20,21 -j ACCEPT
$ipt -t nat -A POSTROUTING -s $M_SRV_PROXY -d $INTERNET -j SNAT --to-destination $M_FW1


####################################################################
echo "## Regras FILIAL 01 (Filial 01 e Filial 02 são identicas - definidas pelo professor)"

echo "#	0) O Firewall deve ter uma conexao VPN com a Matriz"

echo "## INPUT OU OUTPUT ?? - DEPENDE DO PROGRAMA DE VPN?!"

$ipt -t filter -A OUTPUT -s $F1_FW1 -d $M_FW1 -p tcp --dport 1194 -j ACCEPT

echo "#	1) Servidor Proxy pode acessar a Internet pelas portas 80(HTTP), 8080(HTTP), 81(HTTP), 443(HTTPS), 20(FTP), 21(FTP) tcp/udp."

$ipt -t filter -A FORWARD -s $F1_SRV_PROXY -d $INTERNET -p tcp --match multiport --dports 80,8080,81,443,20,21 -j ACCEPT
$ipt -t nat -A POSTROUTING -s $F1_SRV_PROXY -d $INTERNET -j SNAT --to-destination $F1_FW1

echo "#	2) A LAN da Filial poderá acessar as Portas 25(SMTP), 465(SMTPs), 110(POP3), 995(POP3s), 143(IMAP) e 993(IMAPs) do 
#		Servidor SMTP da Matriz pelas portas"

$ipt -t filter -A FORWARD -s $F1_LAN1 -d $M_SRV_SMTP -p tcp --match multiport --dports 25,465,110,995,143,993 -j ACCEPT

echo "#	3) A LAN da Filial poderá acessar o servidor DNS da Matriz através 53(DNS) tcp/udp."

$ipt -t filter -A FORWARD -s $F1_LAN1 -d $M_SRV_DNS -p tcp --dport 53 -j ACCEPT
$ipt -t filter -A FORWARD -s $F1_LAN1 -d $M_SRV_DNS -p udp --dport 53 -j ACCEPT

echo "#	4) O servidor SGBD da Matriz(ORIGEM) pode acessar o servidor SGBD da Filial(destino) pelas portas do SGBD MYSQL: 3306 tcp/udp ou (SQL Data(1433), SQL Monitor(1434))."

$ipt -t filter -A FORWARD -s $M_SRV_MYSQL -d $F1_SRV_MYSQL -p tcp --dport 3306 -j ACCEPT
#$ipt -t filter -A FORWARD -s $M_SRV_MYSQL -d $F1_SRV_MYSQL -p tcp --dport 1433 -j ACCEPT
#$ipt -t filter -A FORWARD -s $M_SRV_MYSQL -d $F1_SRV_MYSQL -p tcp --dport 1434 -j ACCEPT

echo "#	5) A M_LAN2 poderá acessar os arquivos do servidor Samba"

$ipt -t filter -A FORWARD -s $M_LAN2 -d $F1_SRV_SAMBA -j ACCEPT



####################################################################
echo "## Regras FILIAL 02 (Filial 01 e Filial 02 são identicas - definidas pelo professor)"

echo "#	0) O Firewall deve ter uma conexao VPN com a Matriz"

echo "## INPUT OU OUTPUT ?? - DEPENDE DO PROGRAMA DE VPN?!"

$ipt -t filter -A OUTPUT -s $F2_FW1 -d $M_FW1 -p tcp --dport 1194 -j ACCEPT

echo "#	1) Servidor Proxy pode acessar a Internet pelas portas 80(HTTP), 8080(HTTP), 81(HTTP), 443(HTTPS), 20(FTP), 21(FTP) tcp/udp."

$ipt -t filter -A FORWARD -s $F2_SRV_PROXY -d $INTERNET -p tcp --match multiport --dports 80,8080,81,443,20,21 -j ACCEPT
$ipt -t nat -A POSTROUTING -s $F2_SRV_PROXY -d $INTERNET -j SNAT --to-destination $F2_FW1

echo "#	2) A LAN da Filial poderá acessar as Portas 25(SMTP), 465(SMTPs), 110(POP3), 995(POP3s), 143(IMAP) e 993(IMAPs) do 
#		Servidor SMTP da Matriz pelas portas"

$ipt -t filter -A FORWARD -s $F2_LAN1 -d $M_SRV_SMTP -p tcp --match multiport --dports 25,465,110,995,143,993 -j ACCEPT

echo "#	3) A LAN da Filial poderá acessar o servidor DNS da Matriz através 53(DNS) tcp/udp."

$ipt -t filter -A FORWARD -s $F2_LAN1 -d $M_SRV_DNS -p tcp --dport 53 -j ACCEPT
$ipt -t filter -A FORWARD -s $F2_LAN1 -d $M_SRV_DNS -p udp --dport 53 -j ACCEPT

echo "#	4) O servidor SGBD da Matriz(ORIGEM) pode acessar o servidor SGBD da Filial(destino) pelas portas do SGBD MYSQL: 3306 tcp/udp ou (SQL Data(1433), SQL Monitor(1434))."

$ipt -t filter -A FORWARD -s $M_SRV_MYSQL -d $F2_SRV_MYSQL -p tcp --dport 3306 -j ACCEPT
#$ipt -t filter -A FORWARD -s $M_SRV_MYSQL -d $F2_SRV_MYSQL -p tcp --dport 1433 -j ACCEPT
#$ipt -t filter -A FORWARD -s $M_SRV_MYSQL -d $F2_SRV_MYSQL -p tcp --dport 1434 -j ACCEPT

echo "#	5) A M_LAN2 poderá acessar os arquivos do servidor Samba"

$ipt -t filter -A FORWARD -s $M_LAN2 -d $F2_SRV_SAMBA -j ACCEPT

