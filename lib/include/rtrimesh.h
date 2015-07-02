#pragma once

// Internal
#include "aabb.h"
#include "mesh.h"

//
#include <glm/glm.hpp>

float frand()
{
    return rand()/RAND_MAX;
}

class RTriMesh : public Mesh
{
public:
    RTriMesh( AABB bbox, size_t triCount )
    {
        srand(time(NULL));
        for( size_t k = 0; k < triCount; ++k )
        {
            glm::vec3 minVec = bbox._a;
            glm::vec3 maxVec = bbox._b;
            glm::vec3 extent = maxVec - minVec;

            glm::vec3 p( minVec.x + frand() * extent.x,
                         minVec.y + frand() * extent.y,
                         minVec.z + frand() * extent.z );

            glm::vec3 a( p.x - 1.0, p.y - 1.0, p.z );
            glm::vec3 b( p.x + 1.0, p.y - 1.0, p.z );
            glm::vec3 c( p.x - 1.0, p.y + 1.0, p.z );

            Mesh::Face f;
            f._vertexIdx.push_back( _verts.size() );
            f._vertexIdx.push_back( _verts.size() + 1 );
            f._vertexIdx.push_back( _verts.size() + 2 );

            _verts.push_back( a );
            _verts.push_back( b );
            _verts.push_back( c );

            _faces.push_back( f );

        }
    }
};
