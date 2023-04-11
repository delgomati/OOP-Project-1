# OOP-Project-1
\#  Program Description


1.Display a main menu and uses switch cases to adhere to user input.

2.Requires user to choose option 1 before anything else which loads the input files into string and int arrays. 

3.Requires user to enter another option from the main menu. Using switch cases function in other classes are called and utilized. 

\4. In option 2, the user is instructed to input three inputs, the source city, the destination city and the detour distance. The distances between the two cities are added to the detour distance.

5.In option 3, user is instructed to enter two cities and using the distances array and an if stated imbedded in a for loop, the program displays the distance between the two cities.

6.In option 4, based on user inputted information, the program uses the ToDistance function to calculate the distance and based on user inputted gas rates, the total cost of the trip is calculated.

7.In options 5-9, the user is instructed to input a city and by sorting the array using an if statement imbedded in a for loop. Then the program outputs the closest, farthest, second closest, and second farthest city.





\# Source Files Description

\- Add for each source file in your code. 

`   `- Include also configuration files if any, and makefile.

\## Name:  `main.cpp`

Main program.  This is the driver program that uses switch cases to display a main menu, which based on user input, calls sub-functions

to first load data from an input file, then use that data to giver information about distances of cities and trip costs. 

\## Name:  `city.h` 

`   `Contains the definition for the class city.



\## Name:  `distance.h` 

`   `Contains the definition for the class distance.  

\## Name: `city.cpp`

`   `Defines and implements the city class for implementing a series of functions.

`   `This class provides routines to get a city name based on user input and be able to output information such as closest and farthest cities. Additionally, it can calculate trip cos based user input information.

\## Name: `distance.cpp`

`   `Defines and implements the distance class for implementing a series of functions.

`   `This class provides routines to get the name of the city, the distance of the city using user input and input files and it has methods of setting a new distance. 

\## Name:  `makefile` 

`   `Contains the target and source files.




\#  Circumstances of programs

\- Describe how is the current state of your program

`   `- The program runs successfully.  

`   `- The program was developed and tested on CLion.  It was compiled, run, and tested on gcc csegrid server.


\#  How to build and run the program

\- Applies for CSEGrid programs

\1. Decompress the homework.  The homework file is compressed.  

`   `- To decompress it use the following command 

`      `- `% unzip [1234HW1]`

`   `- The directory named `homework` should contain the following files:

`   ````

`      `main.cpp

`      `city.h

`      `city.cpp

`	   `distance.h

`	   `distance.cpp

`      `makefile

`      `Readme.md

`   ````

`	`[any other supporting documents]

\2. Build the program.

\- Change to the directory that contains the file by: 

`   `- `% cd [1234HW1]`

\- Compile the program by: 

`   `- `% make`

\3. Run the program by:

`   `- `% ./[xxx]`

\4. Delete the obj files, executables, and core dump by

`   `- `% ./make clean`
