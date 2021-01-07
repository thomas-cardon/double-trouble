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
void MoveLeft(CPosition & pos);
void MoveRight(CPosition & pos);

void MoveUpLeft(CPosition & Pos);
void MoveUpRight(CPosition & Pos);
void MoveDownLeft(CPosition & pos);
void MoveDownRight(CPosition & pos);
