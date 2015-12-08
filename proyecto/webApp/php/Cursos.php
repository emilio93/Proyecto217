<?php
require_once "DB.php";
class Cursos {

    public function getCursos() {
        $query = "SELECT id FROM Curso";
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->execute();
            $stmt->setFetchMode(PDO::FETCH_NUM);
            $fetch = $stmt->fetchall();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return $fetch;
    }

    public function getCurso($id) {
        $query = "SELECT * FROM Curso WHERE id = ? LIMIT 1";
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $id, PDO::PARAM_INT);
            $stmt->execute();
            $stmt->setFetchMode(PDO::FETCH_ASSOC);
            $fetch = $stmt->fetch();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return $fetch;
    }

    public function addCurso( $sigla, $nombre, $cantidadHoras, $clasesEnSemana, $cantidadGrupos) {
        $query = "INSERT INTO Curso (sigla, nombre, cantidadHoras, clasesEnSemana, cantidadGrupos) VALUES (?, ?, ?, ?, ?)";
        $id = 0;
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $sigla, PDO::PARAM_STR);
            $stmt->bindParam(2, $nombre, PDO::PARAM_STR);
            $stmt->bindParam(3, $cantidadHoras, PDO::PARAM_INT);
            $stmt->bindParam(4, $clasesEnSemana, PDO::PARAM_INT);
            $stmt->bindParam(5, $cantidadGrupos, PDO::PARAM_INT);
            $stmt->execute();
            $id = $db->lastInsertId();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return array(
        'id' => $id,
        'sigla' => $sigla,
        'nombre' => $nombre,
        'cantidadHoras' => $cantidadHoras,
        'clasesEnSemana' => $clasesEnSemana,
        'cantidadGrupos' => $cantidadGrupos);
    }

    public function updateCurso($id, $sigla, $nombre, $cantidadHoras, $clasesEnSemana, $cantidadGrupos) {
        $query = "UPDATE Curso SET sigla=?, nombre=?, cantidadHoras=?, clasesEnSemana=?, cantidadGrupos=? WHERE id=?";
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $sigla, PDO::PARAM_STR);
            $stmt->bindParam(2, $nombre, PDO::PARAM_STR);
            $stmt->bindParam(3, $cantidadHoras, PDO::PARAM_INT);
            $stmt->bindParam(4, $clasesEnSemana, PDO::PARAM_INT);
            $stmt->bindParam(5, $cantidadGrupos, PDO::PARAM_INT);
            $stmt->bindParam(6, $id, PDO::PARAM_INT);
            $stmt->execute();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
    }

    public function deleteCurso($id) {
        $query = "DELETE FROM Curso WHERE id=?";
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $id, PDO::PARAM_INT);
            $stmt->execute();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return $id;
    }

    public function getPlanesCurso($id) {
        $queryIdBloque = "SELECT idBloque FROM CursosBloque WHERE idCurso = ?";
        $querySemestre = "SELECT idPlan, semestre FROM Bloque WHERE id = ? LIMIT 1";
        $queryPlan = "SELECT nombre FROM Plan WHERE id = ? LIMIT 1";
        $result = array();
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($queryIdBloque);
            $stmt->bindParam(1, $id, PDO::PARAM_INT);
            $stmt->execute();
            $stmt->setFetchMode(PDO::FETCH_ASSOC);
            while (($fetch  = $stmt->fetch()) != null)  {
                $stmtSemestre = $db->prepare($querySemestre);
                $stmtSemestre->bindParam(1, $fetch['idBloque'], PDO::PARAM_INT);
                $stmtSemestre->execute();
                $stmtSemestre->setFetchMode(PDO::FETCH_ASSOC);
                $fetchSemestre = $stmtSemestre->fetch();
                $semestre = $fetchSemestre['semestre'];

                $stmtPlan = $db->prepare($queryPlan);
                $stmtPlan->bindParam(1, $fetchSemestre['idPlan'], PDO::PARAM_INT);
                $stmtPlan->execute();
                $stmtPlan->setFetchMode(PDO::FETCH_ASSOC);
                $fetchPlan = $stmtPlan->fetch();
                $plan = $fetchPlan['nombre'];

                array_push($result, array('plan'=>$plan, 'semestre'=>$semestre));
            }
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return $result;
    }

    public function getProfesCurso($id) {
        $queryId = "SELECT idProfesor FROM ProfesoresCurso WHERE idCurso = ?";
        $queryDatos = "SELECT nombre, apellido FROM Profesor WHERE id = ? LIMIT 1";
        $result = array();
        try {
            $db = new DB;
            $db = $db->getDB();
            $stmt = $db->prepare($queryId);
            $stmt->bindParam(1, $id, PDO::PARAM_INT);
            $stmt->execute();
            $stmt->setFetchMode(PDO::FETCH_ASSOC);

            while (($fetch = $stmt->fetch()) != null) {
                $stmt2 = $db->prepare($queryDatos);
                $stmt2->bindParam(1, $fetch['idProfesor'], PDO::PARAM_INT);
                $stmt2->execute();
                $stmt2->setFetchMode(PDO::FETCH_ASSOC);
                $fetchDatos = $stmt2->fetch();
                array_push($result, array('nombre'=>$fetchDatos['nombre'], 'apellido'=>$fetchDatos['apellido']));
            }
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return $result;
    }
}
