//
// Created by nomodeset on 24-2-24.
//

#include "graphcuda.h"

#include <common.h>

Graphcuda &Graphcuda::getinstance() {
    static Graphcuda gc;
    return gc;
}

Graphcuda::Graphcuda() {
    this->initialized = false;
}

void Graphcuda::init(int thread_count, Graph *graph, const Schedule &schedule) {
    initialized = true;
    threadcnt = thread_count;
    graph = graph;
    int provided;
    starttime = get_wall_time();
    idlethreadcnt = 0;
    for (int i = 0; i < threadcnt; i++) {
        data[i] = new unsigned int[MESSAGE_SIZE];
        lock[i].test_and_set();
    }
    const int CHUNK_CONST = 70;
    cuda_block_chunk_size = std::max(int((long long)(graph->v_cnt) * CHUNK_CONST / graph->e_cnt), 8);
    cuda_chunk_size = (threadcnt - 1) * cuda_block_chunk_size;
    skip_flag = ~schedule.get_restrict_last(1);
    printf("cuda_csize = %d, cuda_block_csize = %d\n", cuda_chunk_size, cuda_block_chunk_size);
    fflush(stdout);
}

long long Graphcuda::runmajor() {
    long long tot_ans = 0;
    const int IDLE = 2, END = 3, OVERWORK = 4, REPORT = 5, SERVER = 0, ROLL_SIZE = 327680;
    static unsigned int recv[MESSAGE_SIZE], local_data[MESSAGE_SIZE];

}


