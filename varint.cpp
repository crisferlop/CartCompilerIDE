/*
 * varint.cpp
 *
 *  Created on: 4/11/2015
 *      Author: cristianfernando
 */

#include "varint.h"
#include "string.h"
#include "stdlib.h"

VarInt::VarInt(const char* pname,int pnameLenght, long pblock, int pinteger): block(pblock),integer(pinteger){
	// TODO Auto-generated constructor stub
	name = (char*)malloc(sizeof(char)*pnameLenght + sizeof(char));
	memcpy(name, pname, pnameLenght);
	name[sizeof(char)*pnameLenght] = '\0';
}

long VarInt::getBlock() const {
	return block;
}

void VarInt::setBlock(long block) {
	this->block = block;
}

int VarInt::getInteger() const {
	return integer;
}

void VarInt::setInteger(int integer) {
	this->integer = integer;
}

char* VarInt::getName() const {
	return name;
}

void VarInt::setName(char* name) {
	this->name = name;
}

VarInt::~VarInt() {
	// TODO Auto-generated destructor stub
	free(name);
}

