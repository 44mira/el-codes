<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Result</title>
    <style>
        table, td, th{
            border : 1px solid black;
        }
        td, th{
            padding : 15px;
        }
        td{
            padding-right : 30px;
        }
    </style>
</head>
<body>
    <h3>This program takes in user-inputted data and displays it.</h3>

    <table>
        <?php
            $keys = ["Name","Date of Birth","Email","Degree Program","Sex","Phone Number"];
            $idx = 0;
            foreach ($_POST as $value){
                if ($idx > 5) break;    // ignore submit button
                echo "<tr>";
                echo "<th>{$keys[$idx]}</th><td>{$value}</td>";
                echo "</tr>";
                $idx++;
            }
        ?>
    </table>
    
</body>
</html>

