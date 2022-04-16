#include "graph_doc.h"

void drawLine(unsigned int array_order, Labyrinth* lab, ofstream& file, unsigned int s_size)
{
    Peak* my_peak = lab->peaks[array_order];//return specific peak

    if(my_peak->walls.top)
    {
        file << "<line x1='"<<my_peak->coordinates.x*s_size + s_size<<"' y1='"<<my_peak->coordinates.y*s_size + s_size<<"' x2='"<<my_peak->coordinates.x*s_size + s_size*2 <<"' y2='"<<my_peak->coordinates.y*s_size + s_size<<"' style='stroke:black;stroke-width:"<<L_WITH(s_size)<<"' />"<<endl;
    }
    if(my_peak->walls.left)
    {
        file << "<line x1='"<<my_peak->coordinates.x*s_size + s_size<<"' y1='"<<my_peak->coordinates.y*s_size + s_size<<"' x2='"<<my_peak->coordinates.x*s_size + s_size<<"' y2='"<<my_peak->coordinates.y*s_size + s_size*2<<"' style='stroke:black;stroke-width:"<<L_WITH(s_size)<<"' />"<<endl;
    }
}
bool makeDoc(string f_name, Labyrinth* lab, unsigned int col, unsigned int row)
{
    ofstream file;
    const unsigned int square_size = 20;

    file.open (f_name);
    file << "<!DOCTYPE html><html><body><svg width='"<<col*square_size + square_size*3<<"' height='"<<row*square_size + square_size*3<<"'>"<<endl; //starting html
    file << "  <rect x='"<<square_size<<"' y='"<<square_size<<"' width='"<<square_size*col<<"' height='"<<square_size*row<<"' style='fill:white;stroke:black;stroke-width:"<<L_WITH(square_size)<<";' />"<<endl;

    for (unsigned int i=0; i< lab->n_size*lab->m_size; i++)
        drawLine(i,lab,file,square_size);

    file << "</svg></body></html>";
    file.close();
     
    return 0;
}