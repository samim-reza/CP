<?php
    $name = array("a", "b", "c", "d", "e", "f", "g", "h", "i", "j");
    for($i = 0; $i < count($name); $i++){
        echo $name[$i];
        echo "\n";
    }
    foreach($name as $value){
        echo $value;
        echo "\n";
    }
    function printName($name){
        echo $name;
    }
?>