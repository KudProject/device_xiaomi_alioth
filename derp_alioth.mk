#
# Copyright (C) 2021 Snuggy Wuggy Research and Development Center 
#                    and The hentaiOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# This must be defined before inheriting mainline_system.mk to avoid
# com.android.apex.cts.shim.v1_prebuilt from slipping into flattened build,
# creating an unsupported configuration.
OVERRIDE_TARGET_FLATTEN_APEX := true

#
# All components inherited here go to system image
#
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/mainline_system.mk)

#
# All components inherited here go to system_ext image
#
$(call inherit-product, $(SRC_TARGET_DIR)/product/handheld_system_ext.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/telephony_system_ext.mk)

# All components inherited here go to product image
#
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_product.mk)

#
# All components inherited here go to vendor image
#
# TODO(b/136525499): move *_vendor.mk into the vendor makefile later
$(call inherit-product, $(SRC_TARGET_DIR)/product/handheld_vendor.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/telephony_vendor.mk)

# Inherit some common DerpFest stuff.
$(call inherit-product, vendor/derp/config/common_full_phone.mk)

$(call inherit-product, device/xiaomi/alioth/device.mk)

# Don't build super.img.
PRODUCT_BUILD_SUPER_PARTITION := false

PRODUCT_MANUFACTURER := Xiaomi
PRODUCT_BRAND := Redmi
PRODUCT_NAME := derp_alioth
PRODUCT_DEVICE := alioth
PRODUCT_MODEL := K40

PRODUCT_GMS_CLIENTID_BASE := android-xiaomi

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="alioth-user 12 SQ3A.220605.009.A1 8643238 release-keys"

BUILD_FINGERPRINT := Redmi/alioth/alioth:12/SQ3A.220605.009.A1/8643238:user/release-keys
