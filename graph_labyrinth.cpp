#include "graph_labyrinth.h"

Labyrinth::Labyrinth(unsigned int n, unsigned int m)
{
    this->n_size = n;
    this->m_size = m;

    this->peaks = new Peak*[n*m];

    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            this->peaks[n*i+j] = new Peak(j,i);
            if (i != 0) //isnt top
            {
                this->addNeighbor(this->peaks[n*i+j],this->peaks[n*(i-1)+j]);//upper neighbor
            }
            if (j != 0) //isnt left
            {
                this->addNeighbor(this->peaks[n*i+j],this->peaks[n*i+j-1]);//left neighbor
            }
        }//generating by rows
    }
}

Labyrinth::~Labyrinth()
{
    for (unsigned int i = 0; i < this->m_size*this->n_size; i++)
    {
        delete this->peaks[i];
    }
    delete[] this->peaks;
}

Peak* Labyrinth::getPeak(unsigned int x, unsigned int y)
{
    for (unsigned int i = 0; i < this->m_size*this->n_size; i++)
    {
        if (this->peaks[i]->coordinates.x == x && this->peaks[i]->coordinates.y == y)
        {
            return peaks[i];
        }
        
    }
    return nullptr;
}

bool Labyrinth::makeRoad(unsigned int x, unsigned int y)
{
    Peak* frstPeak = this->getPeak(x,y);
    Peak* actualPeak = frstPeak;
    Peak* actualNeighbor;
  
    if (frstPeak == nullptr)
    {
        // std::cout<<"Ivalid x or y index."<<std::endl;
        return false;
    }
    
    while(frstPeak->cellState != CLOSED)
    {
        // Get random neighbor of the peak from vector of neighbors.
        actualNeighbor = actualPeak->getOpenNeighbor();

        //The peak have neighbor with state OPEN. So the way continue to the neighbor and the peak has been already VISITED and added to the stack of predecessors.
        if (actualNeighbor != nullptr)
        {
            this->predecessors.push_back(actualPeak);
            actualPeak->cellState = VISITED;
            removeWall(actualPeak,actualNeighbor);
            actualPeak = actualNeighbor;
        }

        //The peak doesn't have any neighbor with state OPEN. So this way is dead-end street, have to return back to predecessor peak.
        else
        {
            actualPeak->cellState = CLOSED;
            actualPeak = this->predecessors.back();
            this->predecessors.pop_back();
        }
    }
    return true;
}

void Labyrinth::addNeighbor(Peak* from, Peak*to)
{
    from->neighbors.push_back(to);
    to->neighbors.push_back(from);
}

void Labyrinth::removeWall(Peak* actual, Peak* neighbor)
{
    //Neighbor peak is below actual one
    if(actual->coordinates.y +1 == neighbor->coordinates.y && actual->coordinates.x == neighbor->coordinates.x)
    {
        neighbor->walls.top = false;
    }

    //Neighbor peak is above actual one
    else if(actual->coordinates.y -1 == neighbor->coordinates.y && actual->coordinates.x == neighbor->coordinates.x)
    {
        actual->walls.top = false;
    }

    //Neighbor peak is on the right of actual one
    else if(actual->coordinates.x +1 == neighbor->coordinates.x && actual->coordinates.y == neighbor->coordinates.y)
    {
        neighbor->walls.left = false;
    }
    
    //Neighbor peak is on the left of actual one
    else if(actual->coordinates.x -1== neighbor->coordinates.x && actual->coordinates.y == neighbor->coordinates.y)
    {
        actual->walls.left = false;
    }
}