SELECT s1.nome AS "Selecao A", s3.gol1 AS "Gols-A", s4.gol2 AS "Gols-B"
s2.nome AS "Selecao B"
FROM jogo,
(select jogo.dia AS data1, jogo.cod_selecao1 As cod1, pais.nome AS nome FROM jogo, pais WHERE jogo.cod_selecao1=pais.codigo) AS s1,
(select jogo.dia AS data2, jogo.cod_selecao2 As cod2, pais.nome AS nome FROM jogo, pais WHERE jogo.cod_selecao2=pais.codigo) AS s2,
()
WHERE s1.cod1=jogo.cod_selecao1 AND s2.cod2=jogo.cod_selecao2
AND s1.data1=s2.data2;



/*CONTANDO A QUANTIDADE DE GOLS EM UMA PARTIDA*/
select COUNT(*)
from gols, jogador
WHERE gols.cod_jogo1='2010-07-01'
AND jogador.codigo=gols.cod_jogador
AND gols.cod_jogo2=5
AND gols.cod_jogo3=6;



SELECT DISTINCT s1.nome AS "Selecao A",
s2.nome AS "Selecao B",
s3.gols AS "QtD Gols Partida"
FROM jogo,
(select jogo.dia AS data1, jogo.cod_selecao1 As cod1, pais.nome AS nome FROM jogo, pais WHERE jogo.cod_selecao1=pais.codigo) AS s1,
(select jogo.dia AS data2, jogo.cod_selecao2 As cod2, pais.nome AS nome FROM jogo, pais WHERE jogo.cod_selecao2=pais.codigo) AS s2,
(select COUNT(*) from gols, jogador WHERE gols.cod_jogo1='2010-07-01' AND jogador.codigo=gols.cod_jogador AND gols.cod_jogo2=5 AND gols.cod_jogo3=6)
WHERE s1.cod1=jogo.cod_selecao1 
AND s2.cod2=jogo.cod_selecao2
AND s1.data1=jogo.dia
AND s2.data2=jogo.dia;


FUNFO CONTADOR DE GOLS DE UM JOGO
select COUNT(*)
FROM (select cod_jogador, jogador.cod_pais
from gols, jogador
WHERE gols.cod_jogo1='2010-07-05'
AND jogador.codigo=gols.cod_jogador
AND gols.cod_jogo2=10
AND gols.cod_jogo3=12
AND jogador.cod_pais=gols.cod_jogo2) AS s1


## Cartoes VERMELHOS APLICADOS EM TODA A COPA
select cartoes.cod_jogo1, cartoes.cod_jogo2, cartoes.cod_jogo3, cartoes.corcartao
from cartoes
where cartoes.corcartao='VER'


select jogo.dia, jogo.cod_selecao1, jogo.cod_selecao2, jogo.cod_juiz1, COUNT(DISTINCT jogo.cod_juiz1)
from jogo, (select cartoes.cod_jogo1 AS jg_dia, cartoes.cod_jogo2 As jg_s1, cartoes.cod_jogo3 AS jg_s2, cartoes.corcartao
from cartoes
where cartoes.corcartao='AME') AS s1
WHERE jogo.dia=s1.jg_dia
AND jogo.cod_selecao1=s1.jg_s1
AND jogo.cod_selecao2=s1.jg_s2
ORDER BY jogo.cod_juiz1


SELECT juiz.nome, MAX(s3.coco)
FROM juiz,
(SELECT juiz.nome AS coco2, count(*) AS coco
FROM juiz,
(select jogo.cod_juiz1 AS ju
from jogo, juiz, (select cartoes.cod_jogo1 AS jg_dia, cartoes.cod_jogo2 As jg_s1, cartoes.cod_jogo3 AS jg_s2, cartoes.corcartao
from cartoes
where cartoes.corcartao='AME') AS s1
WHERE jogo.dia=s1.jg_dia
AND jogo.cod_selecao1=s1.jg_s1
AND jogo.cod_selecao2=s1.jg_s2
AND juiz.codigo=jogo.cod_juiz1) as s2
where s2.ju=juiz.codigo
GROUP BY juiz.nome) AS s3
WHERE s3.coco2=juiz.nome
GROUP BY juiz.nome



/* PRONTOOO MAXIMO DE CARTOES */

SELECT s3.nome AS nome, s3.maximo AS "Max Vermelhos"
FROM juiz,
(SELECT juiz.nome AS nome, count(*) AS maximo
FROM juiz,
(select jogo.cod_juiz1 AS ju
from jogo, juiz, (select cartoes.cod_jogo1 AS jg_dia, cartoes.cod_jogo2 As jg_s1, cartoes.cod_jogo3 AS jg_s2, cartoes.corcartao
from cartoes
where cartoes.corcartao='VER') AS s1
WHERE jogo.dia=s1.jg_dia
AND jogo.cod_selecao1=s1.jg_s1
AND jogo.cod_selecao2=s1.jg_s2
AND juiz.codigo=jogo.cod_juiz1) as s2
where s2.ju=juiz.codigo
GROUP BY juiz.nome) AS s3,
(SELECT MAX(s3.maximo) AS maximo
FROM juiz,
(SELECT juiz.nome AS coco2, count(*) AS maximo
FROM juiz,
(select jogo.cod_juiz1 AS juiz
from jogo, juiz, (select cartoes.cod_jogo1 AS jg_dia, cartoes.cod_jogo2 As jg_s1, cartoes.cod_jogo3 AS jg_s2, cartoes.corcartao
from cartoes
where cartoes.corcartao='VER') AS s1
WHERE jogo.dia=s1.jg_dia
AND jogo.cod_selecao1=s1.jg_s1
AND jogo.cod_selecao2=s1.jg_s2
AND juiz.codigo=jogo.cod_juiz1) as s2
where s2.juiz=juiz.codigo
GROUP BY juiz.nome) AS s3) AS S4
WHERE s4.maximo=s3.maximo
and s3.nome=juiz.nome

/* ARTILHEIROS DA COPA */

SELECT jogador.nome AS "Nome do Jogador", s2.todosgols AS "Qtd Gols"
FROM jogador,
(SELECT s1.jogadores AS jogadores, count(s1.jogadores) AS todosGols FROM 
(select gols.cod_jogador As jogadores from gols) AS s1
GROUP BY s1.jogadores) AS s2,
(SELECT MAX(s2.todosGols) AS max
FROM
(SELECT s1.jogadores AS cod_jogadores, count(s1.jogadores) AS todosGols FROM 
(select gols.cod_jogador As jogadores from gols) AS s1
GROUP BY s1.jogadores) AS s2 )AS s3
WHERE s2.todosgols=s3.max
AND jogador.codigo=s2.jogadores
GROUP BY jogador.nome, s2.todosgols



