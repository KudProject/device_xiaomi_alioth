#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sm8250-common
include device/xiaomi/sm8250-common/BoardConfigCommon.mk

DEVICE_PATH := device/xiaomi/alioth

BUILD_BROKEN_DUP_RULES := true

# A/B
BOARD_USES_RECOVERY_AS_BOOT := true
BOARD_BUILD_SYSTEM_ROOT_IMAGE := false
AB_OTA_UPDATER := true

AB_OTA_PARTITIONS += \
    boot \
    dtbo \
    odm \
    product \
    system \
    system_ext \
    vbmeta \
    vbmeta_system \
    vendor \
    vendor_boot

# Display
TARGET_SCREEN_DENSITY := 440

# HIDL
ODM_MANIFEST_SKUS += pro
ODM_MANIFEST_PRO_FILES := $(DEVICE_PATH)/configs/vintf/manifest_pro.xml

# Kernel
TARGET_KERNEL_CONFIG := vendor/alioth_defconfig

# Inherit from the proprietary version
include vendor/xiaomi/alioth/BoardConfigVendor.mk
