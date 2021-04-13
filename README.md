# Gutting-paper-Implementation
This is a Implementation of Guting-paper in C++ which is published in the 1960s to solve the contour and measure problem of Iso-rectangles that are parallel to axis in a O(n logn ) time complexity.

# Running the code
compile and run main.cpp.
The input is given as n which is the number of inputs in the first line and the subsequent n lines take input as x1 x2 y1 y2 
where (x1,y1) is the left bottom point of the rectangle and (x2,y2) is the right top point of the rectangle parallel to the axis.

# Reading the output
the area and the perimeter along with the running time of the code are printed on the terminal. the contour lines of 
the rectangles are written in two seperate files of namely horizontal.txt and Hvertical.txt

the txt files contains lines in the order of co-ordinate and range. (coordinate of x if vertical and y if horizontal)

 sample output:
 1 2 3
 
 1. the linesegment is between the points (2,1) and (3,1) if the output is in horizontal.txt
 2. the linesegment is between the points (1,2) and (1,3) if the output is in Hvertical.txt
 
# visualizing the contours and input:
after running main.cpp successfully, run plotterMain.py to visualize the results
