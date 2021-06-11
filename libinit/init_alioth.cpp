// Copyright (C) 2021 The LineageOS Project
// Copyright (C) 2021 KudProject Development
// SPDX-License-Identifier: Apache-2.0

#include <sys/sysinfo.h>

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

static void load_dalvik_heap_properties()
{
    struct sysinfo sys;
    char const *start_size, *growth_limit, *target_utilization, *max_free;

    sysinfo(&sys);
    if (sys.totalram > 8192ull * 1024 * 1024) {
        // phone-xhdpi-12288-dalvik-heap.mk
        start_size = "24m";
        growth_limit = "384m";
        target_utilization = "0.42";
        max_free = "56m";
    } else if (sys.totalram > 6144ull * 1024 * 1024) {
        // phone-xhdpi-8192-dalvik-heap.mk
        start_size = "24m";
        growth_limit = "256m";
        target_utilization = "0.46";
        max_free = "48m";
    } else { // (sys.totalram > 4096ull * 1024 * 1024)
        // phone-xhdpi-6144-dalvik-heap.mk
        start_size = "16m";
        growth_limit = "256m";
        target_utilization = "0.5";
        max_free = "32m";
    }

    property_override("dalvik.vm.heapstartsize", start_size);
    property_override("dalvik.vm.heapgrowthlimit", growth_limit);
    property_override("dalvik.vm.heapsize", "512m");
    property_override("dalvik.vm.heaptargetutilization", target_utilization);
    property_override("dalvik.vm.heapminfree", "8m");
    property_override("dalvik.vm.heapmaxfree", max_free);
}

void vendor_load_properties()
{
    search_variant(variants);
    load_dalvik_heap_properties();
}
