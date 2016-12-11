#!/bin/bash

rm -rvf pais_jogador.sql

arquivoPrincipal=pais_jogador.sql

#cat criarTabelas.sql > pais_jogador.sql

echo "DELETE FROM Gols;" >> pais_jogador.sql
echo "DELETE FROM Cartoes;" >> pais_jogador.sql
echo "DELETE FROM Escalacao;" >> pais_jogador.sql
echo "DELETE FROM Jogo;" >> pais_jogador.sql
echo "DELETE FROM Estadio;" >> pais_jogador.sql
echo "DELETE FROM Juiz;" >> pais_jogador.sql
echo "DELETE FROM Bandeirinha;" >> pais_jogador.sql
echo "DELETE FROM Jogador;" >> pais_jogador.sql
echo "DELETE FROM Posicao;" >> pais_jogador.sql
echo "DELETE FROM Pais;" >> pais_jogador.sql
echo "DELETE FROM Chave;" >> pais_jogador.sql

echo "INSERT INTO posicao VALUES('GOL');" >> pais_jogador.sql
echo "INSERT INTO posicao VALUES('LAT');" >> pais_jogador.sql
echo "INSERT INTO posicao VALUES('ZAG');" >> pais_jogador.sql
echo "INSERT INTO posicao VALUES('MEI');" >> pais_jogador.sql
echo "INSERT INTO posicao VALUES('ATA');" >> pais_jogador.sql

contJogador=1;

for i in $(seq 32); 
do 
	case $i in
		1) pais=pais1;
			chave='A';
			echo "INSERT INTO chave VALUES('$chave');" >> pais_jogador.sql;
			echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        ## Definido no Wikipedia que são 23 juizes.. os 23 primeiros paises terão um juiz   
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		2) pais=pais2;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		3) pais=pais3;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		4) pais=pais4;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		5) pais=pais5;
			chave='B';
			echo "INSERT INTO chave VALUES('$chave');" >> pais_jogador.sql;
			echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		6) pais=pais6;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		7) pais=pais7;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		8) pais=pais8;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		9) pais=pais9;
			chave='C';
			echo "INSERT INTO chave VALUES('$chave');" >> pais_jogador.sql;
			echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		10) pais=pais10;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		11) pais=pais11;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		12) pais=pais12;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		13) pais=pais13;
			chave='D';
			echo "INSERT INTO chave VALUES('$chave');" >> pais_jogador.sql;
			echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		14) pais=pais14;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		15) pais=pais15;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		16) pais=pais16;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		17) pais=pais17;
			chave='E';
			echo "INSERT INTO chave VALUES('$chave');" >> pais_jogador.sql;
			echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		18) pais=pais18;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		19) pais=pais19;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		20) pais=pais20;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		21) pais=pais21;
			chave='F';
			echo "INSERT INTO chave VALUES('$chave');" >> pais_jogador.sql;
			echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		22) pais=pais22;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		23) pais=pais23;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;
                        echo "INSERT INTO juiz VALUES($i, 'juiz_$i','23/10/1980',$i);" >> pais_jogador.sql;
                        echo "INSERT INTO bandeirinha VALUES($i, 'bandeira_$i','23/10/1980',$i);" >> pais_jogador.sql;;
		24) pais=pais24;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		25) pais=pais25;
			chave='G';
			echo "INSERT INTO chave VALUES('$chave');" >> pais_jogador.sql;
			echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		26) pais=pais26;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		27) pais=pais27;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		28) pais=pais28;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		29) pais=pais29;
			chave='H';
			echo "INSERT INTO chave VALUES('$chave');" >> pais_jogador.sql;
			echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		30) pais=pais30;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		31) pais=pais31;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		32) pais=pais32;
                        echo "INSERT INTO pais VALUES($i,'$pais','continente_$pais', '$chave', 'tecnico_$pais', $i, '20/10/2009');" >> pais_jogador.sql;;
		*) echo Fim dos paises;;
	esac
	
	for j in $(seq 23)
	do
                nome=jogador$j-$pais;
		cpf=$contJogador$contJogador$i;
                #echo $contJogador;
                case $j in
                        1)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'GOL',$cpf,$j);"  >> pais_jogador.sql;;
                        2)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'LAT',$cpf,$j);"  >> pais_jogador.sql;;
                        3)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ZAG',$cpf,$j);"  >> pais_jogador.sql;;
                        4)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ZAG',$cpf,$j);"  >> pais_jogador.sql;;
                        5)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ZAG',$cpf,$j);"  >> pais_jogador.sql;;
                        6)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'LAT',$cpf,$j);"  >> pais_jogador.sql;;
                        7)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'MEI',$cpf,$j);"  >> pais_jogador.sql;;
                        8)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'MEI',$cpf,$j);"  >> pais_jogador.sql;;
                        9)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ATA',$cpf,$j);"  >> pais_jogador.sql;;
                        10)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'MEI',$cpf,$j);"  >> pais_jogador.sql;;
                        11)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ATA',$cpf,$j);"  >> pais_jogador.sql;;
                        12)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'GOL',$cpf,$j);"  >> pais_jogador.sql;;
                        13)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'LAT',$cpf,$j);"  >> pais_jogador.sql;;
                        14)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ZAG',$cpf,$j);"  >> pais_jogador.sql;;
                        15)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ZAG',$cpf,$j);"  >> pais_jogador.sql;;
                        16)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ZAG',$cpf,$j);"  >> pais_jogador.sql;;
                        17)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'LAT',$cpf,$j);"  >> pais_jogador.sql;;
                        18)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'MEI',$cpf,$j);"  >> pais_jogador.sql;;
                        19)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'MEI',$cpf,$j);"  >> pais_jogador.sql;;
                        20)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ATA',$cpf,$j);"  >> pais_jogador.sql;;
                        21)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'MEI',$cpf,$j);"  >> pais_jogador.sql;;                
                        22)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'ATA',$cpf,$j);"  >> pais_jogador.sql;;
                        23)echo "INSERT INTO jogador VALUES($contJogador,'$nome','23/10/1980',$i,'GOL',$cpf,$j);"  >> pais_jogador.sql;;
                esac;
		#echo for contJogador in $(seq $contJogador)
		#echo do 
		#	echo $contJogador - $j - $i;		
		##echo done
		contJogador=$((contJogador+1));
		#secho $contJogador;
	done
	
done

for e in $(seq 12 )
do
	nome="estadio_$e";
	cidade="cidade_$e";
	capacidade=50000;
	echo "INSERT INTO estadio VALUES($e,'$nome','$cidade',$capacidade);" >> pais_jogador.sql
done




mv pais_jogador.sql chave_pais_jogador_juiz_bandeira_estadio.sql

echo "Executado com sucesso." 
