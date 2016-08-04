/*
  Utility function to read Elphel calibration data to a compact format.

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

#pragma once

#include <fastcal-all.h>

#include <iostream>
#include <string>
#include <vector>

#include <openMVG/numeric/numeric.h>

/*********************************************************************
*  load calibration data related to elphel cameras
*
*********************************************************************/

// integers values
typedef  unsigned int li_Size_t;

// real values
typedef  double li_Real_t;

/******************************************************************************
 * sensorData
 *****************************************************************************/

 /*! \struct sensorData
 * \brief structure used to store calibration information
 *
 * This structure is designed to store the needed informations coming from
 * the elphel camera calibration
 *
 * \var sensorData::lfWidth
 *  Width of sensor image
 * \var sensorData::lfHeight
 *  Height of sensor image
 * \var sensorData::lfChannels
 *  Number of channels of elphel camera
 * \var sensorData::lfFocalLength
 *  Focal length in mm
 * \var sensorData::lfPixelSize
 *  pixel size in mm
 * \var sensorData::lfAzimuth
 *  azimuth angle in elphel coordinate frame (in radian)
 * \var sensorData::lfHeading
 *  heading angle in elphel coordinate frame (in radian)
 * \var sensorData::lfElevation
 *  Elevation angle in elphel coordinate frame (in radian)
 * \var sensorData::lfRoll
 *  roll around z axis (in radian)
 * \var sensorData::lfpx0
 *  x coordinate of principal point of sensor image, in pixels
 * \var sensorData::lfpy0
 *  y coordinate of principal point of sensor image, in pixels
 * \var sensorData::lfRadius
 *  radius of optical center of channel in elphel coordinate frame
 * \var sensorData::lfCheight
 *  height of optical center of channel in elphel coordinate frame
 * \var sensorData::lfEntrance
 *  Entrance pupil forward of channel
 * \var sensorData::rotation
 *  Rotation rig coordinate frame from sensor to world
 * \var sensorData::center
 *  sensor's optical center in rig coordinate frame
 */

struct sensorData
{
  lf_Size_t   lfWidth     = 0;
  lf_Size_t   lfHeight    = 0;
  lf_Size_t   lfChannels  = 0;

  lf_Real_t   lfFocalLength = 0.0;
  lf_Real_t   lfPixelSize   = 0.0;
  lf_Real_t   lfAzimuth     = 0.0;
  lf_Real_t   lfHeading     = 0.0;
  lf_Real_t   lfElevation   = 0.0;
  lf_Real_t   lfRoll        = 0.0;
  lf_Real_t   lfpx0         = 0.0;
  lf_Real_t   lfpy0         = 0.0;
  lf_Real_t   lfRadius      = 0.0;
  lf_Real_t   lfCheight     = 0.0;
  lf_Real_t   lfEntrance    = 0.0;

  openMVG::Mat3 rotation;
  openMVG::Vec3 center;
 };

/*! \brief Compute rotation from sensor to world 
*
* This function compute the sensor rotation using
* elphel calibration angle and rotation.
*
* \return R           Computed rotation
* \param az          Elphel's Angle azimuth (in radian) of subcamera
* \param head        Elphel's Angle heading (in radian) of subcamera
* \param ele         Elphel's Angle elevation (in radian) of subcamera
* \param roll        Elphel's Angle roll (in radian) of subcamera
*
*/
openMVG::Mat3
computeRotationEl
(
  li_Real_t az,
  li_Real_t head,
  li_Real_t ele,
  li_Real_t roll
)
{
  const openMVG::Mat3 Rz = openMVG::RotationAroundZ(roll);
  const openMVG::Mat3 Rx = openMVG::RotationAroundX(ele);
  const openMVG::Mat3 Ry = openMVG::RotationAroundY(head+az);

  return (Ry * Rx * Rz).transpose();
}

