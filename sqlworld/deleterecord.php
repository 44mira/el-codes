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
    <title>Delete Record</title>
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
            <li class="nav-item bg-primary">
                <a class="nav-link text-white active" href="#">Delete Record</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="updaterecord.php">Update Record</a>
            </li>
        </ul>
    </nav>

    <form action="deleterecord.php" method="POST" class="row container-md bg-secondary p-3 mt-3 ms-5 needs-validation" style="max-width:50%" novalidate>
        <div class="col-12">
            <label for="lblcountryname" class="form-label">lblcountryname</label>
            <input type="text" class="form-control" name="lblcountryname" required>
        </div> 
        <div class="col">
            <button type="submit" class="btn mt-3 btn-danger" name="submit">Delete</button>
        </div>
    </form>
    <div class="ms-5">
        <?php
            if (isset($_POST["submit"])){
                $conn = new mysqli("localhost", "root", "", "lblworld");
                if ($conn->connect_error) {
                    echo "Failed to connect to MySQL: " . mysqli_connect_error();
                    exit(1);
                };

                $query = "DELETE FROM `world2a` WHERE `lblcountryname` = '{$_POST['lblcountryname']}';";
                $result = $conn->query($query);

                echo (mysqli_affected_rows($conn) == 0) ? "Delete unsuccessful." : "Delete successful.";
            }
        ?>
    </div>
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