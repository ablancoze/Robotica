//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.2
//
// <auto-generated>
//
// Generated from file `JoyStick.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <JoyStick.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 2
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

const ::std::string iceC_RoboCompJoyStick_JoyStick_ids[2] =
{
    "::Ice::Object",
    "::RoboCompJoyStick::JoyStick"
};
const ::std::string iceC_RoboCompJoyStick_JoyStick_ops[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "readJoyStickBufferedData",
    "writeJoyStickBufferedData"
};
const ::std::string iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name = "readJoyStickBufferedData";
const ::std::string iceC_RoboCompJoyStick_JoyStick_writeJoyStickBufferedData_name = "writeJoyStickBufferedData";

}

bool
RoboCompJoyStick::JoyStick::ice_isA(::std::string s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompJoyStick_JoyStick_ids, iceC_RoboCompJoyStick_JoyStick_ids + 2, s);
}

::std::vector<::std::string>
RoboCompJoyStick::JoyStick::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector<::std::string>(&iceC_RoboCompJoyStick_JoyStick_ids[0], &iceC_RoboCompJoyStick_JoyStick_ids[2]);
}

::std::string
RoboCompJoyStick::JoyStick::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompJoyStick::JoyStick::ice_staticId()
{
    static const ::std::string typeId = "::RoboCompJoyStick::JoyStick";
    return typeId;
}

/// \cond INTERNAL
bool
RoboCompJoyStick::JoyStick::_iceD_readJoyStickBufferedData(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Idempotent, current.mode);
    inS.readEmptyParams();
    JoyStickBufferedData iceP_gbd;
    this->readJoyStickBufferedData(iceP_gbd, current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(iceP_gbd);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompJoyStick::JoyStick::_iceD_writeJoyStickBufferedData(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Idempotent, current.mode);
    auto istr = inS.startReadParams();
    JoyStickBufferedData iceP_gbd;
    istr->readAll(iceP_gbd);
    inS.endReadParams();
    this->writeJoyStickBufferedData(::std::move(iceP_gbd), current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompJoyStick::JoyStick::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompJoyStick_JoyStick_ops, iceC_RoboCompJoyStick_JoyStick_ops + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompJoyStick_JoyStick_ops)
    {
        case 0:
        {
            return _iceD_ice_id(in, current);
        }
        case 1:
        {
            return _iceD_ice_ids(in, current);
        }
        case 2:
        {
            return _iceD_ice_isA(in, current);
        }
        case 3:
        {
            return _iceD_ice_ping(in, current);
        }
        case 4:
        {
            return _iceD_readJoyStickBufferedData(in, current);
        }
        case 5:
        {
            return _iceD_writeJoyStickBufferedData(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond INTERNAL
void
RoboCompJoyStick::JoyStickPrx::_iceI_readJoyStickBufferedData(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<JoyStickBufferedData>>& outAsync, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name);
    outAsync->invoke(iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name, ::Ice::OperationMode::Idempotent, ::Ice::FormatType::DefaultFormat, context,
        nullptr,
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompJoyStick::JoyStickPrx::_iceI_writeJoyStickBufferedData(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const JoyStickBufferedData& iceP_gbd, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompJoyStick_JoyStick_writeJoyStickBufferedData_name, ::Ice::OperationMode::Idempotent, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_gbd);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
::std::shared_ptr<::Ice::ObjectPrx>
RoboCompJoyStick::JoyStickPrx::_newInstance() const
{
    return ::IceInternal::createProxy<JoyStickPrx>();
}
/// \endcond

const ::std::string&
RoboCompJoyStick::JoyStickPrx::ice_staticId()
{
    return JoyStick::ice_staticId();
}

#else // C++98 mapping

namespace
{

const ::std::string iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name = "readJoyStickBufferedData";

const ::std::string iceC_RoboCompJoyStick_JoyStick_writeJoyStickBufferedData_name = "writeJoyStickBufferedData";

}

/// \cond INTERNAL
::IceProxy::Ice::Object* ::IceProxy::RoboCompJoyStick::upCast(JoyStick* p) { return p; }

void
::IceProxy::RoboCompJoyStick::_readProxy(::Ice::InputStream* istr, ::IceInternal::ProxyHandle< JoyStick>& v)
{
    ::Ice::ObjectPrx proxy;
    istr->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new JoyStick;
        v->_copyFrom(proxy);
    }
}
/// \endcond

::Ice::AsyncResultPtr
IceProxy::RoboCompJoyStick::JoyStick::_iceI_begin_readJoyStickBufferedData(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name, ::Ice::Idempotent, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompJoyStick::JoyStick::end_readJoyStickBufferedData(::RoboCompJoyStick::JoyStickBufferedData& iceP_gbd, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_gbd);
    result->_endReadParams();
}

void IceProxy::RoboCompJoyStick::JoyStick::_iceI_end_readJoyStickBufferedData(::RoboCompJoyStick::JoyStickBufferedData& iceP_gbd, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompJoyStick_JoyStick_readJoyStickBufferedData_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_gbd);
    result->_endReadParams();
}

::Ice::AsyncResultPtr
IceProxy::RoboCompJoyStick::JoyStick::_iceI_begin_writeJoyStickBufferedData(const ::RoboCompJoyStick::JoyStickBufferedData& iceP_gbd, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompJoyStick_JoyStick_writeJoyStickBufferedData_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompJoyStick_JoyStick_writeJoyStickBufferedData_name, ::Ice::Idempotent, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_gbd);
        result->endWriteParams();
        result->invoke(iceC_RoboCompJoyStick_JoyStick_writeJoyStickBufferedData_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompJoyStick::JoyStick::end_writeJoyStickBufferedData(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompJoyStick_JoyStick_writeJoyStickBufferedData_name);
}

/// \cond INTERNAL
::IceProxy::Ice::Object*
IceProxy::RoboCompJoyStick::JoyStick::_newInstance() const
{
    return new JoyStick;
}
/// \endcond

const ::std::string&
IceProxy::RoboCompJoyStick::JoyStick::ice_staticId()
{
    return ::RoboCompJoyStick::JoyStick::ice_staticId();
}

RoboCompJoyStick::JoyStick::~JoyStick()
{
}

/// \cond INTERNAL
::Ice::Object* RoboCompJoyStick::upCast(JoyStick* p) { return p; }

/// \endcond

namespace
{
const ::std::string iceC_RoboCompJoyStick_JoyStick_ids[2] =
{
    "::Ice::Object",
    "::RoboCompJoyStick::JoyStick"
};

}

bool
RoboCompJoyStick::JoyStick::ice_isA(const ::std::string& s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompJoyStick_JoyStick_ids, iceC_RoboCompJoyStick_JoyStick_ids + 2, s);
}

::std::vector< ::std::string>
RoboCompJoyStick::JoyStick::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&iceC_RoboCompJoyStick_JoyStick_ids[0], &iceC_RoboCompJoyStick_JoyStick_ids[2]);
}

