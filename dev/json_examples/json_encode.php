<?php

$student = array("id"=>101, 
				"name"=>"John Doe", 
				"isStudent"=>true, 
				"scores"=>array(10, 20, 30, 40),
				"courses" => array(
					"major"=>"Finance",
					"minor"=>"Marketing"
				)
		);
		
echo json_encode($student); //encoding the array into a JSON string 
							//and using echo to  print the output  

?>
