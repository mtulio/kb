ALTER TABLE empregado;
ALTER TABLE ADD COLUMN id_especialidade INT NOT NULL;

DROP COLUMN id_especialidade;

ALTER TABLE ADD CONSTRAINTS fk-especialidade FOREIGN KEY(id_especialidade) REFERENCES especialidade(codigo);

DROP CONSTRAINT fk-especialidade;

