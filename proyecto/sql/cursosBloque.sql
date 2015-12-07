--
-- Dumping data for table `CursosBloque`
--

ALTER TABLE `Bloque`
DROP FOREIGN KEY `CursosBloque_ibfk_1`;
ALTER TABLE Bloque
DROP FOREIGN KEY `CursosBloque_ibfk_2`;

TRUNCATE TABLE `CursosBloque`;

ALTER TABLE `CursosBloque`
  ADD CONSTRAINT `CursosBloque_ibfk_1` FOREIGN KEY (`idBloque`) REFERENCES `Bloque` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `CursosBloque_ibfk_2` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `CursosBloque` AUTO_INCREMENT = 1;


INSERT INTO `CursosBloque` (`idBloque`, `idCurso`) VALUES
(1, 1),
(1, 4),
(2, 2),
(2, 3),
(2, 5),
(2, 6),
(3, 7),
(3, 8),
(3, 9),
(3, 10),
(3, 11),
(7, 1),
(8, 2),
(8, 3),
(13, 1),
(14, 2),
(14, 3);

-- --------------------------------------------------------
