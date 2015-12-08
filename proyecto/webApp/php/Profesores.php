<?php
require_once "DB.php";
class Profesores {

    public function getProfesores() {
        $query = "SELECT id FROM Profesor";
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

    public function getProfesor($id) {
        $query = "SELECT * FROM Profesor WHERE id = ? LIMIT 1";
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

    public function addProfe($nombre, $apellido, $horasLaborales) {
        $query = "INSERT INTO Profesor (nombre, apellido, horasLaborales) VALUES (?, ?, ?)";
        $id = 0;
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $nombre, PDO::PARAM_STR);
            $stmt->bindParam(2, $apellido, PDO::PARAM_STR);
            $stmt->bindParam(3, $horasLaborales, PDO::PARAM_INT);
            $stmt->execute();
            $id = $db->lastInsertId();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return array(
        'id' => $id,
        'nombre' => $nombre,
        'apellido' => $apellido,
        'horasLaborales' => $horasLaborales);
    }

    public function updateProfe($id, $nombre, $apellido, $horasLaborales) {
        $query = "UPDATE Profesor SET nombre=?, apellido=?, horasLaborales=? WHERE id=?";
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $nombre, PDO::PARAM_STR);
            $stmt->bindParam(2, $apellido, PDO::PARAM_STR);
            $stmt->bindParam(3, $horasLaborales, PDO::PARAM_INT);
            $stmt->bindParam(4, $id, PDO::PARAM_INT);
            $stmt->execute();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
    }

    public function deleteProfe($id) {
        $query = "DELETE FROM Profesor WHERE id=?";
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

    public function getCursosProfe($id) {
        $queryId = "SELECT idCurso FROM ProfesoresCurso WHERE idProfesor = ?";
        $queryDatos = "SELECT sigla, nombre FROM Curso WHERE id = ? LIMIT 1";
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
                $stmt2->bindParam(1, $fetch['idCurso'], PDO::PARAM_INT);
                $stmt2->execute();
                $stmt2->setFetchMode(PDO::FETCH_ASSOC);
                $fetchDatos = $stmt2->fetch();
                array_push($result, array('sigla'=>$fetchDatos['sigla'], 'nombre'=>$fetchDatos['nombre']));
            }
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return $result;
    }

    public function addCursoAProfe($idProfe, $idCurso) {
        $query = "INSERT INTO ProfesoresCurso (idProfesor, idCurso) VALUES (?, ?)";
        $id = 0;
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $idProfe, PDO::PARAM_INT);
            $stmt->bindParam(2, $idCurso, PDO::PARAM_INT);
            $stmt->execute();
            $id = $db->lastInsertId();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }

        $fetch;
        $query = "SELECT id, sigla, nombre FROM Curso WHERE id = ? LIMIT 1";
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $idCurso, PDO::PARAM_INT);
            $stmt->execute();
            $fetch = $stmt->fetch();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }

        $fetch2;
        $query = "SELECT id, nombre, apellido FROM Profesor WHERE id = ? LIMIT 1";
        try {
            $db = new DB();
            $db = $db->getDB();
            $stmt = $db->prepare($query);
            $stmt->bindParam(1, $idProfe, PDO::PARAM_INT);
            $stmt->execute();
            $fetch2 = $stmt->fetch();
        } catch (PDOException $e) {
            echo "Error: " . $e->getMessage();
        }
        return array(
        'id' => $fetch['id'],
        'idProfe' => $fetch2['id'],
        'sigla' => $fetch['sigla'],
        'nombre' => $fetch['nombre'],
        'nombreProfe' => $fetch2['nombre'],
        'apellido' => $fetch2['apellido']);
    }
}
