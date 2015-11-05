-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 05, 2015 at 02:03 AM
-- Server version: 5.5.46-0ubuntu0.14.04.2
-- PHP Version: 5.5.9-1ubuntu4.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `horarios`
--
CREATE DATABASE IF NOT EXISTS `horarios` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `horarios`;

-- --------------------------------------------------------

--
-- Table structure for table `Bloque`
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

DROP TABLE IF EXISTS `Curso`;
CREATE TABLE IF NOT EXISTS `Curso` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idBloque` int(11) NOT NULL,
  `cantidadHoras` int(11) NOT NULL,
  `clasesEnSemana` int(11) NOT NULL,
  `cantidadGrupos` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `sigla` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idBloque` (`idBloque`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- RELATIONS FOR TABLE `Curso`:
--   `idBloque`
--       `Bloque` -> `id`
--

-- --------------------------------------------------------

--
-- Table structure for table `Grupo`
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
--   `idProfesor`
--       `Profesor` -> `id`
--   `idCurso`
--       `Curso` -> `id`
--

-- --------------------------------------------------------

--
-- Table structure for table `GruposHorario`
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
--   `idGrupo`
--       `Grupo` -> `id`
--   `idHorario`
--       `Horario` -> `id`
--

-- --------------------------------------------------------

--
-- Table structure for table `Horario`
--

DROP TABLE IF EXISTS `Horario`;
CREATE TABLE IF NOT EXISTS `Horario` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Instante`
--

DROP TABLE IF EXISTS `Instante`;
CREATE TABLE IF NOT EXISTS `Instante` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `dia` int(11) NOT NULL,
  `hora` int(11) NOT NULL,
  `minuto` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Periodo`
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
--   `idInstanteFin`
--       `Instante` -> `id`
--   `idInstanteInicio`
--       `Instante` -> `id`
--

-- --------------------------------------------------------

--
-- Table structure for table `PeriodoGrupo`
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
--   `idPeriodo`
--       `Periodo` -> `id`
--   `idGrupo`
--       `Grupo` -> `id`
--

-- --------------------------------------------------------

--
-- Table structure for table `PeriodoProfesor`
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
--   `idPeriodo`
--       `Periodo` -> `id`
--   `idProfesor`
--       `Profesor` -> `id`
--

-- --------------------------------------------------------

--
-- Table structure for table `Plan`
--

DROP TABLE IF EXISTS `Plan`;
CREATE TABLE IF NOT EXISTS `Plan` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

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

DROP TABLE IF EXISTS `Profesor`;
CREATE TABLE IF NOT EXISTS `Profesor` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `horasLaborales` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `apellido` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProfesoresCurso`
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
--   `idProfesor`
--       `Profesor` -> `id`
--   `idCurso`
--       `Curso` -> `id`
--

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Bloque`
--
ALTER TABLE `Bloque`
  ADD CONSTRAINT `Bloque_ibfk_1` FOREIGN KEY (`idPlan`) REFERENCES `Plan` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `Curso`
--
ALTER TABLE `Curso`
  ADD CONSTRAINT `Curso_ibfk_1` FOREIGN KEY (`idBloque`) REFERENCES `Bloque` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `Grupo`
--
ALTER TABLE `Grupo`
  ADD CONSTRAINT `Grupo_ibfk_2` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `Grupo_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `GruposHorario`
--
ALTER TABLE `GruposHorario`
  ADD CONSTRAINT `GruposHorario_ibfk_2` FOREIGN KEY (`idGrupo`) REFERENCES `Grupo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `GruposHorario_ibfk_1` FOREIGN KEY (`idHorario`) REFERENCES `Horario` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `Periodo`
--
ALTER TABLE `Periodo`
  ADD CONSTRAINT `Periodo_ibfk_2` FOREIGN KEY (`idInstanteFin`) REFERENCES `Instante` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `Periodo_ibfk_1` FOREIGN KEY (`idInstanteInicio`) REFERENCES `Instante` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `PeriodoGrupo`
--
ALTER TABLE `PeriodoGrupo`
  ADD CONSTRAINT `PeriodoGrupo_ibfk_2` FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `PeriodoGrupo_ibfk_1` FOREIGN KEY (`idGrupo`) REFERENCES `Grupo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `PeriodoProfesor`
--
ALTER TABLE `PeriodoProfesor`
  ADD CONSTRAINT `PeriodoProfesor_ibfk_2` FOREIGN KEY (`idPeriodo`) REFERENCES `Periodo` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `PeriodoProfesor_ibfk_1` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `ProfesoresCurso`
--
ALTER TABLE `ProfesoresCurso`
  ADD CONSTRAINT `ProfesoresCurso_ibfk_2` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `ProfesoresCurso_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
