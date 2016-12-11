

/*ULTIMA*/
DROP VIEW vw_jogos_todos;

/*Retorna a chave primaria de todos os jogos(dia, cod_selecao1, cod_selecao2)*/
CREATE VIEW vw_jogos_todos AS
SELECT jogo.dia AS dia, jogo.cod_selecao1 AS sl1, jogo.cod_selecao2 AS sl2 
FROM jogo;

/**/
/*############################################################*/
/*############################################################*/
DROP  VIEW vw_mt_1;
CREATE VIEW vw_mt_1 AS
SELECT gols.cod_jogo1 AS dia, gols.cod_jogo2 AS sl1, gols.cod_jogo3 AS sl2, jogador.nome AS jogador, pais.nome AS pais, pais.codigo as codpais
FROM gols, jogador, pais, vw_jogos_todos AS s1
WHERE s1.dia=gols.cod_jogo1
AND s1.sl1=gols.cod_jogo2
AND s1.sl2=gols.cod_jogo3
AND gols.cod_jogador=jogador.codigo
AND jogador.cod_pais=pais.codigo;


DROP VIEW vw_mt_2;
CREATE VIEW vw_mt_2 AS
SELECT s2.dia, s2.sl2 AS sl2, COUNT(s2.pais) AS qtdpais, s2.pais
FROM pais, vw_mt_1 AS s2
WHERE pais.nome=s2.pais
GROUP BY pais.nome , s2.sl2, s2.dia, s2.pais
ORDER BY s2.dia;

/*//usando case*/
SELECT s1.dia AS dia, s1.sl1 AS sl1, s1.sl2 AS sl2, 
CASE WHEN jogador.nome IS NOT NULL THEN jogador.nome 
     WHEN jogador.nome IS NULL then 'NULO' 
END, 
pais.nome AS pais, pais.codigo as codpais
FROM gols, jogador, pais, vw_jogos_todos AS s1
WHERE s1.dia=gols.cod_jogo1
AND s1.sl1=gols.cod_jogo2
AND s1.sl2=gols.cod_jogo3
AND gols.cod_jogador=jogador.codigo
AND jogador.cod_pais=pais.codigo;

/*sem sucesso*/
select jogo.dia, jogo.cod_selecao1,
case WHEN mt.qtdpais IS NOT NULL then jogo.cod_selecao1
when mt.qtdpais IS NULL THEN '0' END
FROM jogo, vw_mt_3 as mt
where jogo.cod_selecao1=mt.sl1
and jogo.cod_selecao2=mt.sl2
and mt.codpais=jogo.cod_selecao1
/*############################################################*/
/*CORRETA..MAS ESTA EM CADA REGISTRO*/
DROP VIEW vw_mt_3;
CREATE VIEW vw_mt_3 AS
SELECT s2.dia, s2.sl1 AS sl1, s2.sl2 AS sl2, COUNT(s2.pais) AS qtdpais, s2.codpais
FROM pais, vw_mt_1 AS s2
WHERE pais.nome=s2.pais
GROUP BY pais.nome , s2.sl1, s2.sl2, s2.dia, s2.pais, s2.codpais
ORDER BY s2.dia;
/*############################################################*/
/*############################################################*/

/**teste 06/12*/
/*TABELA PARCIAL*/
select jogo.dia, mt.qtdpais AS "Gols_1", jogo.cod_selecao1, jogo.cod_selecao2, mt2.qtdpais as "Gols2"
FROM vw_mt_3 as mt, jogo, vw_mt_3 as mt2
WHERE jogo.dia=mt.dia
AND jogo.cod_selecao1=mt.sl1
AND jogo.cod_selecao2=mt.sl2
AND mt.codpais=jogo.cod_selecao1
AND jogo.dia=mt2.dia
AND jogo.cod_selecao1=mt2.sl1
AND jogo.cod_selecao2=mt2.sl2
AND mt2.codpais=jogo.cod_selecao2
ORDER BY jogo.dia

/*testando valores nulos*/
select jogo.dia, 
(IF mt.qtdpais <> NULL THEN
        0
ELSE mt.qtdpais
end if) AS "Gols_1", 
jogo.cod_selecao1, 
jogo.cod_selecao2, 
mt2.qtdpais as "Gols2"
FROM vw_mt_3 as mt, jogo, vw_mt_3 as mt2
WHERE jogo.dia=mt.dia
AND jogo.cod_selecao1=mt.sl1
AND jogo.cod_selecao2=mt.sl2
AND jogo.cod_selecao1=1
AND jogo.dia=mt2.dia
AND jogo.cod_selecao1=mt2.sl1
AND jogo.cod_selecao2=mt2.sl2
AND jogo.cod_selecao2=2
ORDER BY jogo.dia
/*############################################################*/

SELECT COUNT(*) 
FROM vw_mt_resultados1 AS s1
WHERE gols.cod_jogo1=s1.dia
AND gols.cod_jogo2=s1.sl1
AND gols.cod_jogo3=s1.sl2


/*RETORNA AS PKS*/
SELECT s1.dia , s1.sl1, s1.sl2
FROM vw_mt_resultado1 AS s1

/*info pais1*/
SELECT s1.dia as dia, s1.sl1 as cod, pais.nome as nome
FROM pais, vw_mt_resultado1 AS s1
where pais.codigo=s1.sl1
/*info pais2*/
SELECT s1.dia as dia, s1.sl2 as cod, pais.nome as nome
FROM pais, vw_mt_resultado1 AS s1
where pais.codigo=s1.sl2

/**/
select jogo.cod_selecao1, jogo.cod_selecao2
FROM jogo, vw_mt_resultado1 as s1
WHERE jogo.cod_selecao1=s1.sl1
AND jogo.cod_selecao2=s1.sl2


/************************/
/*JOGOS-PAIS 1*/
DROP VIEW  vw_mt_p1;
CREATE VIEW vw_mt_p1 AS
select pais.nome As nome, jogo.cod_selecao2 AS cod
FROM pais, jogo
WHERE jogo.cod_selecao1=pais.codigo;

DROP VIEW vw_mt_p2;
CREATE VIEW vw_mt_p2 AS
select pais.nome as nome, jogo.cod_selecao2 AS cod
FROM pais, jogo
WHERE jogo.cod_selecao2=pais.codigo;


/*MONTANDO A TABELA FINAL*/
SELECT jogo.dia, s1.nome, s2.nome
from pais, jogo, vw_mt_p1 AS s1, vw_mt_p2 AS s2
WHERE s1.cod=jogo.cod_selecao1
AND s2.cod=jogo.cod_selecao2
AND s1.cod=pais.codigo


/**/
SELECT s2.sl1 AS sl1, s2.sl2 AS sl2, COUNT(s2.pais) AS qtdpais
FROM pais, vw_mt_1 AS s2
WHERE pais.nome=s2.pais
OR jogador.cod_pais=s2.sl1
GROUP BY pais.nome , s2.sl1, s2.sl2
ORDER BY pais.nome

/*RETORNA A QTD TOTAL de elementos da tabela gols*/
SELECT sum(s3.qtdpais)
FROM vw_mt_2 AS s3

SELECT s3.sl1, s3.sl2 
FROM gols, vw_mt_2 AS s3
WHERE s3.sl1=gols.cod_jogo2
AND s3.sl2=gols.cod_jogo3
