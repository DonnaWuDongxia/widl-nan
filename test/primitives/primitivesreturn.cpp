// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#include "primitivesreturn.h"

PrimitivesReturn::PrimitivesReturn() {
}

PrimitivesReturn::~PrimitivesReturn() {
}

int8_t PrimitivesReturn::showByte() {
  return -127;
}

uint8_t PrimitivesReturn::showOctet() {
  return 255;
}

int16_t PrimitivesReturn::showShort() {
  return -32768;
}

uint16_t PrimitivesReturn::showUnsignedShort() {
  return 65535;
}

int32_t PrimitivesReturn::showLong() {
  return -1234567;
}

uint32_t PrimitivesReturn::showUnsignedLong() {
  return 1234567;
}

std::string PrimitivesReturn::showDOMString() {
  return "DOMString";
}