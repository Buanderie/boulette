#pragma once

#include "shape.h"

class Mesh : public Shape
{
	public:
		Mesh(){}
		virtual ~Mesh(){}
		std::vector< Shape > tesselate()
		{
			std::vector< Shape > res;
			return res;
		}

	private:

	protected:
}
