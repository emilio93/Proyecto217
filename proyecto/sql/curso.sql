--
-- Dumping data for table `Curso`
--

ALTER TABLE `CursosBloque` DROP FOREIGN KEY `CursosBloque_ibfk_2`;
ALTER TABLE `Grupo` DROP FOREIGN KEY `Grupo_ibfk_1`;
ALTER TABLE `HorariosCurso` DROP FOREIGN KEY `HorariosCurso_ibfk_1`;
ALTER TABLE `ProfesoresCurso` DROP FOREIGN KEY `ProfesoresCurso_ibfk_1`;


TRUNCATE TABLE `Curso`;


ALTER TABLE `CursosBloque`
    ADD CONSTRAINT `CursosBloque_ibfk_2` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
    ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `Grupo`
    ADD CONSTRAINT `Grupo_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
    ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `HorariosCurso`
    ADD CONSTRAINT `HorariosCurso_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
    ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `ProfesoresCurso`
    ADD CONSTRAINT `ProfesoresCurso_ibfk_1` FOREIGN KEY (`idCurso`) REFERENCES `Curso` (`id`)
    ON DELETE CASCADE ON UPDATE CASCADE;

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
