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
-- --------------------------------------------------------
