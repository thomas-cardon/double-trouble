#include "./movements.h"

using namespace std;

void MoveUp(CPosition & Pos) {
    -- Pos.first;
}

void MoveDown(CPosition & Pos) {
    ++ Pos.first;
}

void MoveLeft(CPosition & Pos) {
    -- Pos.second;
}

void MoveRight(CPosition & Pos) {
    ++ Pos.second;
}
