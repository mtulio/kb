

# for para manipular os jogos repetidos
for contJogosRepetidos in (seq 4)
do
        for contJogosDistintos in (seq 12)
        do
                # definindo as sequencias de jogos... serão manipulados 12 jogos
                case $contJogos in
                        1)  ## pais1 X pais2
                                for i in (seq 11) 
                                do
                                        ## Escalacao(cod_jogo1,cod_jogo2,cod_jogo3,cod_jogador,hrInicio,substituido,hrSubstituicao)
                                        echo "INSERT INTO escalacao VALUES('01/07/2010',1,2,$i)" >> jogos.sql;
                                done # fim do for para escalacao da selecao 1
                                for i in (seq 11) 
                                do
                                        j=$((i+22));
                                        echo "INSERT INTO escalacao VALUES('01/07/2010',1,2,$j)" >> jogos.sql;
                                done # fim do for para escalacao da selecao 2
                                ;
                                
                                ## Definindo os atributos do jogo
                                ##Jogo (dia,hora,cod_selecao1,cod_selecao2,cod_estadio,cod_juiz1,cod_juiz2,cod_bandeira1,cod_bandeira2)
                                echo "INSERT INTO jogo VALUES('01/07/2010',16,1,2,1,23,22,23,22)" >> jogos.sql;;
                        2) ## pais1 X pais2
                                for i in (seq 11) 
                                do
                                        echo "INSERT INTO escalacao VALUES('01/07/2010',1,3,$i)" >> jogos.sql;
                                done # fim do for para escalacao da selecao 1
                                for i in (seq 11) 
                                do
                                        j=$((i+47)); # 47 é o inicio dos IDs dos jogadores da Selecao 3
                                        echo "INSERT INTO escalacao VALUES('01/07/2010',1,3,$j)" >> jogos.sql;
                                done # fim do for para escalacao da selecao 2
                                ;;
                        3);;
                        4);;
                        5);;
                        6);;
                        7);;
                        8);;
                        9);;
                        10);;
                        11);;
                        12);;
                esac # fim do case
        done  #fechamento do for principal
done #done do for que manipula os jogos repetidos

