--
-- Dumping data for table `ProfesoresCurso`
--

ALTER TABLE `ProfesoresCurso`
DROP FOREIGN KEY `ProfesoresCurso_ibfk_1`;
ALTER TABLE `ProfesoresCurso`
DROP FOREIGN KEY `ProfesoresCurso_ibfk_2`;

TRUNCATE TABLE `ProfesoresCurso`

ALTER TABLE `ProfesoresCurso`
  ADD CONSTRAINT `ProfesoresCurso_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `ProfesoresCurso_ibfk_2` FOREIGN KEY (`idProfesor`) REFERENCES `Profesor` (`id`)
  ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `ProfesoresCurso` AUTO_INCREMENT = 1;

INSERT INTO `ProfesoresCurso` (`idCurso`, `idProfesor`) VALUES
(3, 1),
(5, 2),
(3, 3),
(3, 4);
