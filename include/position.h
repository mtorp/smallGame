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
	Position();
	virtual ~Position();
	virtual int get_row() = 0;
	virtual int get_height = 0;
private:
	int m_row;
	int m_column;
};


#endif /* POSITION_H_ */
