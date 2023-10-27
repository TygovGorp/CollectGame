#include "LOS.h"

namespace Tmpl8
{
	/*
	// Calculate intersections and draw rays
	for (int i = 0; i < rays.size(); i++)
	{
		// Set ray end-point to default
		rays[i].reset();

		// Cycle through every wall and set end point to intersection
		// When an intersection is found, the end-point is set to that intersection, meaning the next check will check for walls
		// between mouse and the new end-point. This means the ray will always go to the nearest wall
		for (int j = 0; j < walls.size(); j++)
		{
			// Calculate ray end-point
			rays[i].calc_hit(walls[j].start, walls[j].end);
		}

		// Set drawing-line end to final intersection
		ray_line[1].position = rays[i].m_end;

		// Draw ray
		window.draw(ray_line);
	}
	*/
}