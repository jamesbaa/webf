/*
 * Copyright (C) 2022-present The WebF authors. All rights reserved.
 */

#include "dom_matrix_readonly.h"

#include <bindings/qjs/converter_impl.h>

#include "binding_call_methods.h"
#include "core/executing_context.h"
#include "core/geometry/dom_matrix.h"
#include "foundation/native_value_converter.h"

namespace webf {

DOMMatrixReadonly* DOMMatrixReadonly::Create(ExecutingContext* context,
                                             const std::vector<double>& init,
                                             ExceptionState& exception_state) {
  return MakeGarbageCollected<DOMMatrixReadonly>(context, init, exception_state);
}

DOMMatrixReadonly* DOMMatrixReadonly::Create(webf::ExecutingContext* context, webf::ExceptionState& exception_state) {

}

DOMMatrixReadonly::DOMMatrixReadonly(ExecutingContext* context,
                                     const std::vector<double>& init,
                                     ExceptionState& exception_state)
    : BindingObject(context->ctx()) {
  NativeValue arguments[1];
  arguments[0] = NativeValueConverter<NativeTypeArray<NativeTypeDouble>>::ToNativeValue(init);
  GetExecutingContext()->dartMethodPtr()->createBindingObject(GetExecutingContext()->isDedicated(),
                                                              GetExecutingContext()->contextId(), bindingObject(),
                                                              CreateBindingObjectType::kCreateDOMMatrix, arguments, 1);
}

DOMMatrixReadonly::DOMMatrixReadonly(webf::ExecutingContext* context, webf::ExceptionState& exception_state)
    : BindingObject(context->ctx()) {
  GetExecutingContext()->dartMethodPtr()->createBindingObject(GetExecutingContext()->isDedicated(),
                                                              GetExecutingContext()->contextId(), bindingObject(),
                                                              CreateBindingObjectType::kCreateDOMMatrix, nullptr, 0);
}

double DOMMatrixReadonly::getMatrixProperty(const AtomicString& prop) const {
  NativeValue dart_result =
      GetBindingProperty(prop, FlushUICommandReason::kDependentsOnElement, ASSERT_NO_EXCEPTION());
  return NativeValueConverter<NativeTypeDouble>::FromNativeValue(dart_result);
}

void DOMMatrixReadonly::setMatrixProperty(const AtomicString& prop, double v, ExceptionState& exception_state) {
  if (DynamicTo<DOMMatrix>(this)) {
    SetBindingProperty(prop, NativeValueConverter<NativeTypeDouble>::ToNativeValue(v), exception_state);
  }
}

double DOMMatrixReadonly::m11() const {
  return getMatrixProperty(binding_call_methods::km11);
}
void DOMMatrixReadonly::setM11(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km11, v, exception_state);
}
double DOMMatrixReadonly::m12() const {
  return getMatrixProperty(binding_call_methods::km12);
}
void DOMMatrixReadonly::setM12(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km12, v, exception_state);
}
double DOMMatrixReadonly::m13() const {
  return getMatrixProperty(binding_call_methods::km13);
}
void DOMMatrixReadonly::setM13(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km13, v, exception_state);
}
double DOMMatrixReadonly::m14() const {
  return getMatrixProperty(binding_call_methods::km14);
}
void DOMMatrixReadonly::setM14(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km14, v, exception_state);
}

double DOMMatrixReadonly::m21() const {
  return getMatrixProperty(binding_call_methods::km21);
}
void DOMMatrixReadonly::setM21(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km21, v, exception_state);
}
double DOMMatrixReadonly::m22() const {
  return getMatrixProperty(binding_call_methods::km22);
}
void DOMMatrixReadonly::setM22(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km22, v, exception_state);
}
double DOMMatrixReadonly::m23() const {
  return getMatrixProperty(binding_call_methods::km23);
}
void DOMMatrixReadonly::setM23(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km23, v, exception_state);
}
double DOMMatrixReadonly::m24() const {
  return getMatrixProperty(binding_call_methods::km24);
}
void DOMMatrixReadonly::setM24(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km24, v, exception_state);
}

double DOMMatrixReadonly::m31() const {
  return getMatrixProperty(binding_call_methods::km31);
}
void DOMMatrixReadonly::setM31(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km31, v, exception_state);
}
double DOMMatrixReadonly::m32() const {
  return getMatrixProperty(binding_call_methods::km32);
}
void DOMMatrixReadonly::setM32(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km32, v, exception_state);
}
double DOMMatrixReadonly::m33() const {
  return getMatrixProperty(binding_call_methods::km33);
}
void DOMMatrixReadonly::setM33(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km33, v, exception_state);
}
double DOMMatrixReadonly::m34() const {
  return getMatrixProperty(binding_call_methods::km34);
}
void DOMMatrixReadonly::setM34(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km34, v, exception_state);
}
double DOMMatrixReadonly::m41() const {
  return getMatrixProperty(binding_call_methods::km41);
}
void DOMMatrixReadonly::setM41(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km41, v, exception_state);
}
double DOMMatrixReadonly::m42() const {
  return getMatrixProperty(binding_call_methods::km42);
}
void DOMMatrixReadonly::setM42(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km42, v, exception_state);
}
double DOMMatrixReadonly::m43() const {
  return getMatrixProperty(binding_call_methods::km43);
}
void DOMMatrixReadonly::setM43(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km43, v, exception_state);
}
double DOMMatrixReadonly::m44() const {
  return getMatrixProperty(binding_call_methods::km44);
}
void DOMMatrixReadonly::setM44(double v, ExceptionState& exception_state) {
  setMatrixProperty(binding_call_methods::km44, v, exception_state);
}

