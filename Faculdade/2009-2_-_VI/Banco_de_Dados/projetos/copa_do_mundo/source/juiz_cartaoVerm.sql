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
