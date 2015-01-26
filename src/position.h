/*
 * position.h
 *
 *  Created on: Jan 18, 2015
 *      Author: torp
 */

#ifndef POSITION_H_
#define POSITION_H_

namespace Connect_four {
class Position {
public:
	Position(int column, int row):m_row{row},m_column{column}{};
	int get_row() const;
	int get_column() const;
private:
	int m_row;
	int m_column;
};

}
#endif /* POSITION_H_ */
