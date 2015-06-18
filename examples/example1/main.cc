
// bbbbbb
#include <boulette.h>

// STL
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main( int argc, char** argv )
{
	vector< shared_ptr<Mesh> > msh;
	BVH b( msh );
	b.testBuild();

	return 0;
}
