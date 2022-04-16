/**
 * @file graph_doc.h
 * @author Tereza Kalniková (kal0300@vsb.cz)
 * @brief Function for making HTML document and drawing maze line in it.
 * @version 0.1
 * @date 2022-04-16
 */
#pragma once
#include <iostream>
#include <fstream>
#include "graph_labyrinth.h"

#define L_WITH(a) (double)a/100 * 5

using namespace std; 

void drawLine(unsigned int array_order, Labyrinth* lab, ofstream& file, unsigned int s_size);

bool makeDoc(string f_name, Labyrinth* lab, unsigned int col, unsigned int row);