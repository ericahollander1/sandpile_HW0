# sandpile_HW0
### Collaborators/Group Members:
Erica Hollander: Elh1 and Lakin Jenkins: ljenkins

### Title: 
Sandpile

### Description:
This program implements a modified version of an abelian sandpile model that we have created.
In this simulation a 23x23 grid is displayed. Each number on the grid represents the height
of a sandpile in that spot. The sand is put one grain at a time onto the center spot and 
once the height of a pile reaches 8 the sand spills onto the piles surrounding it. There are
also sinkholes around that are represented by a '#' which when a piece of sand falls into it
the sand simply disappears. Same with the edges of the grid. If a piece of sand reaches an
edge it falls off the grid and is never to be seen again. You can start the game with piles 
of different heights too simply by putting in parameters of the position on the grid and the 
height you want it to be at, i.e. 13 15 7. Sinkholes can be placed by using a -1 for the 
height. You can put a pile in the center but it will display a message if you put a sinkhole
 in the center as this is not allowed.
 
 ### Technologies used:
 We used Eclipse to originally write in Java, CLion to write in C and to compile. For the 
 final test we used pyrite to see it on the console and vim to create the MakeFile. The two
 txt files were both done on Eclipse.
