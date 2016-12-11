DROP TABLE Especialidades;
CREATE TABLE Especialidades(
	codigo int NOT NULL,
	nome varchar(20) NOT NULL,
	CONSTRAINT pkEspecialidade PRIMARY KEY(codigo)
);
ALTER TABLE Empregado ADD COLUMN especialidade int;

ALTER TABLE Empregado ADD CONSTRAINT fkEspecialidade FOREIGN KEY(especialidade) references Especialidades (codigo);
