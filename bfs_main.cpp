#include <iostream>
#include "vertex.h"
#include "vertex_queue.h"
int main (void );
#define VERTEX_NUM 8
vertex * bfs_vertices[VERTEX_NUM];
int adj_matrix_bfs_vertices[VERTEX_NUM][VERTEX_NUM];
void breadth_first_search (vertex ** bfs_vertices, int ** adj_matrix_bfs_verices, int vertex_count, int start_index );
void print_breadth_first_search_result (vertex ** bfs_vertices, int ** adj_matrix_bfs_verices, int vertex_count );


int main (void ) 
{
int i, j;

    for (i = 0; i < VERTEX_NUM; i++) {
        for (j = 0; j < VERTEX_NUM; j++) {
            adj_matrix_bfs_vertices[i][j] = (i == j) ? 1 : 0;
        }
    }
    bfs_vertices[0] = new vertex("r", 0);
    bfs_vertices[1] = new vertex("s", 1);
    bfs_vertices[2] = new vertex("t", 2);
    bfs_vertices[3] = new vertex("u", 3);
    bfs_vertices[4] = new vertex("v", 4);
    bfs_vertices[5] = new vertex("w", 5);
    bfs_vertices[6] = new vertex("x", 6);
    bfs_vertices[7] = new vertex("y", 7);
    adj_matrix_bfs_vertices[0][1] = 1;
    adj_matrix_bfs_vertices[0][4] = 1;
    adj_matrix_bfs_vertices[1][0] = 1;
    adj_matrix_bfs_vertices[1][5] = 1;
    adj_matrix_bfs_vertices[2][3] = 1;
    adj_matrix_bfs_vertices[2][5] = 1;
    adj_matrix_bfs_vertices[2][6] = 1;
    adj_matrix_bfs_vertices[3][2] = 1;
    adj_matrix_bfs_vertices[3][6] = 1;
    adj_matrix_bfs_vertices[3][7] = 1;
    adj_matrix_bfs_vertices[4][0] = 1;
    adj_matrix_bfs_vertices[5][1] = 1;
    adj_matrix_bfs_vertices[5][2] = 1;
    adj_matrix_bfs_vertices[5][6] = 1;
    adj_matrix_bfs_vertices[6][2] = 1;
    adj_matrix_bfs_vertices[6][3] = 1;
    adj_matrix_bfs_vertices[6][5] = 1;
    adj_matrix_bfs_vertices[6][7] = 1;
    adj_matrix_bfs_vertices[7][3] = 1;
    adj_matrix_bfs_vertices[7][6] = 1;
    
    breadth_first_search(bfs_vertices, (int **)adj_matrix_bfs_vertices, VERTEX_NUM, 1 );
    print_breadth_first_search_result(bfs_vertices, (int **)adj_matrix_bfs_vertices, VERTEX_NUM );
    return 0;
};


void breadth_first_search (vertex ** bfs_vertices, int **adj_matrix_bfs_verices, int vertex_count, int start_index )
{
   for (int i = 0; i < vertex_count; i++) {
       if (i != start_index) {
           bfs_vertices[i]->set_color(WHITE_COLOR);
           bfs_vertices[i]->set_distance(LARGE_DISTANCE);
           bfs_vertices[i]->set_predecessor(-1);
       } 
    }
    QUEUE_ERROR q_err;
    vertex_queue * p_vert_q = new vertex_queue(vertex_count); 
    bfs_vertices[start_index]->set_color(GRAY_COLOR);
    bfs_vertices[start_index]->set_distance(0);
    bfs_vertices[start_index]->set_predecessor(-1);
    p_vert_q->vertex_enqueue(bfs_vertices[start_index]);
    while (p_vert_q->is_vertex_queue_empty() == false) {
        vertex * u = p_vert_q->vertex_dequeue(&q_err);
        int u_index = u->get_index();
        for (int j = 0; j < vertex_count; j++) {
            if (adj_matrix_bfs_vertices[u_index][j] == 1) {
                vertex * v = bfs_vertices[j];
                if (v->get_color() == WHITE_COLOR) {
                    v->set_color(GRAY_COLOR);
                    v->set_distance(u->get_distance()+1);
                    v->set_predecessor(u_index);
                    p_vert_q->vertex_enqueue(v);
                }
            }
        }
        u->set_color(BLACK_COLOR);
    }
    delete p_vert_q;
}
 


void print_breadth_first_search_result (vertex ** bfs_vertices, int **adj_matrix_bfs_verices, int vertex_count )
{
   for (int i = 0; i < vertex_count; i++) 
       bfs_vertices[i]->print_vertex();
    
}

        
