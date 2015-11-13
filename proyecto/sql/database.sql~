-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 13, 2015 at 01:40 PM
-- Server version: 5.5.46-0ubuntu0.14.04.2
-- PHP Version: 5.5.9-1ubuntu4.14

SET FOREIGN_KEY_CHECKS=0;
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `horarios`
--
CREATE DATABASE IF NOT EXISTS `horarios` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `horarios`;

-- --------------------------------------------------------

--
-- Table structure for table `Bloque`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `Bloque`;
CREATE TABLE IF NOT EXISTS `Bloque` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idPlan` int(11) NOT NULL,
  `semestre` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idPlan` (`idPlan`),
  KEY `idPlan_2` (`idPlan`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=19 ;

--
-- RELATIONS FOR TABLE `Bloque`:
--   `idPlan`
--       `Plan` -> `id`
--

--
-- Truncate table before insert `Bloque`
--

TRUNCATE TABLE `Bloque`;
--
-- Dumping data for table `Bloque`
--

INSERT INTO `Bloque` (`id`, `idPlan`, `semestre`) VALUES
(1, 1, 3),
(2, 1, 4),
(3, 1, 5),
(4, 1, 6),
(5, 1, 7),
(6, 1, 8),
(7, 2, 3),
(8, 2, 4),
(9, 2, 5),
(10, 2, 6),
(11, 2, 7),
(12, 2, 8),
(13, 3, 3),
(14, 3, 4),
(15, 3, 5),
(16, 3, 6),
(17, 3, 7),
(18, 3, 8);

-- --------------------------------------------------------

--
-- Table structure for table `Curso`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `Curso`;
CREATE TABLE IF NOT EXISTS `Curso` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `cantidadHoras` int(11) NOT NULL,
  `clasesEnSemana` int(11) NOT NULL,
  `cantidadGrupos` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `sigla` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Truncate table before insert `Curso`
--

TRUNCATE TABLE `Curso`;
--
-- Dumping data for table `Curso`
--

INSERT INTO `Curso` (`id`, `cantidadHoras`, `clasesEnSemana`, `cantidadGrupos`, `nombre`, `sigla`) VALUES
(1, 4, 2, 3, 'Circuitos Lineales I', 'IE0209'),
(2, 4, 2, 3, 'Circuitos Lineales II', 'IE0309'),
(3, 5, 2, 3, 'Matemáticas Superiores', 'IE0305'),
(4, 6, 2, 3, 'Programación bajo Plataformas Abiertas', 'IE0117'),
(5, 6, 2, 2, 'Estructuras Abstractas de Datos', 'IE0217'),
(6, 4, 2, 3, 'Electrónica I', 'IE0313'),
(7, 4, 2, 2, 'Circuitos Digitales I', 'IE0323'),
(8, 4, 2, 2, 'Modelos Probabilísticos de Señales y Sistemas', 'IE0405'),
(9, 4, 2, 2, 'Teoría del Campo I', 'IE0307'),
(10, 4, 2, 2, 'Laboratorio Eléctrico I', 'IE0308'),
(11, 4, 2, 2, 'Electrónica II', 'IE0413');

-- --------------------------------------------------------

--
-- Table structure for table `CursosBloque`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `CursosBloque`;
CREATE TABLE IF NOT EXISTS `CursosBloque` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idBloque` int(11) NOT NULL,
  `idCurso` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idBloque` (`idBloque`,`idCurso`),
  KEY `idCurso` (`idCurso`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=18 ;

--
-- RELATIONS FOR TABLE `CursosBloque`:
--   `idBloque`
--       `Bloque` -> `id`
--   `idCurso`
--       `Curso` -> `id`
--

--
-- Truncate table before insert `CursosBloque`
--

TRUNCATE TABLE `CursosBloque`;
--
-- Dumping data for table `CursosBloque`
--

INSERT INTO `CursosBloque` (`id`, `idBloque`, `idCurso`) VALUES
(1, 1, 1),
(10, 1, 4),
(2, 2, 2),
(7, 2, 3),
(11, 2, 5),
(12, 2, 6),
(13, 3, 7),
(14, 3, 8),
(15, 3, 9),
(16, 3, 10),
(17, 3, 11),
(3, 7, 1),
(4, 8, 2),
(8, 8, 3),
(5, 13, 1),
(6, 14, 2),
(9, 14, 3);

-- --------------------------------------------------------

--
-- Table structure for table `Grupo`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `Grupo`;
CREATE TABLE IF NOT EXISTS `Grupo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idCurso` int(11) NOT NULL,
  `idProfesor` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idCurso` (`idCurso`,`idProfesor`),
  KEY `idProfesor` (`idProfesor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- RELATIONS FOR TABLE `Grupo`:
--   `idCurso`
--       `Curso` -> `id`
--   `idProfesor`
--       `Profesor` -> `id`
--

--
-- Truncate table before insert `Grupo`
--

TRUNCATE TABLE `Grupo`;
-- --------------------------------------------------------

--
-- Table structure for table `GruposHorario`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `GruposHorario`;
CREATE TABLE IF NOT EXISTS `GruposHorario` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idHorario` int(11) NOT NULL,
  `idGrupo` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idHorario` (`idHorario`,`idGrupo`),
  KEY `idGrupo` (`idGrupo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- RELATIONS FOR TABLE `GruposHorario`:
--   `idHorario`
--       `Horario` -> `id`
--   `idGrupo`
--       `Grupo` -> `id`
--

--
-- Truncate table before insert `GruposHorario`
--

TRUNCATE TABLE `GruposHorario`;
-- --------------------------------------------------------

--
-- Table structure for table `Horario`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `Horario`;
CREATE TABLE IF NOT EXISTS `Horario` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Truncate table before insert `Horario`
--

TRUNCATE TABLE `Horario`;
-- --------------------------------------------------------

--
-- Table structure for table `Instante`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `Instante`;
CREATE TABLE IF NOT EXISTS `Instante` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `dia` int(11) NOT NULL,
  `hora` int(11) NOT NULL,
  `minuto` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Truncate table before insert `Instante`
--

TRUNCATE TABLE `Instante`;
-- --------------------------------------------------------

--
-- Table structure for table `Periodo`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `Periodo`;
CREATE TABLE IF NOT EXISTS `Periodo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idInstanteInicio` int(11) NOT NULL,
  `idInstanteFin` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idInstanteInicio` (`idInstanteInicio`,`idInstanteFin`),
  KEY `idInstanteFin` (`idInstanteFin`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- RELATIONS FOR TABLE `Periodo`:
--   `idInstanteInicio`
--       `Instante` -> `id`
--   `idInstanteFin`
--       `Instante` -> `id`
--

--
-- Truncate table before insert `Periodo`
--

TRUNCATE TABLE `Periodo`;
-- --------------------------------------------------------

--
-- Table structure for table `PeriodoGrupo`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `PeriodoGrupo`;
CREATE TABLE IF NOT EXISTS `PeriodoGrupo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idGrupo` int(11) NOT NULL,
  `idPeriodo` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idGrupo` (`idGrupo`,`idPeriodo`),
  KEY `idPeriodo` (`idPeriodo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- RELATIONS FOR TABLE `PeriodoGrupo`:
--   `idGrupo`
--       `Grupo` -> `id`
--   `idPeriodo`
--       `Periodo` -> `id`
--

--
-- Truncate table before insert `PeriodoGrupo`
--

TRUNCATE TABLE `PeriodoGrupo`;
-- --------------------------------------------------------

--
-- Table structure for table `PeriodoProfesor`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `PeriodoProfesor`;
CREATE TABLE IF NOT EXISTS `PeriodoProfesor` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idPeriodo` int(11) NOT NULL,
  `idProfesor` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idPeriodo` (`idPeriodo`,`idProfesor`),
  KEY `idProfesor` (`idProfesor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- RELATIONS FOR TABLE `PeriodoProfesor`:
--   `idProfesor`
--       `Profesor` -> `id`
--   `idPeriodo`
--       `Periodo` -> `id`
--

--
-- Truncate table before insert `PeriodoProfesor`
--

TRUNCATE TABLE `PeriodoProfesor`;
-- --------------------------------------------------------

--
-- Table structure for table `Plan`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `Plan`;
CREATE TABLE IF NOT EXISTS `Plan` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Truncate table before insert `Plan`
--

TRUNCATE TABLE `Plan`;
--
-- Dumping data for table `Plan`
--

INSERT INTO `Plan` (`id`, `nombre`) VALUES
(1, 'Electrónica y Telecomunicaciones'),
(2, 'Sistemas de Energía'),
(3, 'Computadoras y Redes');

-- --------------------------------------------------------

--
-- Table structure for table `Profesor`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `Profesor`;
CREATE TABLE IF NOT EXISTS `Profesor` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `horasLaborales` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `apellido` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Truncate table before insert `Profesor`
--

TRUNCATE TABLE `Profesor`;
-- --------------------------------------------------------

--
-- Table structure for table `ProfesoresCurso`
--
-- Creation: Nov 06, 2015 at 04:33 AM
--

DROP TABLE IF EXISTS `ProfesoresCurso`;
CREATE TABLE IF NOT EXISTS `ProfesoresCurso` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idCurso` int(11) NOT NULL,
  `idProfesor` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idCurso` (`idCurso`,`idProfesor`),
  KEY `idProfesor` (`idProfesor`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- RELATIONS FOR TABLE `ProfesoresCurso`:
--   `idCurso`
--       `Curso` -> `id`
--   `idProfesor`
--       `Profesor` -> `id`
--

--
-- Truncate table before insert `ProfesoresCurso`
--

TRUNCATE TABLE `ProfesoresCurso`;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `Bloque`
--
ALTER TABLE `Bloque`
  ADD CONSTRAINT `Bloque_ibfk_1` FOREIGN KEY (`idPlan`) REFERENCES `Plan` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `CursosBloque`
--
ALTER TABLE `CursosBloque`
  ADD CONSTRAINT `CursosBloque_ibfk_1` FOREIGN KEY (`idBloque`) REFERENCES `Bloque` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `CursosBloque_ibfk_2` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `Grupo`
--
ALTER TABLE `Grupo`
  ADD CONSTRAINT `Grupo_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `Grupo_ibfk_2` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `GruposHorario`
--
ALTER TABLE `GruposHorario`
  ADD CONSTRAINT `GruposHorario_ibfk_1` FOREIGN KEY (`idHorario`) REFERENCES `Horario` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `GruposHorario_ibfk_2` FOREIGN KEY (`idGrupo`) REFERENCES `Grupo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `Periodo`
--
ALTER TABLE `Periodo`
  ADD CONSTRAINT `Periodo_ibfk_1` FOREIGN KEY (`idInstanteInicio`) REFERENCES `Instante` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `Periodo_ibfk_2` FOREIGN KEY (`idInstanteFin`) REFERENCES `Instante` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `PeriodoGrupo`
--
ALTER TABLE `PeriodoGrupo`
  ADD CONSTRAINT `PeriodoGrupo_ibfk_1` FOREIGN KEY (`idGrupo`) REFERENCES `Grupo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `PeriodoGrupo_ibfk_2` FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `PeriodoProfesor`
--
ALTER TABLE `PeriodoProfesor`
  ADD CONSTRAINT `PeriodoProfesor_ibfk_1` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `PeriodoProfesor_ibfk_2` FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `ProfesoresCurso`
--
ALTER TABLE `ProfesoresCurso`
  ADD CONSTRAINT `ProfesoresCurso_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `ProfesoresCurso_ibfk_2` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;
SET FOREIGN_KEY_CHECKS=1;
