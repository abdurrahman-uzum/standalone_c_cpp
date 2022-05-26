/*
 * Particle.h
 *
 *  Created on: 7 Mar 2020
 *      Author: Abdurrahman
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace au {

class Particle
{

public:
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();

	void update( int interval );


};

} /* namespace au */

#endif /* PARTICLE_H_ */
