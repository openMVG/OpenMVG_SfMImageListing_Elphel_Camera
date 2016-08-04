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

    /*! \file   fastcal-parser.h
     *  \author Nils Hamel <n.hamel@foxel.ch>
     *
     *  Key/value-file management
     */

/*
    Header - Include guard
 */

    # ifndef __LF_PARSER__
    # define __LF_PARSER__

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

/*
    Header - Preprocessor definitions
 */

    /* Define parsing flag variables */
    # define LF_PARSE_KEY   lf_Enum_s( 0 )
    # define LF_PARSE_VALUE lf_Enum_s( 1 )
    # define LF_PARSE_SKIP  lf_Enum_s( 2 )

    /* Define keys search flags */
    # define LF_INVALID     lf_Size_s( -1 )

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

    /*! \brief Key/value-file descriptor management
     *
     *  This function is responsible for calibration key/value-file descriptor 
     *  creation according to specified camera. The descriptor is needed for
     *  queries on calibration data values.
     *
     *  The descriptor has to be empty because memory pointers carried by the
     *  structure are erased by the function.
     *
     *  The function returns LF_FALSE if creation failed, LF_TRUE otherwise.
     *
     *  \param  lfCalibrationFile    The elphel .key calibration file
     *  \param  lfDesc          Pointer to key/value-file descriptor
     *
     *  \return Returns key-file descriptor creation status 
     */

    lf_Enum_t lf_parse( lf_Char_t const * const lfCalibrationFile, lf_Descriptor_t * const lfDesc );

    /*! \brief Key/value-file descriptor management
     *
     *  This function releases the allocated memory carried by the descriptor
     *  structure. It then should be called after descriptor creation and
     *  performed queries on calibration data.
     *
     *  \param  lfDesc          Pointer to key/value-file descriptor
     */

    lf_Void_t lf_release( lf_Descriptor_t * const lfDesc );

    /*! \brief Keys-string searching algorithm
     * 
     *  This function searches the provided key-string in the key/value-file
     *  descriptor for corresponding calibration data value access.
     *
     *  This function returns the mapping index of the found key-string on
     *  success and LF_INVALID if the key is not found.
     *
     *  \param  lfKey           String containing the key
     *  \param  lfDesc          Pointer to key/value-file descriptor
     * 
     *  \return Returns descriptor mapping index where key-string is located
     */

    lf_Size_t lf_key ( lf_Char_t const * const lfKey, lf_Descriptor_t const * const lfDesc );

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

