#pragma once
#include <vector>
#include "graph_peak.h"

/**
 * @file graph_labyrinth.h
 * @author Tereza Kalniková (kal0300@vsb.cz)
 * @brief In this header is a class Labyrinth which is a graph with list of peaks.
 * @version 0.1
 * @date 2022-04-16
 */

/**
 * @brief Class of labyrinth including list of whole peaks
 * 
 */
class Labyrinth
{   
public:
    unsigned int n_size;
    unsigned int m_size;

    Peak** peaks;
    /**
     * @brief Stack of predecessors who were visited.
     * 
     */
    std::vector<Peak*> predecessors;
    /**
     * @brief Construct a new Labyrinth object. Constructor also makes _n_ * _m_ instance of peak and saves them to the list of peaks.
     * 
     * @param n number of colums
     * @param m number of rows
     */
    Labyrinth(unsigned int n, unsigned int m);
    /**
     * @brief Destroy the Labyrinth object and also destruc all instance of peak from the list of peaks.
     * 
     */
    ~Labyrinth();

    /**
     * @brief Get the Peak object
     * 
     * @param x width coordinate
     * @param y height coordinate
     * @return Peak* 
     */
    Peak* getPeak(unsigned int x, unsigned int y);

    /**
     * @brief Algorithm of DFS
     * 
     * @param x Width coordinate of the first peak.
     * @param y Height coordinate of the first peak.
     * @return TRUE Valid _x_ and _y_ index. The DFS was done correctly.
     * @return FALSE Invalid _x_ or _y_ index of first peak.
     */
    bool makeRoad(unsigned int x, unsigned int y);

    /**
     * @brief Linking the two peaks as neighbor.
     */
    void addNeighbor(Peak* from,Peak* to);

    /**
     * @brief Setting off the walls between neighbors peak.
     */
    void removeWall(Peak* actual, Peak* neighbor);
};