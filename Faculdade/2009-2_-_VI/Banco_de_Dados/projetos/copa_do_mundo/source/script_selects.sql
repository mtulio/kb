
/*SELECT PARA EXIBIR TABELA DOS JOGOS DA 1a FASE INDICANDO: Paises, Resultado do Jogo, Juiz da Partida, Data, Estadio*/

select distinct s1.p1 AS "Seleção1", s1.gol AS "GOL", s2.gol AS "GOL", s2.p2 AS "Seleção2", jogo.dia AS "Dia", jogo.hora AS "Hora", estadio.nome AS "Estádio", estadio.cidade AS "Cidade", juiz.nome AS "Arbitro" FROM pais, jogo, estadio,juiz,(select jogo.dia AS "dd",gols.cod_jogo2 AS "time1",pais.nome AS "p1",count(*) AS gol,gols.cod_jogo3 AS "time2" FROM jogo,gols,pais,(select distinct gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2) AS tes WHERE tes.selecao1=jogo.cod_selecao1 AND tes.selecao2=jogo.cod_selecao2 AND gols.cod_jogo2=jogo.cod_selecao1 AND gols.cod_jogo3=jogo.cod_selecao2 AND tes.jogador=gols.cod_jogador AND jogo.dia=gols.cod_jogo1 AND tes.selecao1=gols.cod_jogo2 AND tes.selecao2=gols.cod_jogo3 AND pais.codigo=jogo.cod_selecao1 AND pais.codigo=gols.cod_jogo2 GROUP BY jogo.dia,gols.cod_jogo2,pais.nome,gols.cod_jogo3 ORDER BY jogo.dia) AS s1,(select jogo.dia AS "dd",gols.cod_jogo2 AS "time1",count(*) AS gol,pais.nome AS "p2",gols.cod_jogo3 AS "time2" FROM jogo,gols,pais,(select distinct gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo3=pais.codigo AND jogador.cod_pais=gols.cod_jogo3) AS tes WHERE tes.selecao1=jogo.cod_selecao1 AND tes.selecao2=jogo.cod_selecao2 AND gols.cod_jogo2=jogo.cod_selecao1 AND gols.cod_jogo3=jogo.cod_selecao2 AND tes.jogador=gols.cod_jogador AND jogo.dia=gols.cod_jogo1 AND tes.selecao1=gols.cod_jogo2 AND tes.selecao2=gols.cod_jogo3 AND pais.codigo=jogo.cod_selecao2 AND pais.codigo=gols.cod_jogo3 GROUP BY jogo.dia,gols.cod_jogo2,pais.nome,gols.cod_jogo3 ORDER BY jogo.dia) AS s2 WHERE jogo.cod_selecao1=s1.time1 AND jogo.cod_selecao2=s1.time2 AND jogo.cod_selecao1=s2.time1 AND jogo.cod_selecao2=s2.time2 AND jogo.dia=s1.dd AND jogo.dia=s2.dd AND jogo.cod_estadio=estadio.codigo AND juiz.codigo=jogo.cod_juiz1 AND jogo.dia<'20/07/2010' ORDER BY jogo.dia;

/****************************************************************************************************/
/*  SELECT PARA EXIBIR O(S) JUIZ(ES) QUE MAIS APLICOU CARTAO VERMELHO */

/*A primeira a ser criada e a ultima a ser excluida*/
DROP VIEW vw_juizes_cartoes;
DROP VIEW vw_cartoes_max_cartoes;
DROP VIEW vw_cartoes_juiz_qtd_apl;
DROP VIEW vw_cartoes_juizes_apl_cartoes;
DROP VIEW vw_cartoes_ver_aplicados; /*1*/


/*Cartoes Vermelhos aplicados*/
CREATE VIEW vw_cartoes_ver_aplicados AS
select cartoes.cod_jogo1 AS jg_dia, cartoes.cod_jogo2 As jg_s1, cartoes.cod_jogo3 AS jg_s2, cartoes.corcartao
from cartoes
where cartoes.corcartao='VER';

/*Seleciona o codigo dos juizes que aplicaram cartão*/
CREATE VIEW vw_cartoes_juizes_apl_cartoes AS
select jogo.cod_juiz1 AS cod_juiz
from jogo, juiz, 
vw_cartoes_ver_aplicados AS s1
WHERE jogo.dia=s1.jg_dia
AND jogo.cod_selecao1=s1.jg_s1
AND jogo.cod_selecao2=s1.jg_s2
AND juiz.codigo=jogo.cod_juiz1;

