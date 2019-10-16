/**
* @file CacheMemory.cpp
* @brief Cache memory source
* @author Dennis Porras Barrantes
* @date 29/03/19
**/

#include "../include/CacheMemory.h"

/**
 * @brief Construct a new Cache Memory:: Cache Memory object
 * 
 * @param _x dimension
 * @param _y dimension
 */
CacheMemory::CacheMemory(int _x, int _y)
{
    this->pu_coordinate.x = _x;
    this->pu_coordinate.y = _y;
    this->blocks = NULL;
    this->clk_intance = NULL;
}

int CacheMemory::readData(int address, int priority)
{
    //std::cout << "READ MEMORY ON ADDRESS " << address << " PRIORITY " << priority << std::endl;
    return 2;
}
void CacheMemory::writeData(int address, int data, int priority)
{
    //std::cout << "WRITE TO MEMORY ON ADDRESS " << address << " VALUE OF " << data << " PRIORITY " << priority << std::endl;
}