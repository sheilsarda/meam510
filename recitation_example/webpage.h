/*
 * HTML and Javascript code
 */
const char body[] PROGMEM = R"===(

<!DOCTYPE html>
<html>
    <body>
        <input type="range" min="1" max="100" value="50"  id="slider_1">
        <input type="range" min="1" max="100" value="50"  id="slider_2">
        <br>
        <button id='motor_toggle'>button</button>
        <button id='forward'>forward</button>
        <br>
        <span id="outputlabel"> THIS IS THE INNER HTML </span> <br>
        <span id="motor_status_label"> Motor status: </span> <br>
    </body>

    <script>
    slider_1.onchange = function() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        // This checks if there was a response from the .ino program
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("outputlabel").innerHTML = 'slider value: ' + this.responseText;
        }
        else{
          document.getElementById("outputlabel").innerHTML = 'slider value: ' + 'no response from esp32';
        }
      };
      var msg = "slider_1?val=" + this.value;
      xhttp.open("GET", msg, true);
      xhttp.send();
    }

    motor_toggle.onclick = function() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        // This checks if there was a response from the .ino program
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("motor_status_label").innerHTML = 'motor status: ' + this.responseText;
        }
        else{
          document.getElementById("motor_status_label").innerHTML = 'motor status: ' + 'no response from esp32';
        }
      };
      var msg = "toggle_motors";
      xhttp.open("GET", msg, true);
      xhttp.send();
    }
    
    forward.onclick = function() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        // This checks if there was a response from the .ino program
        // if (this.readyState == 4 && this.status == 200) {
        //   document.getElementById("motor_status_label").innerHTML = 'motor status: ' + this.responseText;
        // }
        // else{
        //   document.getElementById("motor_status_label").innerHTML = 'motor status: ' + 'no response from esp32';
        // }
      };
      var msg = "forward";
      xhttp.open("GET", msg, true);
      xhttp.send();
    }
    

    </script>


</html>

)===";