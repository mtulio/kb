select pais.nome AS "Nome do País", count(*) AS "Placar" FROM pais,jogo,gols where gols.cod_jogo2=jogo.cod_selecao1 AND pais.codigo=jogo.cod_selecao1 GROUP BY pais.nome ORDER BY pais.nome;

select gols.cod_jogador AS "GOLS" FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3

select pais.nome AS "Selecao1", gols1.qtd AS "GOLS", gols2.qtd AS "GOLS1",  (select count(*) AS qtd FROM (select gols.cod_jogador, AS "GOLS" FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3) AS s1) AS gols1,(select count(*) AS qtd FROM (select gols.cod_jogador AS "GOLS" FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3) AS s2) AS gols2;


select s1.sel1 AS "Selecao1", gols1.qtd AS "GOLS", gols2.qtd AS "GOLS1",s2.sel2 AS "Selecao2", jogo.dia AS "DATA"  FROM jogo,(select count(*) AS qtd FROM (select gols.cod_jogador,jogo.cod_selecao1 AS sel1, jogo.dia AS d1 FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3) AS s1) AS gols1,(select count(*) AS qtd FROM (select gols.cod_jogador, jogo.cod_selecao2 AS sel2, jogo.dia AS d2 FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3) AS s2) AS gols2 WHERE jogo.dia=s1.d1 AND jodo.dia=s2.d2;


	select jogo.cod_selecao1 AS "Selecao1", gols1.qtd AS "GOLS", gols2.qtd AS "GOLS1",jogo.cod_selecao2 AS "Selecao2", jogo.dia AS "DATA"  FROM jogo,(select count(*) AS qtd FROM (select gols.cod_jogador,jogo.cod_selecao1 AS sel1, jogo.dia AS d1 FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3) AS s1) AS gols1,(select count(*) AS qtd FROM (select gols.cod_jogador, jogo.cod_selecao2 AS sel2, jogo.dia AS d2 FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3) AS s2) AS gols2;

		select count(*) AS qtd, jogo.cod_selecao1 FROM jogo,(select gols.cod_jogador,jogo.cod_selecao1 AS sel1, jogo.dia AS d1 FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3) AS s1 WHERE jogo.cod_selecao1=s1.sel1 AND s1.d1=jogo.dia GROUP BY jogo.cod_selecao1;
		select count(*) AS qtd, jogo.cod_selecao2 FROM jogo,(select gols.cod_jogador,jogo.cod_selecao2 AS sel2, jogo.dia AS d2 FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3) AS s2 WHERE jogo.cod_selecao2=s2.sel2 AND s2.d2=jogo.dia GROUP BY jogo.cod_selecao2;


select jogo.cod_selecao1, count(*) AS qtd, jogo.cod_selecao2 FROM jogo,(select gols.cod_jogador,jogo.cod_selecao2 AS sel2,jogo.cod_selecao1 AS sel1, jogo.dia AS d2 FROM gols,jogo WHERE jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3 AND gols.cod_jogo1=jogo.dia) AS s2 WHERE jogo.cod_selecao2=s2.sel2 AND s2.d2=jogo.dia AND jogo.cod_selecao1=s2.sel1 GROUP BY jogo.cod_selecao1,jogo.cod_selecao2;



select gols.cod_jogo2 AS "Seleção1",gols.cod_jogador AS "Jogador",pais.nome AS "País" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2;


select gols.cod_jogo2 AS "Seleção1",pais.nome AS "País",gols.cod_jogador AS "Jogador",gols.cod_jogo3 AS "Seleção2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2;


