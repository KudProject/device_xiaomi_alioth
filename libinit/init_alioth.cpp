// Copyright (C) 2021 The LineageOS Project
// Copyright (C) 2021 KudProject Development
// SPDX-License-Identifier: Apache-2.0

#include <libinit_kona.h>

static const variant_info_t alioth_info = {
    .prop_key = "ro.boot.hwc",
    .prop_value = "CN",

    .brand = "Redmi",
    .device = "alioth",
    .marketname = "Redmi K40",
    .model = "M2012K11AC",
    .name = "alioth",
    .build_description = "alioth-user 11 RKQ1.200826.002 V12.5.4.0.RKHCNXM release-keys",
    .build_fingerprint = "Redmi/alioth/alioth:11/RKQ1.200826.002/V12.5.4.0.RKHCNXM:user/release-keys",
};

static const variant_info_t alioth_global_info = {
    .prop_key = "ro.boot.hwc",
    .prop_value = "GLOBAL",

    .brand = "POCO",
    .device = "alioth",
    .marketname = "POCO F3",
    .model = "M2012K11AG",
    .name = "alioth_global",
    .build_description = "alioth-user 11 RKQ1.200826.002 V12.5.2.0.RKHMIXM release-keys",
    .build_fingerprint = "POCO/alioth_global/alioth:11/RKQ1.200826.002/V12.5.2.0.RKHMIXM:user/release-keys",
};

static const variant_info_t aliothin_info = {
    .prop_key = "ro.boot.hwc",
    .prop_value = "INDIA",

    .brand = "Mi",
    .device = "aliothin",
    .marketname = "Mi 11X",
    .model = "M2012K11AI",
    .name = "aliothin",
    .build_description = "aliothin-user 11 RKQ1.200826.002 V12.5.2.0.RKHINXM release-keys",
    .build_fingerprint = "Mi/aliothin/aliothin:11/RKQ1.200826.002/V12.5.2.0.RKHINXM:user/release-keys",
};

static const std::vector<variant_info_t> variants = {
    alioth_info,
    alioth_global_info,
    aliothin_info,
};

void vendor_load_properties()
{
    search_variant(variants);
}
