#pragma once

#include "Model.h"

class StairsModel : public Model
{
public:
	StairsModel();
	StairsModel(const unsigned int stairsNum);
	~StairsModel();

private:
	void GenStairs(const unsigned int stairsNum);

};

