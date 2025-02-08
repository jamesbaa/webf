// Generated by WebF TSDL, don't edit this file directly.
// Generate command: node scripts/generate_binding_code.js
// clang-format off
/*
 * Copyright (C) 2022-present The WebF authors. All rights reserved.
 */
#ifndef WEBF_CORE_WEBF_API_PLUGIN_API_MOUSE_EVENT_H_
#define WEBF_CORE_WEBF_API_PLUGIN_API_MOUSE_EVENT_H_
#include <stdint.h>
#include "rust_readable.h"
#include "ui_event.h"
namespace webf {
class SharedExceptionState;
class ExecutingContext;
typedef struct NativeValue NativeValue;
class MouseEvent;
using PublicMouseEventGetButton = double (*)(MouseEvent*);
using PublicMouseEventGetClientX = double (*)(MouseEvent*);
using PublicMouseEventGetClientY = double (*)(MouseEvent*);
using PublicMouseEventGetOffsetX = double (*)(MouseEvent*);
using PublicMouseEventGetOffsetY = double (*)(MouseEvent*);
struct MouseEventPublicMethods : public WebFPublicMethods {
  static double Button(MouseEvent* mouse_event);
  static double ClientX(MouseEvent* mouse_event);
  static double ClientY(MouseEvent* mouse_event);
  static double OffsetX(MouseEvent* mouse_event);
  static double OffsetY(MouseEvent* mouse_event);
  double version{1.0};
  UIEventPublicMethods ui_event;
  PublicMouseEventGetButton mouse_event_get_button{Button};
  PublicMouseEventGetClientX mouse_event_get_client_x{ClientX};
  PublicMouseEventGetClientY mouse_event_get_client_y{ClientY};
  PublicMouseEventGetOffsetX mouse_event_get_offset_x{OffsetX};
  PublicMouseEventGetOffsetY mouse_event_get_offset_y{OffsetY};
};
}  // namespace webf
#endif  // WEBF_CORE_WEBF_API_PLUGIN_API_MOUSE_EVENT_H_
