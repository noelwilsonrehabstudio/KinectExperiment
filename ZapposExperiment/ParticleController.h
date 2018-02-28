#pragma once

#include <vector>
#include "cinder/gl/gl.h"

//#include "Skeleton.h"
#include "Particle.h"

class ParticleController
{
public:
	ParticleController();
	ParticleController(int initParticles);
	~ParticleController();

	//void					Setup(CSkeleton * skeleton);
	void					Setup();
	void                    Update(glm::vec2 const * lHand, glm::vec2 const * rHand);
	void                    Draw();
private:
	void					addParticle(glm::vec2 pos);
	void					removeParticle(int index);
	std::vector<Particle>	particles;
	int						numParticles;
	//CSkeleton *				skeleton;
};

