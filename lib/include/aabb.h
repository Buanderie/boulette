#pragma once

#include <glm/glm.hpp>

class AABB
{
public:
    AABB( glm::vec3 a, glm::vec3 b )
        :_a(a), _b(b)
    {

    }

    glm::vec3 _a;
    glm::vec3 _b;

};
