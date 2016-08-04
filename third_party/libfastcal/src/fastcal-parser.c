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

    # include "fastcal-parser.h"

/*
    Source - Key/value-file descriptor management
 */

    lf_Enum_t lf_parse( lf_Char_t const * const lfCalibrationFile, lf_Descriptor_t * const lfDesc ) {

        /* File handle variables */
        FILE * lfStream = NULL;

        /* Parsing flag variables */
        lf_Enum_t lfFlag = LF_PARSE_KEY;

        /* Buffer allocation size variables */
        lf_Size_t lfLength = lf_Size_s( 0 );

        /* Parsing variables */
        lf_Size_t lfParse = lf_Size_s( 0 );

        /* Optimization variables */
        lf_Char_t * lfDirect = NULL;

        /* Returned value variables */
        lf_Enum_t lfReturn = LF_FALSE;

        /* Initialize structure */
        lfDesc->dsSize  = 0;
        lfDesc->dsData  = NULL;
        lfDesc->dsCount = 0;
        lfDesc->dsMap   = NULL;

        /* Create stream handle */
        if ( ( lfStream = fopen( ( char * ) lfCalibrationFile, "rb" ) ) != NULL ) {

            /* Head to end of file */
            fseek( lfStream, 0L, SEEK_END );

            /* Retrieve and check stream size */
            if ( ( lfDesc->dsSize = ftell( lfStream ) ) > 0 ) {

                /* Head to beginning of file */
                fseek( lfStream, 0L, SEEK_SET );

                /* Allocate memory */
                if ( ( lfDesc->dsData = ( lf_Char_t * ) malloc( lfDesc->dsSize * sizeof( lf_Char_t ) ) ) != NULL ) {

                    /* Read file content */
                    if ( fread( lfDesc->dsData, 1, lfDesc->dsSize, lfStream ) == lfDesc->dsSize ) {

                        /* Parse file content */
                        for ( lfParse = lf_Size_s( 0 ); lfParse < lfDesc->dsSize; lfParse ++ ) {

                            /* Pre-computation for optimization */
                            lfDirect = lfDesc->dsData + lfParse;

                            /* Check character value */
                            if ( * lfDirect == LF_UTF8_EQUAL ) {

                                /* Update parsing flag */
                                lfFlag = LF_PARSE_VALUE;

                                /* Create null terminated string */
                                * lfDirect = LF_UTF8_NUL;

                            } else if ( * lfDirect >= LF_UTF8_SP ) {

                                /* Check mapping memory allocation */
                                if ( lfDesc->dsCount >= lfLength ) {

                                    /* Update mapping memory descriptor */
                                    lfLength += lf_Size_s( 1024 );

                                    /* Update mapping memory */
                                    lfDesc->dsMap = ( lf_Char_t ** ) realloc( ( void * ) lfDesc->dsMap, lfLength * sizeof( lf_Char_t * ) );

                                }

                                /* Check parsing flag */
                                if ( lfFlag == LF_PARSE_KEY ) {

                                    /* Update parsing flag */
                                    lfFlag = LF_PARSE_SKIP;

                                    /* Map key offset */
                                    * ( lfDesc->dsMap + ( lfDesc->dsCount ++ ) ) = lfDirect;

                                } else if ( lfFlag == LF_PARSE_VALUE )  {

                                    /* Update parsing flag */
                                    lfFlag = LF_PARSE_SKIP;

                                    /* Map value offset */
                                    * ( lfDesc->dsMap + ( lfDesc->dsCount ++ ) ) = lfDirect;

                                }

                            } else {

                                /* Update parsing flag */
                                lfFlag = LF_PARSE_KEY;

                                /* Create null terminated string */
                                * lfDirect = LF_UTF8_NUL;

                            }

                        } /* End of loop */

                        /* Update exit code */
                        lfReturn = LF_TRUE;

                    }

                    /* Memory cleaning on failure */
                    if ( lfReturn == LF_FALSE ) {

                        /* Detect allocated memory */
                        if ( lfDesc->dsData != NULL ) {

                            /* Unallocate memory */
                            free( lfDesc->dsData );

                            /* Invalidate pointer */
                            lfDesc->dsData = NULL;

                        }

                    }

                }

            }

            /* Close stream */
            fclose( lfStream );

        }

        /* Return error flag */
        return ( lfReturn );

    }

/*
    Source - Descriptor release
 */

    lf_Void_t lf_release( lf_Descriptor_t * const lfDesc ) {

        /* Check memory allocation */
        if ( lfDesc->dsMap != NULL ) {

            /* Unallocate memory */
            free( lfDesc->dsMap );

            /* Invalidate pointer */
            lfDesc->dsMap = NULL;

        }

        /* Check memory allocation */
        if ( lfDesc->dsData != NULL ) {

            /* Unallocate memory */
            free( lfDesc->dsData );

            /* Invalidate pointer */
            lfDesc->dsData = NULL;

        }

    }

/*
    Source - Keys-string searching algorithm
 */

    lf_Size_t lf_key( lf_Char_t const * const lfKey, lf_Descriptor_t const * const lfDesc ) {

        /* Parsing variables */
        lf_Size_t lfParse = lf_Size_s( 0 );

        /* Returned value variables */
        lf_Size_t lfReturn = LF_INVALID;

        /* Simple loop search */
        while ( ( lfParse < lfDesc->dsCount ) && ( lfReturn == LF_INVALID ) ) {

            /* Compare string */
            if ( strcmp( ( char * ) lfKey, ( char * ) lfDesc->dsMap[lfParse] ) == 0 ) lfReturn = lfParse;

            /* Update search index */
            lfParse += lf_Size_s( 2 );

        }

        /* Return search result */
        return( lfReturn );

    }

