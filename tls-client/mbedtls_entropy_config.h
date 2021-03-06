/*
 *  Copyright (C) 2006-2018, Arm Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of Mbed TLS (https://tls.mbed.org)
 */

#if !defined(MBEDTLS_ENTROPY_HARDWARE_ALT) && \
    !defined(MBEDTLS_ENTROPY_NV_SEED) && !defined(MBEDTLS_TEST_NULL_ENTROPY)
#error "This hardware does not have an entropy source."
#endif /* !MBEDTLS_ENTROPY_HARDWARE_ALT && !MBEDTLS_ENTROPY_NV_SEED &&
        * !MBEDTLS_TEST_NULL_ENTROPY */

#if !defined(MBEDTLS_SHA1_C)
#define MBEDTLS_SHA1_C
#endif /* !MBEDTLS_SHA1_C */

/*
 *  This value is sufficient for handling 2048 bit RSA keys.
 *
 *  Set this value higher to enable handling larger keys, but be aware that this
 *  will increase the stack usage.
 */
#undef MBEDTLS_MPI_MAX_SIZE
#define MBEDTLS_MPI_MAX_SIZE        256

/* This macro determines whether Mbed TLS uses its own legacy crypto library
 * or an implementation of the PSA Crypto API such as Mbed Crypto.
 *
 * To confirm the use of PSA Crypto, you may enable debugging by setting
 * HELLO_HTTPS_CLIENT_DEBUG_LEVEL in HelloHttpsClient.h and look for
 * PSA-related debugging output on the serial line.
 *
 * Uncomment this to use the PSA Crypto API. */
//#define MBEDTLS_USE_PSA_CRYPTO

#define MBEDTLS_MPI_WINDOW_SIZE     1