TESTE select jogo.cod_selecao1, count(*) AS qtd, jogo.cod_selecao2 FROM jogo,(select gols.cod_jogador,jogo.cod_selecao2 AS sel2,jogo.cod_selecao1 AS sel1, jogo.dia AS d2 FROM (select gols.cod_jogo2 AS "Seleção1",pais.codigo,gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "Seleção2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2) AS pais1,gols,jogo WHERE pais1.jogador=gols.cod_jogador AND jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3 AND gols.cod_jogo1=jogo.dia) AS s2 WHERE jogo.cod_selecao2=s2.sel2 AND s2.d2=jogo.dia AND jogo.cod_selecao1=s2.sel1 GROUP BY jogo.cod_selecao1,jogo.cod_selecao2;


select jogo.cod_selecao1, count(*) AS qtd, jogo.cod_selecao2 FROM jogo,(select gols.cod_jogador,jogo.cod_selecao2 AS sel2,jogo.cod_selecao1 AS sel1, jogo.dia AS d2 FROM gols,jogo,
(select gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2) AS web
WHERE web.selecao1=gols.cod_jogo2 AND web.selecao2=gols.cod_jogo3 AND web.jogador=gols.cod_jogador AND jogo.cod_selecao1=gols.cod_jogo2 AND jogo.cod_selecao2=gols.cod_jogo3 AND gols.cod_jogo1=jogo.dia) AS s2 WHERE jogo.cod_selecao2=s2.sel2 AND s2.d2=jogo.dia AND jogo.cod_selecao1=s2.sel1 GROUP BY jogo.cod_selecao1,jogo.cod_selecao2;


select gols.cod_jogo2 AS "Seleção1",gols.cod_jogador AS "Jogador",gols.cod_jogo3 AS "Seleção2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2;











select count(*) FROM (select gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2) AS tes WHERE tes.selecao1=2 AND tes.selecao2=3;



select count(*) FROM (select gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo3=pais.codigo AND jogador.cod_pais=gols.cod_jogo3) AS tes WHERE tes.selecao1=2 AND tes.selecao2=3;


Imprimindo GOls do jogo 2x3
select gols.cod_jogo2 AS "Seleção1",count(*),gols.cod_jogo3 AS "Seleção2" FROM gols,(select gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2) AS tes WHERE tes.selecao1=2 AND tes.selecao2=3 AND gols.cod_jogo2=2 AND gols.cod_jogo3=3 AND tes.jogador=gols.cod_jogador GROUP BY gols.cod_jogo2,gols.cod_jogo3;

GERAL(Duplicidade)
select jogo.dia AS "DATA",gols.cod_jogo2 AS "Seleção1",count(*),gols.cod_jogo3 AS "Seleção2" FROM jogo,gols, (select gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2) AS tes WHERE tes.selecao1=jogo.cod_selecao1 AND tes.selecao2=jogo.cod_selecao2 AND gols.cod_jogo2=jogo.cod_selecao1 AND gols.cod_jogo3=jogo.cod_selecao2 AND tes.jogador=gols.cod_jogador AND jogo.dia=gols.cod_jogo1 AND tes.selecao1=gols.cod_jogo2 AND tes.selecao2=gols.cod_jogo3 GROUP BY jogo.dia,gols.cod_jogo2,gols.cod_jogo3 ORDER BY jogo.dia;

(OK)
select jogo.dia AS "DATA",gols.cod_jogo2 AS "Seleção1",count(*),gols.cod_jogo3 AS "Seleção2" FROM jogo,gols, (select distinct gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2) AS tes WHERE tes.selecao1=jogo.cod_selecao1 AND tes.selecao2=jogo.cod_selecao2 AND gols.cod_jogo2=jogo.cod_selecao1 AND gols.cod_jogo3=jogo.cod_selecao2 AND tes.jogador=gols.cod_jogador AND jogo.dia=gols.cod_jogo1 AND tes.selecao1=gols.cod_jogo2 AND tes.selecao2=gols.cod_jogo3 GROUP BY jogo.dia,gols.cod_jogo2,gols.cod_jogo3 ORDER BY jogo.dia;


select distinct s1.time1 AS "Seleção1", s1.gol AS "GOL", s2.gol AS "GOL", s2.time2 AS "Seleção2", jogo.dia AS "DIA", jogo.hora AS "HORA", estadio.nome, estadio.cidade FROM pais, jogo, estadio,(select jogo.dia AS "dd",gols.cod_jogo2 AS "time1",count(*) AS gol,gols.cod_jogo3 AS "time2" FROM jogo,gols, (select distinct gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo2=pais.codigo AND jogador.cod_pais=gols.cod_jogo2) AS tes WHERE tes.selecao1=jogo.cod_selecao1 AND tes.selecao2=jogo.cod_selecao2 AND gols.cod_jogo2=jogo.cod_selecao1 AND gols.cod_jogo3=jogo.cod_selecao2 AND tes.jogador=gols.cod_jogador AND jogo.dia=gols.cod_jogo1 AND tes.selecao1=gols.cod_jogo2 AND tes.selecao2=gols.cod_jogo3 GROUP BY jogo.dia,gols.cod_jogo2,gols.cod_jogo3 ORDER BY jogo.dia) AS s1,(select jogo.dia AS "dd",gols.cod_jogo2 AS "time1",count(*) AS gol,gols.cod_jogo3 AS "time2" FROM jogo,gols, (select distinct gols.cod_jogo2 AS "selecao1",gols.cod_jogador AS "jogador",gols.cod_jogo3 AS "selecao2" FROM gols,jogador,pais WHERE gols.cod_jogador=jogador.codigo AND gols.cod_jogo3=pais.codigo AND jogador.cod_pais=gols.cod_jogo3) AS tes WHERE tes.selecao1=jogo.cod_selecao1 AND tes.selecao2=jogo.cod_selecao2 AND gols.cod_jogo2=jogo.cod_selecao1 AND gols.cod_jogo3=jogo.cod_selecao2 AND tes.jogador=gols.cod_jogador AND jogo.dia=gols.cod_jogo1 AND tes.selecao1=gols.cod_jogo2 AND tes.selecao2=gols.cod_jogo3 GROUP BY jogo.dia,gols.cod_jogo2,gols.cod_jogo3 ORDER BY jogo.dia) AS s2 WHERE jogo.cod_selecao1=s1.time1 AND jogo.cod_selecao2=s1.time2 AND jogo.cod_selecao1=s2.time1 AND jogo.cod_selecao2=s2.time2 AND jogo.dia=s1.dd AND jogo.dia=s2.dd AND jogo.cod_estadio=estadio.codigo ORDER BY jogo.dia;
