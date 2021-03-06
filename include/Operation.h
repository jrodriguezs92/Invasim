/**
* @file Operation.h
* @brief Description
* @author Dennis Porras Barrantes
* @date 18/03/19
**/

#ifndef INCLUDE_OPERATION_H_
#define INCLUDE_OPERATION_H_

#include "Utils.h"

/**
 * @brief Enum of invasive computing operations
 * 
 */
enum Invasive_Operation
{
	INVADE,
	INFECT,
	RETREAT
};

/**
 * @brief Array asociated with the enum Invasive_Operation
 * 
 */
static const std::string STRING_OPERATIONS[] = 
{
	"Invade",
	"Infect",
	"Retreat"
};

/**
 * @brief Operation representation with its corresponding parameter.
 * 
 */
class Operation 
{
	public: 
		Operation(Invasive_Operation _operation, int _parameter);
		
		Invasive_Operation get_operation();

		int get_parameter();

	private:
		/**
		 * @brief Invasive operation
		 * 
		 */
		Invasive_Operation operation;
		/**
		 * @brief Parameter of operation
		 * 
		 */
		int parameter;
};

#endif