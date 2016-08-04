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

    /*! \file   fastcal.h
     *  \author Nils Hamel <n.hamel@foxel.ch>
     *
     *  Library common header file
     */

    /*! \mainpage libfastcal
     *
     *  \section libfastcal
     *  \section _ Fast calibration data access
     *
     *  The libfastcal library provides camera calibration data access in the 
     *  fastest and simplest possible way. The library expects a standardized 
     *  directories structure and a key/value-files for each camera that contains 
     *  the calibration data values that library clients want to access.
     *
     *  \section Documentation
     *
     *  A detailed documentation can be generated through doxygen. A more general
     *  documentation can be consulted at https://github.com/FoxelSA/libfastcal/wiki.
     *
     *  \section Copyright
     * 
     *  Copyright (c) 2013-2015 FOXEL SA - http://foxel.ch \n
     *  This program is part of the FOXEL project <http://foxel.ch>.
     *  
     *  Please read the COPYRIGHT.md file for more information.
     *
     *  \section License
     *
     *  This program is licensed under the terms of the GNU Affero General Public
     *  License v3 (GNU AGPL), with two additional terms. The content is licensed
     *  under the terms of the Creative Commons Attribution-ShareAlike 4.0
     *  International (CC BY-SA) license.
     *
     *  You must read <http://foxel.ch/license> for more information about our
     *  Licensing terms and our Usage and Attribution guidelines.
     */

/*
    Header - Include guard
 */

    # ifndef __LF__
    # define __LF__

/*
    Header - C/C++ compatibility
 */

    # ifdef __cplusplus
    extern "C" {
    # endif

/*
    Header - Includes
 */

    # include <stdio.h>
    # include <stdlib.h>
    # include <string.h>

/*
    Header - Preprocessor definitions
 */

    /* Define fundamental constants */
    # define LF_PI              lf_Real_s( 3.14159265358979323846264338327950 )

    /* Define boolean constants */
    # define LF_FALSE           0
    # define LF_TRUE            1

    /* Define channel cache size */
    # define LF_CACHE           64

    /* Define UTF-8 constants */
    # define LF_UTF8_NUL    lf_Char_s( 0x00 )
    # define LF_UTF8_SP     lf_Char_s( 0x20 )
    # define LF_UTF8_EQUAL  lf_Char_s( 0x3D )
    # define LF_UTF8_ZERO   lf_Char_s( 0x30 )

/*
    Header - Preprocessor macros
 */

    /* Define casting macro */
    # define lf_Char_c( x )     ( ( lf_Char_t ) x )
    # define lf_Real_c( x )     ( ( lf_Real_t ) x )
    # define lf_Size_c( x )     ( ( lf_Size_t ) x )
    # define lf_Enum_c( x )     ( ( lf_Enum_t ) x )

    /* Define litteral suffix */
    # define lf_Char_s( x )     ( x      )
    # define lf_Real_s( x )     ( x      )
    # define lf_Size_s( x )     ( x ## l )
    # define lf_Enum_s( x )     ( x ## l )

    /* Define formated output specifiers */
    # define lf_Char_p          "c"
    # define lf_Real_p          "lf"
    # define lf_Size_p          "li"
    # define lf_Enum_p          "li"

    /* Define formated input specifiers */
    # define lf_Char_i          "c"
    # define lf_Real_i          "lf"
    # define lf_Size_i          "li"
    # define lf_Enum_i          "li"

    /* Define string conversion function */
    # define lf_Real_str( x )   atof( x )
    # define lf_Size_str( x )   atol( x )

/*
    Header - Typedefs
 */

    /* Define generic char type */
    typedef unsigned char lf_Char_t;

    /* Define floating point type */
    typedef double        lf_Real_t;

    /* Define generic index type */
    typedef long int      lf_Size_t;

    /* Define generic enumeration type */
    typedef long int      lf_Enum_t;

    /* Define generic void type */
    typedef void          lf_Void_t;

/*
    Header - Structures
 */

    /*! \struct lf_Descriptor_struct
     *  \brief Key-file descriptor
     *
     *  This structure stores needed informations to provide a fast access to
     *  calibration data contained in the considered key/value-file.
     *
     *  \var lf_Descriptor_struct::dsSize
     *  Size, in bytes, of the key/value-file
     *  \var lf_Descriptor_struct::dsData
     *  Key/value-file content storage memory
     *  \var lf_Descriptor_struct::dsMap
     *  Keys and values offset mapping in key/value-file content
     *  \var lf_Descriptor_struct::dsCount
     *  Mapping size, in keys and values units
     */ 

    typedef struct lf_Descriptor_struct {

        /* Data buffer */
        lf_Size_t    dsSize;
        lf_Char_t  * dsData;

        /* Buffer offsets mapping */
        lf_Char_t ** dsMap;
        lf_Size_t    dsCount;

    } lf_Descriptor_t;

/*
    Header - Function prototypes
 */

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