/*! \brief Compute optical center of elphel's subcamera
*
* This function compute the optical center of a given elphel subcamera
*
* \param radius      Radius of optical center in elphel's coordinate frame
* \param heigt       Height of optical center in elphel's coordinate frame
* \param azimuth     Elphel's Angle azimuth (in radian) of subcamera
* \param R           Sensor rig rotation (sensor to world)
* \param entrancePupilForward  Entrance pupil forward of the associated camera
*
* \return The optical center in the array C
*/

openMVG::Vec3
getOpticalCenter
(
  const li_Real_t& radius,
  const li_Real_t& height,
  const li_Real_t& azimuth,
  const openMVG::Mat3 & R,
  const li_Real_t& entrancePupilForward
)
{
  openMVG::Vec3 lensCenter;
  lensCenter << radius * sin(azimuth), -height, radius * cos(azimuth);

  return (lensCenter + R.row(2).transpose() * entrancePupilForward);
}

/*! \brief Load in a compact format the Elphel calibration data contained in the
* specified file.
*
* \param vec_sensorData             Output read calibration data
* \param sElphelCalibrationKeyFile  Elphel calibration file (i.e. calibration.key)
*
* \return Status of the data extraction (true in case of success)
*/
bool
loadCalibrationData
(
  std::vector< sensorData >  & vec_sensorData,
  const std::string & sElphelCalibrationKeyFile
)
{
  /* Key/value-file descriptor */
  lf_Descriptor_t lfDesc;
  lf_Size_t       lfChannels=0;

  if (
      lf_parse((unsigned char*)(sElphelCalibrationKeyFile.c_str()), & lfDesc)
      == LF_TRUE
     )
  {
    /* Query number of camera channels */
    lfChannels = lf_query_channels( & lfDesc );

    /* iter on sub camera */
    for( li_Size_t sensor_index = 0 ; sensor_index < lfChannels ; ++sensor_index )
    {
      sensorData  sD;

      /* Query number width and height of sensor image */
      sD.lfWidth  = lf_query_pixelCorrectionWidth ( sensor_index, & lfDesc );
      sD.lfHeight = lf_query_pixelCorrectionHeight( sensor_index, & lfDesc );

      /* Query focal length of camera sensor index */
      sD.lfFocalLength = lf_query_focalLength( sensor_index , & lfDesc );
      sD.lfPixelSize   = lf_query_pixelSize  ( sensor_index , & lfDesc );

      /* Query angles used for gnomonic rotation */
      sD.lfAzimuth    = lf_query_azimuth    ( sensor_index , & lfDesc );
      sD.lfHeading    = lf_query_heading    ( sensor_index , & lfDesc );
      sD.lfElevation  = lf_query_elevation  ( sensor_index , & lfDesc );
      sD.lfRoll       = lf_query_roll       ( sensor_index , & lfDesc );

      // compute the camera rotation and store it.
      sD.rotation = computeRotationEl ( sD.lfAzimuth , sD.lfHeading, sD.lfElevation, sD.lfRoll );

      /* Query principal point */
      sD.lfpx0 = lf_query_px0 ( sensor_index , & lfDesc );
      sD.lfpy0 = lf_query_py0 ( sensor_index , & lfDesc );

      /* Query information related to entrance pupil center */
      sD.lfRadius   = lf_query_radius               ( sensor_index , & lfDesc );
      sD.lfCheight  = lf_query_height               ( sensor_index , & lfDesc );
      sD.lfEntrance = lf_query_entrancePupilForward ( sensor_index , & lfDesc );

      /* compute the optical center of the camera*/
      sD.center = getOpticalCenter ( sD.lfRadius, sD.lfCheight, sD.lfAzimuth, sD.rotation, sD.lfEntrance );

      vec_sensorData.push_back(sD);
    }

    /* Release descriptor */
    lf_release( & lfDesc );

    /* calibration information are loaded*/
    return true;
  }
  else
  {
    std::cerr << " Could not read calibration data. Exit" << std::endl;
    return false;
  }
}
