#pragma once

#include "cinder/gl/gl.h"

class Particle
{
public:
	Particle(glm::vec2 loc);
	~Particle();

	/// <summary>
	/// Main processing function
	/// </summary>
	void                    Update();
	void                    Draw();
	bool mIsDead;

private:
	glm::vec2 mLoc;
	glm::vec2 mDir;
	float mVel;
	float mRadius;
	int mAge;
	int mLifespan;
};

