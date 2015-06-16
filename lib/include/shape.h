#pragma once

// STL
#include <memory>
#include <vector>

class Mesh;
class Shape
{
	public:
		Shape();
		virtual ~Shape();
		
		// Shall be abstract
		virtual std::vector< std::shared_ptr<Mesh> > tesselate()
		{
			std::vector< std::shared_ptr<Mesh> > res;
			return res;
		}
		
	private:
		
	protected:

};

