/*
  Binary used to create a valid OpenMVG sfm_data.json file from Elphel camera data.

  Copyright (C) 2016 Pierre MOULON

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "elphel_utils.hpp"

#include <openMVG/stl/split.hpp>
#include <openMVG/image/image.hpp>
#include <progress/progress.hpp>
#include <openMVG/sfm/sfm.hpp>

#include <stlplus3/filesystemSimplified/file_system.hpp>
#include <cmdLine/cmdLine.h>

int main(int argc, char **argv)
{
  CmdLine cmd;

  std::string 
    sImageDir = "",
    sElphelCalibrationKeyFile = "",
    sOutputDir = "";

  cmd.add( make_option('i', sImageDir, "imageDirectory") );
  cmd.add( make_option('k', sElphelCalibrationKeyFile, "keyfile") );
  cmd.add( make_option('o', sOutputDir, "outputDirectory") );

  try {
      if (argc == 1) throw std::string("Invalid command line parameter.");
      cmd.process(argc, argv);
  } catch(const std::string& s) {
    std::cerr
      << "Usage: " << argv[0] << '\n'
      << "[-i|--imageDirectory] input image directory\n"
      << "[-k|--keyfile] input Elphel camera calibration data i.e. calibration.key\n"
      << "[-o|--outputDirectory] path where the sfm_data.json file will be saved\n"
      << std::endl;

      std::cerr << s << std::endl;
  }

  if (sOutputDir.empty())
  {
    std::cerr << "\nInvalid output directory" << std::endl;
    return EXIT_FAILURE;
  }

  if ( !stlplus::folder_exists( sOutputDir ) )
  {
    if ( !stlplus::folder_create( sOutputDir ))
    {
      std::cerr << "\nCannot create output directory" << std::endl;
      return EXIT_FAILURE;
    }
  }


  // Extract Elphel camera calibration for each module
  std::vector < sensorData > vec_sensorData;
  const bool bLoadCalibration = loadCalibrationData( vec_sensorData, sElphelCalibrationKeyFile);

  if (!bLoadCalibration)
    return EXIT_FAILURE;

  //----------------------------------------------------
  // Create the OpenMVG SfM_Data scene
  //----------------------------------
  // - Parse the image directory
  // For each image, initialize an openMVG View (imagenames + UID + intrinsic/pose ids)
  // - Initialize the Intrinsic data (one per module)
  //----------------------------------------------------
  
  // List the images
  std::vector<std::string> vec_images = stlplus::folder_files( sImageDir );
  std::sort(vec_images.begin(), vec_images.end());

  openMVG::sfm::SfM_Data sfm_data;
  sfm_data.s_root_path = sImageDir;

  C_Progress_display my_progress_bar_image( vec_images.size(),
    std::cout, "\n List computation progression:\n");

  openMVG::IndexT cpt = 0;
  // Use a timestamp set to determine some contiguous pose Ids from the timestamp
  std::set<std::string> set_existing_timestamp; 
  for (const std::string & image_it : vec_images)
  {
    const std::string sImageFilename = stlplus::create_filespec( sImageDir, image_it );
    if (openMVG::image::GetFormat(sImageFilename.c_str()) == openMVG::image::Unknown)
    {
      std::cerr << " Warning : image " << sImageFilename << "\'s format is not supported." << std::endl;
    }
    else
    {
      // extract channel information from image name
      std::vector<std::string> splitted_name;
      stl::split( image_it, '-', splitted_name );

      const openMVG::IndexT sensor_index = atoi(splitted_name[1].c_str());
      const std::string timestamp = splitted_name[0]; // UID of the pose
      set_existing_timestamp.insert(timestamp);

      // Get back the Elphel camera sensor information related to this camera
      if (sensor_index > vec_sensorData.size())
        continue;

      const sensorData & sensor_data = vec_sensorData[sensor_index];

      // Create a view for this image
      sfm_data.views[cpt] = 
        std::make_shared<openMVG::sfm::View>(
          image_it, cpt, sensor_index, set_existing_timestamp.size(), sensor_data.lfWidth, sensor_data.lfHeight);

      // Create the intrinsic data if required
      if (sfm_data.intrinsics.count(sensor_index) == 0)
      {
        const double focal = sensor_data.lfFocalLength / sensor_data.lfPixelSize;
        const double ppx = sensor_data.lfpx0;
        const double ppy = sensor_data.lfpy0;

        const openMVG::geometry::Pose3 pose(sensor_data.rotation, sensor_data.center);
        sfm_data.intrinsics[sensor_index] =
          std::make_shared< openMVG::cameras::Pinhole_Intrinsic_Subpose >
            (sensor_data.lfWidth, sensor_data.lfHeight, focal, ppx, ppy, pose);
      }
      ++cpt;
    }
    ++my_progress_bar_image;
  }

  std::cout
    << "Created a sfm_data scene with:\n"
    << " #views: " << sfm_data.GetViews().size() << "\n"
    << " #poses: " << sfm_data.GetPoses().size() << "\n"
    << " #intrinsics: " << sfm_data.GetIntrinsics().size() << "\n"
    << " #tracks: " << sfm_data.GetLandmarks().size() << "\n"
    << "------------------------------\n"
    << " Created #Pose UID: " << set_existing_timestamp.size() << "\n"
    << "------------------------------\n"
    << std::endl;
    
  // Store SfM_Data views & intrinsic data
  if (!Save(
        sfm_data,
        stlplus::create_filespec( sOutputDir, "sfm_data.json" ).c_str(),
        openMVG::sfm::ESfM_Data(openMVG::sfm::VIEWS|openMVG::sfm::INTRINSICS|openMVG::sfm::EXTRINSICS)) )
  {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
