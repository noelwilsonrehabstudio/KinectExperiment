#include "cinder/Rand.h"
#include "ParticleController.h"

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

/*void ParticleController::Setup(CSkeleton * inSkeleton)
{
	skeleton = inSkeleton;
}*/

void ParticleController::Setup()
{
}

void ParticleController::Update(vec2 const * lHand, vec2 const *rHand)
{
	//glm::vec2 const * lHand = skeleton->getLHandPos(0);
	//glm::vec2 const * rHand = skeleton->getRHandPos(0);

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

void ParticleController::Draw()
{
	for (int i=0; i<particles.size(); i++)
	{
		particles[i].Draw();
	}
}