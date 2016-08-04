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


/*
    Source - Includes
 */

    # include "fastcal-query.h"

/*
    Source - Query methods for strings
 */

    lf_Char_t * lf_query_camera( lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Char_t * lfvCache = lf_Char_s( 0 );

        /* Cache descriptor variables */
        static lf_Enum_t   lfdCache = LF_FALSE;

        /* Key string variables */
        static lf_Char_t   lfKey[] = "camera";

        /* Cache detection */
        if ( lfdCache == LF_FALSE ) {

            /* Query value */
            lfvCache = lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1];

            /* Update cache state */
            lfdCache = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache );

    }

    lf_Char_t * lf_query_type( lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Char_t * lfvCache = lf_Char_s( 0 );

        /* Cache descriptor variables */
        static lf_Enum_t   lfdCache = LF_FALSE;

        /* Key string variables */
        static lf_Char_t   lfKey[] = "type";

        /* Cache detection */
        if ( lfdCache == LF_FALSE ) {

            /* Query value */
            lfvCache = lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1];

            /* Update cache state */
            lfdCache = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache );

    }

    lf_Char_t * lf_query_model( lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Char_t * lfvCache = lf_Char_s( 0 );

        /* Cache descriptor variables */
        static lf_Enum_t   lfdCache = LF_FALSE;

        /* Key string variables */
        static lf_Char_t   lfKey[] = "model";

        /* Cache detection */
        if ( lfdCache == LF_FALSE ) {

            /* Query value */
            lfvCache = lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1];

            /* Update cache state */
            lfdCache = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache );

    }

    lf_Char_t * lf_query_imu( lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Char_t * lfvCache = lf_Char_s( 0 );

        /* Cache descriptor variables */
        static lf_Enum_t   lfdCache = LF_FALSE;

        /* Key string variables */
        static lf_Char_t   lfKey[] = "imu";

        /* Cache detection */
        if ( lfdCache == LF_FALSE ) {

            /* Query value */
            lfvCache = lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1];

            /* Update cache state */
            lfdCache = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache );

    }

    lf_Char_t * lf_query_gps( lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Char_t * lfvCache = lf_Char_s( 0 );

        /* Cache descriptor variables */
        static lf_Enum_t   lfdCache = LF_FALSE;

        /* Key string variables */
        static lf_Char_t   lfKey[] = "gps";

        /* Cache detection */
        if ( lfdCache == LF_FALSE ) {

            /* Query value */
            lfvCache = lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1];

            /* Update cache state */
            lfdCache = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache );

    }

/*
    Source - Query methods for integer values
 */

    lf_Size_t lf_query_modules( lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache = lf_Size_s( 0 );

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache = LF_FALSE;

        /* Key string variables */
        static lf_Char_t lfKey[] = "modules";

        /* Cache detection */
        if ( lfdCache == LF_FALSE ) {

            /* Query value */
            lfvCache = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache );

    }

    lf_Size_t lf_query_channels( lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache = lf_Size_s( 0 );

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache = LF_FALSE;

        /* Key string variables */
        static lf_Char_t lfKey[] = "channels";

        /* Cache detection */
        if ( lfdCache == LF_FALSE ) {

            /* Query value */
            lfvCache = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache );

    }

    lf_Size_t lf_query_ImageFullWidth( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "ImageFullWidth_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[15] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[16] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_ImageFullLength( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "ImageFullLength_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[16] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[17] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_XPosition( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "XPosition_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[10] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[11] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_YPosition( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "YPosition_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[10] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[11] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_pixelCorrectionWidth( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "pixelCorrectionWidth_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[21] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[22] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_pixelCorrectionHeight( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "pixelCorrectionHeight_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[22] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[23] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_hflip( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "hflip_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[6] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[7] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_vflip( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "vflip_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[6] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[7] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_equirectangularWidth( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "equirectangularWidth_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[21] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[22] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Size_t lf_query_equirectangularHeight( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Size_t lfvCache[LF_CACHE] = { lf_Size_s( 0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "equirectangularHeight_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[22] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[23] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Size_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

/*
    Source - Query methods for real values
 */

    lf_Real_t lf_query_focalLength( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "focalLength_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[12] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[13] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_azimuth( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "azimuth_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[8] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[9] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_elevation( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "elevation_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[10] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[11] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_heading( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "heading_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[8] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[9] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_pixelSize( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "pixelSize_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[10] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[11] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_px0( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "px0_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[4] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[5] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_py0( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "py0_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[4] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[5] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_roll( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "roll_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[5] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[6] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_radius( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "radius_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[7] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[8] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_height( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "height_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[7] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[8] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

    lf_Real_t lf_query_entrancePupilForward( lf_Size_t const lfChannel, lf_Descriptor_t const * const lfDesc ) {

        /* Calibration data cache variables */
        static lf_Real_t lfvCache[LF_CACHE] = { lf_Real_s( 0.0 ) };

        /* Cache descriptor variables */
        static lf_Enum_t lfdCache[LF_CACHE] = { LF_FALSE };

        /* Key string variables */
        static lf_Char_t lfKey[] = "entrancePupilForward_--";

        /* Cache detection */
        if ( lfdCache[lfChannel] == LF_FALSE ) {

            /* Construct key string */
            lfKey[21] = LF_UTF8_ZERO + ( lfChannel / lf_Size_s( 10 ) );
            lfKey[22] = LF_UTF8_ZERO + ( lfChannel % lf_Size_s( 10 ) );

            /* Query value */
            lfvCache[lfChannel] = lf_Real_str( ( char * ) lfDesc->dsMap[lf_key( lfKey, lfDesc ) + 1] );

            /* Update cache state */
            lfdCache[lfChannel] = LF_TRUE;

        }

        /* Return cached value */
        return( lfvCache[lfChannel] );

    }

