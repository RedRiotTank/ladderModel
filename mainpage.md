/**
    \mainpage Ladder model documentation.

    =======================================================
  Initial program:
    G. Arroyo, J.C. Torres 
    Dpto. Lenguajes y Sistemas Informticos
    (Univ. de Granada)

  Modification (Scene Graph):
    Plaza Montes Alberto.
    https://github.com/RedRiotTank

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details 
 http://www.gnu.org/copyleft/gpl.html


=======================================================/


The positions of the comments take spectator's view as reference:

  X axis: Right.
  Y axis: Up.
  Z axis: To the spectator.

  KeyList:

  Default:
  - +: Zoom in camera.
  - -: Zoom out camera.
  - UP: Camera rotation up.
  - DOWN: Camera rotation down.
  - LEFT: Left camera rotation.
  - RIGHT: Right camera rotation.
  - P: Points mode.
  - L: Lines mode.
  - f: fill mode.
  - I: Lighting mode.
  - O: Normal mode (debug).

    \section a Info:

    This software is a modification of a program that was used during the computer graphics subject of the computer engineering degree at the University of Granada. In it, I model the graph of the ladder that entered as an exam exercise in the final exam 22/23.

    The software was modeled in Spanish, only the parts of the code that are to be shown in this repository have been translated and documented, which are those corresponding to the stairs, the other functionalities, such as the movement of the camera, have not been translated, nor documented, others have been suppressed directly, in order to focus attention on the ladder graph.
    