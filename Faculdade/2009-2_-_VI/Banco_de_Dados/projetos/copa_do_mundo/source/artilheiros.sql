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
