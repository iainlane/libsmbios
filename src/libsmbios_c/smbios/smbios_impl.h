// vim:expandtab:autoindent:tabstop=4:shiftwidth=4:filetype=c:
/*
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

#ifndef SMBIOS_IMPL_H
#define SMBIOS_IMPL_H

#include "smbios_c/compat.h"
#include "smbios_c/smbios.h"
#include "smbios_c/types.h"

EXTERN_C_BEGIN;

#define __internal __attribute__((visibility("internal")))
#define __hidden __attribute__((visibility("hidden")))

#if defined(DEBUG_SMBIOS_C)
#   include <stdio.h>
#   define dprintf(format, args...) do { fprintf(stderr , format , ## args);  } while(0)
#else
#   define dprintf(format, args...) do {} while(0)
#endif

#define E_BLOCK_START 0xE0000UL
#define F_BLOCK_START 0xF0000UL
#define F_BLOCK_END   0xFFFFFUL

#if defined(_MSC_VER)
#pragma pack(push,1)
#endif
struct smbios_struct
{
    u8 type;
    u8 length;
    u16 handle;
}
LIBSMBIOS_PACKED_ATTR;

struct dmi_table_entry_point
{
    u8 anchor[5];
    u8 checksum;
    u16 table_length;
    u32 table_address;
    u16 table_num_structs;
    u8 smbios_bcd_revision;
}
LIBSMBIOS_PACKED_ATTR;

struct smbios_table_entry_point
{
    u8 anchor[4];
    u8 checksum;
    u8 eps_length;
    u8 major_ver;
    u8 minor_ver;
    u16 max_struct_size;
    u8 revision;
    u8 formatted_area[5];
    struct dmi_table_entry_point dmi;
    u8 padding_for_Intel_BIOS_bugs;
} LIBSMBIOS_PACKED_ATTR;

#if defined(_MSC_VER)
#pragma pack(pop)
#endif


struct smbios_table
{
    int initialized;
    struct smbios_table_entry_point tep;
    struct table *table;
};

int __internal smbios_get_table_memory(struct smbios_table *m);

#if 0
int __internal smbios_get_table_efi(struct smbios_table *m);
int __internal smbios_get_table_wmi(struct smbios_table *m);
int __internal smbios_get_table_firm_tables(struct smbios_table *m);
#else
#define smbios_get_table_efi(m)         (-1)
#define smbios_get_table_wmi(m)         (-1)
#define smbios_get_table_firm_tables(m) (-1)
#endif

EXTERN_C_END;

#endif /* SMBIOS_IMPL_H */
