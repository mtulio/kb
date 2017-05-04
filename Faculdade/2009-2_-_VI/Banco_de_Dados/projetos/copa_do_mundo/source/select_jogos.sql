select distinct s1.time1 AS "Seleção1", 
s1.gol AS "GOL", 
s2.gol AS "GOL", 
s2.time2 AS "Seleção2", 
jogo.dia AS "DIA", 
jogo.hora AS "HORA", 
estadio.nome, 
estadio.cidade 
FROM pais, jogo, estadio,
/*vw_tb_1: dd - time1 - gol - time2 */
vw_tb_1 AS s1,
/*vw_tb_2: dd - time1 - gol - time2 */
vw_tb_2 AS s2 
WHERE jogo.cod_selecao1=s1.time1 
AND jogo.cod_selecao2=s1.time2 
AND jogo.cod_selecao1=s2.time1 
AND jogo.cod_selecao2=s2.time2 
AND jogo.dia=s1.dd 
AND jogo.dia=s2.dd 
AND jogo.cod_estadio=estadio.codigo 
ORDER BY jogo.dia;

/********************************************************/
/*INICIO DA CRIACAO DAS VIEWS*/
/*vw_tb_11: selecao1 - jogador_pais1 - selecao2*/
DROP VIEW vw_tb_11;
CREATE VIEW vw_tb_11 AS
/*vw_tb_11: selecao1 - jogador_pais1 - selecao2*/
select distinct gols.cod_jogo2 AS "selecao1",
gols.cod_jogador AS "jogador",
gols.cod_jogo3 AS "selecao2" 
FROM gols,jogador,pais 
WHERE gols.cod_jogador=jogador.codigo 
AND gols.cod_jogo2=pais.codigo 
AND jogador.cod_pais=gols.cod_jogo2


DROP VIEW vw_tb_1;
CREATE VIEW vw_tb_1 AS
/*vw_tb_1: dd - time1 - gol - time2 */
select jogo.dia AS "dd",
gols.cod_jogo2 AS "time1",
count(*) AS gol,
gols.cod_jogo3 AS "time2" 
FROM jogo,gols, 
/*vw_tb_11: selecao1 - jogador_pais1 - selecao2*/
vw_tb_11 AS tes 
WHERE tes.selecao1=jogo.cod_selecao1 
AND tes.selecao2=jogo.cod_selecao2 
AND gols.cod_jogo2=jogo.cod_selecao1 
AND gols.cod_jogo3=jogo.cod_selecao2 
AND tes.jogador=gols.cod_jogador 
AND jogo.dia=gols.cod_jogo1 
AND tes.selecao1=gols.cod_jogo2 
AND tes.selecao2=gols.cod_jogo3 
GROUP BY jogo.dia,gols.cod_jogo2,gols.cod_jogo3 
ORDER BY jogo.dia


DROP VIEW vw_tb_22;
CREATE VIEW vw_tb_22 AS
/*vw_tb_22: selecao1 - jogador_pais2 - selecao2*/
select distinct gols.cod_jogo2 AS "selecao1",
gols.cod_jogador AS "jogador",
gols.cod_jogo3 AS "selecao2" 
FROM gols,jogador,pais 
WHERE gols.cod_jogador=jogador.codigo 
AND gols.cod_jogo3=pais.codigo 
AND jogador.cod_pais=gols.cod_jogo3

DROP VIEW vw_tb_2;
CREATE VIEW vw_tb_2 AS
/*vw_tb_2: dd - time1 - gol - time2 */
select jogo.dia AS "dd",
gols.cod_jogo2 AS "time1",
count(*) AS gol,
gols.cod_jogo3 AS "time2" 
FROM jogo,gols, 
/*vw_tb_22: selecao1 - jogador_pais2 - selecao2*/
vw_tb_22 AS tes 
WHERE tes.selecao1=jogo.cod_selecao1 
AND tes.selecao2=jogo.cod_selecao2 
AND gols.cod_jogo2=jogo.cod_selecao1 
AND gols.cod_jogo3=jogo.cod_selecao2 
AND tes.jogador=gols.cod_jogador 
AND jogo.dia=gols.cod_jogo1 
AND tes.selecao1=gols.cod_jogo2 
AND tes.selecao2=gols.cod_jogo3 
GROUP BY jogo.dia,gols.cod_jogo2,gols.cod_jogo3 
ORDER BY jogo.dia 

/*PRINCIPAL*/

DROP VIEW vw_tb;
CREATE VIEW vw_tb AS
select distinct s1.time1 AS "Seleção1", 
s1.gol AS "GOL_1", 
s2.gol AS "GOL_2", 
s2.time2 AS "Seleção2", 
jogo.dia AS "DIA", 
jogo.hora AS "HORA", 
estadio.nome, 
estadio.cidade 
FROM pais, jogo, estadio,
/*vw_tb_1: dd - time1 - gol - time2 */
vw_tb_1 AS s1,
/*vw_tb_2: dd - time1 - gol - time2 */
vw_tb_2 AS s2 
WHERE jogo.cod_selecao1=s1.time1 
AND jogo.cod_selecao2=s1.time2 
AND jogo.cod_selecao1=s2.time1 
AND jogo.cod_selecao2=s2.time2 
AND jogo.dia=s1.dd 
AND jogo.dia=s2.dd 
AND jogo.cod_estadio=estadio.codigo 
ORDER BY jogo.dia;	
