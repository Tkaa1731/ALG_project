/**
 * @mainpage Algorithm for random maze generation
 * @authors Tereza Kalniková (kal0300@vsb.cz)
 * @section Labyrinth
 * <p>This is a documentation of project to subject Algorithms I. The assigned of project was to write a program that generate maze by using DFS (Depth First Search) algorithm.</p></br>
* You can find the generated labyrinth here ->
* <a href="graph_svg.html"> Labyrinth </a> 
*/
/**
 * @file main.cpp
 * @brief Main function of programme. Making instance of Labyrinth and setting basic variables such as the number of rows and columns of the resulting maze. Also calling function for DFS and drawing maze to HTML document.
 * @version 0.1
 * @date 2022-04-16
 */
#include <ctime>
#include "graph_doc.h" 

int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr))); 

    const unsigned int colums = 50;
    const unsigned int rows = 50;

    Labyrinth* my_labyrinth = new Labyrinth(colums,rows);

    int firstPosition_x = rand()%colums;
    int firstPosition_y = rand()%rows;

    my_labyrinth->makeRoad(firstPosition_x,firstPosition_y);

    if (makeDoc("graph_svg.html",my_labyrinth,colums,rows))
    {
        delete my_labyrinth;
        return 1;
    }
    
    delete my_labyrinth;
    return 0;
} 