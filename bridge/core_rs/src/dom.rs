/*
* Copyright (C) 2022-present The WebF authors. All rights reserved.
*/

use std::ffi::{CString};
use webf_sys::executing_context::ExecutingContext;
use webf_sys::node::NodeMethods;

pub fn init_webf_dom(context: &ExecutingContext){
  let document = context.document();
  let exception_state = context.create_exception_state();

  let html_tag_name = CString::new("html");
  let html_element = document.create_element(&html_tag_name.unwrap(), &exception_state)?;

  document.append_child(&html_element, &exception_state).unwrap();

  let head_tag_name = CString::new("head");
  let head_element = document.create_element(&head_tag_name.unwrap(), &exception_state).unwrap();
  document.document_element().append_child(&head_element, &exception_state).unwrap();

  let body_tag_name = CString::new("body");
  let body_element = document.create_element(&body_tag_name.unwrap(), &exception_state).unwrap();
  document.document_element().append_child(&body_element, &exception_state).unwrap();
}

