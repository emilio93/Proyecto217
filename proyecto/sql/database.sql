SET FOREIGN_KEY_CHECKS=0;
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "-06:00";

CREATE DATABASE IF NOT EXISTS `horarios` DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_general_ci;
USE `horarios`;

-- LISTA DE TABLAS -orden alfabético-
--
-- 1  Bloque
-- 2  Curso
-- 3  CursosBloque
-- 4  Grupo
-- 5  GruposHorario
-- 6  Horario
-- 7  HorariosCurso
-- 8  Instante
-- 9  PeriodoGrupo
-- 10 Periodo
-- 11 PeriodoProfesor
-- 12 Plan
-- 13 Profesor
-- 14 ProfesoresCurso

DROP TABLE IF EXISTS `Bloque`;
CREATE TABLE IF NOT EXISTS `Bloque` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idPlan` int(11) NOT NULL,
  `semestre` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idPlan` (`idPlan`),
  FOREIGN KEY (`idPlan`) REFERENCES `Plan` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `Curso`;
CREATE TABLE IF NOT EXISTS `Curso` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `cantidadHoras` int(11) NOT NULL,
  `clasesEnSemana` int(11) NOT NULL,
  `cantidadGrupos` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `sigla` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `CursosBloque`;
CREATE TABLE IF NOT EXISTS `CursosBloque` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idBloque` int(11) NOT NULL,
  `idCurso` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idBloque` (`idBloque`),
  KEY `idCurso` (`idCurso`),
  Key `unico` (`idBloque`, `idCurso`),
  FOREIGN KEY (`idBloque`) REFERENCES `Bloque` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)  ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `Grupo`;
CREATE TABLE IF NOT EXISTS `Grupo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idCurso` int(11) NOT NULL,
  `idProfesor` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idCurso` (`idCurso`,`idProfesor`),
  KEY `idProfesor` (`idProfesor`),
  FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `GruposHorario`;
CREATE TABLE IF NOT EXISTS `GruposHorario` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idHorario` int(11) NOT NULL,
  `idGrupo` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idHorario` (`idHorario`),
  KEY `idGrupo` (`idGrupo`),
  FOREIGN KEY (`idHorario`) REFERENCES `Horario` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (`idGrupo`) REFERENCES `Grupo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `Horario`;
CREATE TABLE IF NOT EXISTS `Horario` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `HorariosCurso`;
CREATE TABLE IF NOT EXISTS `HorariosCurso` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idCurso` int(11) NOT NULL,
  `idPeriodo` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idCurso` (`idCurso`),
  KEY `idPeriodo` (`idPeriodo`),
  FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `Instante`;
CREATE TABLE IF NOT EXISTS `Instante` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `dia` int(11) NOT NULL,
  `hora` int(11) NOT NULL,
  `minuto` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `Periodo`;
CREATE TABLE IF NOT EXISTS `Periodo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idInstanteInicio` int(11) NOT NULL,
  `idInstanteFin` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idInstanteInicio` (`idInstanteInicio`,`idInstanteFin`),
  KEY `idInstanteFin` (`idInstanteFin`),
  FOREIGN KEY (`idInstanteInicio`) REFERENCES `Instante` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (`idInstanteFin`) REFERENCES `Instante` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `PeriodoGrupo`;
CREATE TABLE IF NOT EXISTS `PeriodoGrupo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idGrupo` int(11) NOT NULL,
  `idPeriodo` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idGrupo` (`idGrupo`,`idPeriodo`),
  KEY `idPeriodo` (`idPeriodo`),
  FOREIGN KEY (`idGrupo`) REFERENCES `Grupo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `PeriodoProfesor`;
CREATE TABLE IF NOT EXISTS `PeriodoProfesor` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idProfesor` int(11) NOT NULL,
  `idPeriodo` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idPeriodo` (`idPeriodo`,`idProfesor`),
  KEY `idProfesor` (`idProfesor`),
  FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `Plan`;
CREATE TABLE IF NOT EXISTS `Plan` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `Profesor`;
CREATE TABLE IF NOT EXISTS `Profesor` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `horasLaborales` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `apellido` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;

DROP TABLE IF EXISTS `ProfesoresCurso`;
CREATE TABLE IF NOT EXISTS `ProfesoresCurso` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idCurso` int(11) NOT NULL,
  `idProfesor` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idCurso` (`idCurso`,`idProfesor`),
  KEY `idProfesor` (`idProfesor`),
  FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;
