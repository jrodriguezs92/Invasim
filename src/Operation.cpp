/**
* @file Operation.cpp
* @brief Operation source
* @author Dennis Porras Barrantes
* @date 18/03/19
**/

#include "../include/Operation.h"

/**
 * @brief Construct a new Operation:: Operation object
 * 
 * @param _operation 
 * @param _parameter 
 */

Operation::Operation(Invasive_Operation _operation, int _parameter)
{
    this->operation = _operation;
    this->parameter = _parameter;
}

/**
 * @brief Construct a new Operation:: Operation object
 * 
 * @param _operation 
 * @param _parameter 
 * @param _codeOperation 
 */
Operation::Operation(Invasive_Operation _operation, int _parameter, std::vector<subProcess> _codeOperation)
{
    this->operation = _operation;
    this->parameter = _parameter;
    this->codeOperation = _codeOperation;
}

/**
 * @brief Getter for operation
 * 
 * @return Invasive_Operation 
 */
Invasive_Operation Operation::get_operation()
{
    return this->operation;
}

/**
 * @brief Getter for parameter
 * 
 * @return int 
 */
int Operation::get_parameter()
{
    return this->parameter;
}

/**
 * @brief Getter for execution one instruction of code
 * 
 * @return std::string
 */
std::string Operation::get_codeOperation(int sub, int inst)
{
    //std::cout << inst << std::endl;
    if ((inst >= 0) && (inst < (int)this->codeOperation[sub].code.size()))
    {
        return this->codeOperation[sub].code[inst];
    }
    else
    {
        return "Nope";
    }
}

/**
 * @brief Getter for subProcess
 * 
 * @return std::string
 */
std::vector<subProcess> Operation::get_subProcess()
{
    return this->codeOperation;
}

/**
 * @brief Setter for execution one instruction of code
 * 
 * @return void
 */
void Operation::set_codeOperation(int sub, coordinate pu)
{
    //std::cout << inst << std::endl;
    if ((sub >= 0) && (sub < (int)this->codeOperation.size()))
    {
        this->codeOperation[sub].state = true;
        this->codeOperation[sub].SPxPU = pu; 
    }
}

/**
 * @brief Setter reduce WorkLoad process
 * 
 * @return void
 */
void Operation::reduce_WorkOfProcess(int sub)
{
    //std::cout << inst << std::endl;
    if ((sub >= 0) && (sub < (int)this->codeOperation.size()))
    {
        this->codeOperation[sub].puWork = this->codeOperation[sub].puWork-1;
    }
}