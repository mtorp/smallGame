/*
 * position.h
 *
 *  Created on: Jan 18, 2015
 *      Author: torp
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
public:
	Position(int row, int column);
	int get_row();
	int get_height();
private:
	int m_row;
	int m_column;
};


#endif /* POSITION_H_ */
