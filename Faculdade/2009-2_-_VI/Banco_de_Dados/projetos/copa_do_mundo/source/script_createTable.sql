
/*SCRIPT DE CRIACAO DAS TABELAS*/

DROP TABLE Gols;
DROP TABLE Cartoes;
DROP TABLE Escalacao;
DROP TABLE Jogo;
DROP TABLE Estadio;
DROP TABLE Juiz;
DROP TABLE Bandeirinha;
DROP TABLE Jogador;
DROP TABLE Posicao;
DROP TABLE Pais;
DROP TABLE Chave;


CREATE TABLE Chave (
nome VARCHAR(20) NOT NULL,
CONSTRAINT pk_chave PRIMARY KEY(nome)
);

CREATE TABLE Pais (
codigo INTEGER NOT NULL,
nome VARCHAR(50) NOT NULL,
continente VARCHAR(50) NOT NULL,
cod_chave VARCHAR(20) NOT NULL,
tecnico VARCHAR(20) NOT NULL,
nParticipacoes INTEGER NOT NULL,
dtClassificacao DATE NOT NULL,
CONSTRAINT pk_pais PRIMARY KEY(codigo),
CONSTRAINT fk_cod_chave FOREIGN KEY(cod_chave) REFERENCES chave(nome)
);

CREATE TABLE Posicao (
nome VARCHAR(10) NOT NULL,
CONSTRAINT pk_posicao PRIMARY KEY(nome)
);


CREATE TABLE Jogador (
codigo INTEGER NOT NULL,
nome VARCHAR(50) NOT NULL,
dt_nasc DATE NOT NULL,
cod_pais INTEGER NOT NULL,
cod_posicao VARCHAR(10) NOT NULL,
cpf INTEGER NOT NULL,
nCamisa INTEGER NOT NULL,
CONSTRAINT pk_jogador PRIMARY KEY(codigo),
CONSTRAINT fk_cod_pais FOREIGN KEY(cod_pais) REFERENCES pais(codigo),
CONSTRAINT fk_cod_posicao FOREIGN KEY(cod_posicao) REFERENCES posicao(nome)
);

CREATE TABLE Juiz (
codigo INTEGER NOT NULL,
nome VARCHAR(50) NOT NULL,
dtNasc DATE NOT NULL,
cod_pais INTEGER NOT NULL,
CONSTRAINT pk_juiz PRIMARY KEY(codigo),
CONSTRAINT fk_cod_pais FOREIGN KEY(cod_pais) REFERENCES pais(codigo)
);


CREATE TABLE Bandeirinha (
codigo INTEGER NOT NULL,
nome VARCHAR(50) NOT NULL,
dt_nasc DATE NOT NULL,
cod_pais INTEGER NOT NULL,
CONSTRAINT pk_bandeirinha PRIMARY KEY(codigo),
CONSTRAINT fk_cod_pais FOREIGN KEY(cod_pais) REFERENCES pais(codigo)
);

CREATE TABLE Estadio (
codigo INTEGER NOT NULL,
nome VARCHAR(50) NOT NULL,
cidade VARCHAR(50) NOT NULL,
capacidade INTEGER NOT NULL,
CONSTRAINT pk_estadio PRIMARY KEY(codigo)
);

CREATE TABLE Jogo (
dia DATE NOT NULL,
hora INTEGER NOT NULL,
cod_selecao1 INTEGER NOT NULL,
cod_selecao2 INTEGER NOT NULL,
cod_estadio INTEGER NOT NULL,
cod_juiz1 INTEGER NOT NULL,
cod_juiz2 INTEGER NOT NULL,
cod_bandeira1 INTEGER NOT NULL,
cod_bandeira2 INTEGER NOT NULL,
CONSTRAINT pk_jogo PRIMARY KEY(dia,cod_selecao1,cod_selecao2),
CONSTRAINT fk_selecao1 FOREIGN KEY(cod_selecao1) REFERENCES pais(codigo),
CONSTRAINT fk_selecao2 FOREIGN KEY(cod_selecao2) REFERENCES pais(codigo),
CONSTRAINT fk_estadio FOREIGN KEY(cod_estadio) REFERENCES estadio(codigo)
);


CREATE TABLE Escalacao (
cod_jogo1 DATE NOT NULL,
cod_jogo2 INTEGER NOT NULL,
cod_jogo3 INTEGER NOT NULL,
cod_jogador INTEGER NOT NULL,
hrInicio INTEGER,
substituido INTEGER,
hrSubstituicao INTEGER,
CONSTRAINT pk_escalacao PRIMARY KEY(cod_jogo1,cod_jogo2,cod_jogo3,cod_jogador),
CONSTRAINT fk_escalacao_jogo FOREIGN KEY(cod_jogo1,cod_jogo2,cod_jogo3) REFERENCES jogo(dia,cod_selecao1,cod_selecao2),
CONSTRAINT fk_escalacao_jogador FOREIGN KEY(cod_jogador) REFERENCES jogador(codigo)
);

CREATE TABLE Gols (
cod_jogo1 DATE NOT NULL,
cod_jogo2 INTEGER NOT NULL,
cod_jogo3 INTEGER NOT NULL,
cod_jogador INTEGER NOT NULL,
tempo INTEGER NOT NULL,
CONSTRAINT pk_gols PRIMARY KEY(cod_jogo1,cod_jogo2,cod_jogo3,cod_jogador,tempo),
CONSTRAINT fk_gols_jogo FOREIGN KEY(cod_jogo1,cod_jogo2,cod_jogo3) REFERENCES jogo(dia,cod_selecao1,cod_selecao2),
CONSTRAINT fk_gols_jogador FOREIGN KEY(cod_jogador) REFERENCES jogador(codigo)
);


CREATE TABLE Cartoes (
cod_jogo1 DATE NOT NULL,
cod_jogo2 INTEGER NOT NULL,
cod_jogo3 INTEGER NOT NULL,
cod_jogador INTEGER NOT NULL,
tempo INTEGER NOT NULL,
corCartao VARCHAR(10) NOT NULL,
CONSTRAINT pk_cartoes PRIMARY KEY(cod_jogo1,cod_jogo2,cod_jogo3,cod_jogador,tempo),
CONSTRAINT fk_cartoes_jogo FOREIGN KEY(cod_jogo1,cod_jogo2,cod_jogo3) REFERENCES jogo(dia,cod_selecao1,cod_selecao2),
CONSTRAINT fk_cartoes_jogador FOREIGN KEY(cod_jogador) REFERENCES jogador(codigo)
);

