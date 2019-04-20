/**
* @file SequenceIlet.h
* @brief Description
* @author Dennis Porras Barrantes
* @date 19/04/19
**/

#ifndef INCLUDE_SEQUENCEILET_H_
#define INCLUDE_SEQUENCEILET_H_

#include <vector>
#include "Debug.h"

#include "Clock.h"
#include "ManyCoreArch.h"
#include "ILet.h"

enum Sequence_Type
{
	RANDOM,
	ATTACK
};

class SequenceIlet 
{
	public: 
		SequenceIlet(Clock * _clk_instance, ManyCoreArch * _manycore_ptr);
		SequenceIlet(Sequence_Type _seq_type, Clock * _clk_instance, ManyCoreArch * _manycore_ptr);

		void start();

	private:
		pthread_t seq_thread;

		Sequence_Type seq_type;
		Clock * clk_instance;
		ManyCoreArch * manycore_ptr;
		std::vector<ILet *> created_ilets;

		void init(Clock * _clk_instance, ManyCoreArch * _manycore_ptr);
		static void *generate(void *obj);
};

#endif