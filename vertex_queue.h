#ifndef __INCLUDE_VERTEX_QUEUE_H__
#define __INCLUDE_VERTEX_QUEUE_H__
#include <iostream>
#include "vertex.h"
typedef enum equeue_error { QUEUE_OVERFLOW = -2, QUEUE_UNDERFLOW = -1, QUEUE_SUCCESS = 0 } QUEUE_ERROR;
class vertex_queue {
    public:
        vertex_queue(int _max_queue_depth )  {
            queue_max = _max_queue_depth;
            queue_head = 0;
            queue_tail = 0;
        };
       ~vertex_queue() { };
        QUEUE_ERROR vertex_enqueue(vertex * x) {
            if ((queue_head == queue_tail+1) || ((queue_head == 0) && (queue_tail == queue_max)))
                return QUEUE_OVERFLOW;
            queue_nodes[queue_tail++] = x;
            if (queue_tail == queue_max)
                queue_tail = 0;
            return QUEUE_SUCCESS;
        };

        vertex * vertex_dequeue(QUEUE_ERROR * p_err) {
            if (queue_head == queue_tail) {
                if (p_err != NULL) 
                    *p_err = QUEUE_UNDERFLOW;
                return NULL;
            };
            vertex * x = queue_nodes[queue_head++];
            if (queue_head == queue_max)
                queue_head = 0;
            if (p_err != NULL)
                *p_err = QUEUE_SUCCESS;
            return x;
        }
        bool is_vertex_queue_empty(void ) {
            return (queue_head == queue_tail);
        };
    protected:
        int queue_head;
        int queue_tail;
        int queue_max;
        vertex * queue_nodes[256];
 
};
#endif // __INCLUDE_VERTEX_QUEUE_H__


         
