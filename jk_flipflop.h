/*
 * jk_flipflop.h
 *
 *  Created on: Nov 26, 2014
 *      Author: joe--ngigi
 */
#include "systemc.h"
//#include<iostream>

SC_MODULE (jkflipflop){
	sc_in<bool>j,k,clk;
	sc_inout<bool>q;

	void prc_jkflipflop(){

		sc_uint<2>temp;
		temp[1]=j.read();
		temp[0]=k.read();


		switch(temp)
		{
		case 0x1: q.write(0);
			break;
		case 0x2: q.write(1);
			break;
		case 0x3:
			q.write(!q.read());
			break;
		default: break;
		}
	}

		SC_CTOR (jkflipflop){
		SC_METHOD(prc_jkflipflop);
		sensitive<<clk;
		}
	};



