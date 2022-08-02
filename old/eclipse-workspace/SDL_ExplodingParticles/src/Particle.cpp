#include "Particle.h"
#include <math.h>
#include <stdlib.h>


namespace au {

Particle::Particle()// : m_x(0), m_y(0)
{
	init();

}

Particle::~Particle()
{

}


void Particle::init()
{
	m_x = 0;
	m_y = 0;

	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.04 * rand()) / RAND_MAX;

	m_speed = pow(m_speed, 2.3);
}

void Particle::update( int interval )
{
	//m_direction += interval*0.0006; //Adding homogeneous curve to the direction of particles.
	m_direction += (interval*0.01) * ( rand()%3 - 1 ); //Adding random curve to the direction of particles.

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if ( m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1 )
	{
		init();
	}

	if ( rand() < RAND_MAX/100 )
	{
		init();
	}


	/*
	if ( m_x < -1 || m_x > 1 )
	{
		m_x *= -1;
	}

	if ( m_y < -1 || m_y > 1 )
	{
		m_y *= -1;
	}
	*/








}

} /* namespace au */
