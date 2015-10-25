-- phpMyAdmin SQL Dump
-- version 4.3.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Oct 25, 2015 at 07:08 PM
-- Server version: 5.6.21-log
-- PHP Version: 5.6.4

SET FOREIGN_KEY_CHECKS=0;
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "-06:00";

--
-- Database: `horarios`
--
CREATE DATABASE IF NOT EXISTS `horarios` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `horarios`;

-- --------------------------------------------------------

--
-- Table structure for table `bloque`
--

DROP TABLE IF EXISTS `bloque`;
CREATE TABLE IF NOT EXISTS `bloque` (
  `id` int(11) NOT NULL,
  `semestre` int(11) NOT NULL,
  `idCurso` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `curso`
--

DROP TABLE IF EXISTS `curso`;
CREATE TABLE IF NOT EXISTS `curso` (
  `id` int(11) NOT NULL,
  `cantidadGrupos` int(11) NOT NULL,
  `cupo` int(11) NOT NULL,
  `idPeriodoHorario` int(11) NOT NULL,
  `idProfesor` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `instante`
--

DROP TABLE IF EXISTS `instante`;
CREATE TABLE IF NOT EXISTS `instante` (
  `id` int(11) NOT NULL,
  `dia` int(11) NOT NULL,
  `hora` int(11) NOT NULL,
  `minuto` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `periodo`
--

DROP TABLE IF EXISTS `periodo`;
CREATE TABLE IF NOT EXISTS `periodo` (
  `id` int(11) NOT NULL,
  `idInstanteInicio` int(11) NOT NULL,
  `idInstanteFinal` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `plan`
--

DROP TABLE IF EXISTS `plan`;
CREATE TABLE IF NOT EXISTS `plan` (
  `id` int(11) NOT NULL,
  `idBloque` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `profesores`
--

DROP TABLE IF EXISTS `profesores`;
CREATE TABLE IF NOT EXISTS `profesores` (
  `id` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `apellido` varchar(255) NOT NULL,
  `horasLaborales` int(11) NOT NULL,
  `horasAsignadas` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bloque`
--
ALTER TABLE `bloque`
  ADD PRIMARY KEY (`id`), ADD KEY `idCurso` (`idCurso`), ADD KEY `idCurso_2` (`idCurso`);

--
-- Indexes for table `curso`
--
ALTER TABLE `curso`
  ADD PRIMARY KEY (`id`), ADD KEY `idPeriodoHorario` (`idPeriodoHorario`), ADD KEY `idProfesor` (`idProfesor`);

--
-- Indexes for table `instante`
--
ALTER TABLE `instante`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `periodo`
--
ALTER TABLE `periodo`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `plan`
--
ALTER TABLE `plan`
  ADD PRIMARY KEY (`id`), ADD KEY `idBloque` (`idBloque`);

--
-- Indexes for table `profesores`
--
ALTER TABLE `profesores`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `bloque`
--
ALTER TABLE `bloque`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `curso`
--
ALTER TABLE `curso`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `instante`
--
ALTER TABLE `instante`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `periodo`
--
ALTER TABLE `periodo`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `plan`
--
ALTER TABLE `plan`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `profesores`
--
ALTER TABLE `profesores`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
