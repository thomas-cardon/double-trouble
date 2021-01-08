#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#endif // MOVEMENTS_H

#include "./type.h"

/*!
 * \file movements.h
 * \brief Movements function for the players
 * \author Thomas Cardon
 * \version 12.0
 * \date 6 janvier 2021
 */

void MoveUp(CPosition & Pos);
void MoveDown(CPosition & Pos);
void MoveLeft(CPosition & Pos);
void MoveRight(CPosition & Pos);

void MoveUpLeft(CPosition & Pos);
void MoveUpRight(CPosition & Pos);
void MoveDownLeft(CPosition & Pos);
void MoveDownRight(CPosition & Pos);
