# CS3339_MegaPi
<b>Performance Analysis between Arduino Mega 2560 and Raspberry Pi 4</b><br>
<i>Jeremy Hester, Jason Farrell, John-Luke Speight</i></br>
  
 <b>To run the Pi code:</b></br>

<b>LED: "pilight.c"</b></br>
-Open the "Geany" program </br>
-Select the "Build" tab</br>
-Within "C Commands"</br>
-Copy and paste below into the "Command" portion of "1. Compile" </br>
  <b>"gcc -Wall -c "%f" -lpigpio -lpthread -lm -lrt -lwiringPi"</b></br>
-Copy and paste below into the "Command" portion of "2. Build"</br>
  <b>"gcc -Wall -o "%e" "%f" -lpigpio -lpthread -lm -lrt -lwiringPi"</b></br></br>

-Within Linux Terminal compile with below</br>
  <b>"gcc -o pilight pilight.c"</b></br>
-Run program with below</br>
  <b>"time ./pilight"</br>

<b>Matrix:</b></br>
-Save "MathMatrix.cpp" , "MatrixMath.h" , and "matrix.cpp" into the same file</br></br>


<b>Run the Mega Code:<b></br>
  Need to IDE in order to run these executables. 
  1. Click build and compile
  2. Click the magnifying glass in order to diplay output from the console.

