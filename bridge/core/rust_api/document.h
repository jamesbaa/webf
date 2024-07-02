/*
 * Copyright (C) 2022-present The WebF authors. All rights reserved.
 */

#ifndef WEBF_CORE_RUST_API_DOCUMENT_H_
#define WEBF_CORE_RUST_API_DOCUMENT_H_

#include "core/rust_api/container_node.h"
#include "core/rust_api/element.h"
#include "core/rust_api/rust_value.h"
#include "core/rust_api/text.h"

namespace webf {

typedef struct EventTarget EventTarget;
typedef struct SharedExceptionState SharedExceptionState;
typedef struct ExecutingContext ExecutingContext;
typedef struct Element Element;
typedef struct Document Document;
typedef struct Text Text;

struct RustElementCreationOptions {
  const char* is;
};

using RustDocumentCreateElement =
    RustValue<Element, ElementRustMethods> (*)(Document*, const char*, SharedExceptionState* shared_exception_state);
using RustDocumentCreateElementWithElementCreationOptions =
    RustValue<Element, ElementRustMethods> (*)(Document*, const char*, RustElementCreationOptions&,
                                               SharedExceptionState* shared_exception_state);
using RustDocumentCreateElementNS =
    RustValue<Element, ElementRustMethods> (*)(Document*, const char*, const char*, SharedExceptionState* shared_exception_state);
using RustDocumentCreateElementNSWithElementCreationOptions =
    RustValue<Element, ElementRustMethods> (*)(Document*, const char*, const char*, RustElementCreationOptions&,
                                               SharedExceptionState* shared_exception_state);
using RustDocumentCreateTextNode =
    RustValue<Text, TextNodeRustMethods> (*)(Document*, const char*, SharedExceptionState* shared_exception_state);
using RustDocumentGetDocumentElement = RustValue<Element, ElementRustMethods> (*)(Document*);

struct DocumentRustMethods : public RustMethods {
  DocumentRustMethods(ContainerNodeRustMethods* super_rust_method);

  static RustValue<Element, ElementRustMethods> CreateElement(Document* document,
                                                              const char* tag_name,
                                                              SharedExceptionState* shared_exception_state);
  static RustValue<Element, ElementRustMethods> CreateElementWithElementCreationOptions(Document* document,
                                                                const char* tag_name,
                                                                RustElementCreationOptions& options,
                                                                SharedExceptionState* shared_exception_state);
  static RustValue<Element, ElementRustMethods> CreateElementNS(Document* document,
                                                              const char* uri,
                                                              const char* tag_name,
                                                              SharedExceptionState* shared_exception_state);
  static RustValue<Element, ElementRustMethods> CreateElementNSWithElementCreationOptions(Document* document,
                                                              const char* uri,
                                                              const char* tag_name,
                                                              RustElementCreationOptions& options,
                                                              SharedExceptionState* shared_exception_state);
  static RustValue<Text, TextNodeRustMethods> CreateTextNode(Document* document,
                                                             const char* data,
                                                             SharedExceptionState* shared_exception_state);
  static RustValue<Element, ElementRustMethods> DocumentElement(Document* document);

  double version{1.0};
  ContainerNodeRustMethods* container_node;
  RustDocumentCreateElement rust_document_create_element{CreateElement};
  RustDocumentCreateElementWithElementCreationOptions rust_document_create_element_with_element_creation_options{CreateElementWithElementCreationOptions};
  RustDocumentCreateElementNS rust_document_create_element_ns{CreateElementNS};
  RustDocumentCreateElementNSWithElementCreationOptions rust_document_create_element_ns_with_element_creation_options{CreateElementNSWithElementCreationOptions};
  RustDocumentCreateTextNode rust_document_create_text_node{CreateTextNode};
  RustDocumentGetDocumentElement rust_document_get_document_element{DocumentElement};
};

}  // namespace webf

#endif  // WEBF_CORE_RUST_API_DOCUMENT_H_
