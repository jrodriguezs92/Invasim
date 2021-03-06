/**
* @file ManyCoreArch.cpp
* @brief Manycore architecture source
* @author Dennis Porras Barrantes
* @date 27/03/19
**/

#include "../include/ManyCoreArch.h"

/**
 * @brief Construct a new Many Core Arch:: Many Core Arch object
 * 
 * @param _x_dim 
 * @param _y_dim 
 * @param _clk_instance 
 */
ManyCoreArch::ManyCoreArch(int _x_dim, int _y_dim, Clock *_clk_instance)
{
    dprintf("MANYCOREARCH: Manycore Architecture instance created.\n\t- Dimension: (%d, %d).\n", _x_dim, _y_dim);
    this->init(_x_dim, _y_dim, _clk_instance);
    this->resource_manager = new ResourceAdmin(this->pu_array, this->x_dim,
                                               this->y_dim, this->clk_instance);
    this->max_ilets = DEFAULT_MAX_ILETS;
}

/**
 * @brief Construct a new Many Core Arch:: Many Core Arch object
 * 
 * @param _x_dim 
 * @param _y_dim 
 * @param _clk_instance 
 * @param _max_ilets 
 */
ManyCoreArch::ManyCoreArch(int _x_dim, int _y_dim, Clock *_clk_instance, int _max_ilets)
{
    dprintf("MANYCOREARCH: Manycore Architecture instance created.\n\t- Dimension: (%d, %d).\n", _x_dim, _y_dim);
    this->init(_x_dim, _y_dim, _clk_instance);
    this->resource_manager = new ResourceAdmin(this->pu_array, this->x_dim,
                                               this->y_dim, _max_ilets, 
                                               this->clk_instance);
    this->max_ilets = _max_ilets;
}

/**
 * @brief Function that starts the processing unit and resource administrator
 * 
 */
void ManyCoreArch::start()
{
    dprintf("MANYCOREARCH: Starting processing units.\n");
    for (int i = 0; i < this->x_dim; i++)
    {
        for (int j = 0; j < this->y_dim; j++)
        {
            this->pu_array[i][j]->start();
        }
    }
    this->resource_manager->start();
}

/**
 * @brief Function that invades resources from resource admin
 * 
 * @param new_iLet 
 */
void ManyCoreArch::invade(ILet *new_iLet)
{
    this->resource_manager->add_iLet(new_iLet);
}

/**
 * @brief Getter for the amoun of processing units
 * 
 * @return int 
 */
int ManyCoreArch::get_procs()
{
    return this->x_dim * this->y_dim;
}

/**
 * @brief Getter for the max amount of iLets
 * 
 * @return unsigned int 
 */
unsigned int ManyCoreArch::get_max_ilets()
{
    return this->max_ilets;
}

/**
 * @brief Function that gets the state of every component's state
 * 
 * @return JSON* with info
 */
JSON *ManyCoreArch::monitoring()
{
    //New json for info
    JSON *arch_info = new JSON;
    
    //Get resource admin and processing units info
    JSON *resources_info = this->resource_manager->monitoring();
    
    //Json contruciton
    *arch_info = {
        {"System",
         {{"Processor",
           {{"x", this->x_dim}, {"y", this->y_dim}}},
          {"Cycle", this->clk_instance->get_cycle()}}},
        {"Components", *resources_info}};
    //Deallocate useless memory 
    delete resources_info;
    return arch_info;
}

/**
 * @brief Function that initialize components in system
 * 
 * @param _x_dim 
 * @param _y_dim 
 * @param _clk_instance 
 */
void ManyCoreArch::init(int _x_dim, int _y_dim, Clock *_clk_instance)
{
    this->pu_array = new ProcessingUnit **[_x_dim];

    dprintf("MANYCOREARCH: Instanciating processing units in matrix.\n");
    for (int i = 0; i < _x_dim; i++)
    {
        this->pu_array[i] = new ProcessingUnit *[_y_dim];
        for (int j = 0; j < _y_dim; j++)
        {
            this->pu_array[i][j] = new ProcessingUnit(i, j, _clk_instance);
        }
    }

    this->x_dim = _x_dim;
    this->y_dim = _y_dim;
    this->clk_instance = _clk_instance;
    this->ram = new RandomAccessMemory();
}