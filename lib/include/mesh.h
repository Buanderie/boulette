#pragma once

// Internal
#include "shape.h"

// STL
#include <memory>

class Mesh : public Shape
{
	typedef struct
	{
		std::vector< unsigned int > _vertexIdx;
		std::vector< unsigned int > _normalIdx;
	} Face;

	public:
		Mesh(){}
		virtual ~Mesh(){}
		virtual std::vector< std::shared_ptr<Mesh> > tesselate()
		{
			std::vector< std::shared_ptr<Mesh> > res;
			return res;
		}

	private:

	protected:
};
