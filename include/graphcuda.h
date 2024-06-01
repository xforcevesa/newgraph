//
// Created by nomodeset on 24-2-24.
//

#ifndef GRAPHCUDA_H
#define GRAPHCUDA_H

#include "graph.h"
#include "graphmpi.h"

class Graphcuda {
public:
    static Graphcuda& getinstance();
    void init(int thread_count, Graph *graph, const Schedule& schedule);
    long long runmajor(); // mpi uses on major thread

private:
    static const int MAXTHREAD = 24, MESSAGE_SIZE = 5;
    Graph* graph;
    int *loop_data[MAXTHREAD], comm_sz, my_rank, idlethreadcnt, threadcnt, cuda_chunk_size, cuda_block_chunk_size;
    unsigned int loop_size[MAXTHREAD], *data[MAXTHREAD];
    long long node_ans;
    double starttime;
    bool loop_flag = false, skip_flag; // loop_flag is set when using mpi; skip_flag is set when there is a restriction on the first pattern edge
    Bx2k256Queue idleq;
    //std::queue<int> idleq;
    std::atomic_flag lock[MAXTHREAD], qlock;
    bool initialized;
    Graphcuda();
    Graphcuda(const Graphmpi&&) = delete;
    Graphcuda(const Graphmpi&) = delete;
    Graphcuda& operator = (const Graphmpi&) = delete;
};


#endif //GRAPHCUDA_H