DOMMatrix* DOMMatrixReadonly::flipX(ExceptionState& exception_state) const{
  NativeValue arguments[0];
  NativeValue value = InvokeBindingMethod(binding_call_methods::kflipX, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
DOMMatrix* DOMMatrixReadonly::flipY(ExceptionState& exception_state) const{
  NativeValue arguments[0];
  NativeValue value = InvokeBindingMethod(binding_call_methods::kflipY, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
DOMMatrix* DOMMatrixReadonly::inverse(ExceptionState& exception_state) const{
  NativeValue arguments[0];
  NativeValue value = InvokeBindingMethod(binding_call_methods::kinverse, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
DOMMatrix* DOMMatrixReadonly::rotateAxisAngle(double x, double y, double z, double angle, ExceptionState& exception_state) const {
  NativeValue arguments[] = {NativeValueConverter<NativeTypeDouble>::ToNativeValue(x),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(y),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(z),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(angle)};
  NativeValue value = InvokeBindingMethod(binding_call_methods::krotateAxisAngle, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
DOMMatrix* DOMMatrixReadonly::rotate(double rotX, double rotY, double rotZ, ExceptionState& exception_state) const {
  NativeValue arguments[] = {NativeValueConverter<NativeTypeDouble>::ToNativeValue(rotX),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(rotY),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(rotZ)};
  NativeValue value = InvokeBindingMethod(binding_call_methods::krotate, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
DOMMatrix* DOMMatrixReadonly::rotateFromVector(double x, double y, ExceptionState& exception_state) const {
  NativeValue arguments[] = {NativeValueConverter<NativeTypeDouble>::ToNativeValue(x),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(y)};
  NativeValue value = InvokeBindingMethod(binding_call_methods::krotateFromVector, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
    NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
DOMMatrix* DOMMatrixReadonly::scale(double scaleX,
                                    double scaleY,
                                    double scaleZ,
                                    double originX,
                                    double originY,
                                    double originZ,
                                    ExceptionState& exception_state) const {
  NativeValue arguments[] = {NativeValueConverter<NativeTypeDouble>::ToNativeValue(scaleX),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(scaleY),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(scaleZ),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(originX),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(originY),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(originZ)};
  NativeValue value = InvokeBindingMethod(binding_call_methods::kscale, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
DOMMatrix* DOMMatrixReadonly::scale3d(double scale,
                                      double originX,
                                      double originY,
                                      double originZ,
                                      ExceptionState& exception_state) const {
  NativeValue arguments[] = {NativeValueConverter<NativeTypeDouble>::ToNativeValue(scale),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(originX),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(originY),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(originZ)};
  NativeValue value = InvokeBindingMethod(binding_call_methods::kscale3d, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
// DOMMatrix* scaleNonUniform(ExceptionState& exception_state) const;
DOMMatrix* DOMMatrixReadonly::skewX(double sx, ExceptionState& exception_state) const {
  NativeValue arguments[] = {NativeValueConverter<NativeTypeDouble>::ToNativeValue(sx)};
  NativeValue value = InvokeBindingMethod(binding_call_methods::kskewX, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
DOMMatrix* DOMMatrixReadonly::skewY(double sy, ExceptionState& exception_state) const {
  NativeValue arguments[] = {NativeValueConverter<NativeTypeDouble>::ToNativeValue(sy)};
  NativeValue value = InvokeBindingMethod(binding_call_methods::kskewY, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}
// std::vector<float>& DOMMatrixReadonly::toFloat32Array(ExceptionState& exception_state) const {
//   std::vector<float> float32Vector;
//   // NativeValue arguments[0];
//   // NativeValue value = InvokeBindingMethod(binding_call_methods::ktoFloat32Array, sizeof(arguments) / sizeof(NativeValue),
//   //   arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
//   // auto&& arr = NativeValueConverter<NativeTypeArray<NativeTypeDouble>>::FromNativeValue(ctx(), value);
//   // if (native_binding_object == nullptr)
//   //   return float32Vector;
//   // // return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
//   return float32Vector;
// }
// std::vector<double>& DOMMatrixReadonly::toFloat64Array(ExceptionState& exception_state) const {
//   std::vector<double> float64Vector;
//   return float64Vector;
// }
// toJSON(): DartImpl<JSON>;
AtomicString DOMMatrixReadonly::toString(ExceptionState& exception_state) const {
  NativeValue arguments[0];
  NativeValue dart_result = InvokeBindingMethod(binding_call_methods::ktoString, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  return NativeValueConverter<NativeTypeString>::FromNativeValue(ctx(), std::move(dart_result));
}

DOMMatrix* DOMMatrixReadonly::translate(double tx, double ty, double tz, ExceptionState& exception_state) const {
  NativeValue arguments[] = {NativeValueConverter<NativeTypeDouble>::ToNativeValue(tx),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(ty),
                             NativeValueConverter<NativeTypeDouble>::ToNativeValue(tz)};
  NativeValue value = InvokeBindingMethod(binding_call_methods::ktranslate, sizeof(arguments) / sizeof(NativeValue),
                                          arguments, FlushUICommandReason::kDependentsOnElement, exception_state);
  NativeBindingObject* native_binding_object =
      NativeValueConverter<NativeTypePointer<NativeBindingObject>>::FromNativeValue(value);
  if (native_binding_object == nullptr)
    return nullptr;
  return MakeGarbageCollected<DOMMatrix>(GetExecutingContext(), native_binding_object);
}


NativeValue DOMMatrixReadonly::HandleCallFromDartSide(const AtomicString& method,
                                                      int32_t argc,
                                                      const NativeValue* argv,
                                                      Dart_Handle dart_object) {
  return Native_NewNull();
}

}  // namespace webf