// Generated by WebF TSDL, don't edit this file directly.
// Generate command: node scripts/generate_binding_code.js
/*
* Copyright (C) 2022-present The WebF authors. All rights reserved.
*/
use std::ffi::*;
use crate::*;
#[repr(C)]
pub struct UIEventRustMethods {
  pub version: c_double,
  pub detail: extern "C" fn(ptr: *const OpaquePtr) -> f64,
  pub view: extern "C" fn(ptr: *const OpaquePtr) -> RustValue<WindowRustMethods>,
  pub which: extern "C" fn(ptr: *const OpaquePtr) -> f64,
}
pub struct UIEvent {
  pub ptr: *const OpaquePtr,
  context: *const ExecutingContext,
  method_pointer: *const UIEventRustMethods,
  status: *const RustValueStatus
}
impl UIEvent {
  pub fn initialize(ptr: *const OpaquePtr, context: *const ExecutingContext, method_pointer: *const UIEventRustMethods, status: *const RustValueStatus) -> UIEvent {
    UIEvent {
      ptr,
      context,
      method_pointer,
      status
    }
  }
  pub fn ptr(&self) -> *const OpaquePtr {
    self.ptr
  }
  pub fn context<'a>(&self) -> &'a ExecutingContext {
    assert!(!self.context.is_null(), "Context PTR must not be null");
    unsafe { &*self.context }
  }
  pub fn detail(&self) -> f64 {
    let value = unsafe {
      ((*self.method_pointer).detail)(self.ptr)
    };
    value
  }
  pub fn view(&self) -> Window {
    let value = unsafe {
      ((*self.method_pointer).view)(self.ptr)
    };
    Window::initialize(value.value, self.context, value.method_pointer, value.status)
  }
  pub fn which(&self) -> f64 {
    let value = unsafe {
      ((*self.method_pointer).which)(self.ptr)
    };
    value
  }
}