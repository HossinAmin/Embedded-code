/*
 * plate.h
 *
 * Created: 16-Apr-21 4:02:58 AM
 *  Author: 10
 */ 
#ifndef PLATE_H_
#define PLATE_H_

#include "../Timer/Timer_16.h"

#define ControlPort		'd'
#define In1				 5
#define In2				 4

void plate_init();
void plate_move(Bool dir,uint8 speed);
void plate_stop();



#endif /* PLATE_H_ */