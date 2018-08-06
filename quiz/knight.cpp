//
// Created by Administrator on 2018-08-04.
//

#include <iostream>
#include "knight.h"

Knight::Knight() {

}

Knight::~Knight() {

}

void Knight::RunTestFromAllInitPositions() {
    for (int i = 0; i < NUM_BOARD_LINE; i++) {
        for (int j = 0; j < NUM_BOARD_LINE; j++) {
            Step init_step = Step(i, j);
            Traverse(init_step);
            std::cout << trial_final_steps[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Knight::Traverse(const Step &init_step) {
    // reset chess_board array
    for (int i = 0; i < NUM_BOARD_LINE; i++) {
        for (int j = 0; j < NUM_BOARD_LINE; j++) {
            chess_board[i][j] = 0;
            trial_final_steps[i][j] = 0;
        }
    }
    // reset accessibility table array
    int new_accessibility[8][8] = {{2, 3, 4, 4, 4, 4, 3, 2},
                                   {3, 4, 6, 6, 6, 6, 4, 3},
                                   {4, 6, 8, 8, 8, 8, 6, 4},
                                   {4, 6, 8, 8, 8, 8, 6, 4},
                                   {4, 6, 8, 8, 8, 8, 6, 4},
                                   {4, 6, 8, 8, 8, 8, 6, 4},
                                   {3, 4, 6, 6, 6, 6, 4, 3},
                                   {2, 3, 4, 4, 4, 4, 3, 2}};
    for (int i = 0; i < NUM_BOARD_LINE; i++) {
        for (int j = 0; j < NUM_BOARD_LINE; j++) {
            accessibility[i][j] = new_accessibility[i][j];
        }
    }
    std::vector<Step> possible_steps;
    chess_board[init_step.x][init_step.y] = 1;
    Step step = init_step;
    int num_step = 0;
    do {
        chess_board[step.x][step.y] = ++num_step;
        trial_final_steps[init_step.x][init_step.y] = num_step;
        step = FindNext(possible_steps, step);
    } while (step.x != -1 && step.y != -1 && !ChessBoardVisitAll());
    Print();
}

Step Knight::FindNext(std::vector<Step> &next_steps, const Step &current) {
    if (!next_steps.empty()) {
        next_steps.clear();
    }
    std::vector<Step> step_candidates = {
            {current.x - 2, current.y + 1},
            {current.x - 2, current.y - 1},
            {current.x + 2, current.y + 1},
            {current.x + 2, current.y - 1},
            {current.x - 1, current.y + 2},
            {current.x - 1, current.y - 2},
            {current.x + 1, current.y + 2},
            {current.x + 1, current.y - 2}};
    for (auto &step : step_candidates) {
        if (Valid(step) && chess_board[step.x][step.y] == 0) {
            next_steps.push_back(step);
            // update the accessibility at beginning of each search for possible candidate next steps
            UpdateAccessibility(step);
        }
    }
    if (next_steps.size() < 1) {
        return Step(-1, -1);
    } else {
        Step first_candidate = next_steps[0];
        int minx = first_candidate.x;
        int miny = first_candidate.y;
        int min_accessibility = accessibility[minx][miny];
        for (auto &next_step : next_steps) {
            if (min_accessibility > accessibility[next_step.x][next_step.y]) {
                min_accessibility = accessibility[next_step.x][next_step.y];
                minx = next_step.x;
                miny = next_step.y;
            }
        }
        return Step(minx, miny);
    }
}

void Knight::Print() {
    std::cout << "\nThe Knight Traverse Routine:" << std::endl;
    for (int i = 0; i < NUM_BOARD_LINE; i++) {
        for (int j = 0; j < NUM_BOARD_LINE; j++) {
            std::cout << chess_board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool Knight::Valid(const Step &step) {
    return (step.x >= 0 && step.x <= 7 && step.y >= 0 && step.y <= 7);
}

void Knight::UpdateAccessibility(const Step &step_candidate) {
    accessibility[step_candidate.x][step_candidate.y] -= 1;
}

bool Knight::ChessBoardVisitAll() {
    for (int i = 0; i < NUM_BOARD_LINE; i++) {
        for (int j = 0; j < NUM_BOARD_LINE; j++) {
            if (chess_board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
