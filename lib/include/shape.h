#pragma once

class Shape
{
	public:
		Shape();
		virtual ~Shape();
		
		// Shall be abstract
		std::vector< Shape > tesselate();
		
	private:
		
	protected:

};

