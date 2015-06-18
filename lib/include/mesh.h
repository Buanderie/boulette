#pragma once

// Internal
#include "shape.h"

// GLM
#include <glm/glm.hpp>

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
		std::vector< Face > 		_faces;
		std::vector< glm::vec3 >	_verts;
		std::vector< glm::vec3 > 	_norms;

	protected:
};
