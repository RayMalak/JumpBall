#pragma once

#include "Model.h"

class ShapeModel : public Model
{
public:
	enum Type
	{
		Box = 0,
		Sphere,
	};

public:
	ShapeModel();
	ShapeModel(Type typeShape);
	~ShapeModel();

	const float getRaidius(){ return m_radius; }

private:
	void GenShape(Type typeShape);

private:
	const int m_radius;
};

