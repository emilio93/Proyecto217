<?php
class DB {

    private $db;

    public function getDB($show = false) {
        $dsn = 'mysql:dbname=horarios; host=127.0.0.1;charset=utf8';
        $user = 'root';
        $pass = 'pass';

        try {
            $this->db = new PDO($dsn, $user, $pass);
            $this->db->setAttribute(PDO::ATTR_ERRMODE , PDO::ERRMODE_EXCEPTION);
        } catch (PDOException $e) {
            echo 'Falló la conexión: ' . $e->getMessage();
        }
        if ($show) {
            echo "conexión creada";
        }
        return $this->db;
    }

    public function removeDB() {
        $this->db = null;
    }
}
