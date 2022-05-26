/*
 * Swarm.h
 *
 *  Created on: 7 Mar 2020
 *      Author: Abdurrahman
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace au {

class Swarm
{
public:
	const static int NPARTICLES = 10000;


private:
	Particle*  m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();

	void update( int elapsed );

	const Particle* const getParticles() { return m_pParticles; };







};

} /* namespace au */

#endif /* SWARM_H_ */
