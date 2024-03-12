//
// Created by nomodeset on 24-2-24.
//

#include "graphcuda.h"

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

}



