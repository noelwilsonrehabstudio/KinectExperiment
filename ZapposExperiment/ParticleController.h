#pragma once

#include <vector>
#include "cinder/gl/gl.h"
#include "Particle.h"

class CSkeleton;

class ParticleController
{
public:
	ParticleController();
	ParticleController(int initParticles);
	~ParticleController();

	void					Setup(CSkeleton * skeleton);
	void                    Update();
	void                    Draw();
private:
	void					addParticle(glm::vec2 pos);
	void					removeParticle(int index);
	std::vector<Particle>	particles;
	int						numParticles;
	CSkeleton *				skeleton;
};

