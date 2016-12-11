DROP TABLE cargo;
DROP TABLE empregado;
DROP TABLE departamento;


CREATE TABLE cargo (
    codigo integer NOT NULL,
    nome character varying(20),
    salario integer NOT NULL
);



--
-- Name: departamento; Type: TABLE; Schema: public; Owner: marcotulio; Tablespace: 
--

CREATE TABLE departamento (
    codigo integer NOT NULL,
    nome character varying(60)
);


--
-- Name: empregado; Type: TABLE; Schema: public; Owner: marcotulio; Tablespace: 
--

CREATE TABLE empregado (
    matricula integer NOT NULL,
    nome character varying(30) NOT NULL,
    dt_nasc date NOT NULL,
    cod_depto integer NOT NULL,
    cod_cargo integer NOT NULL
);


--
-- Name: pk_cargo; Type: CONSTRAINT; Schema: public; Owner: marcotulio; Tablespace: 
--

ALTER TABLE ONLY cargo
    ADD CONSTRAINT pk_cargo PRIMARY KEY (codigo);


--
-- Name: pk_departamento; Type: CONSTRAINT; Schema: public; Owner: marcotulio; Tablespace: 
--

ALTER TABLE ONLY departamento
    ADD CONSTRAINT pk_departamento PRIMARY KEY (codigo);


--
-- Name: pk_empregado; Type: CONSTRAINT; Schema: public; Owner: marcotulio; Tablespace: 
--

ALTER TABLE ONLY empregado
    ADD CONSTRAINT pk_empregado PRIMARY KEY (matricula);


--
-- Name: fk1_depto; Type: FK CONSTRAINT; Schema: public; Owner: marcotulio
--

ALTER TABLE ONLY empregado
    ADD CONSTRAINT fk1_depto FOREIGN KEY (cod_depto) REFERENCES departamento(codigo);


--
-- Name: fk2_cargo; Type: FK CONSTRAINT; Schema: public; Owner: marcotulio
--

ALTER TABLE ONLY empregado
    ADD CONSTRAINT fk2_cargo FOREIGN KEY (cod_cargo) REFERENCES cargo(codigo);


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

--
-- PostgreSQL database dump complete
--

