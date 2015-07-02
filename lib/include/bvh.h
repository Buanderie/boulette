#pragma once

// Internal
#include "mesh.h"

// Compute
#include <boost/compute.hpp>

// STL
#include <vector>
#include <memory>

class BVH
{
	public:
		BVH( std::vector< std::shared_ptr<Mesh> > meshes )
		:_meshes(meshes)
                {
                    init();
                }

		virtual ~BVH()
		{

		}
		
		void testBuild();

	private:
		std::vector< std::shared_ptr<Mesh> > _meshes;

		void init();
		
		// Kernels src
		static const char * _clSrc;
		
		// Compute
		boost::compute::device _device;
		boost::compute::context _context;
		boost::compute::program _program;
		boost::compute::kernel _mortonKernel;
		
		
	
	protected:
};

