# Zappos Experiment

## Setup

On Windows 10 machine:

- Install Visual Studio 2017 CE
- Install kinect SDK 1.8
- Install DirectX SDK (June 2010)
- Install & Setup Cinder 0.9.0
	- Open Cinder git repository visual studio solution and build cinder.lib
	- Save Cinder root directory as CINDER_DIR environment variable

- Project should now build

Notes:

- Added kinect include dirs
- Added kinect lib dirs
- Added kinect.lib to linker
- Added cinder include dirs
- Added cinder lib dirs
- Added cinder.lib to linker