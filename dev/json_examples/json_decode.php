<?php

//json string from a HTTP request

$student = '{"id":101,"name":"John Doe","isStudent":true,"scores":[10,20,30,40],
            "courses":{"major":"Finance","minor":"Marketing"}}'; 

print_r(json_decode($student, true)); //decoding a JSON string 
                                      //and converting it into a PHP array

?>