===========================================
main_openMVG_SfMImageListing_Elphel_Camera
===========================================

------------
Introduction
------------

This binary help to initialize a OpenMVG sfm_data's scene for non central Elphel's cameras.

It parses an image directory and initialize the camera subpose for each camera intrinsic (openMVG::cameras::Pinhole_Intrinsic_Subpose) by using the Elphel calibration X.key file.
Note that since that non central camera are used, many Views share the same Pose index.

--------
Building
--------

Since this project depends on OpenMVG/OpenGV, you must compile them and install them.
Here the step by step build instructions:

```
mkdir myProject
cd myProject

build_path=`pwd`

git clone --recursive https://github.com/openMVG/openMVG.git -b develop_subposes
git clone https://github.com/pmoulon/opengv.git -b develop_cmake_install

openMVG_path=$build_path/openMVG
openMVG_build_path=$build_path/openMVG_build
openMVG_install_path=$build_path/openMVG_install

openGV_build_path=$build_path/openGV_Build
openGV_install_path=$build_path/openGV_install

project_path=$build_path/OpenMVG_SfMImageListing_Elphel_Camera_Build

#
# Build Dependencies (OpenGV)
#

mkdir $openGV_build_path
cd $openGV_build_path

cmake ../opengv -DCMAKE_BUILD_TYPE=RELEASE -DEIGEN_INCLUDE_DIR=$openMVG_path/src/third_party/eigen -DINSTALL_OPENGV=ON -DCMAKE_INSTALL_PREFIX=$openGV_install_path

make -j8
make test
make install

cd $build_path

#
# Build Dependencies (OpenMVG)
#

# OpenMVG Compilation

mkdir $openMVG_build_path
cd $openMVG_build_path
mkdir $openGV_install_path

cmake ../openMVG/src -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX:STRING=$openMVG_install_path -DOpenMVG_BUILD_TESTS=ON -Dopengv_DIR:STRING=$openGV_install_path/CMake

make -j8
make install

cd $build_path

#
# Build This project
#

git clone https://github.com/openMVG/OpenMVG_SfMImageListing_Elphel_Camera.git
mkdir $project_path 
cd $project_path

cmake ../OpenMVG_SfMImageListing_Elphel_Camera -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX:STRING=$openMVG_install_path -Dopengv_DIR:STRING=$openGV_install_path/CMake

```

-------
License
-------

See [AGPL LICENSE](https://www.gnu.org/licenses/agpl-3.0.txt) text file

-------
Authors
-------

Pierre MOULON


-------
Usage
-------

$ main_openMVG_SfMImageListing_Elphel_Camera -i myscene/imagePath -k calibration.key -o myscene/matchesPath
