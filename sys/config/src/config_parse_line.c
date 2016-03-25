/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#ifdef NEWTMGR_PRESENT

#include "config/config.h"
#include "config_priv.h"

#include <json/json.h>

int
conf_parse_line(struct json_buffer *jb, char *name, int nlen, char *value,
  int vlen)
{
    const struct json_attr_t val_attr[3] = {
        [0] = {
            .attribute = "name",
            .type = t_string,
            .addr.string = name,
            .len = nlen
        },
        [1] = {
            .attribute = "val",
            .type = t_string,
            .addr.string = value,
            .len = vlen
        },
        [2] = {
            .attribute = NULL
        }
    };
    int rc;

    rc = json_read_object(jb, val_attr);
    if (rc) {
        return rc;
    }
    return 0;
}

#endif