const ::std::string&
RoboCompJoyStick::JoyStick::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompJoyStick::JoyStick::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::RoboCompJoyStick::JoyStick";
    return typeId;
#else
    return iceC_RoboCompJoyStick_JoyStick_ids[1];
#endif
}

/// \cond INTERNAL
bool
RoboCompJoyStick::JoyStick::_iceD_readJoyStickBufferedData(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Idempotent, current.mode);
    inS.readEmptyParams();
    JoyStickBufferedData iceP_gbd;
    this->readJoyStickBufferedData(iceP_gbd, current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(iceP_gbd);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompJoyStick::JoyStick::_iceD_writeJoyStickBufferedData(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Idempotent, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    JoyStickBufferedData iceP_gbd;
    istr->read(iceP_gbd);
    inS.endReadParams();
    this->writeJoyStickBufferedData(iceP_gbd, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

namespace
{
const ::std::string iceC_RoboCompJoyStick_JoyStick_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "readJoyStickBufferedData",
    "writeJoyStickBufferedData"
};

}

/// \cond INTERNAL
bool
RoboCompJoyStick::JoyStick::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompJoyStick_JoyStick_all, iceC_RoboCompJoyStick_JoyStick_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompJoyStick_JoyStick_all)
    {
        case 0:
        {
            return _iceD_ice_id(in, current);
        }
        case 1:
        {
            return _iceD_ice_ids(in, current);
        }
        case 2:
        {
            return _iceD_ice_isA(in, current);
        }
        case 3:
        {
            return _iceD_ice_ping(in, current);
        }
        case 4:
        {
            return _iceD_readJoyStickBufferedData(in, current);
        }
        case 5:
        {
            return _iceD_writeJoyStickBufferedData(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond STREAM
void
RoboCompJoyStick::JoyStick::_iceWriteImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice(ice_staticId(), -1, true);
    ::Ice::StreamWriter< JoyStick, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
RoboCompJoyStick::JoyStick::_iceReadImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< JoyStick, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

/// \cond INTERNAL
void
RoboCompJoyStick::_icePatchObjectPtr(JoyStickPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = JoyStickPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(JoyStick::ice_staticId(), v);
    }
}
/// \endcond

namespace Ice
{
}

#endif
