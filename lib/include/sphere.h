#pragma once

// Internal
#include "mesh.h"
#include "shape.h"

class Sphere : public Shape
{
	public:
		Sphere(){}
		virtual ~Sphere(){}
		virtual std::vector< std::shared_ptr<Mesh> >  tesselate()
		{
			std::vector< std::shared_ptr<Mesh> > res;
			return res;	
		}

	private:

	protected:

};
