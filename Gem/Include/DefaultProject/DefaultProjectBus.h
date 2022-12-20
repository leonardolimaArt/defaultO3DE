
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace DefaultProject
{
    class DefaultProjectRequests
    {
    public:
        AZ_RTTI(DefaultProjectRequests, "{CC2F5967-168D-45C5-B06C-1CB60EF8D702}");
        virtual ~DefaultProjectRequests() = default;
        // Put your public methods here
    };

    class DefaultProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using DefaultProjectRequestBus = AZ::EBus<DefaultProjectRequests, DefaultProjectBusTraits>;
    using DefaultProjectInterface = AZ::Interface<DefaultProjectRequests>;

} // namespace DefaultProject
