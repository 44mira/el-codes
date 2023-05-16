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
    <title>Show Data</title>
</head>
<body class="bg-primary bg-gradient text-white">
    <nav class="mb-2 navbar navbar-expand-md bg-body-tertiary">
        <ul class="ms-2 navbar-nav">
            <li class="nav-item">
                <a class="nav-link" href="index.html">Home</a>
            </li>
            <li class="nav-item bg-primary">
                <a class="nav-link text-white active" href="#">Show Data</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="insertdata.php">Insert Data</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="deleterecord.php">Delete Record</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="updaterecord.php">Update Record</a>
            </li>
        </ul>
    </nav>
    <div class="table-responsive">
    <?php
        $conn = new mysqli("localhost", "root", "", "lblworld");
        if ($conn->connect_error) {
            echo "Failed to connect to MySQL: " . mysqli_connect_error();
            exit();
        };

        $query = "SELECT * FROM `world2a` WHERE 1";
        $columns = ['lblcountryname', 'lblregion', 'lblpopulation', 'lblareasqmiles',
                'lbldensitypersqkm', 'lblnetmigration', 'lblmortalityper1000', 'lblgdp',
                'lblliteracy', 'lblphonesper1000','lblarable', 'lblcrops', 'lblothers',
                'lblbirthrate', 'lbldeathrate'];
        $result = $conn->query($query);
                
        echo "<table class=\"table table-sm table-light table-striped\"><thead><tr>";
        foreach ($columns as $name)
            echo "<th>{$name}</th>";
        echo "</tr></thead><tbody>";
        
        while ($row = $result->fetch_assoc()){
            echo '<tr>';
            foreach ($columns as $name)
                echo "<td>{$row[$name]}</td>";
            echo '</tr>';
        }
        echo '</tbody></table>';
    ?>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-ENjdO4Dr2bkBIFxQpeoTz1HIcje39Wm4jDKdf19U8gI4ddQ3GYNS7NTKfAdVQSZe"
    crossorigin="anonymous"></script>
</body>
</html>
