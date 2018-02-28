#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace glm;

Particle::Particle(vec2 loc) {
	mLoc = loc;
	mDir = Rand::randVec2();
	mVel = Rand::randFloat(5.0f);
	mRadius = 5.0f;
	mAge = 0;
	mLifespan = 200;
	mIsDead = false;
}

Particle::~Particle() {

};

void Particle::Update() {
	mLoc += mDir * mVel;
	mAge++;
	if (mAge > mLifespan)
		mIsDead = true;
}

void Particle::Draw() {
	gl::drawSolidCircle(mLoc, mRadius);
}