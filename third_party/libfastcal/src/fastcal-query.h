/*
 * libfastcal - Fast calibration data access
 *
 * Copyright (c) 2013-2015 FOXEL SA - http://foxel.ch
 * Please read <http://foxel.ch/license> for more information.
 *
 *
 * Author(s):
 *
 *      Nils Hamel <n.hamel@foxel.ch>
 *
 *
 * This file is part of the FOXEL project <http://foxel.ch>.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Additional Terms:
 *
 *      You are required to preserve legal notices and author attributions in
 *      that material or in the Appropriate Legal Notices displayed by works
 *      containing it.
 *
 *      You are required to attribute the work as explained in the "Usage and
 *      Attribution" section of <http://foxel.ch/license>.
 */

    /*! \brief \file   fastcal-query.h
     *  \author Nils Hamel <n.hamel@foxel.ch>
     *
     *  Fast calibration data access methods
     */

/*
    Header - Include guard
 */

    # ifndef __LF_QUERY__
    # define __LF_QUERY__

/*
    Header - C/C++ compatibility
 */

    # ifdef __cplusplus
    extern "C" {
    # endif

/*
    Header - Includes
 */

    # include "fastcal.h"
    # include "fastcal-parser.h"

/*
    Header - Preprocessor definitions
 */

/*
    Header - Preprocessor macros
 */

/*
    Header - Typedefs
 */

/*
    Header - Structures
 */

/*
    Header - Function prototypes
 */

    /*! \brief Query methods for strings
     *
     *  This function returns desired data based on calibration key/value-file
     *  descriptor. The descriptor has to be already built and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *
     *  \return Queried calibration value
     */

    lf_Char_t * lf_query_camera ( lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for strings
     *
     *  This function returns desired data based on calibration key/value-file
     *  descriptor. The descriptor has to be already built and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *
     *  \return Queried calibration value
     */

    lf_Char_t * lf_query_type( lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for strings
     *
     *  This function returns desired data based on calibration key/value-file
     *  descriptor. The descriptor has to be already built and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *
     *  \return Queried calibration value
     */

    lf_Char_t * lf_query_model ( lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for strings
     *
     *  This function returns desired data based on calibration key/value-file
     *  descriptor. The descriptor has to be already built and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *
     *  \return Queried calibration value
     */

    lf_Char_t * lf_query_imu ( lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for strings
     *
     *  This function returns desired data based on calibration key/value-file
     *  descriptor. The descriptor has to be already built and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *
     *  \return Queried calibration value
     */

    lf_Char_t * lf_query_gps ( lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for strings
     *
     *  This function returns desired data based on calibration key/value-file
     *  descriptor. The descriptor has to be already built and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_modules ( lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for strings
     *
     *  This function returns desired data based on calibration key/value-file
     *  descriptor. The descriptor has to be already built and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_channels ( lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_ImageFullWidth ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_ImageFullLength ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_XPosition ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_YPosition ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_pixelCorrectionWidth ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_pixelCorrectionHeight ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_hflip( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_vflip( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_equirectangularWidth( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for integer values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Size_t lf_query_equirectangularHeight( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_focalLength ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_azimuth ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_elevation ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_heading ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_pixelSize ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_px0 ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_py0 ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_roll ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_radius ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_height ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

    /*! \brief \brief Query methods for real values
     *
     *  This function returns desired data about specified sensor channel based
     *  on calibration key/value-file descriptor. The descriptor has to be built 
     *  and not released.
     *
     *  \param  lfDesc      Calibration file descriptor
     *  \param  lfChannel   Sensor channel index
     *
     *  \return Queried calibration value
     */

    lf_Real_t lf_query_entrancePupilForward ( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc );

/*
    Header - C/C++ compatibility
 */

    # ifdef __cplusplus
    }
    # endif

/*
    Header - Include guard
 */

    # endif