/*Nome dos Juizes e quantidade de cartoes aplicados*/
CREATE VIEW vw_cartoes_juiz_qtd_apl AS
SELECT juiz.nome AS nome, count(*) AS maximo
FROM juiz,
vw_cartoes_juizes_apl_cartoes as s2
where s2.cod_juiz=juiz.codigo
GROUP BY juiz.nome;

/*Retorna o numero maximo de cartoes que um juiz aplicou*/
CREATE VIEW vw_cartoes_max_cartoes AS
SELECT MAX(s3.maximo) AS maximo
FROM juiz,
vw_cartoes_juiz_qtd_apl AS s3;

/*Juizes que mais aplicaram cartão*/

CREATE VIEW vw_juizes_cartoes AS
SELECT s1.maximo AS "Qtd Cartoes", s1.nome AS "Nome", pais.nome AS "Nacionalidade", juiz.dtnasc AS "Nascimento"
FROM juiz, pais,
vw_cartoes_juiz_qtd_apl AS s1,
vw_cartoes_max_cartoes AS S2
WHERE s2.maximo=s1.maximo
and s1.nome=juiz.nome
AND juiz.cod_pais=pais.codigo
ORDER BY s1.maximo;

/*Selecionando tudo*/
SELECT * FROM vw_juizes_cartoes;

/****************************************************************************************************/
/* SELECT PARA EXIBIR O(S) ARTILHEIRO(S) DA COṔA */


/*Eh preciso deletar as views em ordem decrescente*/
DROP VIEW vw_artilheiros;
DROP VIEW vw_gols_Max_nro_gols;
DROP VIEW vw_gols_jogadores_Por_Gols;
DROP VIEW vw_gols_jogadores;

/*Criando view para filtrar os codigos dos jogadores que fizeram gols na copa
para ser usado na proxima view que conta a qtd de gols q cada um fez*/
CREATE VIEW vw_gols_jogadores AS
select gols.cod_jogador As jogadores from gols;

/*Criando view para contar os gols que os jogadores fizeram na copa*/
CREATE VIEW vw_gols_jogadores_Por_Gols AS
SELECT s1.jogadores AS jogadores, count(s1.jogadores) AS todosGols FROM 
vw_gols_jogadores AS s1
GROUP BY s1.jogadores;

/*Criando view para saber o numero maximo de gols que um jogador fez na copa*/
CREATE VIEW vw_gols_Max_nro_gols AS
SELECT MAX(s2.todosGols) AS max
FROM vw_gols_jogadores_Por_Gols AS s2;

/*Enfim encontrando os jogadores que fizeram mais gols na copa filtrando pela
quantidade de gols que foram feitos pela view que retorna os jogadores que fizeram gols*/
SELECT jogador.nome AS "Nome do Jogador", s1.todosgols AS "Qtd Gols"
FROM jogador,
vw_gols_jogadores_Por_Gols AS s1,
vw_gols_Max_nro_gols AS s2
WHERE s1.todosgols=s2.max
AND jogador.codigo=s1.jogadores
GROUP BY jogador.nome, s1.todosgols;

/*Se quizer melhorar o Codigo crie uma view para os artilheiros*/
CREATE VIEW vw_artilheiros AS
SELECT jogador.nome AS "Nome do Jogador", s1.todosgols AS "Qtd Gols", pais.nome AS "Selecao", jogador.ncamisa AS "Nro da Camisa"
FROM jogador, pais,
vw_gols_jogadores_Por_Gols AS s1,
vw_gols_Max_nro_gols AS s2
WHERE s1.todosgols=s2.max
AND jogador.codigo=s1.jogadores
AND jogador.cod_pais=pais.codigo
GROUP BY jogador.nome, pais.nome, s1.todosgols, jogador.ncamisa;

/*Descobrindo quais foram os artilheiros da copa*/
SELECT * FROM vw_artilheiros;

/****************************************************************************************************/

/* SELECT PARA EXIBIR OS TIMES CLASSIFICADOS PARA AS OITAVAS DE FINAIS */


select distinct pais.nome AS "Países quasificados para as Oitavas de Finais" FROM pais,jogo WHERE (jogo.cod_selecao1=pais.codigo OR jogo.cod_selecao2=pais.codigo) AND jogo.dia>'19/07/2010' AND jogo.dia<'22/07/2010' ORDER BY pais.nome;

