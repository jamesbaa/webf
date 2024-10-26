// Generated by WebF TSDL, don't edit this file directly.
// Generate command: node scripts/generate_binding_code.js
/*
 * Copyright (C) 2022-present The WebF authors. All rights reserved.
 */
#ifndef WEBF_CORE_WEBF_API_PLUGIN_API_POINTER_EVENT_H_
#define WEBF_CORE_WEBF_API_PLUGIN_API_POINTER_EVENT_H_
#include <stdint.h>
#include "script_value_ref.h"
#include "mouse_event.h"
namespace webf {
typedef struct SharedExceptionState SharedExceptionState;
typedef struct ExecutingContext ExecutingContext;
typedef struct PointerEvent PointerEvent;
typedef struct ScriptValueRef ScriptValueRef;
using PublicPointerEventGetHeight = double (*)(PointerEvent*);
using PublicPointerEventGetIsPrimary = bool (*)(PointerEvent*);
using PublicPointerEventGetPointerId = double (*)(PointerEvent*);
using PublicPointerEventGetPointerType = const char* (*)(PointerEvent*);
using PublicPointerEventDupPointerType = const char* (*)(PointerEvent*);
using PublicPointerEventGetPressure = double (*)(PointerEvent*);
using PublicPointerEventGetTangentialPressure = double (*)(PointerEvent*);
using PublicPointerEventGetTiltX = double (*)(PointerEvent*);
using PublicPointerEventGetTiltY = double (*)(PointerEvent*);
using PublicPointerEventGetTwist = double (*)(PointerEvent*);
using PublicPointerEventGetWidth = double (*)(PointerEvent*);
struct PointerEventPublicMethods : public WebFPublicMethods {
  static double Height(PointerEvent* pointer_event);
  static bool IsPrimary(PointerEvent* pointer_event);
  static double PointerId(PointerEvent* pointer_event);
  static const char* PointerType(PointerEvent* pointer_event);
  static const char* DupPointerType(PointerEvent* pointer_event);
  static double Pressure(PointerEvent* pointer_event);
  static double TangentialPressure(PointerEvent* pointer_event);
  static double TiltX(PointerEvent* pointer_event);
  static double TiltY(PointerEvent* pointer_event);
  static double Twist(PointerEvent* pointer_event);
  static double Width(PointerEvent* pointer_event);
  double version{1.0};
  MouseEventPublicMethods mouse_event;
  PublicPointerEventGetHeight pointer_event_get_height{Height};
  PublicPointerEventGetIsPrimary pointer_event_get_is_primary{IsPrimary};
  PublicPointerEventGetPointerId pointer_event_get_pointer_id{PointerId};
  PublicPointerEventGetPointerType pointer_event_get_pointer_type{PointerType};
  PublicPointerEventDupPointerType pointer_event_dup_pointer_type{DupPointerType};
  PublicPointerEventGetPressure pointer_event_get_pressure{Pressure};
  PublicPointerEventGetTangentialPressure pointer_event_get_tangential_pressure{TangentialPressure};
  PublicPointerEventGetTiltX pointer_event_get_tilt_x{TiltX};
  PublicPointerEventGetTiltY pointer_event_get_tilt_y{TiltY};
  PublicPointerEventGetTwist pointer_event_get_twist{Twist};
  PublicPointerEventGetWidth pointer_event_get_width{Width};
};
}  // namespace webf
#endif // WEBF_CORE_WEBF_API_PLUGIN_API_POINTER_EVENT_H_