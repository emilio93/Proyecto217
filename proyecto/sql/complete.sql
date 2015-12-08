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


--
-- Dumping data for table `Plan`
--
ALTER TABLE `Plan` AUTO_INCREMENT = 1;

INSERT INTO `Plan` (`nombre`) VALUES
('Electrónica y Telecomunicaciones'),
('Sistemas de Energía'),
('Computadoras y Redes');

--
-- Dumping data for table `Profesor`
--

ALTER TABLE `Profesor` AUTO_INCREMENT = 1;

INSERT INTO `Profesor` (`horasLaborales`, `nombre`, `apellido`) VALUES
(36, 'Teodoro', 'Willink'),
(40, 'Francisco', 'Siles'),
(30, 'Sergio', 'Valverde'),
(48, 'Geovanny', 'Martinez'),
(30, 'Sergio', 'Valverde'),
(30, 'Sergio', 'Valverde'),
(30, 'Sergio', 'Valverde'),
(30, 'Sergio', 'Valverde'),
(30, 'Sergio', 'Valverde'),
(30, 'Sergio', 'Valverde'),

--
-- Dumping data for table `Curso`
--

ALTER TABLE `Curso` AUTO_INCREMENT = 1;

INSERT INTO `Curso` (`cantidadHoras`, `clasesEnSemana`, `cantidadGrupos`, `nombre`, `sigla`) VALUES
(4, 2, 3, 'Circuitos Lineales I', 'IE0209'),
(4, 2, 3, 'Circuitos Lineales II', 'IE0309'),
(5, 2, 3, 'Matemáticas Superiores', 'IE0305'),
(6, 2, 2, 'Programación bajo Plataformas Abiertas', 'IE0117'),
(6, 2, 1, 'Estructuras Abstractas de Datos', 'IE0217'),
(4, 2, 3, 'Electrónica I', 'IE0313'),
(4, 2, 2, 'Circuitos Digitales I', 'IE0323'),
(4, 2, 2, 'Modelos Probabilísticos de Señales y Sistemas', 'IE0405'),
(4, 2, 2, 'Teoría del Campo I', 'IE0307'),
(6, 1, 1, 'Laboratorio Eléctrico I', 'IE0308'),
(4, 2, 2, 'Electrónica II', 'IE0413'),
(4, 2, 3, 'Circuitos Digitales II', 'IE0309'),
(4, 2, 1, 'Dispositivos Semiconductores', 'IE0311'),
(4, 2, 2, 'Análisis de Sistemas', 'IE0409'),
(4, 2, 2, 'Estructuras de Computadoras Digitales I', 'IE0321'),
(4, 2, 1, 'Estructuras de Computadoras Digitales II', 'IE0521'),
(6, 2, 2, 'Máquinas Eléctricas I','IE0315'),
(4, 2, 2, 'Sistemas de Control', 'IE0431'),
(6, 1, 1, 'Laboratorio Eléctrico II', 'IE0408'),
(4, 2, 1, 'Electrónica III', 'IE0513'),
(4, 2, 2, 'Máquinas Eléctricas II', 'IE0615'),
(4, 2, 2, 'Ingeniería Económica', 'IE0479'),
(4, 2, 1, 'Ingeniería de comunicaciones', 'IE0527'),
(4, 2, 1, 'Diseño eléctrico industrial ', 'IE0471'),
(4, 2, 1, 'Responsabilidades para el ejercicio profesional ', 'IE0501'),
(4, 2, 1, 'Teoría económica ', 'IE0379'),
(4, 2, 1, 'Microelectrónica sistemas en silicio ', 'IE0311'),
(6, 1, 1, 'Laboratorio de circuitos digitales ', 'IE0424'),
(4, 2, 1, 'Microprocesadores ', 'IE0623'),
(4, 2, 1, 'Redes de computadores ', 'IE0425'),
(4, 2, 1, 'Termofluidos ', 'IE0281'),
(4, 2, 1, 'Ciencia de los materiales ', 'IE0381'),
(4, 2, 1, 'Transmisión de potencia ', 'IE0365'),
(6, 1, 1, 'Proyecto eléctrico', 'IE0499');


--
-- Dumping data for table `Bloque`
--

ALTER TABLE `Bloque` AUTO_INCREMENT = 1;

INSERT INTO `Bloque` (`idPlan`, `semestre`) VALUES
(1, 3), (1, 4), (1, 5), (1, 6), (1, 7), (1, 8), -- 1-6 Electronica y Telecomunicaciones
(2, 3), (2, 4), (2, 5), (2, 6), (2, 7), (2, 8), -- 7-12 Sistemas de Energía
(3, 3), (3, 4), (3, 5), (3, 6), (3, 7), (3, 8); -- 13-18 Computadoras y Redes

--
-- Dumping data for table `CursosBloque`
--

ALTER TABLE `CursosBloque` AUTO_INCREMENT = 1;

INSERT INTO `CursosBloque` (`idBloque`, `idCurso`) VALUES
(1, 1),
(2, 2),
(2, 3),
(2, 5),
(2, 6),
(3, 7),
(3, 8),
(3, 9),
(3, 10),
(4, 11),
(4, 26),
(4, 14),
(4, 25),
(4, 17),
(4, 15),
(5, 19),
(5, 18),
(5, 20),
(5, 21),
(6, 34),
(6, 22),
(6, 23),
(6, 24),
(7, 1),
(8, 2),
(8, 3),
(8, 6),
(8, 31),
(9, 7),
(9, 8),
(9, 9),
(9, 10),
(9, 32),
(10, 11),
(10, 26),
(10, 14),
(10, 25),
(10, 17),
(10, 33),
(11, 19),
(11, 18),
(11, 21),
(12, 22),
(12, 34),
(12, 24),
(13, 1),
(13, 4),
(14, 2),
(14, 3),
(14, 5),
(14, 6),
(15, 7),
(15, 8),
(15, 9),
(15, 10),
(15, 11),
(16, 13),
(16, 12),
(16, 14),
(16, 25),
(16, 17),
(16, 15),
(17, 27),
(17, 28),
(17, 18),
(17, 23),
(17, 16),
(18, 29),
(18, 34),
(18, 30);

ALTER TABLE `ProfesoresCurso` AUTO_INCREMENT = 1;

INSERT INTO `ProfesoresCurso` (`idCurso`, `idProfesor`) VALUES
(3, 1),
(5, 2),
(3, 3),
(3, 4);
