//------------------------------------------------------------------------------
// <copyright file="SkeletonBasics.h" company="Microsoft">
//     Copyright (c) Microsoft Corporation.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

#pragma once

#include <vector>
#include "cinder/gl/gl.h"

#include "NuiApi.h"

class CSkeleton
{
    static const int        cScreenWidth  = 320;
    static const int        cScreenHeight = 240;

    static const int        cStatusMessageMaxLen = MAX_PATH*2;

public:
    /// <summary>
    /// Constructor
    /// </summary>
    CSkeleton();
	CSkeleton(int width, int height);

    /// <summary>
    /// Destructor
    /// </summary>
    ~CSkeleton();

	/// <summary>
	/// Main processing function
	/// </summary>
	void                    Update();
	void                    Draw();
	glm::vec2 const * 		getLHandPos(_NUI_SKELETON_DATA * skeleton);
	glm::vec2 const *		getRHandPos(_NUI_SKELETON_DATA * skeleton);
	std::vector<_NUI_SKELETON_DATA*> getSkeletons();

	/// <summary>
	/// Create the first connected Kinect found 
	/// </summary>
	/// <returns>S_OK on success, otherwise failure code</returns>
	HRESULT                 CreateFirstConnected();
	void					updateWidthHeight(int width, int height);


private:
	int						width, height;
    bool                    m_bSeatedMode;
	bool					tracking;

    // Current Kinect
    INuiSensor*             m_pNuiSensor;

    // Skeletal drawing
	NUI_SKELETON_FRAME		skeletonFrame;
    glm::vec2				m_Points[NUI_SKELETON_POSITION_COUNT];   

	HANDLE                  m_pSkeletonStreamHandle;
	HANDLE                  m_hNextSkeletonEvent;
    /// <summary>
    /// Handle new skeleton data
    /// </summary>
    void                    ProcessSkeleton();
	void					DrawSkeletonState();
	glm::vec2 const *		getBonePosition(_NUI_SKELETON_DATA * skeleton, NUI_SKELETON_POSITION_INDEX boneIndex);

    /// <summary>
    /// Draws a bone line between two joints
    /// </summary>
    /// <param name="skel">skeleton to draw bones from</param>
    /// <param name="joint0">joint to start drawing from</param>
    /// <param name="joint1">joint to end drawing at</param>
    void                    DrawBone(const NUI_SKELETON_DATA & skel, NUI_SKELETON_POSITION_INDEX bone0, NUI_SKELETON_POSITION_INDEX bone1);

    /// <summary>
    /// Draws a skeleton
    /// </summary>
    /// <param name="skel">skeleton to draw</param>
    /// <param name="windowWidth">width (in pixels) of output buffer</param>
    /// <param name="windowHeight">height (in pixels) of output buffer</param>
    void                    DrawSkeleton(const NUI_SKELETON_DATA & skel, int windowWidth, int windowHeight);

    /// <summary>
    /// Converts a skeleton point to screen space
    /// </summary>
    /// <param name="skeletonPoint">skeleton point to tranform</param>
    /// <param name="width">width (in pixels) of output buffer</param>
    /// <param name="height">height (in pixels) of output buffer</param>
    /// <returns>point in screen-space</returns>
	glm::vec2				   SkeletonToScreen(Vector4 skeletonPoint, int width, int height);

};
