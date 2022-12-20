
#pragma once

#include <AzCore/Component/Component.h>

#include <DefaultProject/DefaultProjectBus.h>

namespace DefaultProject
{
    class DefaultProjectSystemComponent
        : public AZ::Component
        , protected DefaultProjectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(DefaultProjectSystemComponent, "{CF8425A7-AF8F-4700-B3EE-9B082CDB9128}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        DefaultProjectSystemComponent();
        ~DefaultProjectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // DefaultProjectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
