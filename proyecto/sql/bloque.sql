--
-- Dumping data for table `Bloque`
--
ALTER TABLE Bloque
DROP FOREIGN KEY `Bloque_ibfk_1`;

TRUNCATE TABLE `Bloque`;

ALTER TABLE `Bloque`
  ADD CONSTRAINT `Bloque_ibfk_1` FOREIGN KEY (`idPlan`) REFERENCES `Plan` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `Bloque` AUTO_INCREMENT = 1;

INSERT INTO `Bloque` (`idPlan`, `semestre`) VALUES
(1, 3), (1, 4), (1, 5), (1, 6), (1, 7), (1, 8), -- 1-6 Electronica y Telecomunicaciones
(2, 3), (2, 4), (2, 5), (2, 6), (2, 7), (2, 8), -- 7-12 Sistemas de Energía
(3, 3), (3, 4), (3, 5), (3, 6), (3, 7), (3, 8); -- 13-18 Computadoras y Redes

-- --------------------------------------------------------
