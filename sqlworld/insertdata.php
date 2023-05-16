<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css"
    rel="stylesheet"
    integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ"
    crossorigin="anonymous">
    <title>Insert Data</title>
</head>
<body class="bg-primary bg-gradient text-white">
    <nav class="mb-2 navbar navbar-expand-md bg-body-tertiary">
        <ul class="ms-2 navbar-nav">
            <li class="nav-item">
                <a class="nav-link" href="index.html">Home</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="showdata.php">Show Data</a>
            </li>
            <li class="nav-item bg-primary">
                <a class="nav-link text-white active" href="#">Insert Data</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="deleterecord.php">Delete Record</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="updaterecord.php">Update Record</a>
            </li>
        </ul>
    </nav>
    <form action="insertdata.php" method="POST" class="bg-secondary container-md mt-3 ms-5 p-2 row g-2 needs-validation" style="max-width:50%" novalidate>
        <?php
            $columns = ['lblcountryname', 'lblregion', 'lblpopulation', 'lblareasqmiles',
                'lbldensitypersqkm', 'lblnetmigration', 'lblmortalityper1000', 'lblgdp',
                'lblliteracy', 'lblphonesper1000','lblarable', 'lblcrops', 'lblothers',
                'lblbirthrate', 'lbldeathrate'];

            foreach ($columns as $label){
                echo "<div class=\"col-sm-4\">"; 
                echo "<div class=\"mb-2\"><label for=\"{$label}\" class=\"form-label\">{$label}</label>";
                echo "<input type=\"text\" class=\"form-control\" name=\"{$label}\" required></div>";
                echo "</div>";
            }
        ?>
        <div class="col">
            <button type="submit" class="btn m-3 btn-info text-white" name="submit">Insert</button>
        </div>
    </form> 
    <script>
        'use strict'

        const forms = document.querySelectorAll('.needs-validation')

        Array.from(forms).forEach(form => {
            form.addEventListener('submit', event => {
            if (!form.checkValidity()) {
                event.preventDefault()
                event.stopPropagation()
            }

            form.classList.add('was-validated')
            }, false)
        })
    </script>
    <div class="ms-5">
        <?php
            $cols = sizeof($_POST) - 1;         /* don't count submit button */
            $i = 0;                             /* counter to ignore submit button */

            if (isset($_POST["submit"])){
                $conn = new mysqli("localhost", "root", "", "lblworld");
                if ($conn->connect_error) {
                    echo "Failed to connect to MySQL: " . mysqli_connect_error();
                    exit(1);
                };

                /* check if pre-existing */
                $query = "SELECT * FROM `world2a` WHERE `lblcountryname` = '{$_POST['lblcountryname']}'";
                $result = $conn->query($query);
                if ($result->num_rows != 0)
                    exit(0);
                

                $query = "INSERT INTO `world2a` VALUES(";
                foreach ($_POST as $label){
                    if ($i++ == $cols - 1){ 
                        $query .= "'".trim($label) ."'";
                        break;
                    }
                    $query .= "'". trim($label) . "',";
                }
                $query .= ");";
                $conn->query($query);

                echo "Just inserted {$_POST['lblcountryname']}";
            }
        ?>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-ENjdO4Dr2bkBIFxQpeoTz1HIcje39Wm4jDKdf19U8gI4ddQ3GYNS7NTKfAdVQSZe"
    crossorigin="anonymous"></script>
</body>
</html>
