/**
 *  @file
 *  @author     This file has been generated by generate-bindings.pl. DO NOT MODIFY!
 *  @copyright  Simplified BSD
 *
 *  @cond
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the FreeBSD license as published by the FreeBSD
 *  project.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  You should have received a copy of the FreeBSD license along with this
 *  program. If not, see <http://www.opensource.org/licenses/bsd-license>.
 *  @endcond
 */

#include "V8ArrayBuffer.h"

namespace Arabica {
namespace DOM {

v8::Persistent<v8::FunctionTemplate> V8ArrayBuffer::Tmpl;
v8::Persistent<v8::FunctionTemplate> V8ArrayBuffer::Constr;

v8::Handle<v8::Value> V8ArrayBuffer::constructor(const v8::Arguments& args) {
	if (!args.IsConstructCall())
		return v8::ThrowException(v8::String::New("Cannot call constructor as function"));

	uscxml::ArrayBuffer* localInstance = NULL;
	if (false) {
	} else if (args.Length() == 1 &&
	           args[0]->IsUint32()) {

		unsigned long localLength = args[0]->ToNumber()->Uint32Value();
		localInstance = new uscxml::ArrayBuffer(localLength);

	}
	if (!localInstance) {
		throw V8Exception("Parameter mismatch while calling constructor for ArrayBuffer");
		return v8::Undefined();
	}

	v8::Handle<v8::Function> retCtor = V8ArrayBuffer::getTmpl()->GetFunction();
	v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

	struct V8ArrayBuffer::V8ArrayBufferPrivate* retPrivData = new V8ArrayBuffer::V8ArrayBufferPrivate();
	retPrivData->nativeObj = localInstance;

	retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

	retObj.MakeWeak(0, V8ArrayBuffer::jsDestructor);
	return retObj;
}

v8::Handle<v8::Value> V8ArrayBuffer::byteLengthAttrGetter(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
	v8::Local<v8::Object> self = info.Holder();
	struct V8ArrayBufferPrivate* privData = V8DOM::toClassPtr<V8ArrayBufferPrivate >(self->GetInternalField(0));

	return v8::Integer::New(privData->nativeObj->getByteLength());
}

v8::Handle<v8::Value> V8ArrayBuffer::mimeTypeAttrGetter(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
	v8::Local<v8::Object> self = info.Holder();
	struct V8ArrayBufferPrivate* privData = V8DOM::toClassPtr<V8ArrayBufferPrivate >(self->GetInternalField(0));

	return v8::String::New(privData->nativeObj->getMimeType().c_str());
}

void V8ArrayBuffer::mimeTypeAttrSetter(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
	v8::Local<v8::Object> self = info.Holder();
	struct V8ArrayBufferPrivate* privData = V8DOM::toClassPtr<V8ArrayBufferPrivate >(self->GetInternalField(0));
	v8::String::AsciiValue localMimeType(value);
	privData->nativeObj->setMimeType(*localMimeType);
}

v8::Handle<v8::Value> V8ArrayBuffer::sliceCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8ArrayBufferPrivate* privData = V8DOM::toClassPtr<V8ArrayBufferPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 2 &&
	           args[0]->IsInt32() &&
	           args[1]->IsInt32()) {
		long localBegin = args[0]->ToNumber()->Int32Value();
		long localEnd = args[1]->ToNumber()->Int32Value();

		uscxml::ArrayBuffer* retVal = new uscxml::ArrayBuffer(privData->nativeObj->slice(localBegin, localEnd));
		v8::Handle<v8::Function> retCtor = V8ArrayBuffer::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8ArrayBuffer::V8ArrayBufferPrivate* retPrivData = new V8ArrayBuffer::V8ArrayBufferPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8ArrayBuffer::jsDestructor);
		return retObj;

	} else if (args.Length() == 1 &&
	           args[0]->IsInt32()) {
		long localBegin = args[0]->ToNumber()->Int32Value();

		uscxml::ArrayBuffer* retVal = new uscxml::ArrayBuffer(privData->nativeObj->slice(localBegin));
		v8::Handle<v8::Function> retCtor = V8ArrayBuffer::getTmpl()->GetFunction();
		v8::Persistent<v8::Object> retObj = v8::Persistent<v8::Object>::New(retCtor->NewInstance());

		struct V8ArrayBuffer::V8ArrayBufferPrivate* retPrivData = new V8ArrayBuffer::V8ArrayBufferPrivate();
		retPrivData->dom = privData->dom;
		retPrivData->nativeObj = retVal;

		retObj->SetInternalField(0, V8DOM::toExternal(retPrivData));

		retObj.MakeWeak(0, V8ArrayBuffer::jsDestructor);
		return retObj;

	}
	throw V8Exception("Parameter mismatch while calling slice");
	return v8::Undefined();
}

v8::Handle<v8::Value> V8ArrayBuffer::isViewCallback(const v8::Arguments& args) {

	v8::Local<v8::Object> self = args.Holder();
	struct V8ArrayBufferPrivate* privData = V8DOM::toClassPtr<V8ArrayBufferPrivate >(self->GetInternalField(0));
	if (false) {
	} else if (args.Length() == 1 &&
	           true) {
		void* localValue = v8::External::Unwrap(args[0]->ToObject()->GetInternalField(0));

		bool retVal = privData->nativeObj->isView(localValue);

		return v8::Boolean::New(retVal);
	}
	throw V8Exception("Parameter mismatch while calling isView");
	return v8::Undefined();
}
bool V8ArrayBuffer::hasInstance(v8::Handle<v8::Value> value) {
	return getTmpl()->HasInstance(value);
}

}
}