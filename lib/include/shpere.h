#pragma once

// Internal
#include "shape.h"

class Sphere : public Shape
{
	public:
		Sphere(){}
		virtual ~Shpere(){}
		virtual std::vector< std::shared_ptr<Mesh> > > tesselate()
		{
			std::vector< std::shared_ptr<Mesh> > res;
			return res;	
		}

	private:

	protected:

};
