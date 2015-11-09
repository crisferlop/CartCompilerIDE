/*
 * varint.h
 *
 *  Created on: 4/11/2015
 *      Author: cristianfernando
 */

#ifndef VARINT_H_
#define VARINT_H_

class VarInt {
	char * name;
	long block;
	int integer;

public:
	VarInt(const char*,int, long, int);

	virtual ~VarInt();
	long getBlock() const;
	void setBlock(long block);
	int getInteger() const;
	void setInteger(int integer);
	char* getName() const;
	void setName(char* name);
};

#endif /* VARINT_H_ */
