/*
 * Copyright (c) 2003-2004 Apple Computer, Inc. All Rights Reserved.
 * 
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*!
	@header SecTrustPriv
	Private part of SecTrust.h
*/

#ifndef _SECURITY_SECTRUST_PRIV_H_
#define _SECURITY_SECTRUST_PRIV_H_

#include <Security/SecTrust.h>


#if defined(__cplusplus)
extern "C" {
#endif

/*
	unique keychain item attributes for user trust records.
*/
enum {
    kSecTrustCertAttr 				 = 'tcrt',
    kSecTrustPolicyAttr				 = 'tpol'
};

/*!
    @function SecTrustSetPolicies
    @abstract Set (replace) set of policies to evaluate
    @param trust The SecTrust object to manipulate
    @param policies An array of one or more policies. A Single SecPolicyRef may also
		be passed, representing an array of one policy.
    @result A result code.  See "Security Error Codes" (SecBase.h).
*/    
OSStatus SecTrustSetPolicies(SecTrustRef trust, CFTypeRef policies);

/*!
	@function SecTrustGetCssmVerifyResult
	@abstract Gets the actual CSSM return code from the last attempted SecTrustEvaluate call.
	@param trust A reference to a trust.
	@param result On return, the CSSM_RETURN produced by the last invocation of the TP.
	@result A result code.  See "Security Error Codes" (SecBase.h).
*/
OSStatus SecTrustGetCssmResultCode(SecTrustRef trust, OSStatus *result);

/*!
	@function SecGetAppleTPHandle - NOT EXPORTED YET; copied from SecurityInterface, 
                                                      but could be useful in the future.
	@abstract Gets the Apple Trust Policy handle (TPHandle).
	@param result On return, the Apple TPHandle.
*/
/* CSSM_TP_HANDLE SecGetAppleTPHandle();
*/
#if defined(__cplusplus)
}
#endif

#endif /* !_SECURITY_SECTRUST_PRIV_H_ */
