
// Test
#include <boost/compute/system.hpp>
#include <boost/compute/algorithm.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/interop/opengl.hpp>
#include <boost/compute/utility/source.hpp>

// Internal
#include "bvh.h"

// STL
#include <iostream>
using namespace std;

namespace compute = boost::compute;

const char * BVH::_clSrc = BOOST_COMPUTE_STRINGIZE_SOURCE(

    uint code(uint x)
    {
        x = (x | (x << 16)) & 0x030000FF;
        x = (x | (x <<  8)) & 0x0300F00F;
        x = (x | (x <<  4)) & 0x030C30C3;
        x = (x | (x <<  2)) & 0x09249249;
        return x;
    }

	__kernel void updateVelocity(__global const float4* position, __global float4* velocity, float dt, uint N)
	{
        uint gid = get_global_id(0);

        float4 r = { 0.0f, 0.0f, 0.0f, 0.0f };
        float f = 0.0f;
        for(uint i = 0; i != gid; i++) {
            if(i != gid) {
                r = position[i]-position[gid];
                f = length(r)+0.001f;
                f *= f*f;
                f = dt/f;
                velocity[gid] += f*r;
            }
        }
    }

    __kernel void updatePosition(__global float4* position, __global const float4* velocity, float dt)
    {
        uint gid = get_global_id(0);

        position[gid].xyz += dt*velocity[gid].xyz;
    }

    __kernel void computeMorton(__global uint* index, __global float4* vertex, __global uint* key, __global uint* val /*, __global AABB* aabb*/ )
    {
        int g = get_global_id(0);

        float4 v0 = vertex[index[g*3+0]];
        float4 v1 = vertex[index[g*3+1]];
        float4 v2 = vertex[index[g*3+2]];

        // float4 normal = ((v0+v1+v2)/3 - aabb[0].bbMin)/(aabb[0].bbMax - aabb[0].bbMin);
        // key[g] = code(normal.x*0x3FF) | (code(normal.y*0x3FF)<<1) | (code(normal.z*0x3FF)<<2);
        // val[g] = g;

    }
);

void BVH::init()
{
	// get the default device
    _device = compute::system::default_device();

	// create a context for the device
	_context = compute::context(_device);

    cout << "building" << endl;
	_program = compute::program::create_with_source( BVH::_clSrc, _context );
	_program.build();

    compute::kernel k = _program.create_kernel( "updateVelocity" );

    cout << "program built" << endl;
}

void BVH::testBuild()
{
    // set the kernel arguments
    /*
    kernel.set_arg(0, buffer_a);
    kernel.set_arg(1, buffer_b);
    kernel.set_arg(2, buffer_c);

    // create a command queue
    compute::command_queue queue(context, device);

    // write the data from 'a' and 'b' to the device
    queue.enqueue_write_buffer(buffer_a, 0, 4 * sizeof(float), a);
    queue.enqueue_write_buffer(buffer_b, 0, 4 * sizeof(float), b);

    // run the add kernel
    queue.enqueue_1d_range_kernel(kernel, 0, 4, 0);

    // transfer results back to the host array 'c'
    queue.enqueue_read_buffer(buffer_c, 0, 4 * sizeof(float), c);

    // print out results in 'c'
    std::cout << "c: [" << c[0] << ", "
                        << c[1] << ", "
                        << c[2] << ", "
                        << c[3] << "]" << std::endl;
	*/
}

