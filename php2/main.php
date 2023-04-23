<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        input, select{
            margin-bottom : 10px;
        }
    
    </style>
    <title>Data Form</title>
</head>
<body>
    <h3>This program takes in user-inputted data and displays it.</h3>
    <form action="result.php" method="POST">

        <label for="name">Name: </label><input type="text" name="name" id="name"><br>
        <label for="bday">Date of Birth: </label><input type="date" name="bday" id="bday"><br>
        <label for="email">Email: </label><input type="email" name="email" id="email"><br>

        <label for="degprog">Degree Program: </label>
        <select name="degprog" id="degprog">
            <option disabled hidden selected>Select a course</option>
        </select><br>

        <label for="sex">Sex: </label>
        <input type="radio" name="sex" id="male" value="Male">Male</input>
        <input type="radio" name="sex" id="female" value="Female">Female</input><br>

        <label for="cpnum">Phone Number: </label><input type="text" name="cpnum" id="cpnum"><br>
        <input type="submit" name="submit" id="submit">

    </form>
    
    <script>
        const DEGPROG = document.querySelector("#degprog"); 
        const PROG_LIST = ["BS Anthropology", "BS Architecture", "BA Communication and Media Arts",
                           "BA English", "BS Applied Mathematics", "BS Biology", "BS Computer Science",
                           "BS Food Technology", "BS Agribusiness Economics"];
        for (degree of PROG_LIST){
            temp = document.createElement("option");
            temp.textContent = degree;
            DEGPROG.append(temp);
        }
    
    </script>
</body>
</html>