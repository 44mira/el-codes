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
    <title>Update Data</title>
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
            <li class="nav-item">
                <a class="nav-link" href="insertdata.php">Insert Data</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="deleterecord.php">Delete Record</a>
            </li>
            <li class="nav-item bg-primary">
                <a class="nav-link text-white active" href="#">Update Record</a>
            </li>
        </ul>
    </nav>
    <form action="updaterecord.php" method="POST" class="row container-md bg-secondary p-3 mt-3 ms-5 needs-validation" style="max-width:50%" novalidate>
        <div class="col-12">
            <label for="lblcountryname" class="form-label">lblcountryname</label>
            <input type="text" class="form-control" name="countryname" required>
        </div> 
        <div class="col">
            <button type="submit" class="btn mt-3 btn-primary" name="submit1">Search</button>
        </div>
    </form>
    <form action="updaterecord.php" method="POST" class="bg-secondary container-md mt-3 ms-5 p-2 row g-2 needs-validation" style="max-width:50%" novalidate>
        <?php
            
            $columns = ['lblcountryname', 'lblregion', 'lblpopulation', 'lblareasqmiles',
                'lbldensitypersqkm', 'lblnetmigration', 'lblmortalityper1000', 'lblgdp',
                'lblliteracy', 'lblphonesper1000','lblarable', 'lblcrops', 'lblothers',
                'lblbirthrate', 'lbldeathrate'];
            $conn = new mysqli("localhost", "root", "", "lblworld");
            if ($conn->connect_error) {
                echo "Failed to connect to MySQL: " . mysqli_connect_error();
                exit(1);
            };


            /* flag for updated form */
            function makeform($flag){
                if ($flag){
                    $query = "SELECT * FROM `world2a` WHERE `lblcountryname` = '{$_POST['countryname']}';";
                    $result = $GLOBALS['conn']->query($query);
                    if (mysqli_affected_rows($GLOBALS['conn']) == 0)
                        $flag = false;
                    else
                        $row = $result->fetch_assoc();
                }

                foreach ($GLOBALS['columns'] as $label){
                    echo "<div class=\"col-sm-4\">"; 
                    echo "<div class=\"mb-2\"><label for=\"{$label}\" class=\"form-label\">{$label}</label>";
                    echo "<input type=\"text\" class=\"form-control\" name=\"{$label}\"";
                    echo ($flag) ? "value=\"{$row[$label]}\"": "";
                    echo "required></div>";
                    echo "</div>";
                }
            }
            if (isset($_POST["submit1"]))
                makeform(true);
            else if (isset($_POST["submit2"])) {
                makeform(false);
                $query = "UPDATE `world2a` SET ";
                $i = 0;
                foreach ($columns as $label){
                    if ($i++ == sizeof($_POST) - 2) {
                        $query .= "`" . $label . "`" . " = '{$_POST[$label]}' WHERE `lblcountryname` = '{$_POST['lblcountryname']}'";
                        break;
                    }
                    $query .= "`". $label . "`" . " = '{$_POST[$label]}', ";
                }
                $conn->query($query);
                echo "Record updated.";
            }
            else 
                makeform(false)
        ?>
        <div class="col">
            <button type="submit" class="btn m-3 btn-info text-white" name="submit2">Update</button>
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
    
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-ENjdO4Dr2bkBIFxQpeoTz1HIcje39Wm4jDKdf19U8gI4ddQ3GYNS7NTKfAdVQSZe"
    crossorigin="anonymous"></script>
</body>
</html>