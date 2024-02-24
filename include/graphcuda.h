//
// Created by nomodeset on 24-2-24.
//

#ifndef GRAPHCUDA_H
#define GRAPHCUDA_H

#include "graph.h"

class CudaPattern : public Pattern {
public:
    explicit CudaPattern(int _size, bool clique = false);
    CudaPattern(int _size, char* buffer);
    ~CudaPattern();
    CudaPattern(const CudaPattern& p);
    explicit CudaPattern(PatternType type);
    void add_edge(int x, int y);
    void del_edge(int x, int y);
    inline void add_ordered_edge(int x, int y) const { adj_mat[INDEX(x, y, size)] = 1;}
    inline int get_size() const {return size;}
    inline const int* get_adj_mat_ptr() const {return adj_mat;}
    bool check_connected() const;
    void count_all_isomorphism(std::set< std::set<int> >& s) const;
    void print() const;
    bool is_dag() const;
protected:
    CudaPattern& operator =(const CudaPattern&);
    void get_full_permutation(std::vector< std::vector<int> >& vec, bool use[], std::vector<int> tmp_vec, int depth) const;
};

class CudaSchedule : public Schedule {
public:
    CudaSchedule();
};

class GraphNew : public Graph {

};

#endif //GRAPHCUDA_H
