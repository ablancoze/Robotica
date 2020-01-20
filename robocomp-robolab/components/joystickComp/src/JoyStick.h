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

#ifndef __JoyStick_h__
#define __JoyStick_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/GCObject.h>
#include <Ice/Value.h>
#include <Ice/Incoming.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <IceUtil/UndefSysMacros.h>

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

namespace RoboCompJoyStick
{

class JoyStick;
class JoyStickPrx;

}

namespace RoboCompJoyStick
{

using JoyStickBufferedData = ::std::vector<::Ice::Byte>;

}

namespace RoboCompJoyStick
{

class JoyStick : public virtual ::Ice::Object
{
public:

    using ProxyType = JoyStickPrx;

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(::std::string id, const ::Ice::Current& current) const override;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector<::std::string> ice_ids(const ::Ice::Current& current) const override;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual ::std::string ice_id(const ::Ice::Current& current) const override;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void readJoyStickBufferedData(JoyStickBufferedData& gbd, const ::Ice::Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_readJoyStickBufferedData(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    virtual void writeJoyStickBufferedData(JoyStickBufferedData gbd, const ::Ice::Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_writeJoyStickBufferedData(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&) override;
    /// \endcond
};

}

namespace RoboCompJoyStick
{

class JoyStickPrx : public virtual ::Ice::Proxy<JoyStickPrx, ::Ice::ObjectPrx>
{
public:

    void readJoyStickBufferedData(JoyStickBufferedData& gbd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        gbd = _makePromiseOutgoing<JoyStickBufferedData>(true, this, &JoyStickPrx::_iceI_readJoyStickBufferedData, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto readJoyStickBufferedDataAsync(const ::Ice::Context& context = ::Ice::noExplicitContext)
        -> decltype(::std::declval<P<JoyStickBufferedData>>().get_future())
    {
        return _makePromiseOutgoing<JoyStickBufferedData, P>(false, this, &JoyStickPrx::_iceI_readJoyStickBufferedData, context);
    }

    ::std::function<void()>
    readJoyStickBufferedDataAsync(::std::function<void(JoyStickBufferedData)> response,
                                  ::std::function<void(::std::exception_ptr)> ex = nullptr,
                                  ::std::function<void(bool)> sent = nullptr,
                                  const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<JoyStickBufferedData>(response, ex, sent, this, &RoboCompJoyStick::JoyStickPrx::_iceI_readJoyStickBufferedData, context);
    }

    /// \cond INTERNAL
    void _iceI_readJoyStickBufferedData(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<JoyStickBufferedData>>&, const ::Ice::Context&);
    /// \endcond

    void writeJoyStickBufferedData(const JoyStickBufferedData& gbd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &JoyStickPrx::_iceI_writeJoyStickBufferedData, gbd, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto writeJoyStickBufferedDataAsync(const JoyStickBufferedData& gbd, const ::Ice::Context& context = ::Ice::noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &JoyStickPrx::_iceI_writeJoyStickBufferedData, gbd, context);
    }

    ::std::function<void()>
    writeJoyStickBufferedDataAsync(const JoyStickBufferedData& gbd,
                                   ::std::function<void()> response,
                                   ::std::function<void(::std::exception_ptr)> ex = nullptr,
                                   ::std::function<void(bool)> sent = nullptr,
                                   const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(response, ex, sent, this, &RoboCompJoyStick::JoyStickPrx::_iceI_writeJoyStickBufferedData, gbd, context);
    }

    /// \cond INTERNAL
    void _iceI_writeJoyStickBufferedData(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, const JoyStickBufferedData&, const ::Ice::Context&);
    /// \endcond

    /**
     * Obtains the Slice type ID of this interface.
     * @return The fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:

    /// \cond INTERNAL
    JoyStickPrx() = default;
    friend ::std::shared_ptr<JoyStickPrx> IceInternal::createProxy<JoyStickPrx>();

    virtual ::std::shared_ptr<::Ice::ObjectPrx> _newInstance() const override;
    /// \endcond
};

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

/// \cond INTERNAL
namespace RoboCompJoyStick
{

using JoyStickPtr = ::std::shared_ptr<JoyStick>;
using JoyStickPrxPtr = ::std::shared_ptr<JoyStickPrx>;

}
/// \endcond

#else // C++98 mapping

namespace IceProxy
{

namespace RoboCompJoyStick
{

class JoyStick;
/// \cond INTERNAL
void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< JoyStick>&);
::IceProxy::Ice::Object* upCast(JoyStick*);
/// \endcond

}

}

namespace RoboCompJoyStick
{

class JoyStick;
/// \cond INTERNAL
::Ice::Object* upCast(JoyStick*);
/// \endcond
typedef ::IceInternal::Handle< JoyStick> JoyStickPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::RoboCompJoyStick::JoyStick> JoyStickPrx;
typedef JoyStickPrx JoyStickPrxPtr;
/// \cond INTERNAL
void _icePatchObjectPtr(JoyStickPtr&, const ::Ice::ObjectPtr&);
/// \endcond

}

namespace RoboCompJoyStick
{

typedef ::std::vector< ::Ice::Byte> JoyStickBufferedData;

}

namespace RoboCompJoyStick
{

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::RoboCompJoyStick::JoyStick::begin_readJoyStickBufferedData.
 * Create a wrapper instance by calling ::RoboCompJoyStick::newCallback_JoyStick_readJoyStickBufferedData.
 */
class Callback_JoyStick_readJoyStickBufferedData_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_JoyStick_readJoyStickBufferedData_Base> Callback_JoyStick_readJoyStickBufferedDataPtr;

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 * Create a wrapper instance by calling ::RoboCompJoyStick::newCallback_JoyStick_writeJoyStickBufferedData.
 */
class Callback_JoyStick_writeJoyStickBufferedData_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_JoyStick_writeJoyStickBufferedData_Base> Callback_JoyStick_writeJoyStickBufferedDataPtr;

}

namespace IceProxy
{

namespace RoboCompJoyStick
{

class JoyStick : public virtual ::Ice::Proxy<JoyStick, ::IceProxy::Ice::Object>
{
public:

    void readJoyStickBufferedData(::RoboCompJoyStick::JoyStickBufferedData& gbd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_readJoyStickBufferedData(gbd, _iceI_begin_readJoyStickBufferedData(context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_readJoyStickBufferedData(const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_readJoyStickBufferedData(context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_readJoyStickBufferedData(const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_readJoyStickBufferedData(::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_readJoyStickBufferedData(const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_readJoyStickBufferedData(context, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_readJoyStickBufferedData(const ::RoboCompJoyStick::Callback_JoyStick_readJoyStickBufferedDataPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_readJoyStickBufferedData(::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_readJoyStickBufferedData(const ::Ice::Context& context, const ::RoboCompJoyStick::Callback_JoyStick_readJoyStickBufferedDataPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_readJoyStickBufferedData(context, cb, cookie);
    }

    void end_readJoyStickBufferedData(::RoboCompJoyStick::JoyStickBufferedData& gbd, const ::Ice::AsyncResultPtr& result);
    /// \cond INTERNAL

    void _iceI_end_readJoyStickBufferedData(::RoboCompJoyStick::JoyStickBufferedData& iceP_gbd, const ::Ice::AsyncResultPtr&);
    /// \endcond

private:

    ::Ice::AsyncResultPtr _iceI_begin_readJoyStickBufferedData(const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    void writeJoyStickBufferedData(const ::RoboCompJoyStick::JoyStickBufferedData& gbd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_writeJoyStickBufferedData(_iceI_begin_writeJoyStickBufferedData(gbd, context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_writeJoyStickBufferedData(const ::RoboCompJoyStick::JoyStickBufferedData& gbd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_writeJoyStickBufferedData(gbd, context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_writeJoyStickBufferedData(const ::RoboCompJoyStick::JoyStickBufferedData& gbd, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeJoyStickBufferedData(gbd, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_writeJoyStickBufferedData(const ::RoboCompJoyStick::JoyStickBufferedData& gbd, const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeJoyStickBufferedData(gbd, context, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_writeJoyStickBufferedData(const ::RoboCompJoyStick::JoyStickBufferedData& gbd, const ::RoboCompJoyStick::Callback_JoyStick_writeJoyStickBufferedDataPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeJoyStickBufferedData(gbd, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_writeJoyStickBufferedData(const ::RoboCompJoyStick::JoyStickBufferedData& gbd, const ::Ice::Context& context, const ::RoboCompJoyStick::Callback_JoyStick_writeJoyStickBufferedDataPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeJoyStickBufferedData(gbd, context, cb, cookie);
    }

    void end_writeJoyStickBufferedData(const ::Ice::AsyncResultPtr& result);

private:

    ::Ice::AsyncResultPtr _iceI_begin_writeJoyStickBufferedData(const ::RoboCompJoyStick::JoyStickBufferedData&, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    /**
     * Obtains the Slice type ID corresponding to this interface.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:
    /// \cond INTERNAL

    virtual ::IceProxy::Ice::Object* _newInstance() const;
    /// \endcond
};

}

}

namespace RoboCompJoyStick
{

class JoyStick : public virtual ::Ice::Object
{
public:

    typedef JoyStickPrx ProxyType;
    typedef JoyStickPtr PointerType;

    virtual ~JoyStick();

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(const ::std::string& id, const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual const ::std::string& ice_id(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void readJoyStickBufferedData(JoyStickBufferedData& gbd, const ::Ice::Current& current = ::Ice::emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_readJoyStickBufferedData(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    virtual void writeJoyStickBufferedData(const JoyStickBufferedData& gbd, const ::Ice::Current& current = ::Ice::emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_writeJoyStickBufferedData(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

protected:

    /// \cond STREAM
    virtual void _iceWriteImpl(::Ice::OutputStream*) const;
    virtual void _iceReadImpl(::Ice::InputStream*);
    /// \endcond
};

/// \cond INTERNAL
inline bool operator==(const JoyStick& lhs, const JoyStick& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) == static_cast<const ::Ice::Object&>(rhs);
}

inline bool operator<(const JoyStick& lhs, const JoyStick& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) < static_cast<const ::Ice::Object&>(rhs);
}
/// \endcond

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

namespace RoboCompJoyStick
{

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::RoboCompJoyStick::JoyStick::begin_readJoyStickBufferedData.
 * Create a wrapper instance by calling ::RoboCompJoyStick::newCallback_JoyStick_readJoyStickBufferedData.
 */
template<class T>
class CallbackNC_JoyStick_readJoyStickBufferedData : public Callback_JoyStick_readJoyStickBufferedData_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(const JoyStickBufferedData&);

    CallbackNC_JoyStick_readJoyStickBufferedData(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    /// \cond INTERNAL
    virtual void completed(const ::Ice::AsyncResultPtr& result) const
    {
        JoyStickPrx proxy = JoyStickPrx::uncheckedCast(result->getProxy());
        JoyStickBufferedData iceP_gbd;
        try
        {
            proxy->end_readJoyStickBufferedData(iceP_gbd, result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::exception(result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::CallbackNC<T>::_callback.get()->*_response)(iceP_gbd);
        }
    }
    /// \endcond

private:

    Response _response;
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_readJoyStickBufferedData.
 */
template<class T> Callback_JoyStick_readJoyStickBufferedDataPtr
newCallback_JoyStick_readJoyStickBufferedData(const IceUtil::Handle<T>& instance, void (T::*cb)(const JoyStickBufferedData&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_JoyStick_readJoyStickBufferedData<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_readJoyStickBufferedData.
 */
template<class T> Callback_JoyStick_readJoyStickBufferedDataPtr
newCallback_JoyStick_readJoyStickBufferedData(T* instance, void (T::*cb)(const JoyStickBufferedData&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_JoyStick_readJoyStickBufferedData<T>(instance, cb, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::RoboCompJoyStick::JoyStick::begin_readJoyStickBufferedData.
 * Create a wrapper instance by calling ::RoboCompJoyStick::newCallback_JoyStick_readJoyStickBufferedData.
 */
template<class T, typename CT>
class Callback_JoyStick_readJoyStickBufferedData : public Callback_JoyStick_readJoyStickBufferedData_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const JoyStickBufferedData&, const CT&);

    Callback_JoyStick_readJoyStickBufferedData(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    /// \cond INTERNAL
    virtual void completed(const ::Ice::AsyncResultPtr& result) const
    {
        JoyStickPrx proxy = JoyStickPrx::uncheckedCast(result->getProxy());
        JoyStickBufferedData iceP_gbd;
        try
        {
            proxy->end_readJoyStickBufferedData(iceP_gbd, result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::exception(result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::Callback<T, CT>::_callback.get()->*_response)(iceP_gbd, CT::dynamicCast(result->getCookie()));
        }
    }
    /// \endcond

private:

    Response _response;
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_readJoyStickBufferedData.
 */
template<class T, typename CT> Callback_JoyStick_readJoyStickBufferedDataPtr
newCallback_JoyStick_readJoyStickBufferedData(const IceUtil::Handle<T>& instance, void (T::*cb)(const JoyStickBufferedData&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_JoyStick_readJoyStickBufferedData<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_readJoyStickBufferedData.
 */
template<class T, typename CT> Callback_JoyStick_readJoyStickBufferedDataPtr
newCallback_JoyStick_readJoyStickBufferedData(T* instance, void (T::*cb)(const JoyStickBufferedData&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_JoyStick_readJoyStickBufferedData<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 * Create a wrapper instance by calling ::RoboCompJoyStick::newCallback_JoyStick_writeJoyStickBufferedData.
 */
template<class T>
class CallbackNC_JoyStick_writeJoyStickBufferedData : public Callback_JoyStick_writeJoyStickBufferedData_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_JoyStick_writeJoyStickBufferedData(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 */
template<class T> Callback_JoyStick_writeJoyStickBufferedDataPtr
newCallback_JoyStick_writeJoyStickBufferedData(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_JoyStick_writeJoyStickBufferedData<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 */
template<class T> Callback_JoyStick_writeJoyStickBufferedDataPtr
newCallback_JoyStick_writeJoyStickBufferedData(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_JoyStick_writeJoyStickBufferedData<T>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 */
template<class T> Callback_JoyStick_writeJoyStickBufferedDataPtr
newCallback_JoyStick_writeJoyStickBufferedData(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_JoyStick_writeJoyStickBufferedData<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 */
template<class T> Callback_JoyStick_writeJoyStickBufferedDataPtr
newCallback_JoyStick_writeJoyStickBufferedData(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_JoyStick_writeJoyStickBufferedData<T>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 * Create a wrapper instance by calling ::RoboCompJoyStick::newCallback_JoyStick_writeJoyStickBufferedData.
 */
template<class T, typename CT>
class Callback_JoyStick_writeJoyStickBufferedData : public Callback_JoyStick_writeJoyStickBufferedData_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_JoyStick_writeJoyStickBufferedData(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 */
template<class T, typename CT> Callback_JoyStick_writeJoyStickBufferedDataPtr
newCallback_JoyStick_writeJoyStickBufferedData(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_JoyStick_writeJoyStickBufferedData<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 */
template<class T, typename CT> Callback_JoyStick_writeJoyStickBufferedDataPtr
newCallback_JoyStick_writeJoyStickBufferedData(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_JoyStick_writeJoyStickBufferedData<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 */
template<class T, typename CT> Callback_JoyStick_writeJoyStickBufferedDataPtr
newCallback_JoyStick_writeJoyStickBufferedData(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_JoyStick_writeJoyStickBufferedData<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompJoyStick::JoyStick::begin_writeJoyStickBufferedData.
 */
template<class T, typename CT> Callback_JoyStick_writeJoyStickBufferedDataPtr
newCallback_JoyStick_writeJoyStickBufferedData(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_JoyStick_writeJoyStickBufferedData<T, CT>(instance, 0, excb, sentcb);
}

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif