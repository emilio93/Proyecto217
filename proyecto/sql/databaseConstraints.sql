-- LISTA DE TABLAS, COLUMNAS Y RELACIONES
--
-- Bloque
--      id
--      idPlan --> Plan.id
--      idCurso -> Curso.id
--
-- Curso
--      id
--      cantidadHoras
--      clasesEnSemana
--      cantidadGrupos
--      nombre
--      sigla
--
-- CursosBloque
--      id
--      idBloque -> Bloque.id
--      idCurso --> Curso.id
--
-- Grupo
--      id
--      idCurso ----> Curso.id
--      idProfesor -> Profesor.id
--
-- GruposHorario
--      id
--      idHorario -> Horario.id
--      idGrupo ---> Grupo.id
--
-- Horario
--      id
--      nombre
--
-- HorariosCurso
--      id
--      idCurso ---> Curso.id
--      idPeriodo -> Periodo.id
--
-- Instante
--      id
--      dia
--      hora
--      minuto
--
-- Periodo
--      id
--      idInstanteInicio -> Instante.id
--      idInstanteFin ----> Instante.id
--
-- PeriodoGrupo
--      id
--      idGrupo ---> Grupo.id
--      idPeriodo -> Periodo.id
--
-- PeriodoProfesor
--      id
--      idProfesor -> Profesor.id
--      idPeriodo --> Periodo.id
--
-- Plan
--      id
--      nombre
--
-- Profesor
--      id
--      horasLaborales
--      nombre
--      apellido
--
-- ProfesoresCurso
--      id
--      idCurso ----> Curso.id
--      idProfesor -> Profesor.id
--
-- LISTA DE RELACIONES
--
-- Bloque.idPlan --------------> Plan.id
-- Bloque.idCurso -------------> Curso.id
--
-- CursosBloque.idBloque ------> Bloque.id
-- CursosBloque.idCurso -------> Curso.id
--
-- Grupo.idCurso --------------> Curso.id
-- Grupo.idProfesor -----------> Profesor.id
--
-- GruposHorario.idHorario ----> Horario.id
-- GruposHorario.idGrupo ------> Grupo.id
--
-- idCurso --------------------> Curso.id
-- idPeriodo ------------------> Periodo.id
--
-- Periodo.idInstanteInicio ---> Instante.id
-- Periodo.idInstanteFin ------> Instante.id
--
-- PeriodoGrupo.idGrupo -------> Grupo.id
-- PeriodoGrupo.idPeriodo -----> Periodo.id
--
-- PeriodoProfesor.idProfesor -> Profesor.id
-- PeriodoProfesor.idPeriodo --> Periodo.id
--
-- ProfesoresCurso.idCurso ----> Curso.id
-- ProfesoresCurso.idProfesor -> Profesor.id


ALTER TABLE `Bloque`
  ADD CONSTRAINT `Bloque_ibfk_1` FOREIGN KEY (`idPlan`) REFERENCES `Plan` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;
  ADD CONSTRAINT `Bloque_ibfk_2` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `CursosBloque`
  ADD CONSTRAINT `CursosBloque_ibfk_1` FOREIGN KEY (`idBloque`) REFERENCES `Bloque` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `CursosBloque_ibfk_2` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `Grupo`
  ADD CONSTRAINT `Grupo_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Grupo_ibfk_2` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `GruposHorario`
  ADD CONSTRAINT `GruposHorario_ibfk_1` FOREIGN KEY (`idHorario`) REFERENCES `Horario` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `GruposHorario_ibfk_2` FOREIGN KEY (`idGrupo`) REFERENCES `Grupo` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `HorariosCurso`
  ADD CONSTRAINT `HorariosCurso_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `HorariosCurso_ibfk_2` FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `Periodo`
  ADD CONSTRAINT `Periodo_ibfk_1` FOREIGN KEY (`idInstanteInicio`) REFERENCES `Instante` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Periodo_ibfk_2` FOREIGN KEY (`idInstanteFin`) REFERENCES `Instante` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `PeriodoGrupo`
  ADD CONSTRAINT `PeriodoGrupo_ibfk_1` FOREIGN KEY (`idGrupo`) REFERENCES `Grupo` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `PeriodoGrupo_ibfk_2` FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `PeriodoProfesor`
  ADD CONSTRAINT `PeriodoProfesor_ibfk_1` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `PeriodoProfesor_ibfk_2` FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `ProfesoresCurso`
  ADD CONSTRAINT `ProfesoresCurso_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `ProfesoresCurso_ibfk_2` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

SET FOREIGN_KEY_CHECKS=1;
