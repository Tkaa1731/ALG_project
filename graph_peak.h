/**
 * @file graph_peak.h
 * @author Tereza Kalniková (kal0300@vsb.cz)
 * @brief In this header is a class Peak of graph and stuctures used by it.
 * @version 0.1
 * @date 2022-04-16
 */
#pragma once
#include <vector>
#include <algorithm>

/**
 * @brief Coordinates of peak.
 * 
 */
struct  Point
{
    unsigned int x;
    unsigned int y;
};

/**
 * @brief Top and left wall setted in each peak on.
 * 
 */
struct Walls
{
    bool left;
    bool top;
};

/**
 * @brief State of peak during DFS.
 * 
 */
enum State
{
    /**
     * @brief Peak hasn't been visited yet.
     * 
     */
    OPEN,
    /**
     * @brief Peak has been already visited. In stack of predecessors.
     * 
     */
    VISITED,
    /**
     * @brief No one neghbor of the peak is OPEN. Put out from stack of predecessors.
     * 
     */
    CLOSED
};

/**
 * @brief Class of peak including list of its neighbor peaks.
 * 
 */
class Peak
{
public:
    Point coordinates;
    Walls walls;
    unsigned int neighborsCount;
    std::vector<Peak*> neighbors;
    State cellState;

    Peak(unsigned int x, unsigned int y);

    /**
     * @brief Get the OPEN Neighbor object from stack of neighbors.
     * 
     * @return Peak* 
     */
    Peak* getOpenNeighbor();
};
