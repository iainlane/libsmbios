/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * vim:expandtab:autoindent:tabstop=4:shiftwidth=4:filetype=c:cindent:textwidth=0:
 *
 * Copyright (C) 2005 Dell Inc.
 *  by Michael Brown <Michael_E_Brown@dell.com>
 * Licensed under the Open Software License version 2.1
 *
 * Alternatively, you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 */

// compat header should always be first header if including system headers
#include "smbios_c/compat.h"

// system

#include "testC_smi.h"
#include "smbios_c/obj/memory.h"
#include "smbios_c/obj/smi.h"
#include "smbios_c/smi.h"

#include "outputctl.h"
#include "main.h"

using namespace std;

// Note:
//      Except for , there are no "using namespace XXXX;" statements
//      here... on purpose. We want to ensure that while reading this code that
//      it is extremely obvious where each function is coming from.
//
//      This leads to verbose code in some instances, but that is fine for
//      these purposes.

// Register the test
CPPUNIT_TEST_SUITE_REGISTRATION (testCsmi);

void testCsmi::setUp()
{
    string writeDirectory = getWritableDirectory();

    // copy the memdump.dat file. We do not write to it, but rw open will fail
    // if we do not copy it
    string memdumpOrigFile = getTestDirectory() + "/memdump.dat";
    string memdumpCopyFile = writeDirectory + "/memdump-copy.dat";
    copyFile( memdumpCopyFile, memdumpOrigFile );

    memory_obj_factory(MEMORY_UNIT_TEST_MODE | MEMORY_GET_SINGLETON, memdumpCopyFile.c_str());
}

void testCsmi::tearDown()
{
}

void testCsmi::testSmiConstruct()
{
    STD_TEST_START(getTestName().c_str() << "  ");
    STD_TEST_END("");
}




