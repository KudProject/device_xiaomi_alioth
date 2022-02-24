//
// Copyright (C) 2021-2022 KudProject Development
//
// SPDX-License-Identifier: Apache-2.0
//

#include <cstdio>

#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

#define MAX_PROP_LIST 8
void property_override_multiple(std::string type, char const value[])
{
    const std::string product_prop_list[MAX_PROP_LIST] = {
        "ro.product.",
        "ro.product.bootimage.",
        "ro.product.odm.",
        "ro.product.product.",
        "ro.product.system.",
        "ro.product.system_ext.",
        "ro.product.vendor.",
        "ro.product.vendor_dlkm.",
    };

    for (int i = 0; i < MAX_PROP_LIST; i++)
        property_override((char *)&(product_prop_list[i] + type)[0], value);
}

void vendor_load_properties()
{
    std::string region = android::base::GetProperty("ro.boot.hwc", "");
    char const *brand, *device, *marketname, *model, *name;

    if (region == "CN") {
        brand = "Redmi";
        device = "alioth";
        marketname = "Redmi K40";
        model = "M2012K11AC";
        name = "alioth";
    } else if (region == "GLOBAL") {
        brand = "POCO";
        device = "alioth";
        marketname = "POCO F3";
        model = "M2012K11AG";
        name = "alioth_global";
    } else if (region == "INDIA") {
        brand = "Mi";
        device = "aliothin";
        marketname = "Mi 11X";
        model = "M2012K11AI";
        name = "aliothin";
    }

    property_override_multiple("brand", brand);
    property_override_multiple("device", device);
    property_override_multiple("marketname", marketname);
    property_override_multiple("model", model);
    property_override_multiple("name", name);
}
