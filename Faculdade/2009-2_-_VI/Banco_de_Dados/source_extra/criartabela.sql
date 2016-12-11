DROP TABLE Cargo;
DROP TABLE Especialidades;
DROP TABLE Empregado;
DROP TABLE Departamento;
create table Departamento
( codigo int not null, nome varchar(20) not null,
constraint pkdepart primary key(codigo));

create table Empregado
( matricula int not null,
  nome varchar(20) not null,
  dt_nasc date not null,
  cod_depto int not null,
  cod_cargo int not null,
  constraint pkEmpregado primary key(matricula),
  constraint fkEmpregadoDepartamento foreign key(cod_depto)
  references Departamento (codigo));

create table Cargo
( codigo int not null,
  nome varchar not null,
  salario numeric not null,
  constraint pkCargo primary key(codigo),
  constraint fkCargoEmpregado foreign key(codigo)
  references Empregado (matricula));
