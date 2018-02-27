//------------------------------------------------------------------------------
// <copyright file="SkeletonBasics.cpp" company="Microsoft">
//     Copyright (c) Microsoft Corporation.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

#include "stdafx.h"
#include <strsafe.h>
#include "resource.h"
#include "Skeleton.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Surface.h"
#include "cinder/Capture.h"
#include "cinder/Text.h"
#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;

class ZapposApp : public App {
	public:
		void	setup() override;
		void	resize() override;
		void	update() override;
		void	draw() override;
		void	cleanup() override;

		CSkeleton * skeleton;
		HANDLE m_hNextSkeletonEvent;
};

void ZapposApp::setup()
{
	int width = getWindowWidth();
	int height = getWindowHeight();
	try {
		skeleton = new CSkeleton(width, height);
		skeleton->CreateFirstConnected();
	}
	catch (CaptureExc &exc) {
		CI_LOG_EXCEPTION("failed to initialize the Capture: ", exc);
	}

	gl::enableDepthRead();
	gl::enableDepthWrite();
}

void ZapposApp::cleanup()
{
	if (skeleton) {
		delete skeleton;
	}

	if (m_hNextSkeletonEvent && (m_hNextSkeletonEvent != INVALID_HANDLE_VALUE))
	{
		CloseHandle(m_hNextSkeletonEvent);
	}
}

void ZapposApp::resize()
{
}

void ZapposApp::update()
{
	if (skeleton) {
		skeleton->Update();
	}
}

void ZapposApp::draw()
{
	skeleton->Draw();
}

CINDER_APP(ZapposApp, RendererGl(RendererGl::Options().msaa(4)))


