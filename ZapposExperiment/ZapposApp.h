#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Surface.h"
#include "cinder/Capture.h"
#include "cinder/Text.h"
#include "cinder/Log.h"

class CSkeleton;
class ParticleController;

class ZapposApp : public ci::app::App {
public:
	void	setup() override;
	void	resize() override;
	void	update() override;
	void	draw() override;
	void	cleanup() override;

	CSkeleton * skeleton;
	ParticleController * particles;
};