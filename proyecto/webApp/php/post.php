<?php
header('Content-Type: application/json');
ini_set('display_errors', 1);


class Fx{
	/*  Example
	 *  $array = array( a=>'sdff' , a=>'fghr' , a=>'jser' )
	 *  Turns into
	 *  $array = array( 'sdff' , 'fghr' , 'jser' )
	 *
	 *  anatomy of (ie.) $array['whatever']
	 *  $array is an array
	 *  $key is 'whatever'
	 *  $value is the value of $array['whatever'], could be an array
	 */
	static function flattenArray($array) {
		if (!is_array( $array )) {
			return false;
		}

		$result = array();
		foreach ( $array as $key => $value ) {
			if (is_array($value)) {
				$result = array_merge( $result , self::flattenArray( $value ) );
			}
			else {
				$result[$key] = $value;
			}
		}
		return $result;
	}
}

$data = file_get_contents('php://input');
$dataObj =  json_decode( $data ) or false;

if( isset( $dataObj->action ) ){

    require_once 'DB.php';
	require_once 'Cursos.php';
    require_once 'Profesores.php';

	$crs = new Cursos;
	$prf = new Profesores;
	switch ($dataObj->action) {
		case 'getCursos':
            $fetch =  Fx::flattenArray($crs->getCursos());
            $result = array();
            if (isset($fetch) && is_array($fetch)) {
                foreach ($fetch as $val) {
                    $crsFetch = $crs->getCurso($val);
                    $crsFetch['cantidadHoras'] = intval($crsFetch['cantidadHoras']);
                    $crsFetch['clasesEnSemana'] = intval($crsFetch['clasesEnSemana']);
                    $crsFetch['cantidadGrupos'] = intval($crsFetch['cantidadGrupos']);
                    array_push($result, $crsFetch);
                }
            }
            $return = json_encode($result);
            echo $return;
    		break;

        case 'addCurso':
            $return = $crs->addCurso($dataObj->sigla, $dataObj->nombre,
                intval($dataObj->cantidadHoras), intval($dataObj->clasesEnSemana),
                intval($dataObj->cantidadGrupos));
                $return = json_encode($return);
                echo $return;
            break;

        case 'updateCurso':
            $crs->updateCurso(intval($dataObj->id), $dataObj->sigla, $dataObj->nombre,
                intval($dataObj->cantidadHoras), intval($dataObj->clasesEnSemana),
                intval($dataObj->cantidadGrupos));
            break;

        case 'deleteCurso':
            $crs->deleteCurso(intval($dataObj->id));
            break;

        case 'loadPlanesCurso':
            $planes = $crs->getPlanesCurso(intval($dataObj->id));
            $planes = json_encode($planes);
            echo $planes;
            break;

        case 'loadProfesCursos':
            $profesores = $crs->getProfesCurso(intval($dataObj->id));
            $profesores = json_encode($profesores);
            echo $profesores;
            break;


		case 'getProfes':
	            $fetch =  Fx::flattenArray($prf->getProfesores());
	            $result = array();
	            if (isset($fetch) && is_array($fetch)) {
	                foreach ($fetch as $val) {
	                    $prfFetch = $prf->getProfesor($val);
	                    $prfFetch['horasLaborales'] = intval($prfFetch['horasLaborales']);
	                    array_push($result, $prfFetch);
	                }
	            }
	            $return = json_encode($result);
	            echo $return;
	    		break;

	        case 'addProfe':
	            $return = $prf->addProfe($dataObj->nombre, $dataObj->apellido,
	                intval($dataObj->horasLaborales));
	                $return = json_encode($return);
	                echo $return;
	            break;

	        case 'updateProfe':
	            $prf->updateProfe(intval($dataObj->id), $dataObj->nombre,
				$dataObj->apellido, intval($dataObj->horasLaborales));
	            break;

	        case 'deleteProfe':
	            $prf->deleteProfe(intval($dataObj->id));
	            break;

	        case 'loadCursosProfe':
	            $cursos = $prf->getCursosProfe(intval($dataObj->id));
	            $cursos = json_encode($cursos);
	            echo $cursos;
	            break;
			case 'addCursoAProfe':
				$return = $prf->addCursoAProfe(intval($dataObj->idProfe),intval($dataObj->idCurso));
				$return = json_encode($return);
				echo $return;
				break;
	}
}
