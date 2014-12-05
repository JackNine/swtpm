/*
 * options.h -- Option parsing
 *
 * (c) Copyright IBM Corporation 2014.
 *
 * Author: Stefan Berger <stefanb@us.ibm.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * Neither the names of the IBM Corporation nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SWTPM_OPTIONS_H
#define _SWTPM_OPTIONS_H

#include <stdbool.h>

enum OptionType {
    OPT_TYPE_STRING,
    OPT_TYPE_INT,
    OPT_TYPE_BOOLEAN,
};

typedef struct {
    enum OptionType type;
    const char *name;
    union {
        char *string;
        int integer;
        bool boolean;
    }u;
} OptionValue;

typedef struct {
    size_t n_options;
    OptionValue *options;
} OptionValues;

typedef struct {
   const char *name;
   enum OptionType type;
} OptionDesc;

#define END_OPTION_DESC \
    { \
        .name = NULL, \
    }

OptionValues *options_parse(char *opts, const OptionDesc optdesc[],
                            char **error);
void option_values_free(OptionValues *ov);
const char *option_get_string(OptionValues *ovs, const char *name);
int option_get_int(OptionValues *ovs, const char *name);
bool option_get_bool(OptionValues *ovs, const char *name);

#endif /* _SWTPM_OPTIONS_H */

