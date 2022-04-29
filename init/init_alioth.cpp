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
void property_override_multiple(std::string type, char const value[], bool is_product)
{
    const std::string build_prop_list[MAX_PROP_LIST] = {
        "ro.bootimage.build.",
        "ro.build.",
        "ro.odm.build.",
        "ro.product.build.",
        "ro.system.build.",
        "ro.system_ext.build.",
        "ro.vendor.build.",
        "ro.vendor_dlkm.build.",
    };

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

    for (int i = 0; i < MAX_PROP_LIST; i++) {
        if (is_product)
            property_override((char *)&(product_prop_list[i] + type)[0], value);
        else
            property_override((char *)&(build_prop_list[i] + type)[0], value);
    }
}

void vendor_load_properties()
{
    std::string region = android::base::GetProperty("ro.boot.hwc", "");
    char const *brand, *device, *marketname, *model, *name;
    char const *description = "alioth-user 12 RKQ1.200826.002 V13.0.5.0.SKHCNXM release-keys";
    char const *fingerprint = "Redmi/alioth/alioth:12/RKQ1.200826.002/V13.0.5.0.SKHCNXM:user/release-keys";

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

    property_override_multiple("brand", brand, true);
    property_override_multiple("device", device, true);
    property_override_multiple("marketname", marketname, true);
    property_override_multiple("model", model, true);
    property_override_multiple("name", name, true);

    property_override_multiple("description", description, false);
    property_override_multiple("fingerprint", fingerprint, false);

    // Keyboard height ratio and bottom padding in dp for portrait mode
    property_override("ro.com.google.ime.height_ratio", "1.0");
    property_override("ro.com.google.ime.kb_pad_port_b", "14.4");
}
