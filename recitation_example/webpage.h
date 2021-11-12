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
        <button>button</button>
        <br>
        <span id="outputlabel"> THIS IS THE INNER HTML </span> <br>
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
    </script>


</html>

)===";