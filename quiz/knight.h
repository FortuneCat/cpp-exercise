//
// Created by Administrator on 2018-08-04.
//

#ifndef CPP_INTERVIEW_KNIGHT_H
#define CPP_INTERVIEW_KNIGHT_H

#include <cstdlib>
#include <vector>

struct Step {
    Step(size_t x_, size_t y_) {
        x = x_;
        y = y_;
    }

    size_t x;
    size_t y;
};

/*
 * 数学家欧拉提出的骑士旅行问题：能否让骑士在空棋盘上移动，在64个方格中经过且只经过一次？
 */
class Knight {
public:
    Knight();

    ~Knight();

    void RunTestFromAllInitPositions();

    void Traverse(const Step &init_step);

    Step FindNext(std::vector<Step> &next_steps, const Step &current);

    void Print();

private:
    inline bool Valid(const Step &step);

    void UpdateAccessibility(const Step &step_candidate);

    bool ChessBoardVisitAll();

    static const int NUM_BOARD_LINE = 8;
    int chess_board[NUM_BOARD_LINE][NUM_BOARD_LINE];
    int accessibility[NUM_BOARD_LINE][NUM_BOARD_LINE] = {{2, 3, 4, 4, 4, 4, 3, 2},
                                                         {3, 4, 6, 6, 6, 6, 4, 3},
                                                         {4, 6, 8, 8, 8, 8, 6, 4},
                                                         {4, 6, 8, 8, 8, 8, 6, 4},
                                                         {4, 6, 8, 8, 8, 8, 6, 4},
                                                         {4, 6, 8, 8, 8, 8, 6, 4},
                                                         {3, 4, 6, 6, 6, 6, 4, 3},
                                                         {2, 3, 4, 4, 4, 4, 3, 2}};
    // 从棋盘上任何一格开始，最后能访问到达的格子数
    int trial_final_steps[NUM_BOARD_LINE][NUM_BOARD_LINE];
};


#endif //CPP_INTERVIEW_KNIGHT_H
