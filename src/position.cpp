/*
 * Position.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: torp
 */

#include "position.h"
using namespace Connect_four;

int Position::get_column() const{
	return Position::m_column;
}

int Position::get_row() const {
	return Position::m_row;
}


