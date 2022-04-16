#include "graph_peak.h"

Peak::Peak(unsigned int x, unsigned int y)
{
    this->coordinates = {x,y};
    this->cellState = OPEN;
    this->walls = {true,true};
}

Peak* Peak::getOpenNeighbor()
{
    std::random_shuffle(this->neighbors.begin(),this->neighbors.end());
    for(auto neighbor : neighbors)
    {
        if (neighbor->cellState == OPEN)
        {
            return neighbor;
        }   
    }
    return nullptr;
}