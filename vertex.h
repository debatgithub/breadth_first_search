#ifndef __INCLUDE_VERTEX_H__
#define __INCLUDE_VERTEX_H__
#include <iostream>
typedef enum e_vertex_color { WHITE_COLOR = 0, GRAY_COLOR = 1, BLACK_COLOR = 2 } VERTEX_COLOR;
const int LARGE_DISTANCE = 1000000;
class vertex
{

public:
    vertex() { };
    vertex (std::string _name, int _index ) { name = _name; index = _index; color = WHITE_COLOR; distance = LARGE_DISTANCE; weight = 1; predecessor = -1; };
    vertex(const vertex& v) { name = v.name; index = v.index; color = v.color; weight = v.weight; distance = v.distance; predecessor = v.predecessor; };
    std::string get_name(void ) { return name; };
    int get_predecessor(void ) { return predecessor; };
    int get_index(void ) { return index; };
    int get_weight(void ) { return weight; };
    int get_distance(void ) { return distance; }
    VERTEX_COLOR get_color(void ) { return color; };
    void set_name(std::string _name ) { name = _name; };
    void set_predecessor(int _predecessor ) { predecessor = _predecessor; };
    void set_index(int _index ) { index = _index; };
    void set_weight(int _weight ) { weight = _weight; };
    void set_color(VERTEX_COLOR _color ) { color = _color; };
    void set_distance(int _distance ) { distance = _distance; };
    void print_vertex (void ) { 
           std::cout << "name = " << name << ", color = " << color << ", distance = " << distance << ", weight = " << weight << ", predecessor = " << predecessor << std::endl;
    };
private:
    std::string name;
    int predecessor;
    VERTEX_COLOR color;
    int index;
    int distance;
    int weight;

};
#endif // __INCLUDE_VERTEX_H__
