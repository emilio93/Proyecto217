-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 05, 2015 at 04:03 AM
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

CREATE TABLE IF NOT EXISTS `Curso` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `cantidadHoras` int(11) NOT NULL,
  `clasesEnSemana` int(11) NOT NULL,
  `cantidadGrupos` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `sigla` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `Curso`
--

INSERT INTO `Curso` (`id`, `cantidadHoras`, `clasesEnSemana`, `cantidadGrupos`, `nombre`, `sigla`) VALUES
(1, 4, 2, 3, 'Circuitos Lineales I', 'IE0209'),
(2, 4, 2, 3, 'Circuitos Lineales II', 'IE0309'),
(3, 5, 2, 3, 'Matemáticas Superiores', 'IE0305');

-- --------------------------------------------------------

--
-- Table structure for table `CursosBloque`
--

CREATE TABLE IF NOT EXISTS `CursosBloque` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idBloque` int(11) NOT NULL,
  `idCurso` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idBloque` (`idBloque`,`idCurso`),
  KEY `idCurso` (`idCurso`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- RELATIONS FOR TABLE `CursosBloque`:
--   `idCurso`
--       `Curso` -> `id`
--   `idBloque`
--       `Bloque` -> `id`
--

--
-- Dumping data for table `CursosBloque`
--

INSERT INTO `CursosBloque` (`id`, `idBloque`, `idCurso`) VALUES
(1, 1, 1),
(2, 2, 2),
(7, 2, 3),
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

CREATE TABLE IF NOT EXISTS `Horario` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Instante`
--

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
-- Constraints for table `CursosBloque`
--
ALTER TABLE `CursosBloque`
  ADD CONSTRAINT `CursosBloque_ibfk_2` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `CursosBloque_ibfk_1` FOREIGN KEY (`idBloque`) REFERENCES `Bloque` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

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
--
-- Database: `miBaseDeDatos`
--
CREATE DATABASE IF NOT EXISTS `miBaseDeDatos` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `miBaseDeDatos`;

-- --------------------------------------------------------

--
-- Table structure for table `tablaPrueba`
--

CREATE TABLE IF NOT EXISTS `tablaPrueba` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `contenido` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `tablaPrueba`
--

INSERT INTO `tablaPrueba` (`id`, `contenido`) VALUES
(1, 'Contenido 1'),
(2, 'Contenido 2');
--
-- Database: `phpmyadmin`
--
CREATE DATABASE IF NOT EXISTS `phpmyadmin` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `phpmyadmin`;

-- --------------------------------------------------------

--
-- Table structure for table `pma_bookmark`
--

CREATE TABLE IF NOT EXISTS `pma_bookmark` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `dbase` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `user` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `label` varchar(255) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `query` text COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Bookmarks' AUTO_INCREMENT=14 ;

--
-- Dumping data for table `pma_bookmark`
--

INSERT INTO `pma_bookmark` (`id`, `dbase`, `user`, `label`, `query`) VALUES
(1, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla \r\nFROM Curso \r\nINNER JOIN CursosBloque \r\n	ON Curso.id = CursosBloque.idCurso \r\n	INNER JOIN Bloque \r\n		ON CursosBloque.id = Bloque.id \r\nWHERE CursosBloque.idBloque = 1'),
(2, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla \r\nFROM Curso \r\nINNER JOIN CursosBloque \r\n	ON Curso.id = CursosBloque.idCurso \r\n	INNER JOIN Bloque \r\n		ON CursosBloque.id = Bloque.id \r\nWHERE CursosBloque.idBloque = 3'),
(3, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla \r\nFROM Curso \r\nINNER JOIN CursosBloque \r\n	ON Curso.id = CursosBloque.idCurso \r\n	INNER JOIN Bloque \r\n		ON CursosBloque.id = Bloque.id \r\nWHERE Bloque.id = 3'),
(4, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla \r\nFROM Curso, CursosBloque, Bloque\r\nWHERE CursosBloque.idBloque = 3'),
(5, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla \r\nFROM Curso, CursosBloque, Bloque\r\nWHERE CursosBloque.idBloque = 4'),
(6, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla \r\nFROM Curso, CursosBloque, Bloque\r\nWHERE CursosBloque.idBloque = 1'),
(7, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla, Bloque.id, Bloque.semestre\r\nFROM Curso, CursosBloque, Bloque\r\nWHERE CursosBloque.idBloque = 1'),
(8, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla, Bloque.id, Bloque.semestre\r\nFROM Curso, CursosBloque, Bloque\r\nWHERE Bloque.id = 1'),
(9, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla, Bloque.id, Bloque.semestre\r\nFROM Curso, CursosBloque, Bloque\r\nWHERE Bloque.id = 1\r\nAND CursosBloque.idBloque = Bloque.id'),
(10, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla, Bloque.id, Bloque.semestre, CursosBloque.id\r\nFROM Curso, CursosBloque, Bloque\r\nWHERE Bloque.id = 1\r\nAND CursosBloque.idBloque = Bloque.id'),
(11, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla, Bloque.id, Bloque.semestre, CursosBloque.id\r\nFROM Curso\r\nINNER JOIN CursosBloque\r\nON CursosBloque.idCurso = Curso.id\r\nINNER JOIN Bloque\r\nON Bloque.id = CursosBloque.idBloque'),
(12, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla, Bloque.id, Bloque.semestre, CursosBloque.id\r\nFROM Curso\r\nINNER JOIN CursosBloque\r\nON CursosBloque.idCurso = Curso.id\r\nINNER JOIN Bloque\r\nON Bloque.id = CursosBloque.idBloque\r\nWHERE Bloque.id = 1'),
(13, 'horarios', 'root', 'innerjoin1', 'SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla, Bloque.id, Bloque.semestre, CursosBloque.id\r\nFROM Curso\r\nINNER JOIN CursosBloque\r\nON CursosBloque.idCurso = Curso.id\r\nINNER JOIN Bloque\r\nON Bloque.id = CursosBloque.idBloque\r\nWHERE Bloque.id = 2');

-- --------------------------------------------------------

--
-- Table structure for table `pma_column_info`
--

CREATE TABLE IF NOT EXISTS `pma_column_info` (
  `id` int(5) unsigned NOT NULL AUTO_INCREMENT,
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `column_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `comment` varchar(255) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `mimetype` varchar(255) CHARACTER SET utf8 NOT NULL DEFAULT '',
  `transformation` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `transformation_options` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  PRIMARY KEY (`id`),
  UNIQUE KEY `db_name` (`db_name`,`table_name`,`column_name`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Column information for phpMyAdmin' AUTO_INCREMENT=51 ;

--
-- Dumping data for table `pma_column_info`
--

INSERT INTO `pma_column_info` (`id`, `db_name`, `table_name`, `column_name`, `comment`, `mimetype`, `transformation`, `transformation_options`) VALUES
(1, 'miBaseDeDatos', 'tablaPrueba', 'id', '', '', '_', ''),
(2, 'miBaseDeDatos', 'tablaPrueba', 'contenido', '', '', '_', ''),
(50, 'horarios', 'CursosBloque', 'idCurso', '', '', '_', ''),
(49, 'horarios', 'CursosBloque', 'idBloque', '', '', '_', ''),
(48, 'horarios', 'CursosBloque', 'id', '', '', '_', '');

-- --------------------------------------------------------

--
-- Table structure for table `pma_designer_coords`
--

CREATE TABLE IF NOT EXISTS `pma_designer_coords` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `x` int(11) DEFAULT NULL,
  `y` int(11) DEFAULT NULL,
  `v` tinyint(4) DEFAULT NULL,
  `h` tinyint(4) DEFAULT NULL,
  PRIMARY KEY (`db_name`,`table_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Table coordinates for Designer';

--
-- Dumping data for table `pma_designer_coords`
--

INSERT INTO `pma_designer_coords` (`db_name`, `table_name`, `x`, `y`, `v`, `h`) VALUES
('horarios', 'Plan', 29, 424, 1, 1),
('horarios', 'PeriodoProfesor', 249, 244, 1, 1),
('horarios', 'PeriodoGrupo', 376, 29, 1, 1),
('horarios', 'Periodo', 698, 57, 1, 1),
('horarios', 'Instante', 914, 36, 1, 1),
('horarios', 'Horario', 1156, 58, 1, 1),
('horarios', 'GruposHorario', 1120, 270, 1, 1),
('horarios', 'Grupo', 624, 671, 1, 1),
('horarios', 'Curso', 488, 410, 1, 1),
('horarios', 'Bloque', 264, 424, 1, 1),
('horarios', 'Profesor', 70, 27, 1, 1),
('horarios', 'ProfesoresCurso', 761, 419, 1, 1),
('horarios', 'CursosBloque', 662, 184, 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `pma_history`
--

CREATE TABLE IF NOT EXISTS `pma_history` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `db` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `timevalue` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `sqlquery` text COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`),
  KEY `username` (`username`,`db`,`table`,`timevalue`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='SQL history for phpMyAdmin' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `pma_pdf_pages`
--

CREATE TABLE IF NOT EXISTS `pma_pdf_pages` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `page_nr` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `page_descr` varchar(50) CHARACTER SET utf8 NOT NULL DEFAULT '',
  PRIMARY KEY (`page_nr`),
  KEY `db_name` (`db_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='PDF relation pages for phpMyAdmin' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `pma_recent`
--

CREATE TABLE IF NOT EXISTS `pma_recent` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `tables` text COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`username`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Recently accessed tables';

--
-- Dumping data for table `pma_recent`
--

INSERT INTO `pma_recent` (`username`, `tables`) VALUES
('root', '[{"db":"horarios","table":"Curso"},{"db":"horarios","table":"Bloque"},{"db":"horarios","table":"CursosBloque"},{"db":"miBaseDeDatos","table":"tablaPrueba"},{"db":"horarios","table":"Plan"},{"db":"horarios","table":"GruposHorario"},{"db":"horarios","table":"Horario"},{"db":"horarios","table":"ProfesoresCurso"},{"db":"horarios","table":"Profesor"},{"db":"horarios","table":"PeriodoProfesor"}]');

-- --------------------------------------------------------

--
-- Table structure for table `pma_relation`
--

CREATE TABLE IF NOT EXISTS `pma_relation` (
  `master_db` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `master_table` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `master_field` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `foreign_db` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `foreign_table` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `foreign_field` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  PRIMARY KEY (`master_db`,`master_table`,`master_field`),
  KEY `foreign_field` (`foreign_db`,`foreign_table`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Relation table';

-- --------------------------------------------------------

--
-- Table structure for table `pma_table_coords`
--

CREATE TABLE IF NOT EXISTS `pma_table_coords` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `pdf_page_number` int(11) NOT NULL DEFAULT '0',
  `x` float unsigned NOT NULL DEFAULT '0',
  `y` float unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`db_name`,`table_name`,`pdf_page_number`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Table coordinates for phpMyAdmin PDF output';

-- --------------------------------------------------------

--
-- Table structure for table `pma_table_info`
--

CREATE TABLE IF NOT EXISTS `pma_table_info` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  `display_field` varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '',
  PRIMARY KEY (`db_name`,`table_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Table information for phpMyAdmin';

-- --------------------------------------------------------

--
-- Table structure for table `pma_table_uiprefs`
--

CREATE TABLE IF NOT EXISTS `pma_table_uiprefs` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `prefs` text COLLATE utf8_bin NOT NULL,
  `last_update` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`username`,`db_name`,`table_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Tables'' UI preferences';

-- --------------------------------------------------------

--
-- Table structure for table `pma_tracking`
--

CREATE TABLE IF NOT EXISTS `pma_tracking` (
  `db_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `table_name` varchar(64) COLLATE utf8_bin NOT NULL,
  `version` int(10) unsigned NOT NULL,
  `date_created` datetime NOT NULL,
  `date_updated` datetime NOT NULL,
  `schema_snapshot` text COLLATE utf8_bin NOT NULL,
  `schema_sql` text COLLATE utf8_bin,
  `data_sql` longtext COLLATE utf8_bin,
  `tracking` set('UPDATE','REPLACE','INSERT','DELETE','TRUNCATE','CREATE DATABASE','ALTER DATABASE','DROP DATABASE','CREATE TABLE','ALTER TABLE','RENAME TABLE','DROP TABLE','CREATE INDEX','DROP INDEX','CREATE VIEW','ALTER VIEW','DROP VIEW') COLLATE utf8_bin DEFAULT NULL,
  `tracking_active` int(1) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`db_name`,`table_name`,`version`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin ROW_FORMAT=COMPACT COMMENT='Database changes tracking for phpMyAdmin';

-- --------------------------------------------------------

--
-- Table structure for table `pma_userconfig`
--

CREATE TABLE IF NOT EXISTS `pma_userconfig` (
  `username` varchar(64) COLLATE utf8_bin NOT NULL,
  `timevalue` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `config_data` text COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`username`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='User preferences storage for phpMyAdmin';

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
