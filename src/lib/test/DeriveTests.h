/*
 * Copyright (c) 2014 SURFnet
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*****************************************************************************
 DeriveTests.h

 Contains test cases to C_DeriveKey
 *****************************************************************************/

#ifndef _SOFTHSM_V2_DERIVETESTS_H
#define _SOFTHSM_V2_DERIVETESTS_H

#include "TestsBase.h"
#include <cppunit/extensions/HelperMacros.h>

class DeriveTests : public TestsBase
{
	CPPUNIT_TEST_SUITE(DeriveTests);
	CPPUNIT_TEST(testDhDerive);
#ifdef WITH_ECC
	CPPUNIT_TEST(testEcdsaDerive);
#endif
#ifdef WITH_EDDSA
	CPPUNIT_TEST_PARAMETERIZED(testEddsaDerive, {"X25519", "X448"});
#endif
	CPPUNIT_TEST(testSymDerive);
	CPPUNIT_TEST(testMiscDerivations);
	CPPUNIT_TEST_SUITE_END();

public:
	void testDhDerive();
#ifdef WITH_ECC
	void testEcdsaDerive();
#endif
#ifdef WITH_EDDSA
	void testEddsaDerive(const char* alg);
#endif
	void testSymDerive();
    void testMiscDerivations();

protected:
	CK_RV generateDhKeyPair(CK_SESSION_HANDLE hSession, CK_BBOOL bTokenPuk, CK_BBOOL bPrivatePuk, CK_BBOOL bTokenPrk, CK_BBOOL bPrivatePrk, CK_OBJECT_HANDLE &hPuk, CK_OBJECT_HANDLE &hPrk);
	CK_RV createAesKey(CK_SESSION_HANDLE hSession, CK_BBOOL bToken, CK_BBOOL bPrivate, CK_BBOOL bSensitive, CK_BBOOL bExtractable, CK_BBOOL bDerive, CK_OBJECT_HANDLE &hKey);
	CK_RV generateAesKey(CK_SESSION_HANDLE hSession, CK_BBOOL bToken, CK_BBOOL bPrivate, CK_OBJECT_HANDLE &hKey);
#ifndef WITH_FIPS
	CK_RV generateDesKey(CK_SESSION_HANDLE hSession, CK_BBOOL bToken, CK_BBOOL bPrivate, CK_OBJECT_HANDLE &hKey);
#endif
	CK_RV generateDes2Key(CK_SESSION_HANDLE hSession, CK_BBOOL bToken, CK_BBOOL bPrivate, CK_OBJECT_HANDLE &hKey);
	CK_RV generateDes3Key(CK_SESSION_HANDLE hSession, CK_BBOOL bToken, CK_BBOOL bPrivate, CK_OBJECT_HANDLE &hKey);
	void dhDerive(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hPublicKey, CK_OBJECT_HANDLE hPrivateKey, CK_OBJECT_HANDLE &hKey);
#ifdef WITH_ECC
	CK_RV generateEcKeyPair(const char* curve, CK_SESSION_HANDLE hSession, CK_BBOOL bTokenPuk, CK_BBOOL bPrivatePuk, CK_BBOOL bTokenPrk, CK_BBOOL bPrivatePrk, CK_OBJECT_HANDLE &hPuk, CK_OBJECT_HANDLE &hPrk);
#endif
#if defined(WITH_ECC) || defined(WITH_EDDSA)
	void ecdhDerive(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hPublicKey, CK_OBJECT_HANDLE hPrivateKey, CK_OBJECT_HANDLE &hKey, bool useRaw);
#endif
#ifdef WITH_EDDSA
	CK_RV generateEdKeyPair(const char* alg, CK_SESSION_HANDLE hSession, CK_BBOOL bTokenPuk, CK_BBOOL bPrivatePuk, CK_BBOOL bTokenPrk, CK_BBOOL bPrivatePrk, CK_OBJECT_HANDLE &hPuk, CK_OBJECT_HANDLE &hPrk);
#endif
	bool compareSecret(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hKey1, CK_OBJECT_HANDLE hKey2);
	void symDerive(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hKey, CK_OBJECT_HANDLE &hDerive, CK_MECHANISM_TYPE mechType, CK_KEY_TYPE keyType);
};

#endif // !_SOFTHSM_V2_DERIVETESTS_H
