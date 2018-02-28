#include "cinder/Rand.h"
#include "ParticleController.h"
#include "Skeleton.h"

using namespace ci;
using namespace std;

ParticleController::ParticleController() :
	numParticles(0)
{
}

ParticleController::ParticleController(int initParticles) :
	numParticles(initParticles)
{
}

ParticleController::~ParticleController()
{
}

void ParticleController::addParticle(glm::vec2 pos) 
{
	particles.push_back(Particle(pos));
}

void ParticleController::removeParticle(int index) 
{
	particles.erase(particles.begin() + index);
}

void ParticleController::Setup(CSkeleton * inSkeleton)
{
	skeleton = inSkeleton;
}

void ParticleController::Update()
{
	// Update particle positions
	std::vector<_NUI_SKELETON_DATA *> skeletons = skeleton->getSkeletons();
	for (int i = 0; i < skeletons.size(); i++)
	{
		glm::vec2 const * lHand = skeleton->getLHandPos(skeletons[i]);
		glm::vec2 const * rHand = skeleton->getRHandPos(skeletons[i]);

		if (particles.size() < numParticles && lHand != NULL && rHand != NULL) {
			addParticle(Rand::randVec2() + *lHand);
			addParticle(Rand::randVec2() + *rHand);
		}

		for (vector<Particle>::iterator p = particles.begin(); p != particles.end(); ) {
			if (p->mIsDead) {
				p = particles.erase(p);
			}
			else {
				p->Update();
				++p;
			}
		}
	}	
}

void ParticleController::Draw()
{
	for (int i=0; i<particles.size(); i++)
	{
		particles[i].Draw();
	}
}