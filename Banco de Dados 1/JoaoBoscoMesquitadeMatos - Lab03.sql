--Listar o nome do projeto e o nome do departamento que o controla

select nom_projeto, nom_depto
	from projeto JOIN departamento
	ON departamento.cod_depto = projeto.cod_depto

--Listar a matr�cula, o nome dos empregados e o nome do departamento de cada um.

select num_matricula, nom_empregado , nom_depto
	from empregado JOIN departamento
	ON empregado.cod_depto = departamento.cod_depto

-- Listar os gerentes e o departamento que eles gerenciam.

select nom_empregado, nom_depto
	from empregado JOIN departamento
	ON departamento.num_matricula_gerente = empregado.num_matricula

--Listar os empregados e os respectivos dependentes

select nom_empregado, nom_dependente
	from empregado JOIN dependente
	ON empregado.num_matricula = dependente.num_matricula

--Listar o nome do empregado e o respectivo supervisor.

select s.nom_empregado, e.nom_empregado as 'supervisor'
	from empregado e INNER JOIN empregado s
	ON e.num_matricula = s.num_matricula_supervisor

--Listar a matr�cula, o nome dos empregados, o nome do departamento de cada um e a
--matr�cula do gerente do departamento.

select num_matricula, nom_empregado, nom_depto, num_matricula_gerente
	from empregado JOIN departamento
 	ON empregado.cod_depto = departamento.cod_depto

-- Listar a matricula e o nome de todos os supervisores

select DISTINCT a.num_matricula_supervisor, b.nom_empregado
	from empregado a JOIN empregado b
	ON a.num_matricula_supervisor = b.num_matricula

--  Listar todos os empregados e o nome do respectivo supervisor (para quem tiver supervisor,
--  caso contr�rio, ser� listado NULL!)
--gerente (usar fun��o ISNULL para substituir NULL por �n�o encontrado�)
-- empregado, exibir tamb�m o nome dos empregados
-- matr�cula e o nome do gerente do departamento.
--alocados no projeto e o n�mero de horas de cada um deles.
--Listar o empregado, o respectivo departamento, o gerente do departamento, as horas
--alocadas em projetos, o nome do projeto e o respectivo departamento do projeto.


 
	INNER JOIN empregado g

	JOIN alocacao a
	on a.num_matricula = e.num_matricula

	INNER JOIN projeto p
	ON p.cod_depto = d.cod_depto

	



---Listar o empregado, o respectivo departamento, o gerente do departamento, as horas
--alocadas em projetos, o nome do projeto e o respectivo departamento do projeto para os
--empregados que est�o alocados em projetos controlados por outros departamentos
--nome do supervisor N�O come�ar com 'Jos�%')


